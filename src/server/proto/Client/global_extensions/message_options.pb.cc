// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: global_extensions/message_options.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "global_extensions/message_options.pb.h"

#include <utility>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace bgs {
namespace protocol {

namespace {

const ::google::protobuf::Descriptor* BGSMessageOptions_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BGSMessageOptions_reflection_ = NULL;

}  // namespace

void protobuf_AssignDesc_global_5fextensions_2fmessage_5foptions_2eproto() {
  protobuf_AddDesc_global_5fextensions_2fmessage_5foptions_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "global_extensions/message_options.proto");
  GOOGLE_CHECK(file != NULL);
  BGSMessageOptions_descriptor_ = file->message_type(0);
  static const int BGSMessageOptions_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BGSMessageOptions, custom_select_shard_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BGSMessageOptions, custom_validator_),
  };
  BGSMessageOptions_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BGSMessageOptions_descriptor_,
      BGSMessageOptions::default_instance_,
      BGSMessageOptions_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BGSMessageOptions, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BGSMessageOptions, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BGSMessageOptions));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_global_5fextensions_2fmessage_5foptions_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BGSMessageOptions_descriptor_, &BGSMessageOptions::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_global_5fextensions_2fmessage_5foptions_2eproto() {
  delete BGSMessageOptions::default_instance_;
  delete BGSMessageOptions_reflection_;
}

void protobuf_AddDesc_global_5fextensions_2fmessage_5foptions_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::protobuf_AddDesc_google_2fprotobuf_2fdescriptor_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\'global_extensions/message_options.prot"
    "o\022\014bgs.protocol\032 google/protobuf/descrip"
    "tor.proto\"J\n\021BGSMessageOptions\022\033\n\023custom"
    "_select_shard\030\001 \001(\010\022\030\n\020custom_validator\030"
    "\002 \001(\010:[\n\017message_options\022\037.google.protob"
    "uf.MessageOptions\030\220\277\005 \001(\0132\037.bgs.protocol"
    ".BGSMessageOptionsB&\n\rbnet.protocolB\023Mes"
    "sageOptionsProtoH\002", 298);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "global_extensions/message_options.proto", &protobuf_RegisterTypes);
  BGSMessageOptions::default_instance_ = new BGSMessageOptions();
  ::google::protobuf::internal::ExtensionSet::RegisterMessageExtension(
    &::google::protobuf::MessageOptions::default_instance(),
    90000, 11, false, false,
    &::bgs::protocol::BGSMessageOptions::default_instance());
  BGSMessageOptions::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_global_5fextensions_2fmessage_5foptions_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_global_5fextensions_2fmessage_5foptions_2eproto {
  StaticDescriptorInitializer_global_5fextensions_2fmessage_5foptions_2eproto() {
    protobuf_AddDesc_global_5fextensions_2fmessage_5foptions_2eproto();
  }
} static_descriptor_initializer_global_5fextensions_2fmessage_5foptions_2eproto_;
// ===================================================================

#ifndef _MSC_VER
const int BGSMessageOptions::kCustomSelectShardFieldNumber;
const int BGSMessageOptions::kCustomValidatorFieldNumber;
#endif  // !_MSC_VER

BGSMessageOptions::BGSMessageOptions()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.BGSMessageOptions)
}

void BGSMessageOptions::InitAsDefaultInstance() {
}

BGSMessageOptions::BGSMessageOptions(const BGSMessageOptions& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.BGSMessageOptions)
}

void BGSMessageOptions::SharedCtor() {
  _cached_size_ = 0;
  custom_select_shard_ = false;
  custom_validator_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BGSMessageOptions::~BGSMessageOptions() {
  // @@protoc_insertion_point(destructor:bgs.protocol.BGSMessageOptions)
  SharedDtor();
}

void BGSMessageOptions::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BGSMessageOptions::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BGSMessageOptions::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BGSMessageOptions_descriptor_;
}

const BGSMessageOptions& BGSMessageOptions::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_global_5fextensions_2fmessage_5foptions_2eproto();
  return *default_instance_;
}

BGSMessageOptions* BGSMessageOptions::default_instance_ = NULL;

BGSMessageOptions* BGSMessageOptions::New() const {
  return new BGSMessageOptions;
}

void BGSMessageOptions::Swap(BGSMessageOptions* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata BGSMessageOptions::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BGSMessageOptions_descriptor_;
  metadata.reflection = BGSMessageOptions_reflection_;
  return metadata;
}

::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::MessageOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::bgs::protocol::BGSMessageOptions >, 11, false >
  message_options(kMessageOptionsFieldNumber, ::bgs::protocol::BGSMessageOptions::default_instance());
// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)