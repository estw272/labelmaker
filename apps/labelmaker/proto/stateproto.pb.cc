// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: stateproto.proto

#include "pch.h"
#include "stateproto.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_stateproto_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ImageInfoProto_stateproto_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_stateproto_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TagProto_stateproto_2eproto;
class TagProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TagProto> _instance;
} _TagProto_default_instance_;
class ImageInfoProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ImageInfoProto> _instance;
} _ImageInfoProto_default_instance_;
class StateProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<StateProto> _instance;
} _StateProto_default_instance_;
static void InitDefaultsscc_info_ImageInfoProto_stateproto_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ImageInfoProto_default_instance_;
    new (ptr) ::ImageInfoProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ImageInfoProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ImageInfoProto_stateproto_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_ImageInfoProto_stateproto_2eproto}, {
      &scc_info_TagProto_stateproto_2eproto.base,}};

static void InitDefaultsscc_info_StateProto_stateproto_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_StateProto_default_instance_;
    new (ptr) ::StateProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::StateProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_StateProto_stateproto_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_StateProto_stateproto_2eproto}, {
      &scc_info_ImageInfoProto_stateproto_2eproto.base,}};

static void InitDefaultsscc_info_TagProto_stateproto_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_TagProto_default_instance_;
    new (ptr) ::TagProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::TagProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TagProto_stateproto_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_TagProto_stateproto_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_stateproto_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_stateproto_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_stateproto_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_stateproto_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::TagProto, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::TagProto, tag_name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ImageInfoProto, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ImageInfoProto, path_),
  PROTOBUF_FIELD_OFFSET(::ImageInfoProto, tags_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::StateProto, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::StateProto, image_info_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::TagProto)},
  { 6, -1, sizeof(::ImageInfoProto)},
  { 13, -1, sizeof(::StateProto)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_TagProto_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ImageInfoProto_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_StateProto_default_instance_),
};

const char descriptor_table_protodef_stateproto_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020stateproto.proto\"\034\n\010TagProto\022\020\n\010tag_na"
  "me\030\001 \001(\t\"7\n\016ImageInfoProto\022\014\n\004path\030\001 \001(\t"
  "\022\027\n\004tags\030\002 \003(\0132\t.TagProto\"1\n\nStateProto\022"
  "#\n\nimage_info\030\001 \003(\0132\017.ImageInfoProtob\006pr"
  "oto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_stateproto_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_stateproto_2eproto_sccs[3] = {
  &scc_info_ImageInfoProto_stateproto_2eproto.base,
  &scc_info_StateProto_stateproto_2eproto.base,
  &scc_info_TagProto_stateproto_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_stateproto_2eproto_once;
static bool descriptor_table_stateproto_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_stateproto_2eproto = {
  &descriptor_table_stateproto_2eproto_initialized, descriptor_table_protodef_stateproto_2eproto, "stateproto.proto", 164,
  &descriptor_table_stateproto_2eproto_once, descriptor_table_stateproto_2eproto_sccs, descriptor_table_stateproto_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_stateproto_2eproto::offsets,
  file_level_metadata_stateproto_2eproto, 3, file_level_enum_descriptors_stateproto_2eproto, file_level_service_descriptors_stateproto_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_stateproto_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_stateproto_2eproto), true);

// ===================================================================

void TagProto::InitAsDefaultInstance() {
}
class TagProto::_Internal {
 public:
};

TagProto::TagProto()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:TagProto)
}
TagProto::TagProto(const TagProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  tag_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_tag_name().empty()) {
    tag_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.tag_name_);
  }
  // @@protoc_insertion_point(copy_constructor:TagProto)
}

void TagProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TagProto_stateproto_2eproto.base);
  tag_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

TagProto::~TagProto() {
  // @@protoc_insertion_point(destructor:TagProto)
  SharedDtor();
}

void TagProto::SharedDtor() {
  tag_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void TagProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TagProto& TagProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TagProto_stateproto_2eproto.base);
  return *internal_default_instance();
}


void TagProto::Clear() {
// @@protoc_insertion_point(message_clear_start:TagProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  tag_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* TagProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string tag_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_mutable_tag_name(), ptr, ctx, "TagProto.tag_name");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* TagProto::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:TagProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string tag_name = 1;
  if (this->tag_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_tag_name().data(), static_cast<int>(this->_internal_tag_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "TagProto.tag_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_tag_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TagProto)
  return target;
}

size_t TagProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TagProto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string tag_name = 1;
  if (this->tag_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_tag_name());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TagProto::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:TagProto)
  GOOGLE_DCHECK_NE(&from, this);
  const TagProto* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<TagProto>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:TagProto)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:TagProto)
    MergeFrom(*source);
  }
}

void TagProto::MergeFrom(const TagProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TagProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.tag_name().size() > 0) {

    tag_name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.tag_name_);
  }
}

