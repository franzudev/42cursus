import type { User } from "@/@types/User"

export interface Room {
    name: string
    id: string
    users: User
}
