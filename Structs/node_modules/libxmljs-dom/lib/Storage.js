'use strict';
var Storage = function() {
    this.items = [];
    return this;
}

Storage.prototype = {
    get length() {
        return items.length;
    },
    clear: function() {
        this.items = [];
    },
    key: function(i) {
        return this[i];
    },
    getItem: function(key) {
        return this.items[this[key]]||null;
    },
    setItem: function(key, val) {
        if (this[key] === undefined) {
            this[key] = this.items.push(val)-1;
        }
        this.items[this[key]] = val;
    },
    removeItem: function(key) {
        this.items[this[key]] = undefined;
        this[key] = undefined;
    }
}

module.exports = Storage;
