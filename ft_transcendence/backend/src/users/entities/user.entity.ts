import {
	BeforeInsert,
	Column,
	Entity,
	JoinTable,
	ManyToMany,
	OneToMany,
	PrimaryColumn,
	PrimaryGeneratedColumn,
	Unique
} from "typeorm";
import { Message } from "../../rooms/entities/message.entity";

@Entity()
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

	@ManyToMany(() => User)
	@JoinTable()
	friends: User

	@BeforeInsert()
	handleInsertion() {
		if (!this.avatar)
			this.avatar = process.env.AVATAR_PATH + "/default.jpg"
	}

}
