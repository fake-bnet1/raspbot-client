var parser = require('../utils/parser');
var Packet = require('../models/packet');
var crypto = require('../utils/crypto');

module.exports = function() {
    return (function(baseSocket) {
        console.log("baseSocket: " + baseSocket);
        var send = function(data) {
            // var chunkedPackets = chunk(data);
            // chunkedPackets.forEach(function(chunk) {
            let parsedPacket = parser.encode(data);
            let encrypted = crypto.encrypt(parsedPacket);
            console.log(`raw Packet: ${data}`);
            console.log(`parsed Packet: ${parsedPacket}`);
            baseSocket.emit('data', encrypted);
            // });
        };

        // var chunk = function chunk(packet) {
        //     var data = packet.data;
        //     var packetarray = [];
        //
        //     if (typeof(data.output) !== 'undefined') {
        //         console.log('raw output: ' + new Buffer(data.output, 'base64'.toString('utf8')));
        //         var chunks = new Buffer(data.output, 'base64').toString('utf8').split("\\n");
        //         chunks.forEach(function(piece) {
        //             console.log('PIECE: ' + piece);
        //             packetarray.push(new Packet(packet.sender_id, packet.receiver_id, {
        //                 output: new Buffer(piece).toString('base64'),
        //                 name: data.name
        //             }));
        //         });
        //         packetarray.push(chunks);
        //     } else {
        //         packetarray.push(packet);
        //     }
        //     return packetarray;
        // }

        return {
            send: send
        }
    });

}();
