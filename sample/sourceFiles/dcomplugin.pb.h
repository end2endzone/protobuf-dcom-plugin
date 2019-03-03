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
class Library;
class Object;
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

class Library : public ::google::protobuf::Message {
 public:
  Library();
  virtual ~Library();

  Library(const Library& from);

  inline Library& operator=(const Library& from) {
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
  static const Library& default_instance();

  void Swap(Library* other);

  // implements Message ----------------------------------------------

  Library* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Library& from);
  void MergeFrom(const Library& from);
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

  // @@protoc_insertion_point(class_scope:dcomplugin.Library)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_id();
  inline void clear_has_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::dcomplugin::Identifier* id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_dcomplugin_2eproto();
  friend void protobuf_AssignDesc_dcomplugin_2eproto();
  friend void protobuf_ShutdownFile_dcomplugin_2eproto();

  void InitAsDefaultInstance();
  static Library* default_instance_;
};
// -------------------------------------------------------------------

class Object : public ::google::protobuf::Message {
 public:
  Object();
  virtual ~Object();

  Object(const Object& from);

  inline Object& operator=(const Object& from) {
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
  static const Object& default_instance();

  void Swap(Object* other);

  // implements Message ----------------------------------------------

  Object* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Object& from);
  void MergeFrom(const Object& from);
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

  // @@protoc_insertion_point(class_scope:dcomplugin.Object)
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
  static Object* default_instance_;
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

  // optional .dcomplugin.Object object = 2;
  inline bool has_object() const;
  inline void clear_object();
  static const int kObjectFieldNumber = 2;
  inline const ::dcomplugin::Object& object() const;
  inline ::dcomplugin::Object* mutable_object();
  inline ::dcomplugin::Object* release_object();
  inline void set_allocated_object(::dcomplugin::Object* object);

  // optional .dcomplugin.Library library = 3;
  inline bool has_library() const;
  inline void clear_library();
  static const int kLibraryFieldNumber = 3;
  inline const ::dcomplugin::Library& library() const;
  inline ::dcomplugin::Library* mutable_library();
  inline ::dcomplugin::Library* release_library();
  inline void set_allocated_library(::dcomplugin::Library* library);

  // optional .dcomplugin.Identifier idispatch = 4;
  inline bool has_idispatch() const;
  inline void clear_idispatch();
  static const int kIdispatchFieldNumber = 4;
  inline const ::dcomplugin::Identifier& idispatch() const;
  inline ::dcomplugin::Identifier* mutable_idispatch();
  inline ::dcomplugin::Identifier* release_idispatch();
  inline void set_allocated_idispatch(::dcomplugin::Identifier* idispatch);

  // optional .dcomplugin.Identifier ifileio = 5;
  inline bool has_ifileio() const;
  inline void clear_ifileio();
  static const int kIfileioFieldNumber = 5;
  inline const ::dcomplugin::Identifier& ifileio() const;
  inline ::dcomplugin::Identifier* mutable_ifileio();
  inline ::dcomplugin::Identifier* release_ifileio();
  inline void set_allocated_ifileio(::dcomplugin::Identifier* ifileio);

  // optional .dcomplugin.Identifier iunknown = 6;
  inline bool has_iunknown() const;
  inline void clear_iunknown();
  static const int kIunknownFieldNumber = 6;
  inline const ::dcomplugin::Identifier& iunknown() const;
  inline ::dcomplugin::Identifier* mutable_iunknown();
  inline ::dcomplugin::Identifier* release_iunknown();
  inline void set_allocated_iunknown(::dcomplugin::Identifier* iunknown);

  // optional .dcomplugin.Identifier coclass = 7;
  inline bool has_coclass() const;
  inline void clear_coclass();
  static const int kCoclassFieldNumber = 7;
  inline const ::dcomplugin::Identifier& coclass() const;
  inline ::dcomplugin::Identifier* mutable_coclass();
  inline ::dcomplugin::Identifier* release_coclass();
  inline void set_allocated_coclass(::dcomplugin::Identifier* coclass);

