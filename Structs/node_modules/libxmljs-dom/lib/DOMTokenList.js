'use strict';
function DOMTokenList(str) {
    if (str === undefined)
        this.keys = [];
    else
        this.keys = str.split(' ');
}

DOMTokenList.prototype = {
    add: function(key) {
        for (var i = 0; i < arguments.length; i++) {
            this.keys.push(arguments[i])
        }
    },
    contains: function(keys) {
        return this.keys.indexOf(key)!== -1;
    },
    item: function(index) {
        return this.keys[index];
    },
    get keys() {

    },
    set keys(val) {

    },
    get length() {
        return this.keys.length;
    },
    set length(val) {

    },
    remove: function() {
        for (var i = 0; i < arguments.length; i++) {
            this.keys.splice(this.keys.indexOf(arguments[i]), 1);
        }
    },
    toggle: function(key) {
        if (this.contains(key)) {
            this.remove(key);
            return false;
        }else{
            this.add(key);
            return true;
        }
    },
    value: function(key) {
        return this.keys.join(' ');
    }
}

module.exports = DOMTokenList;
