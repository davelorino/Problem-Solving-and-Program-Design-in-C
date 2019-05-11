'use strict';
var History = require('./History.js');
var vm = require('vm');
var needle = require('needle');
var URL = require('url');
var Event = require('./Event.js');
var Storage = require('./Storage.js');
var HttpRequest    = require('./HttpRequest.js')
var XMLHttpRequest = require('./XMLHttpRequest.js')

function bindEvent(name, cb) {
    return cb;
}

var noop = function() {
    libxmljs.log("WINDOW NOOP");
}

function Window(context) {
    var window = this;

    if (context !== undefined)
        this.document = context;

    return this;
}

Object.defineProperty(console, 'log', {
    configurable: true,
    writable: true
})

Window.prototype = {
    alert: function(m) { libxmljs.log('alert:', m) },
    applicationCache: {
        status: 0,
    },
    atob: function(s) { return (new Buffer(s, 'base64')).toString() },
    btoa: function(s) { return s.toString('base64') },
    back: function() {
        this.history.back();
    },
    blur: noop,
    cancelAnimationFrame: noop,
    close: function() {
        this.closed = true;
    },
    closed: false,
    confirm: noop,
    crypto: {},
    defaultStatus: '',
    devicePixelRatio: 1,
    get document() {
        if (this.__document === undefined)
            this.__document = new libxmljs.Document();
        return this.__document;
    },
    set document(doc) {
        this.__document = doc;
        this.__document.defaultView = this;
        this.__document.readyState = 'interactive';
        this.__evalScripts();
    },
    domain: '',
    //dump: libxmljs.log,
    __evalScripts: function() {
        var window = this;
        window.__stackPush();
        var script = window.document.querySelector('script:not([ran])');
        if (!script) {
            if (this.document.readyState !== "complete") {
                this.document.readyState = "complete";
                this.document.dispatchEvent('DOMContentLoaded');
                this.dispatchEvent('load');
            }
            window.__stackPop();
            return;
        }
        script.setAttribute('ran', true);
        window.document.currentScript = script;
        var src = script.src;
        if (src && src.length > 0) {
            HttpRequest(window, src, function(err, res, data) {
                if (err) {
                    libxmljs.log("error:", err)
                }else if (res.headers && res.headers['content-type'] !== undefined && res.headers['content-type'].indexOf('javascript') === -1) {
                    //libxmljs.log("Got non javascript", res.headers['content-type'])
                }else{
                    libxmljs.log("[libxmljs-dom] Executing remote script: "+src);
                    window.eval(data.toString(), src);
                }
                window.__evalScripts();
                window.__stackPop();
            })
        }else{
            var type = script.getAttribute('type');
            if (type === null || type.toLowerCase().indexOf('text/j') === -1) {
                var src = window.location.href+'.<script>['+(script.querySelectorAll('.//preceding::script').length+1)+']';
                libxmljs.log("[libxmljs-dom] Executing local script: " + src);
                window.eval(script.text(), src);
            }
            window.__evalScripts();
            window.__stackPop();
        }
    },
    eval: function(code, filename) {
        var self = this;
        if (this.__scriptContext === undefined) {
            Object.defineProperty(self, '__scriptContext', { value: vm.createContext(), enumerable:false, configurable: true, writable:true });
            for (var oi = 2; oi--;) {
                var obj = (oi===1)?self:Window.prototype;
                var keys = Object.keys(obj);
                var i = keys.length;
                while (i--) {
                    var key = keys[i];
                    if (key === 'window') continue;
                    Object.defineProperty(self.__scriptContext, key, {
                        configurable: true,
                        enumerable: true,
                        get: (function(key) {
                            if (Object.getOwnPropertyDescriptor(obj, key).get === undefined &&
                                typeof obj[key] === 'function')
                                return function() { return self[key].bind(self) };
                            else
                                return function() { return self[key] };
                        })(key),
                        set: (function(key) {
                            return function(val) { self[key] = val; };
                        })(key)
                    })
                }
                obj  = null;
                keys = null;
            }
        }
        this.__scriptContext.window = this.__scriptContext;
        try {
            var script = vm.createScript(code, {filename: filename });
            script.runInContext(this.__scriptContext);
        } catch (err) {
            if (this.onerror !== undefined)
                this.onerror(err.message, err.filename, err.lineno, err.colno, err)
            libxmljs.log(err.stack)
            //process.exit();
        }
        for (var key in this.__scriptContext) {
            if (Object.getOwnPropertyDescriptor(this.__scriptContext, key).get !== undefined) continue;
            if (self[key] == this.__scriptContext[key] || key === 'window') continue;
            //libxmljs.log("setting key", key)
            self[key] = this.__scriptContext[key];
        }
        code = null;
    },
    Event: Event,
    frameElement: null,
    get frames() {
        return this.document.getElementsByTagName('iframe');
    },
    focus: noop,
    forward: function() {
        this.history.forward();
    },
    fullScreen: false,
    getComputedStyle: function(el, pseudoEl) {
        return el.style;
    },
    getDefaultComputedStyle: function(el, pseudoEl) {
        return el.style;
    },
    getSelection: function() {
        return {
            anchorNode: null,
            anchorOffset: 0,
            focusNode: null,
            focusOffset: 0,
            isCollapsed: true,
            rangeCount: 0,
            caretBidiLevel: null
        }
    },
    history: new History(),
    Image: function(height, width) {

    },
    innerHeight: 1000,
    innerWidth: 1000,
    get length() {
        return this.document.getElementsByTagName('iframe').length;
    },
    get location() {
        return this.document.location;
    },
    set location(val) {
        this.document.location = val;
    },
    localStorage: new Storage,
    locationbar: { visible: true },
    matchMedia: function(mediaQuery) {
        //libxmljs.log("MATCH Media", mediaQuery)
        return {
            __compile: function() {
                if (this.__cb !== undefined)
                    return this.__cb;
            },
            addListener: function(listener) {
                //libxmljs.log("add media listener", listener.toString())
            },
            removeListener: function(listener) {
                //libxmljs.log("remove media listener", listener.toString())
            },
            match: mediaQuery,
            get matches() {
                //return this.__compile();
                return false;
            }
        };
    },
    moveBy: noop,
    moveTo: noop,
    menubar: { visible: true },
    name: '',
    navigator: require('./Navigator.js'),
    onerror: function(message, filename, line, column, err) {
        libxmljs.error("[libxmljs-dom] Window.onerror: ", err)
    },
    open: function(url, name, features) {
        return new Window;
        var window = new Window(this.document.parse("<body></body>"));
        var request = new this.XMLHttpRequest();
        request.open('get', url);
        request.send();
        request.onload = function(err, res, data) {
            window.document = data;
        }
        return window;
    },
    opener: null,
    Option: function(text, value, defaultSelected, selected) {

    },
    outerHeight: 1000,
    outerWidth: 1000,
    pageXOffset: 0,
    pageYOffset: 0,
    get parent() {
        return this;
    },
    /*performance: {
        timing: {},
        navigation: {},
        onresourcetimingbufferfull: null
    },*/
    personalbar: {
        visible: true,
    },
    postMessage: noop,
    print: noop,
    prompt: noop,
    requestAnimationFrame: function(cb) {
        cb((new Date()).getTime());
    },
    resizeBy: noop,
    resizeTo: noop,
    screen: {
        colorDepth: 24,
        pixelDepth: 24,
        availHeight: 1000,
        availWidth: 1000,
        width: 1000,
        height: 1000
    },
    screenLeft:0,
    screenTop:0,
    screenX:0,
    screenY:0,
    scroll: noop,
    scrollBy: noop,
    scrollByLines: noop,
    scrollByPages: noop,
    scrollTo: noop,
    scrollX:0,
    scrollY:0,
    scrollMaxX:0,
    scrollMaxY:0,
    scrollbars: { visible: true },
    get self() {
        return this;
    },
    sessionStorage: new Storage,
    __stackCount: 0,
    __stackPush: function() {
        return ++this.__stackCount;
    },
    __stackPop: function() {
        if (--this.__stackCount === 0) {
            this.document.currentScript = null;
            this.dispatchEvent('done');
        }
    },
    status: '',
    statusbar: { visible: true },
    stop: noop,
    toolbar: { visible: true },
    get top() {
        return this;
    },
    get window() {
        return this;
    },
    get XMLHttpRequest() {
        return XMLHttpRequest(this);
    },
    setTimeout: function() {
        if (this.closed === true) return;
        var self = this;
        var cb = arguments[0];
        var delay = arguments[1];
        if (delay > 5000) // Allow no more than 5 seconds
            arguments[1] = 5000;
        //self.__stackPush();
        arguments[0] = function() {
            if (self.closed === true) return;
            if (typeof cb === 'function')
                cb();
            else
                self.eval(cb);
            //self.__stackPop();
        }
        return setTimeout.apply(null, arguments);
    },
    setInterval: function() {
        if (this.closed === true) return;
        var self = this;
        var cb = arguments[0];
        if (arguments[1] > 3000)
            arguments[1] = 3000;
        var count = 0;
        //self.__stackPush();
        arguments[0] = function() {
            if (self.closed === true || ++count === 3)
                return clearInterval(interval)
            if (typeof cb === 'function')
                cb();
            else
                self.eval(cb);
        }
        var interval = setInterval.apply(null, arguments);
        return interval;
    },
    clearTimeout: function(cb) {
        //this.__stackPop();
        return clearTimeout(cb);
    },
    clearInterval: function(cb) {
        //this.__stackPop();
        return clearInterval(cb);
    },
    console: console,
}

/* define implied setters */
var setNoop = function() {};
for (var key in Window.prototype) {
    var prop = Object.getOwnPropertyDescriptor(Window.prototype, key);
    if (prop.get !== undefined && prop.set === undefined) {
        prop.set = setNoop;
        Object.defineProperty(Window.prototype, key, prop);
    }
}

var scriptCache = {

}

function extend(obj1, obj2) {
    for (var key in obj2) {
        if (obj2.hasOwnProperty(key)) {
            obj1[key] = obj2[key];
        }
    }
    return obj1;
}

var libxmljs = null;
module.exports = function(libxml) {
    libxmljs = libxml;
    return Window;
}
