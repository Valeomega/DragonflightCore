// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: embed_types.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "embed_types.pb.h"

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

const ::google::protobuf::Descriptor* EmbedImage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EmbedImage_reflection_ = NULL;
const ::google::protobuf::Descriptor* Provider_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Provider_reflection_ = NULL;
const ::google::protobuf::Descriptor* EmbedHTML_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EmbedHTML_reflection_ = NULL;
const ::google::protobuf::Descriptor* EmbedInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EmbedInfo_reflection_ = NULL;

}  // namespace

void protobuf_AssignDesc_embed_5ftypes_2eproto() {
  protobuf_AddDesc_embed_5ftypes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "embed_types.proto");
  GOOGLE_CHECK(file != NULL);
  EmbedImage_descriptor_ = file->message_type(0);
  static const int EmbedImage_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedImage, url_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedImage, width_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedImage, height_),
  };
  EmbedImage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EmbedImage_descriptor_,
      EmbedImage::default_instance_,
      EmbedImage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedImage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedImage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EmbedImage));
  Provider_descriptor_ = file->message_type(1);
  static const int Provider_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Provider, name_),
  };
  Provider_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Provider_descriptor_,
      Provider::default_instance_,
      Provider_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Provider, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Provider, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Provider));
  EmbedHTML_descriptor_ = file->message_type(2);
  static const int EmbedHTML_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedHTML, content_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedHTML, width_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedHTML, height_),
  };
  EmbedHTML_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EmbedHTML_descriptor_,
      EmbedHTML::default_instance_,
      EmbedHTML_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedHTML, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedHTML, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EmbedHTML));
  EmbedInfo_descriptor_ = file->message_type(3);
  static const int EmbedInfo_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, title_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, original_url_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, thumbnail_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, provider_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, description_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, html_),
  };
  EmbedInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EmbedInfo_descriptor_,
      EmbedInfo::default_instance_,
      EmbedInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EmbedInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EmbedInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_embed_5ftypes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EmbedImage_descriptor_, &EmbedImage::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Provider_descriptor_, &Provider::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EmbedHTML_descriptor_, &EmbedHTML::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EmbedInfo_descriptor_, &EmbedInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_embed_5ftypes_2eproto() {
  delete EmbedImage::default_instance_;
  delete EmbedImage_reflection_;
  delete Provider::default_instance_;
  delete Provider_reflection_;
  delete EmbedHTML::default_instance_;
  delete EmbedHTML_reflection_;
  delete EmbedInfo::default_instance_;
  delete EmbedInfo_reflection_;
}

void protobuf_AddDesc_embed_5ftypes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021embed_types.proto\022\014bgs.protocol\"8\n\nEmb"
    "edImage\022\013\n\003url\030\001 \001(\t\022\r\n\005width\030\002 \001(\r\022\016\n\006h"
    "eight\030\003 \001(\r\"\030\n\010Provider\022\014\n\004name\030\001 \001(\t\";\n"
    "\tEmbedHTML\022\017\n\007content\030\001 \001(\t\022\r\n\005width\030\002 \001"
    "(\r\022\016\n\006height\030\003 \001(\r\"\321\001\n\tEmbedInfo\022\r\n\005titl"
    "e\030\001 \001(\t\022\014\n\004type\030\002 \001(\t\022\024\n\014original_url\030\003 "
    "\001(\t\022+\n\tthumbnail\030\004 \001(\0132\030.bgs.protocol.Em"
    "bedImage\022(\n\010provider\030\005 \001(\0132\026.bgs.protoco"
    "l.Provider\022\023\n\013description\030\006 \001(\t\022%\n\004html\030"
    "\010 \001(\0132\027.bgs.protocol.EmbedHTMLB\002H\002", 394);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "embed_types.proto", &protobuf_RegisterTypes);
  EmbedImage::default_instance_ = new EmbedImage();
  Provider::default_instance_ = new Provider();
  EmbedHTML::default_instance_ = new EmbedHTML();
  EmbedInfo::default_instance_ = new EmbedInfo();
  EmbedImage::default_instance_->InitAsDefaultInstance();
  Provider::default_instance_->InitAsDefaultInstance();
  EmbedHTML::default_instance_->InitAsDefaultInstance();
  EmbedInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_embed_5ftypes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_embed_5ftypes_2eproto {
  StaticDescriptorInitializer_embed_5ftypes_2eproto() {
    protobuf_AddDesc_embed_5ftypes_2eproto();
  }
} static_descriptor_initializer_embed_5ftypes_2eproto_;
// ===================================================================

#ifndef _MSC_VER
const int EmbedImage::kUrlFieldNumber;
const int EmbedImage::kWidthFieldNumber;
const int EmbedImage::kHeightFieldNumber;
#endif  // !_MSC_VER

EmbedImage::EmbedImage()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.EmbedImage)
}

void EmbedImage::InitAsDefaultInstance() {
}

EmbedImage::EmbedImage(const EmbedImage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.EmbedImage)
}

void EmbedImage::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  url_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  width_ = 0u;
  height_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EmbedImage::~EmbedImage() {
  // @@protoc_insertion_point(destructor:bgs.protocol.EmbedImage)
  SharedDtor();
}

