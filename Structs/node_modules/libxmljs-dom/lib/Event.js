var Event = function(type, eventInit) {
    var self = this;
    this.timeStamp = (new Date()).getTime();
    this.type = type;
    return this;
}

Event.prototype = {
    bubbles:            true,
    cancelable:         true,
    target:             null,
    currentTarget:      null,
    defaultPrevented:   false,
    eventPhase:         0,
    type:               null,
    isTrusted:          false,
    preventDefault:     function() {
        this.defaultPrevented = true;
    },
    stopImmediatePropagation: function() {

    },
    stopPropagation:    function() {

    }
}

var phases = {
    NONE: 0,
    CAPTURING_PHASE: 1,
    AT_TARGET: 2,
    BUBBLING_PHASE:	3
}

module.exports = Event;