void TagProto::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:TagProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TagProto::CopyFrom(const TagProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TagProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TagProto::IsInitialized() const {
  return true;
}

void TagProto::InternalSwap(TagProto* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  tag_name_.Swap(&other->tag_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata TagProto::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ImageInfoProto::InitAsDefaultInstance() {
}
class ImageInfoProto::_Internal {
 public:
};

ImageInfoProto::ImageInfoProto()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ImageInfoProto)
}
ImageInfoProto::ImageInfoProto(const ImageInfoProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      tags_(from.tags_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_path().empty()) {
    path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
  // @@protoc_insertion_point(copy_constructor:ImageInfoProto)
}

void ImageInfoProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ImageInfoProto_stateproto_2eproto.base);
  path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

ImageInfoProto::~ImageInfoProto() {
  // @@protoc_insertion_point(destructor:ImageInfoProto)
  SharedDtor();
}

void ImageInfoProto::SharedDtor() {
  path_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ImageInfoProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ImageInfoProto& ImageInfoProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ImageInfoProto_stateproto_2eproto.base);
  return *internal_default_instance();
}


void ImageInfoProto::Clear() {
// @@protoc_insertion_point(message_clear_start:ImageInfoProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  tags_.Clear();
  path_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* ImageInfoProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string path = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_mutable_path(), ptr, ctx, "ImageInfoProto.path");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .TagProto tags = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_tags(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ImageInfoProto::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ImageInfoProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string path = 1;
  if (this->path().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_path().data(), static_cast<int>(this->_internal_path().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ImageInfoProto.path");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_path(), target);
  }

  // repeated .TagProto tags = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_tags_size()); i < n; i++) {
    stream->EnsureSpace(&target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(2, this->_internal_tags(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ImageInfoProto)
  return target;
}

size_t ImageInfoProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ImageInfoProto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .TagProto tags = 2;
  total_size += 1UL * this->_internal_tags_size();
  for (const auto& msg : this->tags_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string path = 1;
  if (this->path().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_path());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ImageInfoProto::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ImageInfoProto)
  GOOGLE_DCHECK_NE(&from, this);
  const ImageInfoProto* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ImageInfoProto>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ImageInfoProto)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ImageInfoProto)
    MergeFrom(*source);
  }
}

void ImageInfoProto::MergeFrom(const ImageInfoProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ImageInfoProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  tags_.MergeFrom(from.tags_);
  if (from.path().size() > 0) {

    path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
}

void ImageInfoProto::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ImageInfoProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ImageInfoProto::CopyFrom(const ImageInfoProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ImageInfoProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ImageInfoProto::IsInitialized() const {
  return true;
}

void ImageInfoProto::InternalSwap(ImageInfoProto* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  tags_.InternalSwap(&other->tags_);
  path_.Swap(&other->path_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata ImageInfoProto::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void StateProto::InitAsDefaultInstance() {
}
class StateProto::_Internal {
 public:
};

StateProto::StateProto()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:StateProto)
}
StateProto::StateProto(const StateProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      image_info_(from.image_info_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:StateProto)
}

void StateProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_StateProto_stateproto_2eproto.base);
}

StateProto::~StateProto() {
  // @@protoc_insertion_point(destructor:StateProto)
  SharedDtor();
}

void StateProto::SharedDtor() {
}

void StateProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const StateProto& StateProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_StateProto_stateproto_2eproto.base);
  return *internal_default_instance();
}


void StateProto::Clear() {
// @@protoc_insertion_point(message_clear_start:StateProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  image_info_.Clear();
  _internal_metadata_.Clear();
}

const char* StateProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .ImageInfoProto image_info = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_image_info(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* StateProto::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:StateProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .ImageInfoProto image_info = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_image_info_size()); i < n; i++) {
    stream->EnsureSpace(&target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(1, this->_internal_image_info(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:StateProto)
  return target;
}

size_t StateProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:StateProto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .ImageInfoProto image_info = 1;
  total_size += 1UL * this->_internal_image_info_size();
  for (const auto& msg : this->image_info_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void StateProto::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:StateProto)
  GOOGLE_DCHECK_NE(&from, this);
  const StateProto* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<StateProto>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:StateProto)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:StateProto)
    MergeFrom(*source);
  }
}

void StateProto::MergeFrom(const StateProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:StateProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  image_info_.MergeFrom(from.image_info_);
}

void StateProto::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:StateProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StateProto::CopyFrom(const StateProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:StateProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StateProto::IsInitialized() const {
  return true;
}

void StateProto::InternalSwap(StateProto* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  image_info_.InternalSwap(&other->image_info_);
}

::PROTOBUF_NAMESPACE_ID::Metadata StateProto::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::TagProto* Arena::CreateMaybeMessage< ::TagProto >(Arena* arena) {
  return Arena::CreateInternal< ::TagProto >(arena);
}
template<> PROTOBUF_NOINLINE ::ImageInfoProto* Arena::CreateMaybeMessage< ::ImageInfoProto >(Arena* arena) {
  return Arena::CreateInternal< ::ImageInfoProto >(arena);
}
template<> PROTOBUF_NOINLINE ::StateProto* Arena::CreateMaybeMessage< ::StateProto >(Arena* arena) {
  return Arena::CreateInternal< ::StateProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>