var util = require('util');
var NodeList = require('./NodeList.js');
var Event = require('./Event.js');
var CSSStyleDeclaration = require('./CSSStyleDeclaration.js');
var DOMTokenList = require('./DOMTokenList.js');

var noop = function() {
    console.log("ELEMENT NOOP")
}

var Element = {
    get accessKeyLabel() {
        return this.accessKey
    },
    get attributes() {
        var arr = this.attrs();
        var obj = { length: arr.length };
        var i = arr.length;
        while (i--) {
            var attr = arr[i];
            obj[attr.name()] = obj[i] = this.getAttributeNode(attr.name());
        }
        return obj;
    },
    blur: function() {
        this.doc().activeElement = this.doc().documentElement;
    },
    get classList() {
        return (this.getAttribute('class')||'').split(' ');
    },
    set classList(val) {
    },
    get className() {
        return this.getAttribute('class')||'';
    },
    set className(val) {
        this.setAttribute('class', val);
    },
    clientHeight: null,
    clientLeft: null,
    clientTop: null,
    clientWidth: null,
    closest: function(selector) {
        return this.querySelector('(ancestor::'+selector+'|preceding::'+selector+')[last()]')
    },
    checked: false,
    contentEditable: "inherit",
    isContentEditable: false,
    contextMenu: null,
    get contentWindow() {
        return this.doc().defaultView;
    },
    dataset: {

    },
    dir: "",
    draggable: false,
    focus: function() {
        this.doc().activeElement = this;
    },
    get form() {
        return this.querySelector('parent::form')||undefined;
    },
    get: function(selector) {
        var nodes = this.find(selector);
        if (!nodes || nodes.length === 0)
            return null;
        return nodes[0];
    },
    getAttribute: function(name) {
        if (this.attr === undefined)
            return null;
        var attr = this.attr(name);
        if (attr === null)
            return null;
        return attr.value();
    },
    getAttributeNS: function(namespace, attr, node) {
        var attr = this.getAttributeNode(attr);
        if (!attr) return null;
        if (!namespace) return node?attr:attr.value;
        var ns = attr.namespace();
        if (!ns) return null;
        if (namespace.href() !== this.namespaceURI)
            return null;
        return node?attr:attr.value;
    },
    getAttributeNode: function(name) {
        var attrs = this.attrs();
        if (!attr) return null;
        for (var i = 0; i < attrs.length; i++) {
            if (attrs[i].name() === name) {
                var attr = attrs[i];
                attr.name = name;
                attr.value = attr;
                return attr;
            }
        }
        return null;
    },
    getAttributeNodeNS: function(namespace, attr) {
        return this.getAttributeNS(namespace, attr, true)
    },
    getBoundingClientRect: function() {
        // The Element.getBoundingClientRect() method returns the size of an element and its position relative to the viewport.;
        return {
            x: 0,
            y: 0,
            width: 0,
            height: 0,
            top: 0,
            right: 0,
            bottom: 0,
            left: 0,
        }
    },
    getClientRects: function() {
        return [this.getBoundingClientRect()]
    },
    getElementsByClassName: function(name) {
        return this.querySelectorAll('.'+name);
    },
    getElementsByTagName: function(name) {
        return this.querySelectorAll(name);
    },
    getElementsByTagNameNS: function(namespaceURI, name) {
        return this.find('.//'+name, namespaceURI)||[];
    },
    hasAttribute: function(name) {
        return this.attr(name)!==null;
    },
    hasAttributeNS: function(namespaceURI, name) {
        if (!this.hasAttribute(name))
            return false;
        return this.attr(name).namespace().href() == namespaceURI;
    },
    hasAttributes: function() {
        if (this.nodeType === Node.DOCUMENT_NODE)
            return false;
        return this.attrs().length !== 0;
    },
    hidden: false,
    get id() {
        return this.getAttribute('id');
    },
    get innerHTML() {
        if (this.documentElement === undefined) {
            var src = this.toString(false);
            return src.substring((src.indexOf(">")||-1)+1, src.lastIndexOf("<")||src.length)
        }else
            return this.toString(false);
    },
    set innerHTML(str) {
        var self = this;
        var doc = this.doc().parse('<body>'+str+'</body>').root()
        if (doc === null) {
            self.text(str);
            return;
        }
        var body = doc.get('body');
        if (body !== null)
            doc = body;
        self.childNodes.forEach(function(child) {
            child.remove();
        })
        self.text("");
        doc.childNodes.forEach(function(child) {
            self.appendChild(child);
        })
    },
    insertAdjacentHTML: function(position, text) {
        return;
        var html = this.doc.parse('<body>'+str+'</bod>').root();
        if (html === null)
            return;
        var body = doc.get('body');
        var next = true;
        var node = this;
        switch (position) {
            case 'beforebegin':
                next = true;
                node = this.previousSibling;
                break;
            case 'afterbegin':
                next = false;
                node = this.firstChild;
                break;
            case 'beforeend':
                next = true;
                node = this.lastChild;
                break;
            case 'afterend':
                next = true;
                node = this;
                break;
        }
        body.childNodes.forEach(function(child) {
            if (next)
                node.addNextSibling(child)
            else
                node.addPrevSibling(child)
        })
    },
    isContentEditable: null,
    itemScope: false,
    itemId: "",
    get itemRef() {
        if (!this.__itemRef)
            this.__itemRef = new DOMTokenList;
        return this.__itemRef;
    },
    get itemType() {
        if (!this.__itemType)
            this.__itemType = new DOMTokenList;
        return this.__itemType;
    },
    get itemProp() {
        if (!this.__itemProp)
            this.__itemProp = new DOMTokenList;
        return this.__itemProp;
    },
    itemValue: null,
    get labels() {
        return this.querySelectorAll('label');
    },
    lang: null,
    get length() {
        if (typeof this.name !== 'function') {
            return;
        }
        
        var name = this.name();
        if (name === 'form')
            return this.querySelectorAll('input, select, textarea').length;
        else if (name === 'select')
            return this.querySelectorAll('option').length;
    },
    matches: function(selector) {
        return this.get('self::node()/'+selector) !== null;
    },
    get nextElementSibling() {
        return this.nextElement();
    },
    offsetHeight: null,
    offsetWidth: null,
    offsetLeft: null,
    offsetParent: null,
    offsetTop: null,
    get options() {
        return this.querySelectorAll('options');
    },
    get outerHTML() {
        return this.toString();
    },
    properties: {
        names: [],
        length: 0,
    },
    get previousElementSibling() {
        return this.previousElement();
    },
    querySelector: function(selector) {
        return this.get(this.css2xpath(selector))||null;
    },
    querySelectorAll: function(selector) {
        return NodeList(this.find(this.css2xpath(selector))||[]);
    },
    get rel() {
        return this.getAttribute('rel');
    },
    set rel(str) {
        this.relList.keys = str.split(' ');
    },
    get relList() {
        if (!this.__relList) {
            if (!this.hasAttribute('rel'))
                this.setAttribute('rel', '');
            this.__relList = new DOMTokenList(this.getAttribute('rel'));
        }

        return this.__relList;
    },
    set relList(val) {

    },
    removeAttribute: function(name) {
        var attr = this.getAttributeNode(name);
        if (attr !== null)
            return attr.remove();
    },
    removeAttributeNS: function(name) {
        this.removeAttribute(name);
    },
    removeAttributeNode: function(attr) {
        return attr.remove();
    },
    removeEventListener: function(ev, cb) {
        if (ev.indexOf('load')) cb();
    },
    removeAttributeNode: noop,
    scrollHeight: null,
    scrollLeft: null,
    scrollTop: null,
    scrollWidth: null,
    setAttribute: function(name, val) {
        //if (this.getAttributeNode(name) !== null)
        //    return this.getAttributeNode(name).value(val);
        var attr = {};
        attr[name] = val;
        this.attr(attr);
    },
    setAttributeNS: function(namespace, name, value) {
        this.setAttribute(name, value);
    },
    setAttributeNode: function(attr) {
        this.setAttribute(attr.name, attr.value);
    },
    setAttributeNodeNS: function(attr) {
        return this.setAttributeNode(attr);
    },
    spellcheck: false,
    get style() {
        if (!this.__styles)
            this.__styles = new CSSStyleDeclaration(this.getAttribute('style')||'');
        return this.__styles;
    },
    set style(str) {
        var arr = str.split(':');
        this.style.setProperty(arr[0], arr[1]);
    },
    tabIndex: -1,
    get tagName() {
        return (this.nodeName||'').toUpperCase();
    },
    get type() {
        if (this.nodeName === 'button') {
            // button, submit, reset, menu
            // default: submit
        }else{
            return this.getAttribute('type')||undefined;
        }
    },
    set type(value) {
        this.setAttribute('type', value);
    },
    validity: {
        valueMissing: false, typeMismatch: false, patternMismatch: false, tooLong: false,
        rangeUnderflow: false, rangeOverflow: false, stepMismatch: false, badInput: false, customError: false, valid: true },
    validationMessage: '',
}

var attributes = {
    'autofocus': {
        type: 'bool',
    },
    'accessKey': {
    },
    'charset': {},
    'coords': {
        types: ['a']
    },
    'disabled': {
        type: 'bool'
    },
    'formAction': {
        types: ['button']
    },
    'formEncType': {
        types: ['button']
    },
    'formMethod': {
        types: ['button']
    },
    'formNoValidate': {
        types: ['button']
    },
    'formTarget': {
        types: ['button']
    },
    'height': {},
    'href': {
        value:'',
    },
    'hreflang': {
        types: ['a']
    },
    'link': {},
    'media': {},
    'name': {},
    'shape': {},
    'src': {
        value:'',
    },
    'target': {},
    'title': {},
    'value': {},
    'width': {}
}

for (var name in attributes) {
    var attr = attributes[name];
    (function(name, value) {
        Object.defineProperty(Element, name, {
            enumerable: true,
            get: function() { return this.getAttribute(name)||value; },
            set: function(key) { this.setAttribute(name, key) }
        })
    })(name.toLowerCase(), attr.value)
}

module.exports = Element;