void EmbedImage::SharedDtor() {
  if (url_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete url_;
  }
  if (this != default_instance_) {
  }
}

void EmbedImage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EmbedImage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EmbedImage_descriptor_;
}

const EmbedImage& EmbedImage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_embed_5ftypes_2eproto();
  return *default_instance_;
}

EmbedImage* EmbedImage::default_instance_ = NULL;

EmbedImage* EmbedImage::New() const {
  return new EmbedImage;
}

void EmbedImage::Swap(EmbedImage* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata EmbedImage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EmbedImage_descriptor_;
  metadata.reflection = EmbedImage_reflection_;
  return metadata;
}

// ===================================================================

#ifndef _MSC_VER
const int Provider::kNameFieldNumber;
#endif  // !_MSC_VER

Provider::Provider()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.Provider)
}

void Provider::InitAsDefaultInstance() {
}

Provider::Provider(const Provider& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.Provider)
}

void Provider::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Provider::~Provider() {
  // @@protoc_insertion_point(destructor:bgs.protocol.Provider)
  SharedDtor();
}

void Provider::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void Provider::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Provider::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Provider_descriptor_;
}

const Provider& Provider::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_embed_5ftypes_2eproto();
  return *default_instance_;
}

Provider* Provider::default_instance_ = NULL;

Provider* Provider::New() const {
  return new Provider;
}

void Provider::Swap(Provider* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata Provider::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Provider_descriptor_;
  metadata.reflection = Provider_reflection_;
  return metadata;
}

// ===================================================================

#ifndef _MSC_VER
const int EmbedHTML::kContentFieldNumber;
const int EmbedHTML::kWidthFieldNumber;
const int EmbedHTML::kHeightFieldNumber;
#endif  // !_MSC_VER

EmbedHTML::EmbedHTML()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.EmbedHTML)
}

void EmbedHTML::InitAsDefaultInstance() {
}

EmbedHTML::EmbedHTML(const EmbedHTML& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.EmbedHTML)
}

void EmbedHTML::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  content_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  width_ = 0u;
  height_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EmbedHTML::~EmbedHTML() {
  // @@protoc_insertion_point(destructor:bgs.protocol.EmbedHTML)
  SharedDtor();
}

void EmbedHTML::SharedDtor() {
  if (content_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete content_;
  }
  if (this != default_instance_) {
  }
}

void EmbedHTML::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EmbedHTML::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EmbedHTML_descriptor_;
}

const EmbedHTML& EmbedHTML::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_embed_5ftypes_2eproto();
  return *default_instance_;
}

EmbedHTML* EmbedHTML::default_instance_ = NULL;

EmbedHTML* EmbedHTML::New() const {
  return new EmbedHTML;
}

void EmbedHTML::Swap(EmbedHTML* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata EmbedHTML::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EmbedHTML_descriptor_;
  metadata.reflection = EmbedHTML_reflection_;
  return metadata;
}

// ===================================================================

#ifndef _MSC_VER
const int EmbedInfo::kTitleFieldNumber;
const int EmbedInfo::kTypeFieldNumber;
const int EmbedInfo::kOriginalUrlFieldNumber;
const int EmbedInfo::kThumbnailFieldNumber;
const int EmbedInfo::kProviderFieldNumber;
const int EmbedInfo::kDescriptionFieldNumber;
const int EmbedInfo::kHtmlFieldNumber;
#endif  // !_MSC_VER

EmbedInfo::EmbedInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.EmbedInfo)
}

void EmbedInfo::InitAsDefaultInstance() {
  thumbnail_ = const_cast< ::bgs::protocol::EmbedImage*>(&::bgs::protocol::EmbedImage::default_instance());
  provider_ = const_cast< ::bgs::protocol::Provider*>(&::bgs::protocol::Provider::default_instance());
  html_ = const_cast< ::bgs::protocol::EmbedHTML*>(&::bgs::protocol::EmbedHTML::default_instance());
}

EmbedInfo::EmbedInfo(const EmbedInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.EmbedInfo)
}

void EmbedInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  title_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  original_url_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  thumbnail_ = NULL;
  provider_ = NULL;
  description_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  html_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EmbedInfo::~EmbedInfo() {
  // @@protoc_insertion_point(destructor:bgs.protocol.EmbedInfo)
  SharedDtor();
}

void EmbedInfo::SharedDtor() {
  if (title_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete title_;
  }
  if (type_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete type_;
  }
  if (original_url_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete original_url_;
  }
  if (description_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete description_;
  }
  if (this != default_instance_) {
    delete thumbnail_;
    delete provider_;
    delete html_;
  }
}

void EmbedInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EmbedInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EmbedInfo_descriptor_;
}

const EmbedInfo& EmbedInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_embed_5ftypes_2eproto();
  return *default_instance_;
}

EmbedInfo* EmbedInfo::default_instance_ = NULL;

EmbedInfo* EmbedInfo::New() const {
  return new EmbedInfo;
}

void EmbedInfo::Swap(EmbedInfo* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata EmbedInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EmbedInfo_descriptor_;
  metadata.reflection = EmbedInfo_reflection_;
  return metadata;
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)