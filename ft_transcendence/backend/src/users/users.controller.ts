import {
    BadRequestException,
    Body,
    Controller,
    Delete,
    Get,
    Logger,
    NotFoundException,
    Param,
    Patch,
    Post,
    Req,
    Request,
    Res,
    UploadedFile,
    UseGuards,
    UseInterceptors
} from '@nestjs/common'
import { UsersService } from './users.service'
import { CreateUserDto } from './dto/create-user.dto'
import { UpdateUserDto } from './dto/update-user.dto'
import { Serialize } from "./users.interceptor"
import { UserDto } from "./dto/user.dto"
import { AuthGuard } from '@nestjs/passport'
import { Response } from 'express'
import { FileInterceptor } from "@nestjs/platform-express"
import * as fs from "fs"
import { diskStorage } from "multer"
import * as path from "path"
import { JwtAuthGuard } from "../auth/jwt-auth.guard"

// const utils = {
//   getFileExtension()
// }

@Controller('users')
@Serialize(UserDto)
export class UsersController {

    private logger: Logger = new Logger('UsersController')

    constructor(private readonly usersService: UsersService) {
    }

    @Post()
    async create(@Body() createUserDto: CreateUserDto) {
        return await this.usersService.create(createUserDto)
    }

    @Get()
    findAll() {
        return this.usersService.findAll()
    }

    @Get('/me')
    @UseGuards(JwtAuthGuard)
    findMe(@Request() req) {
        const username = req.user.username
        return this.usersService.findOne(username)
    }

    @Get(':username')
    @UseGuards(JwtAuthGuard)
    async findOne(@Param('username') username: string) {
        const user = await this.usersService.findOne(username)
        if (!user)
            throw new NotFoundException("User not found")
        return user
    }

    @Patch(':id')
    update(@Param('id') id: string, @Body() updateUserDto: UpdateUserDto) {
        return this.usersService.update(+id, updateUserDto)
    }

    @Delete(':id')
    remove(@Param('id') id: string) {
        return this.usersService.remove(+id)
    }

    @Get('/:id/friends')
    findFriends(@Param('id') id: string) {
        return this.usersService.findFriends(+id)
    }

    @Patch('/:id/add-friend')
    addFriend(@Param('id') id: string, @Body() {friendId}) {
        return this.usersService.addFriend(+id, friendId)
    }

    @Get('login')
    @UseGuards(AuthGuard('api42'))
    async login(@Req() req, @Res() res: Response) {
        return req.user
    }

    @Post('/:username/avatar')
    @UseGuards(JwtAuthGuard)
    @UseInterceptors(FileInterceptor('avatar', {
        storage: diskStorage({
            destination: function (req, file, cb) {
                const path = process.env.AVATAR_PATH
                fs.mkdirSync(path, {
                    recursive: true
                })
                cb(null, path)
            },
            filename: (req, file, cb) => {
                const filename = file.originalname.split(".")
                const extension = filename[filename.length - 1]
                cb(null, `${req.params.username}.${extension}`)
            }
        }),
        fileFilter: (req, file, callback) => {
            let ext = path.extname(file.originalname)
            if (ext !== '.png' && ext !== '.jpg' && ext !== '.gif' && ext !== '.jpeg')
                callback(new BadRequestException('Only images are allowed'), false)
            else
                callback(null, true)
        }
    }))
    async avatarUpload(@Param('username') username: string, @UploadedFile() file: Express.Multer.File) {
        const user = await this.usersService.findOne(username)
        if (!user) {
            fs.rm(`avatars/${file.filename}`, (err) => null)
            throw new NotFoundException()
        }
        user.avatar = file.filename
        await this.usersService.update(user.id, user)
        return user
    }

}
