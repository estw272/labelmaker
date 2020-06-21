// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protoimageinfo.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protoimageinfo_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protoimageinfo_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3010000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3010000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "prototag.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_protoimageinfo_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protoimageinfo_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_protoimageinfo_2eproto;
class ProtoImageInfo;
class ProtoImageInfoDefaultTypeInternal;
extern ProtoImageInfoDefaultTypeInternal _ProtoImageInfo_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::ProtoImageInfo* Arena::CreateMaybeMessage<::ProtoImageInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class ProtoImageInfo :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ProtoImageInfo) */ {
 public:
  ProtoImageInfo();
  virtual ~ProtoImageInfo();

  ProtoImageInfo(const ProtoImageInfo& from);
  ProtoImageInfo(ProtoImageInfo&& from) noexcept
    : ProtoImageInfo() {
    *this = ::std::move(from);
  }

  inline ProtoImageInfo& operator=(const ProtoImageInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline ProtoImageInfo& operator=(ProtoImageInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ProtoImageInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ProtoImageInfo* internal_default_instance() {
    return reinterpret_cast<const ProtoImageInfo*>(
               &_ProtoImageInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ProtoImageInfo& a, ProtoImageInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(ProtoImageInfo* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ProtoImageInfo* New() const final {
    return CreateMaybeMessage<ProtoImageInfo>(nullptr);
  }

  ProtoImageInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ProtoImageInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ProtoImageInfo& from);
  void MergeFrom(const ProtoImageInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ProtoImageInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ProtoImageInfo";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_protoimageinfo_2eproto);
    return ::descriptor_table_protoimageinfo_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTagsFieldNumber = 2,
    kFilenameFieldNumber = 1,
  };
  // repeated .ProtoTag tags = 2;
  int tags_size() const;
  private:
  int _internal_tags_size() const;
  public:
  void clear_tags();
  ::ProtoTag* mutable_tags(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtoTag >*
      mutable_tags();
  private:
  const ::ProtoTag& _internal_tags(int index) const;
  ::ProtoTag* _internal_add_tags();
  public:
  const ::ProtoTag& tags(int index) const;
  ::ProtoTag* add_tags();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtoTag >&
      tags() const;

  // string filename = 1;
  void clear_filename();
  const std::string& filename() const;
  void set_filename(const std::string& value);
  void set_filename(std::string&& value);
  void set_filename(const char* value);
  void set_filename(const char* value, size_t size);
  std::string* mutable_filename();
  std::string* release_filename();
  void set_allocated_filename(std::string* filename);
  private:
  const std::string& _internal_filename() const;
  void _internal_set_filename(const std::string& value);
  std::string* _internal_mutable_filename();
  public:

  // @@protoc_insertion_point(class_scope:ProtoImageInfo)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtoTag > tags_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr filename_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_protoimageinfo_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ProtoImageInfo

// string filename = 1;
inline void ProtoImageInfo::clear_filename() {
  filename_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ProtoImageInfo::filename() const {
  // @@protoc_insertion_point(field_get:ProtoImageInfo.filename)
  return _internal_filename();
}
inline void ProtoImageInfo::set_filename(const std::string& value) {
  _internal_set_filename(value);
  // @@protoc_insertion_point(field_set:ProtoImageInfo.filename)
}
inline std::string* ProtoImageInfo::mutable_filename() {
  // @@protoc_insertion_point(field_mutable:ProtoImageInfo.filename)
  return _internal_mutable_filename();
}
inline const std::string& ProtoImageInfo::_internal_filename() const {
  return filename_.GetNoArena();
}
inline void ProtoImageInfo::_internal_set_filename(const std::string& value) {
  
  filename_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ProtoImageInfo::set_filename(std::string&& value) {
  
  filename_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ProtoImageInfo.filename)
}
inline void ProtoImageInfo::set_filename(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  filename_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ProtoImageInfo.filename)
}
inline void ProtoImageInfo::set_filename(const char* value, size_t size) {
  
  filename_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ProtoImageInfo.filename)
}
inline std::string* ProtoImageInfo::_internal_mutable_filename() {
  
  return filename_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ProtoImageInfo::release_filename() {
  // @@protoc_insertion_point(field_release:ProtoImageInfo.filename)
  
  return filename_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ProtoImageInfo::set_allocated_filename(std::string* filename) {
  if (filename != nullptr) {
    
  } else {
    
  }
  filename_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), filename);
  // @@protoc_insertion_point(field_set_allocated:ProtoImageInfo.filename)
}

// repeated .ProtoTag tags = 2;
inline int ProtoImageInfo::_internal_tags_size() const {
  return tags_.size();
}
inline int ProtoImageInfo::tags_size() const {
  return _internal_tags_size();
}
inline ::ProtoTag* ProtoImageInfo::mutable_tags(int index) {
  // @@protoc_insertion_point(field_mutable:ProtoImageInfo.tags)
  return tags_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtoTag >*
ProtoImageInfo::mutable_tags() {
  // @@protoc_insertion_point(field_mutable_list:ProtoImageInfo.tags)
  return &tags_;
}
inline const ::ProtoTag& ProtoImageInfo::_internal_tags(int index) const {
  return tags_.Get(index);
}
inline const ::ProtoTag& ProtoImageInfo::tags(int index) const {
  // @@protoc_insertion_point(field_get:ProtoImageInfo.tags)
  return _internal_tags(index);
}
inline ::ProtoTag* ProtoImageInfo::_internal_add_tags() {
  return tags_.Add();
}
inline ::ProtoTag* ProtoImageInfo::add_tags() {
  // @@protoc_insertion_point(field_add:ProtoImageInfo.tags)
  return _internal_add_tags();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProtoTag >&
ProtoImageInfo::tags() const {
  // @@protoc_insertion_point(field_list:ProtoImageInfo.tags)
  return tags_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protoimageinfo_2eproto
