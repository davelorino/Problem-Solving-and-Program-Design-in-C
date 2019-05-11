'use strict';
var needle = require('needle');
var URL = require('url');

module.exports = function(window) {
    var XMLHttpRequest = function() {
        this.opts = {
            parse: false
        };
    }

    XMLHttpRequest.prototype = {
        status: 200,
        statusText: '',
        readyState: 0,
        withCredentials: false,
        getAllResponseHeaders: function() {
            return this.rawResponseHeaders;
        },
        getResponseHeader: function(header) {
            return this.responseHeaders[header.toLowerCase()];
        },
        setRequestHeader: function(header, value) {
            if (this.opts.headers === undefined)
                this.opts.headers = {};
            this.opts.headers[header] = value;
        },
        open: function(method, url, is_async, user, pass) {
            this.method = method;
            this.setRequestHeader('Referer', window.location.href);
            this.setRequestHeader('Cookie', window.document.cookie);
            this.url = URL.format(URL.resolve(window.location.href, url));
            this.async = is_async;
            this.user = user;
            this.pass = pass;
            this.readyState = 1;
        },
        overrideMimeType: function(mime) {

        },
        send: function(data) {
            var self = this;
            window.__stackPush();
            console.log('[libxmljs-dom] XMLHttpRequest: '+this.method+' '+this.url);
            needle.request(this.method, this.url, data, this.opts, function(err, res, data) {
                if (err) console.log('[libxmljs-dom] XMLHttpRequest: '+err);
                self.readyState = 4;
                self.response = data.toString();
                self.responseText = data.toString();
                self.responseType = "text";
                self.responseHeaders = res.headers;
                var rawHeaders = res.socket._httpMessage._header;
                self.rawResponseHeaders = rawHeaders.substr(rawHeaders.indexOf("\r\n")+2);
                self.status = res.statusCode;
                self.statusText = res.statusMessage;
                if (self.onreadystatechange !== undefined) {
                    self.onreadystatechange();
                }else if (self.onload !== undefined) {
                    self.onload();
                }
                window.__stackPop();
            })
        }
    }

    return XMLHttpRequest;
}
