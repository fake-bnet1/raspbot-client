module.exports = function() {
    return (function(baseSocket) {
        var CommandProcessor = require('./commandProcessor')(baseSocket);
        var self = this;
        var sender_id;
        var receiver_id;

        var processCommand = function(cmd, cmdData) {
            CommandProcessor.processCommand(cmd, cmdData, self.sender_id, self.receiver_id);
        }

        var processPacket = function(packet, sender_id, receiver_id) {
            self.sender_id = sender_id;
            self.receiver_id = receiver_id;
            for (let cmd in packet.data) {
                processCommand(cmd, packet.data[cmd], packet);
            }
        };

        var execute = function(packet) {
            var commands = [];
            var promises = [];

            for (var commandName in packet.data) {
                commands.push(commandName);
            }

            require('fs').readdirSync(normalizedPath).forEach((file) => {
                let command = commands.indexOf(file);
                if (command >= 0) {
                    let module = require(`${normalizedPath}${file}`)(packet.data[command]);
                    promises.push(module.execute(packet.data));
                }
            });
            return Promise.all(promises);
        };

        return {
            execute: execute,
            processCommand: processCommand,
            processPacket: processPacket
        }
    });
}();
