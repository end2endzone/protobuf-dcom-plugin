// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dcomplugin.proto

#ifndef PROTOBUF_dcomplugin_2eproto__INCLUDED
#define PROTOBUF_dcomplugin_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "google/protobuf/descriptor.pb.h"
// @@protoc_insertion_point(includes)

namespace dcomplugin {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_dcomplugin_2eproto();
void protobuf_AssignDesc_dcomplugin_2eproto();
void protobuf_ShutdownFile_dcomplugin_2eproto();

class Identifier;
class CoClass;
class CoInterface;
class TypeLib;
class Component;

// ===================================================================

class Identifier : public ::google::protobuf::Message {
 public:
  Identifier();
  virtual ~Identifier();

  Identifier(const Identifier& from);

  inline Identifier& operator=(const Identifier& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Identifier& default_instance();

  void Swap(Identifier* other);

  // implements Message ----------------------------------------------

  Identifier* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Identifier& from);
  void MergeFrom(const Identifier& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string guid = 1;
  inline bool has_guid() const;
  inline void clear_guid();
  static const int kGuidFieldNumber = 1;
  inline const ::std::string& guid() const;
  inline void set_guid(const ::std::string& value);
  inline void set_guid(const char* value);
  inline void set_guid(const char* value, size_t size);
  inline ::std::string* mutable_guid();
  inline ::std::string* release_guid();
  inline void set_allocated_guid(::std::string* guid);

  // optional string helpstring = 2;
  inline bool has_helpstring() const;
  inline void clear_helpstring();
  static const int kHelpstringFieldNumber = 2;
  inline const ::std::string& helpstring() const;
  inline void set_helpstring(const ::std::string& value);
  inline void set_helpstring(const char* value);
  inline void set_helpstring(const char* value, size_t size);
  inline ::std::string* mutable_helpstring();
  inline ::std::string* release_helpstring();
  inline void set_allocated_helpstring(::std::string* helpstring);

  // @@protoc_insertion_point(class_scope:dcomplugin.Identifier)
 private:
  inline void set_has_guid();
  inline void clear_has_guid();
  inline void set_has_helpstring();
  inline void clear_has_helpstring();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* guid_;
  ::std::string* helpstring_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_dcomplugin_2eproto();
  friend void protobuf_AssignDesc_dcomplugin_2eproto();
  friend void protobuf_ShutdownFile_dcomplugin_2eproto();

  void InitAsDefaultInstance();
  static Identifier* default_instance_;
};
// -------------------------------------------------------------------

class CoClass : public ::google::protobuf::Message {
 public:
  CoClass();
  virtual ~CoClass();

  CoClass(const CoClass& from);

  inline CoClass& operator=(const CoClass& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CoClass& default_instance();

  void Swap(CoClass* other);

  // implements Message ----------------------------------------------

  CoClass* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CoClass& from);
  void MergeFrom(const CoClass& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional string friendlyname = 2;
  inline bool has_friendlyname() const;
  inline void clear_friendlyname();
  static const int kFriendlynameFieldNumber = 2;
  inline const ::std::string& friendlyname() const;
  inline void set_friendlyname(const ::std::string& value);
  inline void set_friendlyname(const char* value);
  inline void set_friendlyname(const char* value, size_t size);
  inline ::std::string* mutable_friendlyname();
  inline ::std::string* release_friendlyname();
  inline void set_allocated_friendlyname(::std::string* friendlyname);

  // optional .dcomplugin.Identifier id = 3;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 3;
  inline const ::dcomplugin::Identifier& id() const;
  inline ::dcomplugin::Identifier* mutable_id();
  inline ::dcomplugin::Identifier* release_id();
  inline void set_allocated_id(::dcomplugin::Identifier* id);

  // @@protoc_insertion_point(class_scope:dcomplugin.CoClass)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_friendlyname();
  inline void clear_has_friendlyname();
  inline void set_has_id();
  inline void clear_has_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::std::string* friendlyname_;
  ::dcomplugin::Identifier* id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_dcomplugin_2eproto();
  friend void protobuf_AssignDesc_dcomplugin_2eproto();
  friend void protobuf_ShutdownFile_dcomplugin_2eproto();

  void InitAsDefaultInstance();
  static CoClass* default_instance_;
};
// -------------------------------------------------------------------

class CoInterface : public ::google::protobuf::Message {
 public:
  CoInterface();
  virtual ~CoInterface();

