module.exports = function() {
    var Packet = require('../../models/packet');
    var os = require('os');
    var hostname = os.hostname();
    var toSend;

    var handleAckResponse = function handleAckResponse(sender_id, receiver_id, send) {
        toSend = new Packet(sender_id, receiver_id, {
            name: hostname
        });
        send(toSend);
    }

    return {
        handleAckResponse: handleAckResponse
    }
}();
