import { Column, Entity, PrimaryColumn, PrimaryGeneratedColumn, Unique } from "typeorm";

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

}
