#include "MessageSerializer.h"

#include <vector>

namespace DCOMPLUGIN_PACKAGE_NAME {

HRESULT Variant2ByteArray(VARIANT & iVar, DCOMPLUGIN_PACKAGE_NAME::VariantFlavor & oVariantFlavor, std::string & oData)
{
  static const VARTYPE IS_VARIANT       = (VT_BYREF | VT_VARIANT);
  static const VARTYPE BYTE_ARRAY       = (VT_ARRAY | VT_UI1);
  static const VARTYPE VARIANT_ARRAY    = (VT_ARRAY | VT_VARIANT);

  //Note that c++ serialize a "byte array" as a "SAFEARRAY of bytes inside a VARIANT". This structure 
  //store the bytes data in a consecutive buffer (all values are one after the other) which makes the 
  //process of converting the data to a std::vector or std::string easy.
  //However, weakly-typed languages (such as VBScript) does not serialize data the same way.
  //VBScript serialize data as a VARIANT holding a SAFEARRAY of VARIANT, each VARIANT holding a single byte.
  //To recover the data, one must read every VARIANT one by one and make sure it contains a byte before
  //storing this byte within the output array.

  if (iVar.vt == IS_VARIANT)
  {
    //this VARIANT contains another VARIANT
    //it is expected that the inner VARIANT contains an ARRAY of VARIANT...
    //this is typical of VBScript (weakly-typed languages)
    VARIANT * v1 = iVar.pvarVal;
    if (v1 == NULL)
      return NULL;

    HRESULT hr = Variant2ByteArray(*v1, oVariantFlavor, oData);
    oVariantFlavor = VBSCRIPT;
    return hr;
  }
  else if (iVar.vt == VARIANT_ARRAY)
  {
    //this variant contains an array of VARIANT
    //this is typical of VBScript (weakly-typed languages)
    SAFEARRAY * sa = iVar.parray;

    VARIANT * values;
    HRESULT hr = SafeArrayAccessData(sa, (void**)&values); // direct access to SA memory
    if (FAILED(hr))
      return NULL;

    // get array bounds
    long lowerBound = 0;
    long upperBound = 0;
    SafeArrayGetLBound(sa, 1, &lowerBound);
    SafeArrayGetUBound(sa, 1, &upperBound);

    long numElements = upperBound - lowerBound + 1;
    if (numElements == 0)
    {
      oData.clear();
    }
    else
    {
      //copy each VARIANT element one by one
      for(long i=0; i<numElements; i++)
      {
        VARIANT & var = values[i];

        //does the VARIANT contains unsigned char data ?
        if (var.vt == VT_UI1)
        {
          oData.append(1, var.bVal);
        }
      }
    }
    SafeArrayUnaccessData(sa);

    oVariantFlavor = VBSCRIPT;

    return S_OK;
  }
  else if (iVar.vt == BYTE_ARRAY)
  {
    //this VARIANT is a SAFEARRAY that contains Bytes (unsigned char)
    //this is typical of C++ client calls
    SAFEARRAY * sa = iVar.parray;

    byte * values;
    HRESULT hr = SafeArrayAccessData(sa, (void**)&values); // direct access to SA memory
    if (FAILED(hr))
      return NULL;

    // get array bounds
    long lowerBound = 0;
    long upperBound = 0;
    SafeArrayGetLBound(sa, 1, &lowerBound);
    SafeArrayGetUBound(sa, 1, &upperBound);

    long numElements = upperBound - lowerBound + 1;
    if (numElements == 0)
    {
      oData.clear();
    }
    else
    {
      //copy all continuous BYTE elements as a single operation
      oData.assign( (const char*)values, numElements);
    }
    SafeArrayUnaccessData(sa);
    
    oVariantFlavor = CPLUSPLUS;

    return S_OK;
  }
  else
    return E_INVALIDARG;
}

HRESULT ByteArray2Variant(const std::string & iData, const DCOMPLUGIN_PACKAGE_NAME::VariantFlavor & iVariantFlavor, VARIANT & oVar)
{
  switch(iVariantFlavor)
  {
  case DCOMPLUGIN_PACKAGE_NAME::CPLUSPLUS:
    {
      //https://stackoverflow.com/questions/10905043/c-sharp-marshal-byte-to-com-safearray-parameter-with-ref-object-signature
      VariantInit (&oVar);
      VariantClear(&oVar);

      SAFEARRAYBOUND bounds[1];
      bounds[0].cElements = iData.size();
      bounds[0].lLbound = 1;

      SAFEARRAY* sa = SafeArrayCreate(VT_UI1, 1, bounds);
      if(sa == NULL)
        return E_OUTOFMEMORY;

      //copy data to SAFEARRAY
      SafeArrayLock(sa);
      memcpy(sa->pvData, iData.c_str(), iData.size());
      SafeArrayUnlock(sa);

      oVar.parray = sa;
      oVar.vt = VT_ARRAY | VT_UI1;
      return S_OK;
    };
    break;
  case DCOMPLUGIN_PACKAGE_NAME::VBSCRIPT:
    {
      //https://stackoverflow.com/questions/10905043/c-sharp-marshal-byte-to-com-safearray-parameter-with-ref-object-signature
      VariantInit (&oVar);
      VariantClear(&oVar);

      SAFEARRAYBOUND bounds[1];
      bounds[0].cElements = iData.size();
      bounds[0].lLbound = 1;

      SAFEARRAY* sa = SafeArrayCreate(VT_VARIANT, 1, bounds);
      if(sa == NULL)
        return E_OUTOFMEMORY;

      //copy data to SAFEARRAY
      VARIANT * values = NULL;
      HRESULT hr = SafeArrayAccessData(sa, (void **)&values);
      if (SUCCEEDED(hr))
      {
        for(size_t i=0; i<iData.size(); i++)
        {
          VARIANT & tmp = values[i];
          VariantInit (&tmp);
          tmp.vt = VT_UI1;
          tmp.bVal = (unsigned char)iData[i];
        }
        SafeArrayUnaccessData(sa);
      }

      oVar.parray = sa;
      oVar.vt = VT_ARRAY | VT_VARIANT;
      return S_OK;
    };
    break;
  default:
    return E_INVALIDARG;
  };

}

///
HRESULT SerializeMessageToVariant(const google::protobuf::MessageLite & iMsg, const DCOMPLUGIN_PACKAGE_NAME::VariantFlavor & iVariantFlavor, VARIANT & oVar)
{
  std::string data;
  bool success = iMsg.SerializeToString(&data);
  if (!success)
    return E_INVALIDARG;

  HRESULT hr = ByteArray2Variant(data, iVariantFlavor, oVar);
  if (FAILED(hr))
    return hr;
  return S_OK;
}

///
HRESULT DeserializeVariantToMessage(VARIANT & iVar, google::protobuf::MessageLite & oMsg, DCOMPLUGIN_PACKAGE_NAME::VariantFlavor & oVariantFlavor)
{
  std::string data;
  HRESULT hr = Variant2ByteArray(iVar, oVariantFlavor, data);
  if (FAILED(hr))
    return hr;

  //deserialize data into message
  bool success = oMsg.ParseFromString(data);
  if (!success)
  {
    return E_INVALIDARG;
  }

  return S_OK;
}

}  // namespace DCOMPLUGIN_PACKAGE_NAME
