var Event = require('./Event.js');

EventTarget = {
    addEventListener: function (name, cb, capture) {
        //console.log("addEventListener", this.nodeName||'window', name)
        var events = this.__events__;
        if (events === undefined)
            events = this.__events__ = {};
        if (events[name] === undefined)
            events[name] = [];

        events[name].push(cb);

        if (name === 'done') {
            var window = this.window||this.defaultView||this.doc().defaultView;
            if (window.__stackCount === 0)
                this.dispatchEvent('done');
        }
    },
    dispatchEvent: function (event) {
        if (this.window !== undefined && !this.document) return true;
        if (typeof event === 'string') {
            event = new Event(event);
            event.target = this;
        }

        //console.log("dispatchEvent", this.nodeName||'window', event.type)
        var type = event.type;
        var events = this.__events__;
        if (events === undefined) {
            events = this.__events__ = {};
        }

        var window = window||this.window||this.defaultView||this.doc().defaultView;

        if (this.getAttribute !== undefined) {
            var f = this['on'+type];
            if (f !== undefined && f !== null) {
                if (typeof f === 'function')
                    f = f.toString();
                f = '(function () {' + f + '})()';
                //console.log("on"+type+'="'+f.toString()+'"');
                window.eval(f);
            }
        }

        if (events[type] === undefined || events[type].length === 0) {
            //console.log("NO EVENT", type);
            return false;
        }

        if (event.target === undefined)
            event.target = this;
        if (event.target.getAttribute === undefined)
            event.target = this.document?this.document.documentElement:this.documentElement||this.doc().documentElement;
        event.currentTarget = this;

        window.__stackPush();
        var arr = events[type];
        var i = arr.length;
        while (i--) {
            var cb = arr[i];
            if (event.defaultPrevented === true) {
                //console.log("got prevent default")
                window.__stackPop();
                return;
            }
            cb.call(event.currentTarget, event)
            if (type === 'done')
                event.currentTarget.removeEventListener(type, cb)
        }
        window.__stackPop();
        //window.__evalScripts();
        return true;
    },
    removeEventListener: function (name, cb, capture) {
        //console.log("removeEventListener", name)
        var events = this.__events__;
        if (events === undefined)
            return this.__events__ = {};
        if (events[name] === undefined)
            return;
        for (var i = events[name].length; i--;) {
            if (events[name][i] != cb) continue;
            events[name][i] = null;
            events[name].splice(i, 1);
            break;
        }
    },
}

var handlers = ['abort', 'afterprint', 'beforeprint', 'beforeunload', //'blur',
                'change', 'click', 'contextmenu', 'dblclick',
                'error',/* 'focus',*/, 'focusin', 'hashchange', 'input', 'keydown', 'keypress',
                'keyup', 'languagechange', 'load', 'mousedown', 'mousemove',
                'mouseout', 'mouseover', 'mouseup', 'popstate', 'reset',
                'resize', 'scroll', 'select', 'selectstart', 'submit', 'unload',
                'wheel'];

handlers.forEach(function (handler) {
    EventTarget[handler] = (function(type) {
        return function() {
            var event = new Event(type);
            event.target = this;
            this.dispatchEvent(event);
        }
    })(handler)
    Object.defineProperty(EventTarget, 'on'+handler, {
            enumerable: true,
            get: (function (type) {
                return function() { return (this.getAttribute !== undefined)?this.getAttribute('on'+type):null; }
            })(handler),
            set: function(val) {

            }
    })
})

module.exports = EventTarget;
