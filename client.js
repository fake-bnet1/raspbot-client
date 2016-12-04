var net = require('net');
var crypto = require('./utils/crypto');
var delay = require('./utils/delay');
var config = require('./config.json');
var parser = require('./utils/parser');
var logger = require('./utils/logger');
var Packet = require('./models/packet')

var sender_id;
var reciever_id;
var baseSocket;
var socketOpen = false;

function openSocket() {
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

}
var onConnect = function() {
    console.log('-> SERVER : Succesfully connected');
};

var onData = function(socket, cipher) {
    var data = crypto.decrypt(cipher);
    if (!parser.isValid(data)) {
        return;
    }
    var packet = parser.decode(data);
    processPacket(packet);
    console.log(`-> ${packet.sender_id} : Received packet`);
    reciever_id = packet.sender_id;
    sender_id = packet.reciever_id;

};
var send = function(data) {
    let parsedPacket = parser.encode(data);
    console.log(`raw Packet: ${data}`);
    console.log(`parsed Packet: ${parsedPacket}`);
    let encryptedPacket = crypto.encrypt(parsedPacket);
    baseSocket.write(encryptedPacket);
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
var processCommand = function(cmd, cdmData) {
    if (cmd === 'ack') {
        var toSend = new Packet(sender_id, reciever_id, {
            output: "I Succesfully recieved the id's"
        });
        send(toSend);
    }
};


openSocket();
