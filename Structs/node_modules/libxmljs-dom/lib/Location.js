'use strict';
var URL = require('url');

function Location(url, document) {
    this.url = url;
    if (typeof this.url === 'string')
        this.url    = URL.parse(url);
    if (this.url.host === null || this.url.protocol === null)
        this.url    = URL.parse(URL.resolve(document.location.href, this.url.href));

    this.document = document;
    return this;
}

Location.prototype = {
    assign: function() {

    },
    get hash() {
        return this.url.hash||'';
    },
    set hash(val) {
        this.url.hash = '#'+val;
    },
    get host() {
        return this.url.host;
    },
    set host(val) {
        this.url.host = val;
        this.reload();
    },
    get hostname() {
        return this.url.hostname;
    },
    set hostname(val) {
        this.url.hostname = val;
        this.reload();
    },
    get href() {
        return URL.format(this.url);//this.url.href;
    },
    set href(val) {
        console.log("setting href", val)
        this.url = URL.parse(val);
        this.reload();
    },
    get origin() {
        return this.url.protocol.replace(/:$/, '://')+this.host;
    },
    get password() {
        return this.url.password||'';
    },
    set password(val) {
        this.url.password = val;
        var auth = this.username;
    },
    get pathname() {
        return this.url.pathname;
    },
    set pathname(val) {
        this.url.pathname = val;
        this.reload();
    },
    get port() {
        return this.url.port||'';
    },
    set port(val) {
        this.url.port = val;
        this.reload();
    },
    get protocol() {
        return this.url.protocol;
    },
    set protocol(val) {
        this.url.protocol = val;
    },
    reload: function(cache) {
        this.document.reload();
    },
    replace: function() {
        this.document.reload();
    },
    resolve: function(url) {
        return URL.resolve(this.url, url);
    },
    get search() {
        if (this.url.search !== null && this.url.search.length > 0 && this.url.search.charAt(0) !== '?')
            return '?'+this.url.search;
        return this.url.search;
    },
    set search(val) {
        this.url.search = val;
        this.reload();
    },
    get username() {
        return this.url.username;
    },
    set username(val) {
        this.url.username = val.username;
    },
    toString: function() {
        return URL.format(this.url);
    }
}

module.exports = Location;