  CoInterface(const CoInterface& from);

  inline CoInterface& operator=(const CoInterface& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CoInterface& default_instance();

  void Swap(CoInterface* other);

  // implements Message ----------------------------------------------

  CoInterface* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CoInterface& from);
  void MergeFrom(const CoInterface& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .dcomplugin.Identifier id = 3;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 3;
  inline const ::dcomplugin::Identifier& id() const;
  inline ::dcomplugin::Identifier* mutable_id();
  inline ::dcomplugin::Identifier* release_id();
  inline void set_allocated_id(::dcomplugin::Identifier* id);

  // @@protoc_insertion_point(class_scope:dcomplugin.CoInterface)
 private:
  inline void set_has_id();
  inline void clear_has_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::dcomplugin::Identifier* id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_dcomplugin_2eproto();
  friend void protobuf_AssignDesc_dcomplugin_2eproto();
  friend void protobuf_ShutdownFile_dcomplugin_2eproto();

  void InitAsDefaultInstance();
  static CoInterface* default_instance_;
};
// -------------------------------------------------------------------

class TypeLib : public ::google::protobuf::Message {
 public:
  TypeLib();
  virtual ~TypeLib();

  TypeLib(const TypeLib& from);

  inline TypeLib& operator=(const TypeLib& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TypeLib& default_instance();

  void Swap(TypeLib* other);

  // implements Message ----------------------------------------------

  TypeLib* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TypeLib& from);
  void MergeFrom(const TypeLib& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional .dcomplugin.Identifier id = 2;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 2;
  inline const ::dcomplugin::Identifier& id() const;
  inline ::dcomplugin::Identifier* mutable_id();
  inline ::dcomplugin::Identifier* release_id();
  inline void set_allocated_id(::dcomplugin::Identifier* id);

  // optional .dcomplugin.CoInterface cointerface = 3;
  inline bool has_cointerface() const;
  inline void clear_cointerface();
  static const int kCointerfaceFieldNumber = 3;
  inline const ::dcomplugin::CoInterface& cointerface() const;
  inline ::dcomplugin::CoInterface* mutable_cointerface();
  inline ::dcomplugin::CoInterface* release_cointerface();
  inline void set_allocated_cointerface(::dcomplugin::CoInterface* cointerface);

  // optional .dcomplugin.CoClass coclass = 4;
  inline bool has_coclass() const;
  inline void clear_coclass();
  static const int kCoclassFieldNumber = 4;
  inline const ::dcomplugin::CoClass& coclass() const;
  inline ::dcomplugin::CoClass* mutable_coclass();
  inline ::dcomplugin::CoClass* release_coclass();
  inline void set_allocated_coclass(::dcomplugin::CoClass* coclass);

  // @@protoc_insertion_point(class_scope:dcomplugin.TypeLib)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_cointerface();
  inline void clear_has_cointerface();
  inline void set_has_coclass();
  inline void clear_has_coclass();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::dcomplugin::Identifier* id_;
  ::dcomplugin::CoInterface* cointerface_;
  ::dcomplugin::CoClass* coclass_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_dcomplugin_2eproto();
  friend void protobuf_AssignDesc_dcomplugin_2eproto();
  friend void protobuf_ShutdownFile_dcomplugin_2eproto();

  void InitAsDefaultInstance();
  static TypeLib* default_instance_;
};
// -------------------------------------------------------------------

class Component : public ::google::protobuf::Message {
 public:
  Component();
  virtual ~Component();

