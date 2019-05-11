'use strict';

var libxmljs    = require('libxmljs'),
    css2xpath   = require('css2xpath'),
    EventTarget = require('./lib/EventTarget.js'),
    Window      = require('./lib/Window.js')(libxmljs),
    XMLDocument = libxmljs.Document.prototype,
    XMLElement  = libxmljs.Element.prototype;

libxmljs.log = console.log;
libxmljs.error = console.error || console.log;

libxmljs.css2xpath = css2xpath;

extend(Window.prototype, EventTarget);
libxmljs.Window = Window;


XMLDocument.css2xpath   = libxmljs.css2xpath;
XMLDocument.doc = function () {
    return this;
};

XMLElement.css2xpath     = libxmljs.css2xpath;
XMLElement.__childNodes  = XMLElement.childNodes;
XMLElement.__nextSibling = XMLElement.nextSibling;
XMLElement.__name        = XMLElement.name;
XMLElement.__type        = XMLElement.type;
delete XMLElement.childNodes;

var Node = require('./lib/Node.js');
var Element = extend(require('./lib/Element.js'), Node, true);

extend(XMLElement, Element, true);
extend(XMLElement, EventTarget);

var Document = extend(require('./lib/Document.js')(libxmljs), Node, true);

extend(XMLDocument, Document, true);
extend(XMLDocument, EventTarget);

function extend(parent, child, replace) {
    for (var key in child) {
        if (parent.hasOwnProperty(key) && replace !== true) continue;
        var desc = Object.getOwnPropertyDescriptor(child, key);

        if (desc.value !== undefined) {
            parent[key] = child[key];
        } else {
            Object.defineProperty(parent, key, { get: desc.get, set: desc.set, enumerable: true, configurable: true });
        }
    }

    return parent;
}

var readFileSync = require('fs').readFileSync;
var jQueryFile = __dirname + '/lib/jquery.js';
var jQuery = null;

Object.defineProperty(libxmljs, 'jQuery', {
    get: function () {
        if (jQuery === null)
            jQuery = readFileSync(jQueryFile).toString();
        return jQuery;
    },
    set: function () {

    }
});

module.exports = libxmljs;
