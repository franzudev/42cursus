import {
	BeforeInsert,
	Column,
	Entity,
	JoinTable,
	ManyToMany, ManyToOne,
	OneToMany,
	PrimaryColumn,
	PrimaryGeneratedColumn,
	Unique
} from "typeorm";
import { Message } from "../../rooms/entities/message.entity";

@Entity("users")
@Unique(["username"])
export class User {
	@PrimaryGeneratedColumn()
	id: number;

	@Column()
	username: string;

	@Column({ nullable: true })
	avatar: string;

	@Column({ nullable: true })
	twoFactorAuthCode: string;

	@Column()
	oauthToken: string;

	@Column({ nullable: true }) 
	twoFactorEnabled: boolean;

	@Column({ nullable: true })
	telephoneNumber: string;

	@ManyToMany((type) => User, (user) => user.friends, {
		onUpdate: "CASCADE"
	})
	@JoinTable({
		schema: "public",
		name: "users_friends_users",
		joinColumn: {
			name: "usersId_1"
		}
	})
	friends: User[]

	@BeforeInsert()
	handleInsertion() {
		if (!this.avatar)
			this.avatar = process.env.AVATAR_PATH + "/default.jpg"
	}

}
