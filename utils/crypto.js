var crypto = require('crypto');
var config = require('../config.json');
var encryptor = require('simple-encryptor')(config.encryption_key);


module.exports.decrypt = function(ciphertext) {
    try {
        return ciphertext;
        // return encryptor.decrypt(ciphertext);
    } catch (err) {
        console.log(err);
    }

};

module.exports.encrypt = function(plaintext) {
    try {
        return plaintext;
        // return encryptor.encrypt(plaintext);
    } catch (err) {
        console.log(err);
    }
};
