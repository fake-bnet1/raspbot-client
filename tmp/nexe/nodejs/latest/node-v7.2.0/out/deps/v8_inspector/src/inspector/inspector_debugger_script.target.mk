# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := inspector_debugger_script
### Rules for action "convert_js_to_cpp_char_array":
quiet_cmd__home_tom_Repositories_raspbot_client_tmp_nexe_nodejs_latest_node_v7_2_0_deps_v8_inspector_src_inspector_inspector_gyp_inspector_debugger_script_target_convert_js_to_cpp_char_array = ACTION _home_tom_Repositories_raspbot_client_tmp_nexe_nodejs_latest_node_v7_2_0_deps_v8_inspector_src_inspector_inspector_gyp_inspector_debugger_script_target_convert_js_to_cpp_char_array $@
cmd__home_tom_Repositories_raspbot_client_tmp_nexe_nodejs_latest_node_v7_2_0_deps_v8_inspector_src_inspector_inspector_gyp_inspector_debugger_script_target_convert_js_to_cpp_char_array = LD_LIBRARY_PATH=$(builddir)/lib.host:$(builddir)/lib.target:$$LD_LIBRARY_PATH; export LD_LIBRARY_PATH; cd $(srcdir)/deps/v8_inspector/src/inspector; mkdir -p $(obj)/gen/src/inspector; python build/xxd.py DebuggerScript_js debugger-script.js "$(obj)/gen/src/inspector/debugger-script.h"

$(obj)/gen/src/inspector/debugger-script.h: obj := $(abs_obj)
$(obj)/gen/src/inspector/debugger-script.h: builddir := $(abs_builddir)
$(obj)/gen/src/inspector/debugger-script.h: TOOLSET := $(TOOLSET)
$(obj)/gen/src/inspector/debugger-script.h: $(srcdir)/deps/v8_inspector/src/inspector/build/xxd.py $(srcdir)/deps/v8_inspector/src/inspector/debugger-script.js FORCE_DO_CMD
	$(call do_cmd,_home_tom_Repositories_raspbot_client_tmp_nexe_nodejs_latest_node_v7_2_0_deps_v8_inspector_src_inspector_inspector_gyp_inspector_debugger_script_target_convert_js_to_cpp_char_array)

all_deps += $(obj)/gen/src/inspector/debugger-script.h
action__home_tom_Repositories_raspbot_client_tmp_nexe_nodejs_latest_node_v7_2_0_deps_v8_inspector_src_inspector_inspector_gyp_inspector_debugger_script_target_convert_js_to_cpp_char_array_outputs := $(obj)/gen/src/inspector/debugger-script.h


### Rules for final target.
# Build our special outputs first.
$(obj).target/deps/v8_inspector/src/inspector/inspector_debugger_script.stamp: | $(action__home_tom_Repositories_raspbot_client_tmp_nexe_nodejs_latest_node_v7_2_0_deps_v8_inspector_src_inspector_inspector_gyp_inspector_debugger_script_target_convert_js_to_cpp_char_array_outputs)

# Preserve order dependency of special output on deps.
$(action__home_tom_Repositories_raspbot_client_tmp_nexe_nodejs_latest_node_v7_2_0_deps_v8_inspector_src_inspector_inspector_gyp_inspector_debugger_script_target_convert_js_to_cpp_char_array_outputs): | 

$(obj).target/deps/v8_inspector/src/inspector/inspector_debugger_script.stamp: TOOLSET := $(TOOLSET)
$(obj).target/deps/v8_inspector/src/inspector/inspector_debugger_script.stamp:  FORCE_DO_CMD
	$(call do_cmd,touch)

all_deps += $(obj).target/deps/v8_inspector/src/inspector/inspector_debugger_script.stamp
# Add target alias
.PHONY: inspector_debugger_script
inspector_debugger_script: $(obj).target/deps/v8_inspector/src/inspector/inspector_debugger_script.stamp

# Add target alias to "all" target.
.PHONY: all
all: inspector_debugger_script

