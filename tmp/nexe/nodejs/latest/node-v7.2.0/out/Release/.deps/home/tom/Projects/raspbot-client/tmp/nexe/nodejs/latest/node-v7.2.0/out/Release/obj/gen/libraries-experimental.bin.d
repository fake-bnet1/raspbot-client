cmd_/home/tom/Projects/raspbot-client/tmp/nexe/nodejs/latest/node-v7.2.0/out/Release/obj/gen/libraries-experimental.bin := LD_LIBRARY_PATH=/home/tom/Projects/raspbot-client/tmp/nexe/nodejs/latest/node-v7.2.0/out/Release/lib.host:/home/tom/Projects/raspbot-client/tmp/nexe/nodejs/latest/node-v7.2.0/out/Release/lib.target:$$LD_LIBRARY_PATH; export LD_LIBRARY_PATH; cd ../deps/v8/src; mkdir -p /home/tom/Projects/raspbot-client/tmp/nexe/nodejs/latest/node-v7.2.0/out/Release/obj/gen; python ../tools/js2c.py "/home/tom/Projects/raspbot-client/tmp/nexe/nodejs/latest/node-v7.2.0/out/Release/obj/gen/experimental-libraries.cc" EXPERIMENTAL js/macros.py messages.h js/harmony-atomics.js js/harmony-simd.js js/harmony-string-padding.js js/harmony-async-await.js js/icu-case-mapping.js js/intl-extra.js --startup_blob "/home/tom/Projects/raspbot-client/tmp/nexe/nodejs/latest/node-v7.2.0/out/Release/obj/gen/libraries-experimental.bin" --nojs