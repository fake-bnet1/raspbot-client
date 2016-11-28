var config = require('../config.json');

module.exports = function(){
    const MIN_DELAY = config.reconnect_delay_min;
    const MAX_DELAY = config.reconnect_delay_max;

    const RECONNECT_DELAY_STEP = config.reconnect_delay_step_multiply;
    var currentDelay = MIN_DELAY;

    var get = function(){
        let oldCurrentDelay = currentDelay;

        let newCurrentDelay = currentDelay*RECONNECT_DELAY_STEP;

        if(newCurrentDelay >= MAX_DELAY){
            newCurrentDelay = MAX_DELAY;
        }

        currentDelay = newCurrentDelay;
        return oldCurrentDelay;
    };
    var reset = function(){
        currentDelay = MIN_DELAY;
    };

    return {
        reset: reset,
        get: get
    }
}();