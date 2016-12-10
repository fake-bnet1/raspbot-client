var parser = require('../utils/parser');

module.exports = function() {
    return (function(baseSocket) {
        var send = function(data) {
            let parsedPacket = parser.encode(data);
            console.log(`raw Packet: ${data}`);
            console.log(`parsed Packet: ${parsedPacket}`);
            
            baseSocket.write(parsedPacket);
        };
        return {
            send: send
        }
    });

}();
