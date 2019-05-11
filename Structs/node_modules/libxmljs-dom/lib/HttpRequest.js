'use strict';
var URL     = require('url');
var needle  = require('needle');

needle.defaults({
    follow: 3,
    compressed: true,
    parse_response: false,
    decode_response: true,
    follow_set_cookies: true,
    follow_set_referer: true,
    rejectUnauthorized: false
})

function HttpRequest(window, url, callback) {
    if (url.substr(0, 2) === '//')
        url = window.location.protocol+url;
    if (typeof url === 'string')
        url = URL.parse(url);
    var method  = url.method||'get';
    var href    = URL.format(url);
    if (url.host === null || url.protocol === null)
        href    = URL.resolve(window.location.href, href);

    var data    = url.data;
    var opts = {
        proxy:      url.proxy,
        timeout:    url.timeout||30*1000,
        user_agent: url.user_agent||window.navigator.userAgent,
        //headers:    url.headers,
        headers: {
            referer:    url.referer||window.location.href,
        },
        cookies:    window.document.cookies,
        accept:     url.accept
    }

    window.__stackPush();
    window.alert('[libxmljs-dom] '+method+' '+href);
    needle.request(method, href, data, opts, function(err, res, data) {
        if (res !== undefined && res.cookies !== undefined)
            window.document.cookies = res.cookies;
        callback(err, res, data);
        window.__stackPop();
    })
}

module.exports = HttpRequest;
