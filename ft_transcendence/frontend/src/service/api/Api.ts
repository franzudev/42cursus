import axios, { AxiosError, AxiosResponse } from 'axios';

const env = process.env.MIX_APP_ENV
const prod = process.env.MIX_APP_URL;
const dev = process.env.MIX_DEV_APP_URL;

const url = env === 'production'? prod : dev

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
        return '';
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

    // _unwrapList = (response: AxiosResponse) => this._unwrap(response);

    protected _getEntityUrl(id: string | number) {
        return `${this._url()}/${id}`;
    }

    protected _getCountUrl() {
        return `${this._url()}/count`;
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

    protected _commonGet(url: string) {
        return this
            ._client()
            .get(`${this._url()}${url}`)
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

    protected _count() {
        return this
            ._client()
            .get(this._getCountUrl())
            .then(this._unwrap);
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

function normalizeConfigUrl(path: string | undefined): string {
    if (path?.startsWith('http')) {
        return path;
    }

    const base = location.protocol + '//' + location.hostname + (location.port ? ':' + location.port : '');
    return base + path;
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
    timeout: AJAX_REQUEST_TIMEOUT_MS
});

apiClient.interceptors.request.use((config) => {
    config.headers['X-Requested-With'] = 'XMLHttpRequest';
    config.headers['X-CSRF-TOKEN'] = (document.head.querySelector('meta[name="csrf-token"]')! as HTMLMetaElement).content;
    return config;
});

apiClient.interceptors.response.use(
    (response: AxiosResponse) => response,
    (error: AxiosError) => Promise.reject(error)
);
