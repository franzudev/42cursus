import { Injectable } from '@nestjs/common'
import { ConfigService } from "@nestjs/config"

@Injectable()
export class RedisService {
    private redis: any

    constructor(
        private readonly configService: ConfigService
    ) {
        const Redis = require("ioredis")
        this.redis = new Redis(configService.get<number>("REDIS_PORT"), configService.get<string>("REDIS_HOST"))
    }

    setKey(key: string, value: any) {
        return this.redis.set(key, value)
    }

    getKey(key: string) {
        return this.redis.get(key)
    }
}
