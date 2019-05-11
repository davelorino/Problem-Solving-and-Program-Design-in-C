'use strict';
var NodeList = function(array) {
    if (array.item === undefined)
        array.item = item;
    return array;
}

function item(i) {
    return this[i];
}

module.exports = NodeList;
