'use strict';
var CSSStyleDeclaration = function(str) {
    this.keys = [];
    this.vals = [];
}

CSSStyleDeclaration.prototype = {
    get cssText() {
        var str = '',
            length = this.keys.length;
        for (var i = 0; i < length; i++) {
            str += this.keys[i]+':'+this.vals[i];
        }
        return str;
    },
    set cssText(str) {
        this.items = [];
        var arr = str.split(';'),
            length = arr.length;
        for (var i = 0; i < length; i++) {
            var s = arr[i].split(':');
            if (s[0].length === 0) continue;
            this.keys.push(s[0]);
            this.vals.push(s[1]);
        }
    },
    parentRule: null,
    getPropertyPriority: function() {
        return '';
    },
    getPropertyValue: function(key) {
        return this.vals[this.keys.indexOf(key)];
    },
    item: function(i) {
        return this.keys[i];
    },
    get length() {
        return this.keys.length;
    },
    removeProperty: function(key) {
        var index = this.keys.indexOf(key);
        this.keys.splice(index, 1);
        this.vals.splice(index, 1);
    },
    setProperty: function(key, value, important) {
        var index = this.keys.indexOf(key);
        if (index !== -1) {
            this.vals[index] = value;
        }else{
            this.keys.push(key);
            this.vals.push(val);
        }
    },
    getPropertyCSSValue: function() {

    }
}


var CSSProperties = {
    'background': 'background',
    'background-attachment': 'backgroundAttachment',
    'background-color': 'backgroundColor',
    'background-image': 'backgroundImage',
    'background-position': 'backgroundPosition',
    'background-repeat': 'backgroundRepeat',
    'border': 'border',
    'border-bottom': 'borderBottom',
    'border-bottom-color': 'borderBottomColor',
    'border-bottom-style': 'borderBottomStyle',
    'border-bottom-width': 'borderBottomWidth',
    'border-color': 'borderColor',
    'border-left': 'borderLeft',
    'border-left-color': 'borderLeftColor',
    'border-left-style': 'borderLeftStyle',
    'border-left-width': 'borderLeftWidth',
    'border-right': 'borderRight',
    'border-right-color': 'borderRightColor',
    'border-right-style': 'borderRightStyle',
    'border-right-width': 'borderRightWidth',
    'border-style': 'borderStyle',
    'border-top': 'borderTop',
    'border-top-color': 'borderTopColor',
    'border-top-style': 'borderTopStyle',
    'border-top-width': 'borderTopWidth',
    'border-width': 'borderWidth',
    'clear': 'clear',
    'clip': 'clip',
    'color': 'color',
    'cursor': 'cursor',
    'display': 'display',
    'filter': 'filter',
    'font': 'font',
    'font-family': 'fontFamily',
    'font-size': 'fontSize',
    'font-variant': 'fontVariant',
    'font-weight': 'fontWeight',
    'height': 'height',
    'left': 'left',
    'letter-spacing': 'letterSpacing',
    'line-height': 'lineHeight',
    'list-style': 'listStyle',
    'list-style-image': 'listStyleImage',
    'list-style-position': 'listStylePosition',
    'list-style-type': 'listStyleType',
    'margin': 'margin',
    'margin-bottom': 'marginBottom',
    'margin-left': 'marginLeft',
    'margin-right': 'marginRight',
    'margin-top': 'marginTop',
    'overflow': 'overflow',
    'padding': 'padding',
    'padding-bottom': 'paddingBottom',
    'padding-left': 'paddingLeft',
    'padding-right': 'paddingRight',
    'padding-top': 'paddingTop',
    'page-break-after': 'pageBreakAfter',
    'page-break-before': 'pageBreakBefore',
    'position': 'position',
    'float': 'cssFloat',
    'text-align': 'textAlign',
    'text-decoration': 'textDecoration',
    'text-decoration: blink': 'textDecorationBlink',
    'text-decoration: line-through': 'textDecorationLineThrough',
    'text-decoration: none': 'textDecorationNone',
    'text-decoration: overline': 'textDecorationOverline',
    'text-decoration: underline': 'textDecorationUnderline',
    'text-indent': 'textIndent',
    'text-transform': 'textTransform',
    'top': 'top',
    'vertical-align': 'verticalAlign',
    'visibility': 'visibility',
    'width': 'width',
    'z-index': 'zIndex',
}

for (var prop in CSSProperties) {
    (function(prop, attr) {
        Object.defineProperty(CSSStyleDeclaration.prototype, attr, {
            get: function() {
                var index = this.keys.indexOf(prop);
                if (index === -1) return null;
                return this.vals[index];
            },
            set: function(val) {
                return this.vals[prop] = val;
            }
        })
    })(prop, CSSProperties[prop]);
}

module.exports = CSSStyleDeclaration;
