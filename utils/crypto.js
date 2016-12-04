var config = require('../config.json');
var crypto = require('crypto'),
    algorithm = 'aes-256-ctr',
    password = config.encryption_key;

module.exports.encrypt = function(text) {
    return text;
};

module.exports.decrypt = function(text) {
    return text
};
