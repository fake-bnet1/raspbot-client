//var net = require('net');
var io = require('socket.io-client');
var config = require('./config.json');
var socket = io.connect(`http://${config.host}:${config.port}`, {
    reconnect: true
});
var crypto = require('./utils/crypto');
var delay = require('./utils/delay');
var parser = require('./utils/parser');
var logger = require('./utils/logger');

var Processor;
var sender_id;
var receiver_id;
var hostname;
var baseSocket;
var socketOpen = false;


function openSocket() {
    try {
        // baseSocket = net.connect({
        //     port: config.port,
        //     host: config.host
        // });


        socket.on('connect', function() {
            console.log('Connected!');
            baseSocket = socket;
            Processor = require('./processor/processor')(socket);
            socketOpen = true;
        });

        socket.on('data', function(data) {
            console.log(data);
            onData(data);
        });

        // baseSocket.setKeepAlive(true);
        // baseSocket.setEncoding(config.default_encoding);
        // baseSocket.on('connect', onConnect.bind({}, baseSocket));
        // baseSocket.on('error', destroySocket.bind({}, baseSocket));
        // baseSocket.on('data', onData.bind({}, baseSocket));
        // baseSocket.on('close', destroySocket.bind({}, baseSocket));
        console.log(`Processor: ${Processor}`);

        socketOpen = true;
    } catch (err) {
        console.log(`error: ${err}`);
    }
}
var onConnect = function() {
    console.log('-> SERVER : Succesfully connected');
};

var onData = function(data) {
    console.log("Got DATA");
    console.log("Got DATA: " + JSON.stringify(packet));
    var decrypted = crypto.decrypt(data);

    if (!parser.isValid(decrypted)) {
        return;
    }
    var packet = parser.decode(decrypted);

    receiver_id = packet.sender_id;
    sender_id = packet.receiver_id;
    console.log(`Processor: ${Processor}`);
    Processor.processPacket(packet, sender_id, receiver_id);
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

openSocket();
