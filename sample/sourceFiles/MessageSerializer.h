#pragma once

#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <OAIdl.h>

#include <google/protobuf/message_lite.h>

namespace testdemo {

///<summary>An enum defining how to encode a protobuf message to a VARIANT* or decoding a VARIANT* to a protbuf message.</summary>
enum VariantFlavor
{
  CPLUSPLUS,
  VBSCRIPT,
};

///<summary>Serializes a protobuf message to a VARIANT object using the given encoding flavor.</summary>
///<param name="iMsg">The protobuf message to serialize.</param>
///<param name="iVariantFlavor">The given flavor to use for encoding the VARIANT.</param>
///<param name="oVar">The output VARIANT which contains the serialized protobuf message.</param>
///<returns>Returns a VARIANT containing a serialized protobuf message.</returns>
HRESULT SerializeMessageToVariant(const google::protobuf::MessageLite & iMsg, const VariantFlavor & iVariantFlavor, VARIANT & oVar);

///<summary>Deserializes a VARIANT object into a given protobuf message.</summary>
///<param name="iVar">The input VARIANT which contains the serialized protobuf message.</param>

///<param name="iMsg">The protobuf message to serialize.</param>
///<param name="iVariantFlavor">The given flavor to use for encoding the VARIANT.</param>
///<returns>Returns a VARIANT containing a serialized protobuf message.</returns>
HRESULT DeserializeVariantToMessage(VARIANT & iVar, google::protobuf::MessageLite & oMsg, VariantFlavor & oVariantFlavor);

}  // namespace testdemo
