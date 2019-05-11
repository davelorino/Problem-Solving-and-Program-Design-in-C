'use strict';

var NodeList = require('./NodeList.js');

var Node = {
    appendChild: function (child) {
        if (this.nodeType === Node.DOCUMENT_NODE) {
            console.log("append to DOC");
            this.documentElement.addChild(child);
            return;
        }

        this.addChild(child);

        if (child.nodeName === 'script')
            this.doc().defaultView.__evalScripts();
        return child;
    },
    get baseURI() {
        return this.doc().baseURI;
    },
    get childElementCount() {
        return this.childNodes.length;
    },
    get childNodes() {
        if (this.nodeType === Node.DOCUMENT_NODE)
            return NodeList([this.documentElement]);
        return NodeList(this.__childNodes());
    },
    get children() {
        return this.childNodes;
    },
    cloneNode: function (recursive) {
        //console.log("CLONING", recursive==true, this.nodeName)
        return this.clone(recursive);
    },
    compareDocumentPosition: function (node) {
        var bitmask = 0;
        var h1 = this.path();
        var h2 = node.path();

        if (h1.length > h2.length) {
            bitmask += Node.DOCUMENT_POSITION_PRECEDING;

            if (h2.indexOf(h1) === 0) {
                bitmask += Node.DOCUMENT_POSITION_CONTAINS;
            }
        } else if (h2.length > h1.length) {
            bitmask += Node.DOCUMENT_POSITION_FOLLOWING;

            if (h1.indexOf(h2) === 0) {
                bitmask += Node.DOCUMENT_POSITION_CONTAINED_BY;
            }

        }

        return bitmask;
    },
    contains: function (node) {
        return node.path().indexOf(this.path()) === 0;
    },
    get firstChild() {
        return this.childNodes[0] || null;
    },
    get firstElementChild() {
        return this.firstChild;
    },
    // getFeature()
    getUserData: function (key) {
        if (this.__userData === undefined)
            return;
        return this.__userData[key];
    },
    hasAttributes: function () {
        if (this.nodeType === Node.DOCUMENT_NODE)
            return false;
        return this.attrs().length !== 0;
    },
    hasChildNodes: function () {
        return this.childNodes.length !== 0;
    },
    // TODO: innerText != textContent
    get innerText() {
        return this.text();
    },
    insertBefore: function (node, sibling) {
        if (node.nodeName === 'script') {
            var window = this.doc().defaultView;

            process.nextTick(function () {
                window.__evalScripts();
            });
        }

        if (!sibling) {
            if (this.lastChild !== null)
                return this.lastChild.addNextSibling(node);
            return null;
        }

        return sibling.addPrevSibling(node);
    },
    isDefaultNamespace: function () {
        return true;
    },
    isEqualNode: function (node) {
        return this.toString() === node.toString();
    },
    isSameNode: function (node) {
        return this.path() === node.path();
    },
    isSupported: function () {
        return true;
    },
    get lastElementChild() {
        return this.lastChild;
    },
    get lastChild() {
        return this.childNodes[this.childNodes.length - 1] || null;
    },
    get localName() {
        return this.nodeName;
    },
    lookupNamespaceURI: function () {
        return null;
    },
    lookupPrefix: function () {
        return null;
    },
    namespaceURI: null,
    get nextSibling() {
        return this.__nextSibling();
    },
    get nodeName() {
        if (this.nodeType === Node.DOCUMENT_NODE)
            return '#document';
        return this.__name();
    },
    set nodeName(val) {
        this.__name(val);
    },
    nodePrincipal: undefined,
    get nodeType() {
        if (this.documentElement !== undefined)
            return Node.DOCUMENT_NODE;

        if (this.__name() === '#document-fragment')
            return Node.DOCUMENT_FRAGMENT_NODE;
        /*if (Object.getOwnPropertyDescriptor(this, 'type').get === undefined) {
            switch (this.type()) {
                case 'attribute':
                    return Node.ATTRIBUTE_NODE;
                case 'text':
                    return Node.TEXT_NODE;
                case 'comment':
                    return Node.COMMENT_NODE;
            }
        }*/
        return Node.ELEMENT_NODE;
    },
    get nodeValue() {
        // TODO: return text for Node.TEXT_NODE and Node.COMMENT_NODE
        return null;
    },
    normalize: function () {
        // TODO: remove empty text nodes and join adjacent text nodes
    },
    get ownerDocument() {
        return this.doc();
    },
    get parentElement() {
        if (this.nodeType === Node.DOCUMENT_FRAGMENT_NODE)
            return null;

        if (this.parent === undefined)
            return null;

        if (this.parent().nodeType === Node.DOCUMENT_NODE)
            return null;
        return this.parent();
    },
    get parentNode() {
        if (this.nodeType === Node.DOCUMENT_NODE)
            return null;

        if (this.nodeType === Node.DOCUMENT_FRAGMENT_NODE)
            return null;

        if (this.parent === undefined)
            return null;
        return this.parent();
    },
    prefix: null,
    get previousSibling() {
        return this.prevSibling();
    },
    removeChild: function (child) {
        //console.log("REMOVE", child.nodeName);
        return child.remove();
    },
    replaceChild: function (newChild, oldChild) {
        //console.log("REPLACE", oldChild.nodeName, "with", newChild.nodeName);
        return oldChild.replace(newChild);
    },
    setUserData: function (key, value) {
        // TODO: handler callback on Node clone, import, rename, delete or adopt
        if (!this.__userData)
            this.__userData = {};
        this.__userData[key] = value;
    },
    get textContent() {
        return this.text();
    },
    set textContent(value) {
        this.text(value);
    },
    DOCUMENT_POSITION_DISCONNECTED: 	1,
    DOCUMENT_POSITION_PRECEDING: 	2,
    DOCUMENT_POSITION_FOLLOWING: 	4,
    DOCUMENT_POSITION_CONTAINS: 	8,
    DOCUMENT_POSITION_CONTAINED_BY: 	16,
    DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC: 	32,
    ELEMENT_NODE:      1,
    ATTRIBUTE_NODE:    2,
    TEXT_NODE:         3,
    CDATA_SECTION_NODE: 4,
    ENTITY_REFERENCE_NODE: 5,
    ENTITY_NODE:    6,
    PROCESSING_INSTRUCTION_NODE:	7,
    COMMENT_NODE:	8,
    DOCUMENT_NODE:	9,
    DOCUMENT_TYPE_NODE:	10,
    DOCUMENT_FRAGMENT_NODE:	11,
    NOTATION_NODE: 12
};

module.exports = Node;