  // @@protoc_insertion_point(class_scope:dcomplugin.Component)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_object();
  inline void clear_has_object();
  inline void set_has_library();
  inline void clear_has_library();
  inline void set_has_idispatch();
  inline void clear_has_idispatch();
  inline void set_has_ifileio();
  inline void clear_has_ifileio();
  inline void set_has_iunknown();
  inline void clear_has_iunknown();
  inline void set_has_coclass();
  inline void clear_has_coclass();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::dcomplugin::Object* object_;
  ::dcomplugin::Library* library_;
  ::dcomplugin::Identifier* idispatch_;
  ::dcomplugin::Identifier* ifileio_;
  ::dcomplugin::Identifier* iunknown_;
  ::dcomplugin::Identifier* coclass_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

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

// Library

// optional string name = 1;
inline bool Library::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Library::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Library::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Library::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Library::name() const {
  return *name_;
}
inline void Library::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Library::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Library::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Library::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Library::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Library::set_allocated_name(::std::string* name) {
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
inline bool Library::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Library::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Library::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Library::clear_id() {
  if (id_ != NULL) id_->::dcomplugin::Identifier::Clear();
  clear_has_id();
}
inline const ::dcomplugin::Identifier& Library::id() const {
  return id_ != NULL ? *id_ : *default_instance_->id_;
}
inline ::dcomplugin::Identifier* Library::mutable_id() {
  set_has_id();
  if (id_ == NULL) id_ = new ::dcomplugin::Identifier;
  return id_;
}
inline ::dcomplugin::Identifier* Library::release_id() {
  clear_has_id();
  ::dcomplugin::Identifier* temp = id_;
  id_ = NULL;
  return temp;
}
inline void Library::set_allocated_id(::dcomplugin::Identifier* id) {
  delete id_;
  id_ = id;
  if (id) {
    set_has_id();
  } else {
    clear_has_id();
  }
}

// -------------------------------------------------------------------

// Object

// optional string name = 1;
inline bool Object::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Object::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Object::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Object::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Object::name() const {
  return *name_;
}
inline void Object::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Object::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Object::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Object::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Object::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Object::set_allocated_name(::std::string* name) {
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
inline bool Object::has_friendlyname() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Object::set_has_friendlyname() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Object::clear_has_friendlyname() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Object::clear_friendlyname() {
  if (friendlyname_ != &::google::protobuf::internal::kEmptyString) {
    friendlyname_->clear();
  }
  clear_has_friendlyname();
}
inline const ::std::string& Object::friendlyname() const {
  return *friendlyname_;
}
inline void Object::set_friendlyname(const ::std::string& value) {
  set_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    friendlyname_ = new ::std::string;
  }
  friendlyname_->assign(value);
}
inline void Object::set_friendlyname(const char* value) {
  set_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    friendlyname_ = new ::std::string;
  }
  friendlyname_->assign(value);
}
inline void Object::set_friendlyname(const char* value, size_t size) {
  set_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    friendlyname_ = new ::std::string;
  }
  friendlyname_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Object::mutable_friendlyname() {
  set_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    friendlyname_ = new ::std::string;
  }
  return friendlyname_;
}
inline ::std::string* Object::release_friendlyname() {
  clear_has_friendlyname();
  if (friendlyname_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = friendlyname_;
    friendlyname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Object::set_allocated_friendlyname(::std::string* friendlyname) {
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
inline bool Object::has_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Object::set_has_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Object::clear_has_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Object::clear_id() {
  if (id_ != NULL) id_->::dcomplugin::Identifier::Clear();
  clear_has_id();
}
inline const ::dcomplugin::Identifier& Object::id() const {
  return id_ != NULL ? *id_ : *default_instance_->id_;
}
inline ::dcomplugin::Identifier* Object::mutable_id() {
  set_has_id();
  if (id_ == NULL) id_ = new ::dcomplugin::Identifier;
  return id_;
}
inline ::dcomplugin::Identifier* Object::release_id() {
  clear_has_id();
  ::dcomplugin::Identifier* temp = id_;
  id_ = NULL;
  return temp;
}
inline void Object::set_allocated_id(::dcomplugin::Identifier* id) {
  delete id_;
  id_ = id;
  if (id) {
    set_has_id();
  } else {
    clear_has_id();
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

// optional .dcomplugin.Object object = 2;
inline bool Component::has_object() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Component::set_has_object() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Component::clear_has_object() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Component::clear_object() {
  if (object_ != NULL) object_->::dcomplugin::Object::Clear();
  clear_has_object();
}
inline const ::dcomplugin::Object& Component::object() const {
  return object_ != NULL ? *object_ : *default_instance_->object_;
}
inline ::dcomplugin::Object* Component::mutable_object() {
  set_has_object();
  if (object_ == NULL) object_ = new ::dcomplugin::Object;
  return object_;
}
inline ::dcomplugin::Object* Component::release_object() {
  clear_has_object();
  ::dcomplugin::Object* temp = object_;
  object_ = NULL;
  return temp;
}
inline void Component::set_allocated_object(::dcomplugin::Object* object) {
  delete object_;
  object_ = object;
  if (object) {
    set_has_object();
  } else {
    clear_has_object();
  }
}

// optional .dcomplugin.Library library = 3;
inline bool Component::has_library() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Component::set_has_library() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Component::clear_has_library() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Component::clear_library() {
  if (library_ != NULL) library_->::dcomplugin::Library::Clear();
  clear_has_library();
}
inline const ::dcomplugin::Library& Component::library() const {
  return library_ != NULL ? *library_ : *default_instance_->library_;
}
inline ::dcomplugin::Library* Component::mutable_library() {
  set_has_library();
  if (library_ == NULL) library_ = new ::dcomplugin::Library;
  return library_;
}
inline ::dcomplugin::Library* Component::release_library() {
  clear_has_library();
  ::dcomplugin::Library* temp = library_;
  library_ = NULL;
  return temp;
}
inline void Component::set_allocated_library(::dcomplugin::Library* library) {
  delete library_;
  library_ = library;
  if (library) {
    set_has_library();
  } else {
    clear_has_library();
  }
}

// optional .dcomplugin.Identifier idispatch = 4;
inline bool Component::has_idispatch() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Component::set_has_idispatch() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Component::clear_has_idispatch() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Component::clear_idispatch() {
  if (idispatch_ != NULL) idispatch_->::dcomplugin::Identifier::Clear();
  clear_has_idispatch();
}
inline const ::dcomplugin::Identifier& Component::idispatch() const {
  return idispatch_ != NULL ? *idispatch_ : *default_instance_->idispatch_;
}
inline ::dcomplugin::Identifier* Component::mutable_idispatch() {
  set_has_idispatch();
  if (idispatch_ == NULL) idispatch_ = new ::dcomplugin::Identifier;
  return idispatch_;
}
inline ::dcomplugin::Identifier* Component::release_idispatch() {
  clear_has_idispatch();
  ::dcomplugin::Identifier* temp = idispatch_;
  idispatch_ = NULL;
  return temp;
}
inline void Component::set_allocated_idispatch(::dcomplugin::Identifier* idispatch) {
  delete idispatch_;
  idispatch_ = idispatch;
  if (idispatch) {
    set_has_idispatch();
  } else {
    clear_has_idispatch();
  }
}

// optional .dcomplugin.Identifier ifileio = 5;
inline bool Component::has_ifileio() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Component::set_has_ifileio() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Component::clear_has_ifileio() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Component::clear_ifileio() {
  if (ifileio_ != NULL) ifileio_->::dcomplugin::Identifier::Clear();
  clear_has_ifileio();
}
inline const ::dcomplugin::Identifier& Component::ifileio() const {
  return ifileio_ != NULL ? *ifileio_ : *default_instance_->ifileio_;
}
inline ::dcomplugin::Identifier* Component::mutable_ifileio() {
  set_has_ifileio();
  if (ifileio_ == NULL) ifileio_ = new ::dcomplugin::Identifier;
  return ifileio_;
}
inline ::dcomplugin::Identifier* Component::release_ifileio() {
  clear_has_ifileio();
  ::dcomplugin::Identifier* temp = ifileio_;
  ifileio_ = NULL;
  return temp;
}
inline void Component::set_allocated_ifileio(::dcomplugin::Identifier* ifileio) {
  delete ifileio_;
  ifileio_ = ifileio;
  if (ifileio) {
    set_has_ifileio();
  } else {
    clear_has_ifileio();
  }
}

// optional .dcomplugin.Identifier iunknown = 6;
inline bool Component::has_iunknown() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Component::set_has_iunknown() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Component::clear_has_iunknown() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Component::clear_iunknown() {
  if (iunknown_ != NULL) iunknown_->::dcomplugin::Identifier::Clear();
  clear_has_iunknown();
}
inline const ::dcomplugin::Identifier& Component::iunknown() const {
  return iunknown_ != NULL ? *iunknown_ : *default_instance_->iunknown_;
}
inline ::dcomplugin::Identifier* Component::mutable_iunknown() {
  set_has_iunknown();
  if (iunknown_ == NULL) iunknown_ = new ::dcomplugin::Identifier;
  return iunknown_;
}
inline ::dcomplugin::Identifier* Component::release_iunknown() {
  clear_has_iunknown();
  ::dcomplugin::Identifier* temp = iunknown_;
  iunknown_ = NULL;
  return temp;
}
inline void Component::set_allocated_iunknown(::dcomplugin::Identifier* iunknown) {
  delete iunknown_;
  iunknown_ = iunknown;
  if (iunknown) {
    set_has_iunknown();
  } else {
    clear_has_iunknown();
  }
}

// optional .dcomplugin.Identifier coclass = 7;
inline bool Component::has_coclass() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Component::set_has_coclass() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Component::clear_has_coclass() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Component::clear_coclass() {
  if (coclass_ != NULL) coclass_->::dcomplugin::Identifier::Clear();
  clear_has_coclass();
}
inline const ::dcomplugin::Identifier& Component::coclass() const {
  return coclass_ != NULL ? *coclass_ : *default_instance_->coclass_;
}
inline ::dcomplugin::Identifier* Component::mutable_coclass() {
  set_has_coclass();
  if (coclass_ == NULL) coclass_ = new ::dcomplugin::Identifier;
  return coclass_;
}
inline ::dcomplugin::Identifier* Component::release_coclass() {
  clear_has_coclass();
  ::dcomplugin::Identifier* temp = coclass_;
  coclass_ = NULL;
  return temp;
}
inline void Component::set_allocated_coclass(::dcomplugin::Identifier* coclass) {
  delete coclass_;
  coclass_ = coclass;
  if (coclass) {
    set_has_coclass();
  } else {
    clear_has_coclass();
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
