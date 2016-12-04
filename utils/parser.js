"use strict";
var Packet = require('../models/packet');


module.exports.isValid = function(packet) {
    try {
        Packet.fromJSON(JSON.parse(packet));
        return true;
    } catch (e) {
        return false;
    }
};

module.exports.decode = function(packet) {
    let temp = Packet.fromJSON(JSON.parse(packet));
    // temp.data = new Buffer(packet.data, 'base64').toString('utf8');
    return temp;
};

module.exports.encode = function(packet) {
    // packet.data = new Buffer(packet.data).toString('base64');
    return JSON.stringify(packet);
};
