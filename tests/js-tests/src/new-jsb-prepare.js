"use strict"

function __defineProperty(proto, name, getter, setter) {
    log("__defineProperty, name: " + name);
    var desc = {
        enumerable: true,
        configurable: true
    };
    getter && (desc.get = getter);
    setter && (desc.set = setter);
    Object.defineProperty(proto, name, desc);
}