  Component(const Component& from);

  inline Component& operator=(const Component& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Component& default_instance();

  void Swap(Component* other);

  // implements Message ----------------------------------------------

  Component* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Component& from);
  void MergeFrom(const Component& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional .dcomplugin.TypeLib typelib = 2;
  inline bool has_typelib() const;
  inline void clear_typelib();
  static const int kTypelibFieldNumber = 2;
  inline const ::dcomplugin::TypeLib& typelib() const;
  inline ::dcomplugin::TypeLib* mutable_typelib();
  inline ::dcomplugin::TypeLib* release_typelib();
  inline void set_allocated_typelib(::dcomplugin::TypeLib* typelib);

  // optional .dcomplugin.Identifier appid = 3;
  inline bool has_appid() const;
  inline void clear_appid();
  static const int kAppidFieldNumber = 3;
  inline const ::dcomplugin::Identifier& appid() const;
  inline ::dcomplugin::Identifier* mutable_appid();
  inline ::dcomplugin::Identifier* release_appid();
  inline void set_allocated_appid(::dcomplugin::Identifier* appid);

  // @@protoc_insertion_point(class_scope:dcomplugin.Component)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_typelib();
  inline void clear_has_typelib();
  inline void set_has_appid();
  inline void clear_has_appid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::dcomplugin::TypeLib* typelib_;
  ::dcomplugin::Identifier* appid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_dcomplugin_2eproto();
  friend void protobuf_AssignDesc_dcomplugin_2eproto();
  friend void protobuf_ShutdownFile_dcomplugin_2eproto();

  void InitAsDefaultInstance();
  static Component* default_instance_;
};
// ===================================================================

static const int kComponentFieldNumber = 50000;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::FileOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::dcomplugin::Component >, 11, false >
  component;

// ===================================================================

// Identifier

// optional string guid = 1;
inline bool Identifier::has_guid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Identifier::set_has_guid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Identifier::clear_has_guid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Identifier::clear_guid() {
  if (guid_ != &::google::protobuf::internal::kEmptyString) {
    guid_->clear();
  }
  clear_has_guid();
}
inline const ::std::string& Identifier::guid() const {
  return *guid_;
}
inline void Identifier::set_guid(const ::std::string& value) {
  set_has_guid();
  if (guid_ == &::google::protobuf::internal::kEmptyString) {
    guid_ = new ::std::string;
  }
  guid_->assign(value);
}
inline void Identifier::set_guid(const char* value) {
  set_has_guid();
  if (guid_ == &::google::protobuf::internal::kEmptyString) {
    guid_ = new ::std::string;
  }
  guid_->assign(value);
}
inline void Identifier::set_guid(const char* value, size_t size) {
  set_has_guid();
  if (guid_ == &::google::protobuf::internal::kEmptyString) {
    guid_ = new ::std::string;
  }
  guid_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Identifier::mutable_guid() {
  set_has_guid();
  if (guid_ == &::google::protobuf::internal::kEmptyString) {
    guid_ = new ::std::string;
  }
  return guid_;
}
inline ::std::string* Identifier::release_guid() {
  clear_has_guid();
  if (guid_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = guid_;
    guid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Identifier::set_allocated_guid(::std::string* guid) {
  if (guid_ != &::google::protobuf::internal::kEmptyString) {
    delete guid_;
  }
  if (guid) {
    set_has_guid();
    guid_ = guid;
  } else {
    clear_has_guid();
    guid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string helpstring = 2;
inline bool Identifier::has_helpstring() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Identifier::set_has_helpstring() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Identifier::clear_has_helpstring() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Identifier::clear_helpstring() {
  if (helpstring_ != &::google::protobuf::internal::kEmptyString) {
    helpstring_->clear();
  }
  clear_has_helpstring();
}
inline const ::std::string& Identifier::helpstring() const {
  return *helpstring_;
}
inline void Identifier::set_helpstring(const ::std::string& value) {
  set_has_helpstring();
  if (helpstring_ == &::google::protobuf::internal::kEmptyString) {
    helpstring_ = new ::std::string;
  }
  helpstring_->assign(value);
}
inline void Identifier::set_helpstring(const char* value) {
  set_has_helpstring();
  if (helpstring_ == &::google::protobuf::internal::kEmptyString) {
    helpstring_ = new ::std::string;
  }
  helpstring_->assign(value);
}
inline void Identifier::set_helpstring(const char* value, size_t size) {
  set_has_helpstring();
  if (helpstring_ == &::google::protobuf::internal::kEmptyString) {
    helpstring_ = new ::std::string;
  }
  helpstring_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Identifier::mutable_helpstring() {
  set_has_helpstring();
  if (helpstring_ == &::google::protobuf::internal::kEmptyString) {
    helpstring_ = new ::std::string;
  }
  return helpstring_;
}
inline ::std::string* Identifier::release_helpstring() {
  clear_has_helpstring();
  if (helpstring_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = helpstring_;
    helpstring_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Identifier::set_allocated_helpstring(::std::string* helpstring) {
  if (helpstring_ != &::google::protobuf::internal::kEmptyString) {
    delete helpstring_;
  }
  if (helpstring) {
    set_has_helpstring();
    helpstring_ = helpstring;
  } else {
    clear_has_helpstring();
    helpstring_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// CoClass

// optional string name = 1;
inline bool CoClass::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CoClass::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CoClass::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CoClass::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& CoClass::name() const {
  return *name_;
}
inline void CoClass::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void CoClass::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void CoClass::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CoClass::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* CoClass::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CoClass::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string friendlyname = 2;
inline bool CoClass::has_friendlyname() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CoClass::set_has_friendlyname() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CoClass::clear_has_friendlyname() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CoClass::clear_friendlyname() {
  if (friendlyname_ != &::google::protobuf::internal::kEmptyString) {
    friendlyname_->clear();
  }
  clear_has_friendlyname();
}
inline const ::std::string& CoClass::friendlyname() const {
  return *friendlyname_;
}
inline void CoClass::set_friendlyname(const ::std::string& value) {
  set_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    friendlyname_ = new ::std::string;
  }
  friendlyname_->assign(value);
}
inline void CoClass::set_friendlyname(const char* value) {
  set_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    friendlyname_ = new ::std::string;
  }
  friendlyname_->assign(value);
}
inline void CoClass::set_friendlyname(const char* value, size_t size) {
  set_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    friendlyname_ = new ::std::string;
  }
  friendlyname_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CoClass::mutable_friendlyname() {
  set_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    friendlyname_ = new ::std::string;
  }
  return friendlyname_;
}
inline ::std::string* CoClass::release_friendlyname() {
  clear_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = friendlyname_;
    friendlyname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CoClass::set_allocated_friendlyname(::std::string* friendlyname) {
  if (friendlyname_ != &::google::protobuf::internal::kEmptyString) {
    delete friendlyname_;
  }
  if (friendlyname) {
    set_has_friendlyname();
    friendlyname_ = friendlyname;
  } else {
    clear_has_friendlyname();
    friendlyname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional .dcomplugin.Identifier id = 3;
inline bool CoClass::has_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CoClass::set_has_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CoClass::clear_has_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CoClass::clear_id() {
  if (id_ != NULL) id_->::dcomplugin::Identifier::Clear();
  clear_has_id();
}
inline const ::dcomplugin::Identifier& CoClass::id() const {
  return id_ != NULL ? *id_ : *default_instance_->id_;
}
inline ::dcomplugin::Identifier* CoClass::mutable_id() {
  set_has_id();
  if (id_ == NULL) id_ = new ::dcomplugin::Identifier;
  return id_;
}
inline ::dcomplugin::Identifier* CoClass::release_id() {
  clear_has_id();
  ::dcomplugin::Identifier* temp = id_;
  id_ = NULL;
  return temp;
}
inline void CoClass::set_allocated_id(::dcomplugin::Identifier* id) {
  delete id_;
  id_ = id;
  if (id) {
    set_has_id();
  } else {
    clear_has_id();
  }
}

// -------------------------------------------------------------------

// CoInterface

// optional .dcomplugin.Identifier id = 3;
inline bool CoInterface::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CoInterface::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CoInterface::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CoInterface::clear_id() {
  if (id_ != NULL) id_->::dcomplugin::Identifier::Clear();
  clear_has_id();
}
inline const ::dcomplugin::Identifier& CoInterface::id() const {
  return id_ != NULL ? *id_ : *default_instance_->id_;
}
inline ::dcomplugin::Identifier* CoInterface::mutable_id() {
  set_has_id();
  if (id_ == NULL) id_ = new ::dcomplugin::Identifier;
  return id_;
}
inline ::dcomplugin::Identifier* CoInterface::release_id() {
  clear_has_id();
  ::dcomplugin::Identifier* temp = id_;
  id_ = NULL;
  return temp;
}
inline void CoInterface::set_allocated_id(::dcomplugin::Identifier* id) {
  delete id_;
  id_ = id;
  if (id) {
    set_has_id();
  } else {
    clear_has_id();
  }
}

// -------------------------------------------------------------------

// TypeLib

// optional string name = 1;
inline bool TypeLib::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TypeLib::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TypeLib::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TypeLib::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& TypeLib::name() const {
  return *name_;
}
inline void TypeLib::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void TypeLib::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void TypeLib::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TypeLib::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* TypeLib::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void TypeLib::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional .dcomplugin.Identifier id = 2;
inline bool TypeLib::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TypeLib::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TypeLib::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TypeLib::clear_id() {
  if (id_ != NULL) id_->::dcomplugin::Identifier::Clear();
  clear_has_id();
}
inline const ::dcomplugin::Identifier& TypeLib::id() const {
  return id_ != NULL ? *id_ : *default_instance_->id_;
}
inline ::dcomplugin::Identifier* TypeLib::mutable_id() {
  set_has_id();
  if (id_ == NULL) id_ = new ::dcomplugin::Identifier;
  return id_;
}
inline ::dcomplugin::Identifier* TypeLib::release_id() {
  clear_has_id();
  ::dcomplugin::Identifier* temp = id_;
  id_ = NULL;
  return temp;
}
inline void TypeLib::set_allocated_id(::dcomplugin::Identifier* id) {
  delete id_;
  id_ = id;
  if (id) {
    set_has_id();
  } else {
    clear_has_id();
  }
}

// optional .dcomplugin.CoInterface cointerface = 3;
inline bool TypeLib::has_cointerface() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void TypeLib::set_has_cointerface() {
  _has_bits_[0] |= 0x00000004u;
}
inline void TypeLib::clear_has_cointerface() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void TypeLib::clear_cointerface() {
  if (cointerface_ != NULL) cointerface_->::dcomplugin::CoInterface::Clear();
  clear_has_cointerface();
}
inline const ::dcomplugin::CoInterface& TypeLib::cointerface() const {
  return cointerface_ != NULL ? *cointerface_ : *default_instance_->cointerface_;
}
inline ::dcomplugin::CoInterface* TypeLib::mutable_cointerface() {
  set_has_cointerface();
  if (cointerface_ == NULL) cointerface_ = new ::dcomplugin::CoInterface;
  return cointerface_;
}
inline ::dcomplugin::CoInterface* TypeLib::release_cointerface() {
  clear_has_cointerface();
  ::dcomplugin::CoInterface* temp = cointerface_;
  cointerface_ = NULL;
  return temp;
}
inline void TypeLib::set_allocated_cointerface(::dcomplugin::CoInterface* cointerface) {
  delete cointerface_;
  cointerface_ = cointerface;
  if (cointerface) {
    set_has_cointerface();
  } else {
    clear_has_cointerface();
  }
}

// optional .dcomplugin.CoClass coclass = 4;
inline bool TypeLib::has_coclass() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void TypeLib::set_has_coclass() {
  _has_bits_[0] |= 0x00000008u;
}
inline void TypeLib::clear_has_coclass() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void TypeLib::clear_coclass() {
  if (coclass_ != NULL) coclass_->::dcomplugin::CoClass::Clear();
  clear_has_coclass();
}
inline const ::dcomplugin::CoClass& TypeLib::coclass() const {
  return coclass_ != NULL ? *coclass_ : *default_instance_->coclass_;
}
inline ::dcomplugin::CoClass* TypeLib::mutable_coclass() {
  set_has_coclass();
  if (coclass_ == NULL) coclass_ = new ::dcomplugin::CoClass;
  return coclass_;
}
inline ::dcomplugin::CoClass* TypeLib::release_coclass() {
  clear_has_coclass();
  ::dcomplugin::CoClass* temp = coclass_;
  coclass_ = NULL;
  return temp;
}
inline void TypeLib::set_allocated_coclass(::dcomplugin::CoClass* coclass) {
  delete coclass_;
  coclass_ = coclass;
  if (coclass) {
    set_has_coclass();
  } else {
    clear_has_coclass();
  }
}

// -------------------------------------------------------------------

// Component

// optional string name = 1;
inline bool Component::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Component::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Component::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Component::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Component::name() const {
  return *name_;
}
inline void Component::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Component::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Component::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Component::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Component::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Component::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional .dcomplugin.TypeLib typelib = 2;
inline bool Component::has_typelib() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Component::set_has_typelib() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Component::clear_has_typelib() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Component::clear_typelib() {
  if (typelib_ != NULL) typelib_->::dcomplugin::TypeLib::Clear();
  clear_has_typelib();
}
inline const ::dcomplugin::TypeLib& Component::typelib() const {
  return typelib_ != NULL ? *typelib_ : *default_instance_->typelib_;
}
inline ::dcomplugin::TypeLib* Component::mutable_typelib() {
  set_has_typelib();
  if (typelib_ == NULL) typelib_ = new ::dcomplugin::TypeLib;
  return typelib_;
}
inline ::dcomplugin::TypeLib* Component::release_typelib() {
  clear_has_typelib();
  ::dcomplugin::TypeLib* temp = typelib_;
  typelib_ = NULL;
  return temp;
}
inline void Component::set_allocated_typelib(::dcomplugin::TypeLib* typelib) {
  delete typelib_;
  typelib_ = typelib;
  if (typelib) {
    set_has_typelib();
  } else {
    clear_has_typelib();
  }
}

// optional .dcomplugin.Identifier appid = 3;
inline bool Component::has_appid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Component::set_has_appid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Component::clear_has_appid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Component::clear_appid() {
  if (appid_ != NULL) appid_->::dcomplugin::Identifier::Clear();
  clear_has_appid();
}
inline const ::dcomplugin::Identifier& Component::appid() const {
  return appid_ != NULL ? *appid_ : *default_instance_->appid_;
}
inline ::dcomplugin::Identifier* Component::mutable_appid() {
  set_has_appid();
  if (appid_ == NULL) appid_ = new ::dcomplugin::Identifier;
  return appid_;
}
inline ::dcomplugin::Identifier* Component::release_appid() {
  clear_has_appid();
  ::dcomplugin::Identifier* temp = appid_;
  appid_ = NULL;
  return temp;
}
inline void Component::set_allocated_appid(::dcomplugin::Identifier* appid) {
  delete appid_;
  appid_ = appid;
  if (appid) {
    set_has_appid();
  } else {
    clear_has_appid();
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace dcomplugin

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_dcomplugin_2eproto__INCLUDED