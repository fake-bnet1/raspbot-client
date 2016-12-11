var parser = require('../utils/parser');
var Packet = require('../models/packet');

module.exports = function() {
    return (function(baseSocket) {
        var send = function(data) {
            var chunkedPackets = chunk(data);

            chunkedPackets.forEach(function(chunk) {
                let parsedPacket = parser.encode(chunk);
                console.log(`raw Packet: ${chunk}`);
                console.log(`parsed Packet: ${parsedPacket}`);
                baseSocket.write(parsedPacket);

            });
        };


        var chunk = function chunk(packet) {
            var data = packet.data;
            var packetarray = [];

            if (typeof(data.output) !== 'undefined') {
                var chunks = new Buffer(data.output, 'base64').toString('utf8').split('\\n');
                chunks.forEach(function(piece) {
                    packetarray.push(new Packet(packet.sender_id, packet.receiver_id, {
                        output: new Buffer(piece).toString('base64'),
                        name: data.name
                    }));
                });
            } else {
                packetarray.push(packet);
            }
            return packetarray;
        }

        return {
            send: send
        }
    });

}();
