import type { User } from "@/@types/User"

export interface Room {
    name: string
    id: number
    users: User[]
    image: string
    description: string
}
