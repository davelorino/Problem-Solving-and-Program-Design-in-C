'use strict';

var Element = require('./Element.js'),
    Location = require('./Location.js'),
    noop = function (name) {
        return function () {
            console.log("DOCUMENT NOOP", name, JSON.stringify(arguments));
        };
    },

    libxmljs,
    Document = {
    get activeElement() {
        return this.__activeElement || this.body;
    },
    set activeElement(el) {
        return this.__activeElement = el;
    },
    adoptNode: noop,
    alinkColor: '',
    get all() {
        return this.querySelectorAll('[id]');
    },
    get anchors() {
        return this.getElementsByTagName('a');
    },
    get applets() {
        return this.getElementsByTagName('applet');
    },
    get baseURI() {
        return this.URL;
    },
    bgColor: '',
    get body() {
        return this.getElementsByTagName('body')[0];
    },
    charset: 'UTF-8',
    characterSet: 'UTF-8',
    childElementCount: 1,
    get childNodes() {
        return this.documentElement.childNodes;
    },
    get children() {
        return this.documentElement;
    },
    close: function () {
        return this;
    },
    compatMode: 'CSS1Compat',
    contentType: 'text/html',
    get cookie() {
        var i = 0, str = '', keys;

        if (this.cookies === undefined) {
            return '';
        }

        keys = Object.keys(this.cookies);

        for (; i < keys.length; i++) {
            str += keys[i] + ':' + this.cookies[keys[i]];

            if (i !== keys.length - 1) {
                str += '; ';
            }
        }

        return str;
    },
    set cookie(value) {
        var key, arr, length, cookie;

        if (this.cookies === undefined) {
            this.cookies = {};
        }

        if (typeof value === 'object') {
            for (key in value) {
                this.cookies[key] = value[key];
            }

            return;
        }

        arr = value.split('; ');
        length = arr.length;

        while (length--) {
            cookie = arr[length].split(':');
            this.cookies[cookie[0]] = cookie[1];
        }
    },
    currentScript: null,
    createAttribute: function (name) {
        //console.log('create attribute:', name);
        var el = this.createElement('attrElement');

        el.setAttribute(name, '');
        return el.getAttributeNode(name);
    },
    createComment: function (text) {
        //console.log('create comment:', text)
        return new libxmljs.Comment(this, text);
    },
    createDocument: function () {
        //console.log('create document')
        return new libxmljs.Document;
    },
    createDocumentFragment: function () {
        //console.log('create document fragment')
        var frag = this.createElement('#document-fragment');
        //Object.defineProperty
        return frag;
    },
    createElement: function (name) {
        //console.log('create element:', name)
        var child = new libxmljs.Element(this, name);

        return child;
    },
    createTextNode: function (text) {
        //console.log("create text:", text)
        return new libxmljs.Text(this, String(text));
    },
    get defaultView() {
        if (this.__window === undefined)
            this.__window = new libxmljs.Window(this);
        return this.__window;
    },
    set defaultView(window) {
        this.__window = window;
    },
    designMode: 'off',
    dir: 'ltr',
    doctype: {

    },
    get documentElement() {
        return this.root() || null;
    },
    get documentURI() {
        return this.URL;
    },
    get domain() {
        return this.location.hostname;
    },
    get embeds() {
        return this.getElementsByTagName('embeds');
    },
    evaluate: function () {

    },
    fgColor: '',
    fonts: {

    },
    get forms() {
        return this.getElementsByTagName('form');
    },
    getElementById: function (id) {
        return this.querySelector('#' + id);
    },
    getElementsByClassName: function (name) {
        return this.documentElement.getElementsByClassName(name);
    },
    getElementsByName: function (name) {
        return this.documentElement.querySelectorAll('[name="' + name + '"]');
    },
    getElementsByTagName: function (name) {
        return this.documentElement.getElementsByTagName(name);
    },
    getElementsByTagNameNS: function (namespace, name) {
        return this.documentElement.getElementsByTagNameNS(name);
    },
    hasFocus: function () {
        return true;
    },
    get head() {
        return this.getElementsByTagName('head')[0];
    },
    hidden: false,
    get images() {
        return this.getElementsByTagName('img');
    },
    get implementation() {
        var self = this;

        return {
            hasFeature: function (name, version) {
                console.log("checking for feature", name, version);
                return true;
            },
            createHTMLDocument: function (title) {
                var document = self.createDocument(),
                    iframe = self.createElement('iframe');

                var root = document.createElement('html');

                root.appendChild(document.createElement('body'));

                document.root(root);

                self.documentElement.appendChild(iframe);

                return document;
            }
        }
    },
    importNode: noop,
    inputEncoding: 'UTF-8',
    get lastModified() {
        return this.defaultView.request.headers['last-modified'];
    },
    lastStyleSheet: null,
    linkColor: '',
    get links() {
        return this.querySelector('a[href]');
    },
    localName: null,
    get location() {
        if (this.__location === undefined)
            this.__location = new Location('http://localhost', this);
        return this.__location;
    },
    set location(val) {
        this.__location = new Location(val, this);

        if (this.documentElement !== null) {
            this.documentElement.setAttribute('url', this.__location.href);
        }
    },
    namespaceURI: null,
    open: function () {
        return this;
    },
    parse: function (str) {
        return libxmljs.parseHtml(str); // parseHtmlFragment when available
    },
    plugins: {},
    prefix: null,
    get querySelector() {
        return this.documentElement.querySelector;
    },
    get querySelectorAll() {
        return this.documentElement.querySelectorAll;
    },
    readyState: "loading",
    /*
    __readyState: "loading",
    get readyState() {
                console.log("GET READY STATE:", this.__readyState, this.querySelectorAll('script:not([@ran])').length);
        return this.__readyState;
    },
    set readyState(val) {
        if (val === this.__readyState) return;
        this.__readyState = val;
        console.log("READY STATE CHANGE", val)
        this.dispatchEvent('readystatechange');
    },*/
    get referrer() {
        return this.request.headers.referer;
    },
    renameNode: function () {

    },
    get scripts() {
        return this.getElementsByTagName('script');
    },
    title: function (str) {
        if (!str) {
            return this.querySelector('title').innerHTML;
        } else {

        }
    },
    visibilityState: 'visible',
    vlinkColor: '',
    write: function (data) {
        var script = this.currentScript;
        var b = libxmljs.parseHtml('<body>' + data + '</body>').get('body');

        if (!b) return;
        var children = b.childNodes;
        var i   = children.length;

        while (i--) {
            script.addNextSibling(children[i]);
        }
    },
    get URL() {
        return this.location.toString();
    }
};

module.exports = function (libxml) {
    libxmljs = libxml;
    return Document;
};
