
/*
 * This file is generated by ../tools/gen-postmortem-metadata.py.  Do not edit directly.
 */

#include "src/v8.h"
#include "src/frames.h"
#include "src/frames-inl.h" /* for architecture-specific frame constants */
#include "src/contexts.h"

using namespace v8::internal;

extern "C" {

/* stack frame constants */
#define FRAME_CONST(value, klass)           int v8dbg_frametype_##klass = StackFrame::value;

STACK_FRAME_TYPE_LIST(FRAME_CONST)

#undef FRAME_CONST

/* miscellaneous constants */
int v8dbg_FirstNonstringType = FIRST_NONSTRING_TYPE;
int v8dbg_IsNotStringMask = kIsNotStringMask;
int v8dbg_StringTag = kStringTag;
int v8dbg_NotStringTag = kNotStringTag;
int v8dbg_StringEncodingMask = kStringEncodingMask;
int v8dbg_TwoByteStringTag = kTwoByteStringTag;
int v8dbg_OneByteStringTag = kOneByteStringTag;
int v8dbg_StringRepresentationMask = kStringRepresentationMask;
int v8dbg_SeqStringTag = kSeqStringTag;
int v8dbg_ConsStringTag = kConsStringTag;
int v8dbg_ExternalStringTag = kExternalStringTag;
int v8dbg_SlicedStringTag = kSlicedStringTag;
int v8dbg_HeapObjectTag = kHeapObjectTag;
int v8dbg_HeapObjectTagMask = kHeapObjectTagMask;
int v8dbg_SmiTag = kSmiTag;
int v8dbg_SmiTagMask = kSmiTagMask;
int v8dbg_SmiValueShift = kSmiTagSize;
int v8dbg_SmiShiftSize = kSmiShiftSize;
int v8dbg_PointerSizeLog2 = kPointerSizeLog2;
int v8dbg_OddballFalse = Oddball::kFalse;
int v8dbg_OddballTrue = Oddball::kTrue;
int v8dbg_OddballTheHole = Oddball::kTheHole;
int v8dbg_OddballNull = Oddball::kNull;
int v8dbg_OddballArgumentsMarker = Oddball::kArgumentsMarker;
int v8dbg_OddballUndefined = Oddball::kUndefined;
int v8dbg_OddballUninitialized = Oddball::kUninitialized;
int v8dbg_OddballOther = Oddball::kOther;
int v8dbg_OddballException = Oddball::kException;
int v8dbg_prop_idx_first = DescriptorArray::kFirstIndex;
int v8dbg_prop_type_field = DATA;
int v8dbg_prop_type_const_field = DATA_CONSTANT;
int v8dbg_prop_type_mask = PropertyDetails::TypeField::kMask;
int v8dbg_prop_index_mask = PropertyDetails::FieldIndexField::kMask;
int v8dbg_prop_index_shift = PropertyDetails::FieldIndexField::kShift;
int v8dbg_prop_representation_mask = PropertyDetails::RepresentationField::kMask;
int v8dbg_prop_representation_shift = PropertyDetails::RepresentationField::kShift;
int v8dbg_prop_representation_integer8 = Representation::Kind::kInteger8;
int v8dbg_prop_representation_uinteger8 = Representation::Kind::kUInteger8;
int v8dbg_prop_representation_integer16 = Representation::Kind::kInteger16;
int v8dbg_prop_representation_uinteger16 = Representation::Kind::kUInteger16;
int v8dbg_prop_representation_smi = Representation::Kind::kSmi;
int v8dbg_prop_representation_integer32 = Representation::Kind::kInteger32;
int v8dbg_prop_representation_double = Representation::Kind::kDouble;
int v8dbg_prop_representation_heapobject = Representation::Kind::kHeapObject;
int v8dbg_prop_representation_tagged = Representation::Kind::kTagged;
int v8dbg_prop_representation_external = Representation::Kind::kExternal;
int v8dbg_prop_desc_key = DescriptorArray::kDescriptorKey;
int v8dbg_prop_desc_details = DescriptorArray::kDescriptorDetails;
int v8dbg_prop_desc_value = DescriptorArray::kDescriptorValue;
int v8dbg_prop_desc_size = DescriptorArray::kDescriptorSize;
int v8dbg_elements_fast_holey_elements = FAST_HOLEY_ELEMENTS;
int v8dbg_elements_fast_elements = FAST_ELEMENTS;
int v8dbg_elements_dictionary_elements = DICTIONARY_ELEMENTS;
int v8dbg_bit_field2_elements_kind_mask = Map::ElementsKindBits::kMask;
int v8dbg_bit_field2_elements_kind_shift = Map::ElementsKindBits::kShift;
int v8dbg_bit_field3_dictionary_map_shift = Map::DictionaryMap::kShift;
int v8dbg_bit_field3_number_of_own_descriptors_mask = Map::NumberOfOwnDescriptorsBits::kMask;
int v8dbg_bit_field3_number_of_own_descriptors_shift = Map::NumberOfOwnDescriptorsBits::kShift;
int v8dbg_off_fp_context = StandardFrameConstants::kContextOffset;
int v8dbg_off_fp_constant_pool = StandardFrameConstants::kConstantPoolOffset;
int v8dbg_off_fp_function = JavaScriptFrameConstants::kFunctionOffset;
int v8dbg_off_fp_args = JavaScriptFrameConstants::kLastParameterOffset;
int v8dbg_scopeinfo_idx_nparams = ScopeInfo::kParameterCount;
int v8dbg_scopeinfo_idx_nstacklocals = ScopeInfo::kStackLocalCount;
int v8dbg_scopeinfo_idx_ncontextlocals = ScopeInfo::kContextLocalCount;
int v8dbg_scopeinfo_idx_ncontextglobals = ScopeInfo::kContextGlobalCount;
int v8dbg_scopeinfo_idx_first_vars = ScopeInfo::kVariablePartIndex;
int v8dbg_sharedfunctioninfo_start_position_mask = SharedFunctionInfo::kStartPositionMask;
int v8dbg_sharedfunctioninfo_start_position_shift = SharedFunctionInfo::kStartPositionShift;
int v8dbg_jsarray_buffer_was_neutered_mask = JSArrayBuffer::WasNeutered::kMask;
int v8dbg_jsarray_buffer_was_neutered_shift = JSArrayBuffer::WasNeutered::kShift;
int v8dbg_context_idx_closure = Context::CLOSURE_INDEX;
int v8dbg_context_idx_native = Context::NATIVE_CONTEXT_INDEX;
int v8dbg_context_idx_prev = Context::PREVIOUS_INDEX;
int v8dbg_context_idx_ext = Context::EXTENSION_INDEX;
int v8dbg_context_min_slots = Context::MIN_CONTEXT_SLOTS;
int v8dbg_namedictionaryshape_prefix_size = NameDictionaryShape::kPrefixSize;
int v8dbg_namedictionaryshape_entry_size = NameDictionaryShape::kEntrySize;
int v8dbg_globaldictionaryshape_entry_size = GlobalDictionaryShape::kEntrySize;
int v8dbg_namedictionary_prefix_start_index = NameDictionary::kPrefixStartIndex;
int v8dbg_seedednumberdictionaryshape_prefix_size = SeededNumberDictionaryShape::kPrefixSize;
int v8dbg_seedednumberdictionaryshape_entry_size = SeededNumberDictionaryShape::kEntrySize;
int v8dbg_unseedednumberdictionaryshape_prefix_size = UnseededNumberDictionaryShape::kPrefixSize;
int v8dbg_unseedednumberdictionaryshape_entry_size = UnseededNumberDictionaryShape::kEntrySize;

/* class type information */
int v8dbg_type_AccessorInfo__ACCESSOR_INFO_TYPE = ACCESSOR_INFO_TYPE;
int v8dbg_type_AccessorPair__ACCESSOR_PAIR_TYPE = ACCESSOR_PAIR_TYPE;
int v8dbg_type_AccessCheckInfo__ACCESS_CHECK_INFO_TYPE = ACCESS_CHECK_INFO_TYPE;
int v8dbg_type_AliasedArgumentsEntry__ALIASED_ARGUMENTS_ENTRY_TYPE = ALIASED_ARGUMENTS_ENTRY_TYPE;
int v8dbg_type_AllocationMemento__ALLOCATION_MEMENTO_TYPE = ALLOCATION_MEMENTO_TYPE;
int v8dbg_type_AllocationSite__ALLOCATION_SITE_TYPE = ALLOCATION_SITE_TYPE;
int v8dbg_type_Box__BOX_TYPE = BOX_TYPE;
int v8dbg_type_BreakPointInfo__BREAK_POINT_INFO_TYPE = BREAK_POINT_INFO_TYPE;
int v8dbg_type_BytecodeArray__BYTECODE_ARRAY_TYPE = BYTECODE_ARRAY_TYPE;
int v8dbg_type_ByteArray__BYTE_ARRAY_TYPE = BYTE_ARRAY_TYPE;
int v8dbg_type_CallHandlerInfo__CALL_HANDLER_INFO_TYPE = CALL_HANDLER_INFO_TYPE;
int v8dbg_type_Cell__CELL_TYPE = CELL_TYPE;
int v8dbg_type_Code__CODE_TYPE = CODE_TYPE;
int v8dbg_type_ConsString__CONS_ONE_BYTE_STRING_TYPE = CONS_ONE_BYTE_STRING_TYPE;
int v8dbg_type_ConsString__CONS_STRING_TYPE = CONS_STRING_TYPE;
int v8dbg_type_DebugInfo__DEBUG_INFO_TYPE = DEBUG_INFO_TYPE;
int v8dbg_type_ExternalOneByteString__EXTERNAL_ONE_BYTE_STRING_TYPE = EXTERNAL_ONE_BYTE_STRING_TYPE;
int v8dbg_type_ExternalTwoByteString__EXTERNAL_STRING_TYPE = EXTERNAL_STRING_TYPE;
int v8dbg_type_FixedArray__FIXED_ARRAY_TYPE = FIXED_ARRAY_TYPE;
int v8dbg_type_FixedDoubleArray__FIXED_DOUBLE_ARRAY_TYPE = FIXED_DOUBLE_ARRAY_TYPE;
int v8dbg_type_Foreign__FOREIGN_TYPE = FOREIGN_TYPE;
int v8dbg_type_FreeSpace__FREE_SPACE_TYPE = FREE_SPACE_TYPE;
int v8dbg_type_FunctionTemplateInfo__FUNCTION_TEMPLATE_INFO_TYPE = FUNCTION_TEMPLATE_INFO_TYPE;
int v8dbg_type_HeapNumber__HEAP_NUMBER_TYPE = HEAP_NUMBER_TYPE;
int v8dbg_type_InterceptorInfo__INTERCEPTOR_INFO_TYPE = INTERCEPTOR_INFO_TYPE;
int v8dbg_type_JSArrayBuffer__JS_ARRAY_BUFFER_TYPE = JS_ARRAY_BUFFER_TYPE;
int v8dbg_type_JSArray__JS_ARRAY_TYPE = JS_ARRAY_TYPE;
int v8dbg_type_JSBoundFunction__JS_BOUND_FUNCTION_TYPE = JS_BOUND_FUNCTION_TYPE;
int v8dbg_type_JSDataView__JS_DATA_VIEW_TYPE = JS_DATA_VIEW_TYPE;
int v8dbg_type_JSDate__JS_DATE_TYPE = JS_DATE_TYPE;
int v8dbg_type_JSFunction__JS_FUNCTION_TYPE = JS_FUNCTION_TYPE;
int v8dbg_type_JSGeneratorObject__JS_GENERATOR_OBJECT_TYPE = JS_GENERATOR_OBJECT_TYPE;
int v8dbg_type_JSGlobalObject__JS_GLOBAL_OBJECT_TYPE = JS_GLOBAL_OBJECT_TYPE;
int v8dbg_type_JSGlobalProxy__JS_GLOBAL_PROXY_TYPE = JS_GLOBAL_PROXY_TYPE;
int v8dbg_type_JSMap__JS_MAP_TYPE = JS_MAP_TYPE;
int v8dbg_type_JSMessageObject__JS_MESSAGE_OBJECT_TYPE = JS_MESSAGE_OBJECT_TYPE;
int v8dbg_type_JSObject__JS_OBJECT_TYPE = JS_OBJECT_TYPE;
int v8dbg_type_JSProxy__JS_PROXY_TYPE = JS_PROXY_TYPE;
int v8dbg_type_JSRegExp__JS_REGEXP_TYPE = JS_REGEXP_TYPE;
int v8dbg_type_JSSet__JS_SET_TYPE = JS_SET_TYPE;
int v8dbg_type_JSTypedArray__JS_TYPED_ARRAY_TYPE = JS_TYPED_ARRAY_TYPE;
int v8dbg_type_JSValue__JS_VALUE_TYPE = JS_VALUE_TYPE;
int v8dbg_type_JSWeakMap__JS_WEAK_MAP_TYPE = JS_WEAK_MAP_TYPE;
int v8dbg_type_JSWeakSet__JS_WEAK_SET_TYPE = JS_WEAK_SET_TYPE;
int v8dbg_type_Map__MAP_TYPE = MAP_TYPE;
int v8dbg_type_ObjectTemplateInfo__OBJECT_TEMPLATE_INFO_TYPE = OBJECT_TEMPLATE_INFO_TYPE;
int v8dbg_type_Oddball__ODDBALL_TYPE = ODDBALL_TYPE;
int v8dbg_type_SeqOneByteString__ONE_BYTE_STRING_TYPE = ONE_BYTE_STRING_TYPE;
int v8dbg_type_PropertyCell__PROPERTY_CELL_TYPE = PROPERTY_CELL_TYPE;
int v8dbg_type_PrototypeInfo__PROTOTYPE_INFO_TYPE = PROTOTYPE_INFO_TYPE;
int v8dbg_type_Script__SCRIPT_TYPE = SCRIPT_TYPE;
int v8dbg_type_SharedFunctionInfo__SHARED_FUNCTION_INFO_TYPE = SHARED_FUNCTION_INFO_TYPE;
int v8dbg_type_Simd128Value__SIMD128_VALUE_TYPE = SIMD128_VALUE_TYPE;
int v8dbg_type_SlicedString__SLICED_ONE_BYTE_STRING_TYPE = SLICED_ONE_BYTE_STRING_TYPE;
int v8dbg_type_SlicedString__SLICED_STRING_TYPE = SLICED_STRING_TYPE;
int v8dbg_type_SloppyBlockWithEvalContextExtension__SLOPPY_BLOCK_WITH_EVAL_CONTEXT_EXTENSION_TYPE = SLOPPY_BLOCK_WITH_EVAL_CONTEXT_EXTENSION_TYPE;
int v8dbg_type_SeqTwoByteString__STRING_TYPE = STRING_TYPE;
int v8dbg_type_SeqTwoByteString__SYMBOL_TYPE = SYMBOL_TYPE;
int v8dbg_type_TypeFeedbackInfo__TYPE_FEEDBACK_INFO_TYPE = TYPE_FEEDBACK_INFO_TYPE;
int v8dbg_type_WeakCell__WEAK_CELL_TYPE = WEAK_CELL_TYPE;

/* class hierarchy information */
int v8dbg_parent_AbstractCode__HeapObject = 0;
int v8dbg_parent_AccessCheckInfo__Struct = 0;
int v8dbg_parent_AccessorInfo__Struct = 0;
int v8dbg_parent_AccessorPair__Struct = 0;
int v8dbg_parent_AliasedArgumentsEntry__Struct = 0;
int v8dbg_parent_AllocationMemento__Struct = 0;
int v8dbg_parent_AllocationSite__Struct = 0;
int v8dbg_parent_ArrayList__FixedArray = 0;
int v8dbg_parent_Box__Struct = 0;
int v8dbg_parent_BreakPointInfo__Struct = 0;
int v8dbg_parent_ByteArray__FixedArrayBase = 0;
int v8dbg_parent_BytecodeArray__FixedArrayBase = 0;
int v8dbg_parent_CallHandlerInfo__Struct = 0;
int v8dbg_parent_Cell__HeapObject = 0;
int v8dbg_parent_Code__HeapObject = 0;
int v8dbg_parent_ConsString__String = 0;
int v8dbg_parent_DebugInfo__Struct = 0;
int v8dbg_parent_DeoptimizationInputData__FixedArray = 0;
int v8dbg_parent_DeoptimizationOutputData__FixedArray = 0;
int v8dbg_parent_DependentCode__FixedArray = 0;
int v8dbg_parent_DescriptorArray__FixedArray = 0;
int v8dbg_parent_ExternalOneByteString__ExternalString = 0;
int v8dbg_parent_ExternalString__String = 0;
int v8dbg_parent_ExternalTwoByteString__ExternalString = 0;
int v8dbg_parent_FixedArray__FixedArrayBase = 0;
int v8dbg_parent_FixedArrayBase__HeapObject = 0;
int v8dbg_parent_FixedDoubleArray__FixedArrayBase = 0;
int v8dbg_parent_FixedTypedArray__FixedTypedArrayBase = 0;
int v8dbg_parent_FixedTypedArrayBase__FixedArrayBase = 0;
int v8dbg_parent_Foreign__HeapObject = 0;
int v8dbg_parent_FreeSpace__HeapObject = 0;
int v8dbg_parent_FunctionTemplateInfo__TemplateInfo = 0;
int v8dbg_parent_HandlerTable__FixedArray = 0;
int v8dbg_parent_HashTable__HashTableBase = 0;
int v8dbg_parent_HashTableBase__FixedArray = 0;
int v8dbg_parent_HeapNumber__HeapObject = 0;
int v8dbg_parent_HeapObject__Object = 0;
int v8dbg_parent_InterceptorInfo__Struct = 0;
int v8dbg_parent_JSAccessorPropertyDescriptor__JSObject = 0;
int v8dbg_parent_JSArgumentsObject__JSObject = 0;
int v8dbg_parent_JSArray__JSObject = 0;
int v8dbg_parent_JSArrayBuffer__JSObject = 0;
int v8dbg_parent_JSArrayBufferView__JSObject = 0;
int v8dbg_parent_JSBoundFunction__JSObject = 0;
int v8dbg_parent_JSCollection__JSObject = 0;
int v8dbg_parent_JSDataPropertyDescriptor__JSObject = 0;
int v8dbg_parent_JSDataView__JSArrayBufferView = 0;
int v8dbg_parent_JSDate__JSObject = 0;
int v8dbg_parent_JSFunction__JSObject = 0;
int v8dbg_parent_JSGeneratorObject__JSObject = 0;
int v8dbg_parent_JSGlobalObject__JSObject = 0;
int v8dbg_parent_JSGlobalProxy__JSObject = 0;
int v8dbg_parent_JSIteratorResult__JSObject = 0;
int v8dbg_parent_JSMap__JSCollection = 0;
int v8dbg_parent_JSMessageObject__JSObject = 0;
int v8dbg_parent_JSObject__JSReceiver = 0;
int v8dbg_parent_JSProxy__JSReceiver = 0;
int v8dbg_parent_JSReceiver__HeapObject = 0;
int v8dbg_parent_JSRegExp__JSObject = 0;
int v8dbg_parent_JSRegExpResult__JSArray = 0;
int v8dbg_parent_JSSet__JSCollection = 0;
int v8dbg_parent_JSSloppyArgumentsObject__JSArgumentsObject = 0;
int v8dbg_parent_JSStrictArgumentsObject__JSArgumentsObject = 0;
int v8dbg_parent_JSTypedArray__JSArrayBufferView = 0;
int v8dbg_parent_JSValue__JSObject = 0;
int v8dbg_parent_JSWeakCollection__JSObject = 0;
int v8dbg_parent_JSWeakMap__JSWeakCollection = 0;
int v8dbg_parent_JSWeakSet__JSWeakCollection = 0;
int v8dbg_parent_LiteralsArray__FixedArray = 0;
int v8dbg_parent_Map__HeapObject = 0;
int v8dbg_parent_Name__HeapObject = 0;
int v8dbg_parent_NormalizedMapCache__FixedArray = 0;
int v8dbg_parent_ObjectTemplateInfo__TemplateInfo = 0;
int v8dbg_parent_Oddball__HeapObject = 0;
int v8dbg_parent_OrderedHashTable__FixedArray = 0;
int v8dbg_parent_OrderedHashTableIterator__JSObject = 0;
int v8dbg_parent_PropertyCell__HeapObject = 0;
int v8dbg_parent_PrototypeInfo__Struct = 0;
int v8dbg_parent_ScopeInfo__FixedArray = 0;
int v8dbg_parent_Script__Struct = 0;
int v8dbg_parent_SeqOneByteString__SeqString = 0;
int v8dbg_parent_SeqString__String = 0;
int v8dbg_parent_SeqTwoByteString__SeqString = 0;
int v8dbg_parent_SharedFunctionInfo__HeapObject = 0;
int v8dbg_parent_Simd128Value__HeapObject = 0;
int v8dbg_parent_SlicedString__String = 0;
int v8dbg_parent_SloppyBlockWithEvalContextExtension__Struct = 0;
int v8dbg_parent_Smi__Object = 0;
int v8dbg_parent_String__Name = 0;
int v8dbg_parent_Struct__HeapObject = 0;
int v8dbg_parent_Symbol__Name = 0;
int v8dbg_parent_TemplateInfo__Struct = 0;
int v8dbg_parent_TemplateList__FixedArray = 0;
int v8dbg_parent_Typefinal__Simd128Value = 0;
int v8dbg_parent_TypeFeedbackInfo__Struct = 0;
int v8dbg_parent_WeakCell__HeapObject = 0;
int v8dbg_parent_WeakFixedArray__FixedArray = 0;

/* field information */
int v8dbg_class_JSReceiver__properties__FixedArray = JSReceiver::kPropertiesOffset;
int v8dbg_class_Oddball__to_string__String = Oddball::kToStringOffset;
int v8dbg_class_Oddball__to_number__Object = Oddball::kToNumberOffset;
int v8dbg_class_Oddball__type_of__String = Oddball::kTypeOfOffset;
int v8dbg_class_Cell__value__Object = Cell::kValueOffset;
int v8dbg_class_PropertyCell__dependent_code__DependentCode = PropertyCell::kDependentCodeOffset;
int v8dbg_class_PropertyCell__property_details_raw__Object = PropertyCell::kDetailsOffset;
int v8dbg_class_PropertyCell__value__Object = PropertyCell::kValueOffset;
int v8dbg_class_FixedArrayBase__length__SMI = FixedArrayBase::kLengthOffset;
int v8dbg_class_FreeSpace__size__SMI = FreeSpace::kSizeOffset;
int v8dbg_class_String__length__SMI = String::kLengthOffset;
int v8dbg_class_Symbol__name__Object = Symbol::kNameOffset;
int v8dbg_class_Symbol__flags__SMI = Symbol::kFlagsOffset;
int v8dbg_class_SlicedString__offset__SMI = SlicedString::kOffsetOffset;
int v8dbg_class_BytecodeArray__constant_pool__FixedArray = BytecodeArray::kConstantPoolOffset;
int v8dbg_class_BytecodeArray__handler_table__FixedArray = BytecodeArray::kHandlerTableOffset;
int v8dbg_class_BytecodeArray__source_position_table__ByteArray = BytecodeArray::kSourcePositionTableOffset;
int v8dbg_class_FixedTypedArrayBase__base_pointer__Object = FixedTypedArrayBase::kBasePointerOffset;
int v8dbg_class_Map__instance_descriptors__DescriptorArray = Map::kDescriptorsOffset;
int v8dbg_class_Map__layout_descriptor__LayoutDescriptor = Map::kLayoutDescriptorOffset;
int v8dbg_class_Map__raw_transitions__Object = Map::kTransitionsOrPrototypeInfoOffset;
int v8dbg_class_Map__code_cache__FixedArray = Map::kCodeCacheOffset;
int v8dbg_class_Map__dependent_code__DependentCode = Map::kDependentCodeOffset;
int v8dbg_class_Map__weak_cell_cache__Object = Map::kWeakCellCacheOffset;
int v8dbg_class_Map__constructor_or_backpointer__Object = Map::kConstructorOrBackPointerOffset;
int v8dbg_class_JSBoundFunction__bound_target_function__JSReceiver = JSBoundFunction::kBoundTargetFunctionOffset;
int v8dbg_class_JSBoundFunction__bound_this__Object = JSBoundFunction::kBoundThisOffset;
int v8dbg_class_JSBoundFunction__bound_arguments__FixedArray = JSBoundFunction::kBoundArgumentsOffset;
int v8dbg_class_JSFunction__shared__SharedFunctionInfo = JSFunction::kSharedFunctionInfoOffset;
int v8dbg_class_JSFunction__literals__LiteralsArray = JSFunction::kLiteralsOffset;
int v8dbg_class_JSFunction__next_function_link__Object = JSFunction::kNextFunctionLinkOffset;
int v8dbg_class_JSGlobalObject__native_context__Context = JSGlobalObject::kNativeContextOffset;
int v8dbg_class_JSGlobalObject__global_proxy__JSObject = JSGlobalObject::kGlobalProxyOffset;
int v8dbg_class_JSGlobalProxy__native_context__Object = JSGlobalProxy::kNativeContextOffset;
int v8dbg_class_JSGlobalProxy__hash__Object = JSGlobalProxy::kHashOffset;
int v8dbg_class_AccessorInfo__name__Object = AccessorInfo::kNameOffset;
int v8dbg_class_AccessorInfo__flag__SMI = AccessorInfo::kFlagOffset;
int v8dbg_class_AccessorInfo__expected_receiver_type__Object = AccessorInfo::kExpectedReceiverTypeOffset;
int v8dbg_class_AccessorInfo__getter__Object = AccessorInfo::kGetterOffset;
int v8dbg_class_AccessorInfo__setter__Object = AccessorInfo::kSetterOffset;
int v8dbg_class_AccessorInfo__js_getter__Object = AccessorInfo::kJsGetterOffset;
int v8dbg_class_AccessorInfo__data__Object = AccessorInfo::kDataOffset;
int v8dbg_class_Box__value__Object = Box::kValueOffset;
int v8dbg_class_PrototypeInfo__prototype_users__Object = PrototypeInfo::kPrototypeUsersOffset;
int v8dbg_class_PrototypeInfo__object_create_map__Object = PrototypeInfo::kObjectCreateMap;
int v8dbg_class_PrototypeInfo__registry_slot__SMI = PrototypeInfo::kRegistrySlotOffset;
int v8dbg_class_PrototypeInfo__validity_cell__Object = PrototypeInfo::kValidityCellOffset;
int v8dbg_class_PrototypeInfo__bit_field__SMI = PrototypeInfo::kBitFieldOffset;
int v8dbg_class_SloppyBlockWithEvalContextExtension__scope_info__ScopeInfo = SloppyBlockWithEvalContextExtension::kScopeInfoOffset;
int v8dbg_class_SloppyBlockWithEvalContextExtension__extension__JSObject = SloppyBlockWithEvalContextExtension::kExtensionOffset;
int v8dbg_class_AccessorPair__getter__Object = AccessorPair::kGetterOffset;
int v8dbg_class_AccessorPair__setter__Object = AccessorPair::kSetterOffset;
int v8dbg_class_AccessCheckInfo__callback__Object = AccessCheckInfo::kCallbackOffset;
int v8dbg_class_AccessCheckInfo__named_interceptor__Object = AccessCheckInfo::kNamedInterceptorOffset;
int v8dbg_class_AccessCheckInfo__indexed_interceptor__Object = AccessCheckInfo::kIndexedInterceptorOffset;
int v8dbg_class_AccessCheckInfo__data__Object = AccessCheckInfo::kDataOffset;
int v8dbg_class_InterceptorInfo__getter__Object = InterceptorInfo::kGetterOffset;
int v8dbg_class_InterceptorInfo__setter__Object = InterceptorInfo::kSetterOffset;
int v8dbg_class_InterceptorInfo__query__Object = InterceptorInfo::kQueryOffset;
int v8dbg_class_InterceptorInfo__deleter__Object = InterceptorInfo::kDeleterOffset;
int v8dbg_class_InterceptorInfo__enumerator__Object = InterceptorInfo::kEnumeratorOffset;
int v8dbg_class_InterceptorInfo__data__Object = InterceptorInfo::kDataOffset;
int v8dbg_class_InterceptorInfo__flags__SMI = InterceptorInfo::kFlagsOffset;
int v8dbg_class_CallHandlerInfo__callback__Object = CallHandlerInfo::kCallbackOffset;
int v8dbg_class_CallHandlerInfo__data__Object = CallHandlerInfo::kDataOffset;
int v8dbg_class_CallHandlerInfo__fast_handler__Object = CallHandlerInfo::kFastHandlerOffset;
int v8dbg_class_TemplateInfo__tag__Object = TemplateInfo::kTagOffset;
int v8dbg_class_TemplateInfo__serial_number__Object = TemplateInfo::kSerialNumberOffset;
int v8dbg_class_TemplateInfo__number_of_properties__SMI = TemplateInfo::kNumberOfProperties;
int v8dbg_class_TemplateInfo__property_list__Object = TemplateInfo::kPropertyListOffset;
int v8dbg_class_TemplateInfo__property_accessors__Object = TemplateInfo::kPropertyAccessorsOffset;
int v8dbg_class_FunctionTemplateInfo__call_code__Object = FunctionTemplateInfo::kCallCodeOffset;
int v8dbg_class_FunctionTemplateInfo__prototype_template__Object = FunctionTemplateInfo::kPrototypeTemplateOffset;
int v8dbg_class_FunctionTemplateInfo__parent_template__Object = FunctionTemplateInfo::kParentTemplateOffset;
int v8dbg_class_FunctionTemplateInfo__named_property_handler__Object = FunctionTemplateInfo::kNamedPropertyHandlerOffset;
int v8dbg_class_FunctionTemplateInfo__indexed_property_handler__Object = FunctionTemplateInfo::kIndexedPropertyHandlerOffset;
int v8dbg_class_FunctionTemplateInfo__instance_template__Object = FunctionTemplateInfo::kInstanceTemplateOffset;
int v8dbg_class_FunctionTemplateInfo__class_name__Object = FunctionTemplateInfo::kClassNameOffset;
int v8dbg_class_FunctionTemplateInfo__signature__Object = FunctionTemplateInfo::kSignatureOffset;
int v8dbg_class_FunctionTemplateInfo__instance_call_handler__Object = FunctionTemplateInfo::kInstanceCallHandlerOffset;
int v8dbg_class_FunctionTemplateInfo__access_check_info__Object = FunctionTemplateInfo::kAccessCheckInfoOffset;
int v8dbg_class_FunctionTemplateInfo__shared_function_info__Object = FunctionTemplateInfo::kSharedFunctionInfoOffset;
int v8dbg_class_FunctionTemplateInfo__flag__SMI = FunctionTemplateInfo::kFlagOffset;
int v8dbg_class_ObjectTemplateInfo__constructor__Object = ObjectTemplateInfo::kConstructorOffset;
int v8dbg_class_ObjectTemplateInfo__data__Object = ObjectTemplateInfo::kDataOffset;
int v8dbg_class_AllocationSite__transition_info__Object = AllocationSite::kTransitionInfoOffset;
int v8dbg_class_AllocationSite__nested_site__Object = AllocationSite::kNestedSiteOffset;
int v8dbg_class_AllocationSite__pretenure_data__SMI = AllocationSite::kPretenureDataOffset;
int v8dbg_class_AllocationSite__pretenure_create_count__SMI = AllocationSite::kPretenureCreateCountOffset;
int v8dbg_class_AllocationSite__dependent_code__DependentCode = AllocationSite::kDependentCodeOffset;
int v8dbg_class_AllocationSite__weak_next__Object = AllocationSite::kWeakNextOffset;
int v8dbg_class_AllocationMemento__allocation_site__Object = AllocationMemento::kAllocationSiteOffset;
int v8dbg_class_Script__source__Object = Script::kSourceOffset;
int v8dbg_class_Script__name__Object = Script::kNameOffset;
int v8dbg_class_Script__id__SMI = Script::kIdOffset;
int v8dbg_class_Script__line_offset__SMI = Script::kLineOffsetOffset;
int v8dbg_class_Script__column_offset__SMI = Script::kColumnOffsetOffset;
int v8dbg_class_Script__context_data__Object = Script::kContextOffset;
int v8dbg_class_Script__wrapper__HeapObject = Script::kWrapperOffset;
int v8dbg_class_Script__type__SMI = Script::kTypeOffset;
int v8dbg_class_Script__line_ends__Object = Script::kLineEndsOffset;
int v8dbg_class_Script__shared_function_infos__Object = Script::kSharedFunctionInfosOffset;
int v8dbg_class_Script__flags__SMI = Script::kFlagsOffset;
int v8dbg_class_Script__source_url__Object = Script::kSourceUrlOffset;
int v8dbg_class_Script__source_mapping_url__Object = Script::kSourceMappingUrlOffset;
int v8dbg_class_DebugInfo__shared__SharedFunctionInfo = DebugInfo::kSharedFunctionInfoIndex;
int v8dbg_class_DebugInfo__debug_bytecode_array__Object = DebugInfo::kDebugBytecodeArrayIndex;
int v8dbg_class_DebugInfo__break_points__FixedArray = DebugInfo::kBreakPointsStateIndex;
int v8dbg_class_BreakPointInfo__source_position__SMI = BreakPointInfo::kSourcePositionIndex;
int v8dbg_class_BreakPointInfo__break_point_objects__Object = BreakPointInfo::kBreakPointObjectsIndex;
int v8dbg_class_SharedFunctionInfo__name__Object = SharedFunctionInfo::kNameOffset;
int v8dbg_class_SharedFunctionInfo__optimized_code_map__FixedArray = SharedFunctionInfo::kOptimizedCodeMapOffset;
int v8dbg_class_SharedFunctionInfo__construct_stub__Code = SharedFunctionInfo::kConstructStubOffset;
int v8dbg_class_SharedFunctionInfo__feedback_metadata__TypeFeedbackMetadata = SharedFunctionInfo::kFeedbackMetadataOffset;
int v8dbg_class_SharedFunctionInfo__unique_id__SMI = SharedFunctionInfo::kUniqueIdOffset;
int v8dbg_class_SharedFunctionInfo__instance_class_name__Object = SharedFunctionInfo::kInstanceClassNameOffset;
int v8dbg_class_SharedFunctionInfo__function_data__Object = SharedFunctionInfo::kFunctionDataOffset;
int v8dbg_class_SharedFunctionInfo__script__Object = SharedFunctionInfo::kScriptOffset;
int v8dbg_class_SharedFunctionInfo__debug_info__Object = SharedFunctionInfo::kDebugInfoOffset;
int v8dbg_class_SharedFunctionInfo__function_identifier__Object = SharedFunctionInfo::kFunctionIdentifierOffset;
int v8dbg_class_FunctionTemplateInfo__length__SMI = FunctionTemplateInfo::kLengthOffset;
int v8dbg_class_SharedFunctionInfo__length__SMI = SharedFunctionInfo::kLengthOffset;
int v8dbg_class_SharedFunctionInfo__internal_formal_parameter_count__SMI = SharedFunctionInfo::kFormalParameterCountOffset;
int v8dbg_class_SharedFunctionInfo__expected_nof_properties__SMI = SharedFunctionInfo::kExpectedNofPropertiesOffset;
int v8dbg_class_SharedFunctionInfo__num_literals__SMI = SharedFunctionInfo::kNumLiteralsOffset;
int v8dbg_class_SharedFunctionInfo__start_position_and_type__SMI = SharedFunctionInfo::kStartPositionAndTypeOffset;
int v8dbg_class_SharedFunctionInfo__end_position__SMI = SharedFunctionInfo::kEndPositionOffset;
int v8dbg_class_SharedFunctionInfo__function_token_position__SMI = SharedFunctionInfo::kFunctionTokenPositionOffset;
int v8dbg_class_SharedFunctionInfo__compiler_hints__SMI = SharedFunctionInfo::kCompilerHintsOffset;
int v8dbg_class_SharedFunctionInfo__opt_count_and_bailout_reason__SMI = SharedFunctionInfo::kOptCountAndBailoutReasonOffset;
int v8dbg_class_SharedFunctionInfo__counters__SMI = SharedFunctionInfo::kCountersOffset;
int v8dbg_class_SharedFunctionInfo__ast_node_count__SMI = SharedFunctionInfo::kAstNodeCountOffset;
int v8dbg_class_SharedFunctionInfo__profiler_ticks__SMI = SharedFunctionInfo::kProfilerTicksOffset;
int v8dbg_class_JSFunction__prototype_or_initial_map__Object = JSFunction::kPrototypeOrInitialMapOffset;
int v8dbg_class_JSProxy__target__JSReceiver = JSProxy::kTargetOffset;
int v8dbg_class_JSProxy__handler__Object = JSProxy::kHandlerOffset;
int v8dbg_class_JSProxy__hash__Object = JSProxy::kHashOffset;
int v8dbg_class_JSCollection__table__Object = JSCollection::kTableOffset;
int v8dbg_class_JSWeakCollection__table__Object = JSWeakCollection::kTableOffset;
int v8dbg_class_JSWeakCollection__next__Object = JSWeakCollection::kNextOffset;
int v8dbg_class_JSGeneratorObject__function__JSFunction = JSGeneratorObject::kFunctionOffset;
int v8dbg_class_JSGeneratorObject__context__Context = JSGeneratorObject::kContextOffset;
int v8dbg_class_JSGeneratorObject__receiver__Object = JSGeneratorObject::kReceiverOffset;
int v8dbg_class_JSGeneratorObject__input_or_debug_pos__Object = JSGeneratorObject::kInputOrDebugPosOffset;
int v8dbg_class_JSGeneratorObject__resume_mode__SMI = JSGeneratorObject::kResumeModeOffset;
int v8dbg_class_JSGeneratorObject__continuation__SMI = JSGeneratorObject::kContinuationOffset;
int v8dbg_class_JSGeneratorObject__operand_stack__FixedArray = JSGeneratorObject::kOperandStackOffset;
int v8dbg_class_JSValue__value__Object = JSValue::kValueOffset;
int v8dbg_class_JSDate__value__Object = JSDate::kValueOffset;
int v8dbg_class_JSDate__cache_stamp__Object = JSDate::kCacheStampOffset;
int v8dbg_class_JSDate__year__Object = JSDate::kYearOffset;
int v8dbg_class_JSDate__month__Object = JSDate::kMonthOffset;
int v8dbg_class_JSDate__day__Object = JSDate::kDayOffset;
int v8dbg_class_JSDate__weekday__Object = JSDate::kWeekdayOffset;
int v8dbg_class_JSDate__hour__Object = JSDate::kHourOffset;
int v8dbg_class_JSDate__min__Object = JSDate::kMinOffset;
int v8dbg_class_JSDate__sec__Object = JSDate::kSecOffset;
int v8dbg_class_JSMessageObject__type__SMI = JSMessageObject::kTypeOffset;
int v8dbg_class_JSMessageObject__argument__Object = JSMessageObject::kArgumentsOffset;
int v8dbg_class_JSMessageObject__script__Object = JSMessageObject::kScriptOffset;
int v8dbg_class_JSMessageObject__stack_frames__Object = JSMessageObject::kStackFramesOffset;
int v8dbg_class_JSMessageObject__start_position__SMI = JSMessageObject::kStartPositionOffset;
int v8dbg_class_JSMessageObject__end_position__SMI = JSMessageObject::kEndPositionOffset;
int v8dbg_class_Code__relocation_info__ByteArray = Code::kRelocationInfoOffset;
int v8dbg_class_Code__handler_table__FixedArray = Code::kHandlerTableOffset;
int v8dbg_class_Code__deoptimization_data__FixedArray = Code::kDeoptimizationDataOffset;
int v8dbg_class_Code__source_position_table__ByteArray = Code::kSourcePositionTableOffset;
int v8dbg_class_Code__raw_type_feedback_info__Object = Code::kTypeFeedbackInfoOffset;
int v8dbg_class_Code__next_code_link__Object = Code::kNextCodeLinkOffset;
int v8dbg_class_Code__gc_metadata__Object = Code::kGCMetadataOffset;
int v8dbg_class_JSArray__length__Object = JSArray::kLengthOffset;
int v8dbg_class_JSArrayBuffer__byte_length__Object = JSArrayBuffer::kByteLengthOffset;
int v8dbg_class_JSArrayBufferView__buffer__Object = JSArrayBufferView::kBufferOffset;
int v8dbg_class_JSArrayBufferView__raw_byte_offset__Object = JSArrayBufferView::kByteOffsetOffset;
int v8dbg_class_JSArrayBufferView__raw_byte_length__Object = JSArrayBufferView::kByteLengthOffset;
int v8dbg_class_JSTypedArray__raw_length__Object = JSTypedArray::kLengthOffset;
int v8dbg_class_JSRegExp__data__Object = JSRegExp::kDataOffset;
int v8dbg_class_JSRegExp__flags__Object = JSRegExp::kFlagsOffset;
int v8dbg_class_JSRegExp__source__Object = JSRegExp::kSourceOffset;
int v8dbg_class_AliasedArgumentsEntry__aliased_context_slot__SMI = AliasedArgumentsEntry::kAliasedContextSlot;
int v8dbg_class_JSFunction__context__Context = JSFunction::kContextOffset;
int v8dbg_class_HeapObject__map__Map = HeapObject::kMapOffset;
int v8dbg_class_JSObject__elements__Object = JSObject::kElementsOffset;
int v8dbg_class_FixedArray__data__uintptr_t = FixedArray::kHeaderSize;
int v8dbg_class_JSArrayBuffer__backing_store__Object = JSArrayBuffer::kBackingStoreOffset;
int v8dbg_class_JSArrayBufferView__byte_offset__Object = JSArrayBufferView::kByteOffsetOffset;
int v8dbg_class_JSTypedArray__length__Object = JSTypedArray::kLengthOffset;
int v8dbg_class_Map__instance_attributes__int = Map::kInstanceAttributesOffset;
int v8dbg_class_Map__inobject_properties_or_constructor_function_index__int = Map::kInObjectPropertiesOrConstructorFunctionIndexOffset;
int v8dbg_class_Map__instance_size__int = Map::kInstanceSizeOffset;
int v8dbg_class_Map__bit_field__char = Map::kBitFieldOffset;
int v8dbg_class_Map__bit_field2__char = Map::kBitField2Offset;
int v8dbg_class_Map__bit_field3__int = Map::kBitField3Offset;
int v8dbg_class_Map__prototype__Object = Map::kPrototypeOffset;
int v8dbg_class_Oddball__kind_offset__int = Oddball::kKindOffset;
int v8dbg_class_HeapNumber__value__double = HeapNumber::kValueOffset;
int v8dbg_class_ConsString__first__String = ConsString::kFirstOffset;
int v8dbg_class_ConsString__second__String = ConsString::kSecondOffset;
int v8dbg_class_ExternalString__resource__Object = ExternalString::kResourceOffset;
int v8dbg_class_SeqOneByteString__chars__char = SeqOneByteString::kHeaderSize;
int v8dbg_class_SeqTwoByteString__chars__char = SeqTwoByteString::kHeaderSize;
int v8dbg_class_SharedFunctionInfo__code__Code = SharedFunctionInfo::kCodeOffset;
int v8dbg_class_SharedFunctionInfo__scope_info__ScopeInfo = SharedFunctionInfo::kScopeInfoOffset;
int v8dbg_class_SlicedString__parent__String = SlicedString::kParentOffset;
int v8dbg_class_Code__instruction_start__uintptr_t = Code::kHeaderSize;
int v8dbg_class_Code__instruction_size__int = Code::kInstructionSizeOffset;


}
