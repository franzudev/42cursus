import axios, {
    type AxiosError,
    type AxiosResponse
} from 'axios';

const url: string = (import.meta.env.VITE_APP_ENV === 'production'? import.meta.env.VITE_APP_URL : import.meta.env.VITE_APP_DEV_URL) as string

export class Api {
    public resourcePath: string;
    public pageSize: number;

    constructor(resourcePath: string, pageSize: number = 20) {
        this.resourcePath = resourcePath;
        this.pageSize = pageSize;
    }

    /** abstract */
    public getWritableProperties = () => null;

    /** abstract */
    public getIdPropertyName = () => 'id';

    protected _baseUrl() {
        return this._client().defaults.baseURL;
    }

    protected _url() {
        return `${this._baseUrl()}${this.resourcePath}`;
    }

    protected urlForResource(id: string) {
        return `${this._url()}/${id}`;
    }

    protected _client() {
        return apiClient;
    }

    protected _unwrap = (response: AxiosResponse) => response.data;

    protected _getEntityUrl(id: string | number) {
        return `${this._url()}/${id}`;
    }

    protected _file(data: any, config: any) {
        return this
            ._client()
            .post(`${this._url()}/upload`, data, config)
            .then(this._unwrap);
    }

    protected _getAll() {
        return this
            ._client()
            .get(`${this._url()}/all`)
            .then(this._unwrap);
    }

    protected _getOne(id: string, params = {}) {
        return this
            ._client()
            .get(this._getEntityUrl(id), { params })
            .then(this._unwrap);
    }

    protected _put(id: string | number, data = {}, overrides = {}) {
        return this
            ._client()
            .put(this._getEntityUrl(id), this._prepare(data, this.getWritableProperties(), overrides))
            .then(this._unwrap)
    }

    protected _post(data: any, others = {}) {
        return this
            ._client()
            .post(`${this._url()}`, this._prepare(data, this.getWritableProperties(), others))
            .then(this._unwrap);
    }

    protected _putOrPost(data: any, others = {}) {
        const idCandidate = data[this.getIdPropertyName()];
        return idCandidate
            ? this._put(idCandidate, data, others)
            : this._post(data, others);
    }

    protected _delete(id: string) {
        return this
            ._client()
            .delete(this._getEntityUrl(id));
    }

    protected _prepare(original: any, writablePropertyNames: any[] | null = [], overrides = {}) {

        let clone = writablePropertyNames === null ? Object.assign({}, original) : {};
        clone = Object.assign(clone, overrides);

        if (writablePropertyNames) {
            writablePropertyNames.forEach((name) => {
                if (typeof clone[name] === 'undefined') {
                    clone[name] = original[name];
                }
            });
        }

        return clone;
    }
}

const AJAX_REQUEST_TIMEOUT_MS = 20 * 60 * 1000; // 20 minutes.

/**
 * AUTH
 */
export const authClient = axios.create({
    baseURL: url,
    timeout: AJAX_REQUEST_TIMEOUT_MS,
    headers: {
        'Content-Type': 'application/json',
    },
});

/**
 * API
 */
export const apiClient = axios.create({
    baseURL: url,
    timeout: AJAX_REQUEST_TIMEOUT_MS,
    xsrfCookieName: 'token',
    xsrfHeaderName: 'jwt',
});

apiClient.interceptors.request.use((config) => {
    config.headers!["Access-Control-Allow-Origin"] = "*"
    console.log(getJwt("token"))
    config.headers!['Authorization'] = `Bearer ${getJwt("token")}`;
    return config;
});

apiClient.interceptors.response.use(
    (response: AxiosResponse) => response,
    (error: AxiosError) => Promise.reject(error)
);

const getJwt = (cname: string) => {
    let name = cname + "=";
    let decodedCookie = decodeURIComponent(document.cookie);
    let ca = decodedCookie.split(';');
    for(let i = 0; i <ca.length; i++) {
        let c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}
