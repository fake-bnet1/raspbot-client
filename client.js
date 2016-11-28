var net = require('net');
var crypto = require('./utils/crypto');
var delay = require('./utils/delay');
var config = require('./config.json');
var parser = require('./utils/parser');
var logger = require('./utils/logger');


var baseSocket;
var socketOpen = false;
function openSocket() {
    if(!socketOpen){
        baseSocket = net.connect({port: config.port, host: config.host});
        baseSocket.setKeepAlive(true);
        baseSocket.setEncoding(config.default_encoding);
        baseSocket.on('connect', onConnect.bind({}, baseSocket));
        baseSocket.on('error', destroySocket.bind({}, baseSocket));
        baseSocket.on('data', onData.bind({}, baseSocket));
        baseSocket.on('close', destroySocket.bind({}, baseSocket));
        socketOpen = true;
    }

}
var onConnect = function () {
    console.log('-> SERVER : Succesfully connected');
};

var onData = function (socket, cipher) {
    var data = crypto.decrypt(cipher);
    if (!parser.isValid(data)) {
        return;
    }
    var packet = parser.decode(data);
    console.log(`-> ${packet.sender_id} : Received packet`);
};
var send = function (data) {
    crypto.encrypt(data);
    baseSocket.write(data);
};
var destroySocket = function () {
    // Kill socket
    if (socketOpen) {
        console.log('Killing socket');
        baseSocket.end();
        baseSocket.destroy();
        baseSocket.unref();
        socketOpen = false;
    }


    // Re-open socket
    var timeout = setTimeout(openSocket,delay.get());
};

var processPacket = function (packet) {
    var parsedPacket = parser.decode(packet);
    for (let cmd in parsedPacket.data) {
        processCommand(cmd, parsedPacket.data[cmd], packet);
    }
};
var processCommand = function (cmd, cdmData, packet) {
    if (cmd === 'ack') {
        send('hello world');
    }
};


openSocket();