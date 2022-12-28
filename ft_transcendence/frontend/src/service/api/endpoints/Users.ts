import { Api } from '../Api'

class Users extends Api {
    constructor() {
        super('/users', 10)
    }

    // public list = this._filtered;

    public byId = this._getOne

    public createOrUpdate = this._putOrPost

    public update = this._put

    public create = this._post

    public delete = this._delete
}

export default new Users()
