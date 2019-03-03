/**
 * This file was generated by
 * bin2cpp v1.3.
 * Copyright (C) 2013-2014 end2endzone.com. All rights reserved.
 * Do not modify this file.
 */
#include ".\EmbeddedFileSmartPointers.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class SmartPointersFile : public virtual bin2cpp::File
  {
  public:
    SmartPointersFile() {}
    ~SmartPointersFile() {}
    virtual size_t getSize() { return 9311; }
    virtual size_t getSegmentSize() { return 200; }
    virtual size_t getNumSegments() { return 47; }
    virtual const char * getFilename() { return "SmartPointers.h"; }
    virtual const char * getSegment(size_t iIndex, size_t & oLength)
    {
      oLength = 0;
      if (iIndex >= getNumSegments())
        return NULL;
      const char * buffer = NULL;
      size_t index = 0;
      oLength = getSegmentSize();
      buffer = "#pragma once\x0d\x0a\x0d\012#define _T(expression) (expression)\x0d\012#define ATLASSERT(expression) assert(expression)\x0d\012#define CComBSTR BSTR\x0d\012#define ATLA2WHELPER AtlA2WHelper\x0d\012#define ATLW2AHELPER AtlW2AHelper\x0d\x0a\x0d\012//"; if (iIndex == index) return buffer; index++;
      buffer = "///////////////////////////////////////////////////////////////////////////\x0d\012// COM Smart pointers\x0d\x0a\x0d\012template <class T>\x0d\012class _NoAddRefReleaseOnCComPtr : public T\x0d\012{\x0d\012  private:\x0d\012    STDMETHOD_(ULON"; if (iIndex == index) return buffer; index++;
      buffer = "G, AddRef)()=0;\x0d\012    STDMETHOD_(ULONG, Release)()=0;\x0d\012};\x0d\x0a\x0d\012//CComPtrBase provides the basis for all other smart pointers\x0d\012//The other smartpointers add their own constructors and operators\x0d\012template "; if (iIndex == index) return buffer; index++;
      buffer = "<class T>\x0d\012class CComPtrBase\x0d\012{\x0d\012protected:\x0d\012  CComPtrBase() throw()\x0d\012  {\x0d\012    p = NULL;\x0d\012  }\x0d\012  CComPtrBase(int nNull) throw()\x0d\012  {\x0d\012    ATLASSERT(nNull == 0);\x0d\012    (void)nNull;\x0d\012    p = NULL;\x0d\012  }\x0d\x0a"; if (iIndex == index) return buffer; index++;
      buffer = "  CComPtrBase(T* lp) throw()\x0d\012  {\x0d\012    p = lp;\x0d\012    if (p != NULL)\x0d\012      p->AddRef();\x0d\012  }\x0d\012public:\x0d\012  typedef T _PtrClass;\x0d\012  ~CComPtrBase() throw()\x0d\012  {\x0d\012    if (p)\x0d\012      p->Release();\x0d\012  }\x0d\012  ope"; if (iIndex == index) return buffer; index++;
      buffer = "rator T*() const throw()\x0d\012  {\x0d\012    return p;\x0d\012  }\x0d\012  T& operator*() const throw()\x0d\012  {\x0d\012    ATLASSERT(p!=NULL);\x0d\012    return *p;\x0d\012  }\x0d\012  //The assert on operator& usually indicates a bug.  If this is r"; if (iIndex == index) return buffer; index++;
      buffer = "eally\x0d\012  //what is needed, however, take the address of the p member explicitly.\x0d\012  T** operator&() throw()\x0d\012  {\x0d\012    ATLASSERT(p==NULL);\x0d\012    return &p;\x0d\012  }\x0d\012  _NoAddRefReleaseOnCComPtr<T>* operator"; if (iIndex == index) return buffer; index++;
      buffer = "->() const throw()\x0d\012  {\x0d\012    ATLASSERT(p!=NULL);\x0d\012    return (_NoAddRefReleaseOnCComPtr<T>*)p;\x0d\012  }\x0d\012  bool operator!() const throw()\x0d\012  {\x0d\012    return (p == NULL);\x0d\012  }\x0d\012  bool operator<(T* pT) const "; if (iIndex == index) return buffer; index++;
      buffer = "throw()\x0d\012  {\x0d\012    return p < pT;\x0d\012  }\x0d\012  bool operator==(T* pT) const throw()\x0d\012  {\x0d\012    return p == pT;\x0d\012  }\x0d\x0a\x0d\012  // Release the interface and set to NULL\x0d\012  void Release() throw()\x0d\012  {\x0d\012    T* pTemp "; if (iIndex == index) return buffer; index++;
      buffer = "= p;\x0d\012    if (pTemp)\x0d\012    {\x0d\012      p = NULL;\x0d\012      pTemp->Release();\x0d\012    }\x0d\012  }\x0d\012  // Compare two objects for equivalence\x0d\012  bool IsEqualObject(IUnknown* pOther) throw()\x0d\012  {\x0d\012    if (p == NULL && p"; if (iIndex == index) return buffer; index++;
      buffer = "Other == NULL)\x0d\012      return true;  // They are both NULL objects\x0d\x0a\x0d\012    if (p == NULL || pOther == NULL)\x0d\012      return false;  // One is NULL the other is not\x0d\x0a\x0d\012    CComPtr<IUnknown> punk1;\x0d\012    CCo"; if (iIndex == index) return buffer; index++;
      buffer = "mPtr<IUnknown> punk2;\x0d\012    p->QueryInterface(__uuidof(IUnknown), (void**)&punk1);\x0d\012    pOther->QueryInterface(__uuidof(IUnknown), (void**)&punk2);\x0d\012    return punk1 == punk2;\x0d\012  }\x0d\012  // Attach to an e"; if (iIndex == index) return buffer; index++;
      buffer = "xisting interface (does not AddRef)\x0d\012  void Attach(T* p2) throw()\x0d\012  {\x0d\012    if (p)\x0d\012      p->Release();\x0d\012    p = p2;\x0d\012  }\x0d\012  // Detach the interface (does not Release)\x0d\012  T* Detach() throw()\x0d\012  {\x0d\012   "; if (iIndex == index) return buffer; index++;
      buffer = " T* pt = p;\x0d\012    p = NULL;\x0d\012    return pt;\x0d\012  }\x0d\012  HRESULT CopyTo(T** ppT) throw()\x0d\012  {\x0d\012    ATLASSERT(ppT != NULL);\x0d\012    if (ppT == NULL)\x0d\012      return E_POINTER;\x0d\012    *ppT = p;\x0d\012    if (p)\x0d\012      p-"; if (iIndex == index) return buffer; index++;
      buffer = ">AddRef();\x0d\012    return S_OK;\x0d\012  }\x0d\012  HRESULT SetSite(IUnknown* punkParent) throw()\x0d\012  {\x0d\012    return AtlSetChildSite(p, punkParent);\x0d\012  }\x0d\012  HRESULT Advise(IUnknown* pUnk, const IID& iid, LPDWORD pdw) "; if (iIndex == index) return buffer; index++;
      buffer = "throw()\x0d\012  {\x0d\012    return AtlAdvise(p, pUnk, iid, pdw);\x0d\012  }\x0d\012  HRESULT CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL) throw()\x0d\012  {\x0d\012    ATLASSERT(p == N"; if (iIndex == index) return buffer; index++;
      buffer = "ULL);\x0d\012    return ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, __uuidof(T), (void**)&p);\x0d\012  }\x0d\012  HRESULT CoCreateInstance(LPCOLESTR szProgID, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CL"; if (iIndex == index) return buffer; index++;
      buffer = "SCTX_ALL) throw()\x0d\012  {\x0d\012    CLSID clsid;\x0d\012    HRESULT hr = CLSIDFromProgID(szProgID, &clsid);\x0d\012    ATLASSERT(p == NULL);\x0d\012    if (SUCCEEDED(hr))\x0d\012      hr = ::CoCreateInstance(clsid, pUnkOuter, dwClsC"; if (iIndex == index) return buffer; index++;
      buffer = "ontext, __uuidof(T), (void**)&p);\x0d\012    return hr;\x0d\012  }\x0d\012  template <class Q>\x0d\012  HRESULT QueryInterface(Q** pp) const throw()\x0d\012  {\x0d\012    ATLASSERT(pp != NULL);\x0d\012    return p->QueryInterface(__uuidof(Q),"; if (iIndex == index) return buffer; index++;
      buffer = " (void**)pp);\x0d\012  }\x0d\012  T* p;\x0d\012};\x0d\x0a\x0d\012template <class T>\x0d\012class CComPtr : public CComPtrBase<T>\x0d\012{\x0d\012public:\x0d\012  CComPtr() throw()\x0d\012  {\x0d\012  }\x0d\012  CComPtr(int nNull) throw() :\x0d\012    CComPtrBase<T>(nNull)\x0d\012  {\x0d"; if (iIndex == index) return buffer; index++;
      buffer = "\012  }\x0d\012  /*\x0d\012  template <typename Q>\x0d\012  CComPtr(Q* lp)\x0d\012  {\x0d\012    if (lp != NULL)\x0d\012      lp->QueryInterface(__uuidof(Q), (void**)&p);\x0d\012    else\x0d\012      p = NULL;\x0d\012  }\x0d\012  template <>\x0d\012  */\x0d\012  CComPtr(T* l"; if (iIndex == index) return buffer; index++;
      buffer = "p) throw() :\x0d\012    CComPtrBase<T>(lp)\x0d\x0a\x0d\012  {\x0d\012  }\x0d\012  CComPtr(const CComPtr<T>& lp) throw() :\x0d\012    CComPtrBase<T>(lp.p)\x0d\012  {\x0d\012  }\x0d\012//  template<>\x0d\012  /*\x0d\012  T* operator=(void* lp)\x0d\012  {\x0d\012    return (T*)Atl"; if (iIndex == index) return buffer; index++;
      buffer = "ComPtrAssign((IUnknown**)&p, (T*)lp);\x0d\012  }\x0d\012  */\x0d\012  /*\x0d\012  template <typename Q>\x0d\012  T* operator=(Q* lp)\x0d\012  {\x0d\012    return (T*)AtlComQIPtrAssign((IUnknown**)&p, lp, __uuidof(T));\x0d\012  }\x0d\012  template <>\x0d\012  *"; if (iIndex == index) return buffer; index++;
      buffer = "/\x0d\012  T* operator=(T* lp) throw()\x0d\012  {\x0d\012    return static_cast<T*>(AtlComPtrAssign((IUnknown**)&p, lp));\x0d\012  }\x0d\012  template <typename Q>\x0d\012  T* operator=(const CComPtr<Q>& lp) throw()\x0d\012  {\x0d\012    return sta"; if (iIndex == index) return buffer; index++;
      buffer = "tic_cast<T*>(AtlComQIPtrAssign((IUnknown**)&p, lp, __uuidof(T)));\x0d\012  }\x0d\x0a\x0d\012  //if before VS2005 (all versions of VS2003)\x0d\012  #if (_MSC_VER < 1400)\x0d\012  template <>\x0d\012  T* operator=(const CComPtr<T>& lp) th"; if (iIndex == index) return buffer; index++;
      buffer = "row()\x0d\012  {\x0d\012    return static_cast<T*>(AtlComPtrAssign((IUnknown**)&p, lp));\x0d\012  }\x0d\012  #endif\x0d\012};\x0d\x0a\x0d\x0a\x0d\012//ATL replacement macros\x0d\012#ifndef _DEBUG\x0d\012  #define USES_CONVERSION int _convert; (_convert); UINT "; if (iIndex == index) return buffer; index++;
      buffer = "_acp = /*ATL::_AtlGetConversionACP()*/ CP_THREAD_ACP; (_acp); LPCWSTR _lpw; (_lpw); LPCSTR _lpa; (_lpa)\x0d\012#else\x0d\012  #define USES_CONVERSION int _convert = 0; (_convert); UINT _acp = /*ATL::_AtlGetConver"; if (iIndex == index) return buffer; index++;
      buffer = "sionACP()*/ CP_THREAD_ACP; (_acp); LPCWSTR _lpw = NULL; (_lpw); LPCSTR _lpa = NULL; (_lpa)\x0d\012#endif\x0d\x0a\x0d\012/////////////////////////////////////////////////////////////////////////////\x0d\012// Global UNICODE<>"; if (iIndex == index) return buffer; index++;
      buffer = "ANSI translation helpers\x0d\012inline LPWSTR WINAPI AtlA2WHelper(LPWSTR lpw, LPCSTR lpa, int nChars, UINT acp) throw()\x0d\012{\x0d\012  ATLASSERT(lpa != NULL);\x0d\012  ATLASSERT(lpw != NULL);\x0d\012  if (lpw == NULL || lpa == "; if (iIndex == index) return buffer; index++;
      buffer = "NULL)\x0d\012    return NULL;\x0d\012  // verify that no illegal character present\x0d\012  // since lpw was allocated based on the size of lpa\x0d\012  // don't worry about the number of chars\x0d\012  lpw[0] = '\\0';\x0d\012  int ret ="; if (iIndex == index) return buffer; index++;
      buffer = " MultiByteToWideChar(acp, 0, lpa, -1, lpw, nChars);\x0d\012  if(ret == 0)\x0d\012  {\x0d\012    ATLASSERT(FALSE);\x0d\012    return NULL;\x0d\012  }    \x0d\012  return lpw;\x0d\012}\x0d\x0a\x0d\012inline LPSTR WINAPI AtlW2AHelper(LPSTR lpa, LPCWSTR lpw,"; if (iIndex == index) return buffer; index++;
      buffer = " int nChars, UINT acp) throw()\x0d\012{\x0d\012  ATLASSERT(lpw != NULL);\x0d\012  ATLASSERT(lpa != NULL);\x0d\012  if (lpa == NULL || lpw == NULL)\x0d\012    return NULL;\x0d\012  // verify that no illegal character present\x0d\012  // since "; if (iIndex == index) return buffer; index++;
      buffer = "lpa was allocated based on the size of lpw\x0d\012  // don't worry about the number of chars\x0d\012  lpa[0] = '\\0';\x0d\012  int ret = WideCharToMultiByte(acp, 0, lpw, -1, lpa, nChars, NULL, NULL);\x0d\012  if(ret == 0)\x0d\012  "; if (iIndex == index) return buffer; index++;
      buffer = "{\x0d\012    ATLASSERT(FALSE);\x0d\012    return NULL;\x0d\012  }\x0d\012  return lpa;\x0d\012}\x0d\012inline LPWSTR WINAPI AtlA2WHelper(LPWSTR lpw, LPCSTR lpa, int nChars) throw()\x0d\012{\x0d\012  return AtlA2WHelper(lpw, lpa, nChars, CP_ACP);\x0d\012}"; if (iIndex == index) return buffer; index++;
      buffer = "\x0d\x0a\x0d\012inline LPSTR WINAPI AtlW2AHelper(LPSTR lpa, LPCWSTR lpw, int nChars) throw()\x0d\012{\x0d\012  return AtlW2AHelper(lpa, lpw, nChars, CP_ACP);\x0d\012}\x0d\x0a\x0d\012#define A2W(lpa) (\\\x0d\012  ((_lpa = lpa) == NULL) ? NULL : (\\\x0d\012 "; if (iIndex == index) return buffer; index++;
      buffer = "   _convert = (lstrlenA(_lpa)+1),\\\x0d\012    ATLA2WHELPER((LPWSTR) alloca(_convert*2), _lpa, _convert, _acp)))\x0d\x0a\x0d\012#define W2A(lpw) (\\\x0d\012  ((_lpw = lpw) == NULL) ? NULL : (\\\x0d\012    _convert = (lstrlenW(_lpw)+1"; if (iIndex == index) return buffer; index++;
      buffer = ")*2,\\\x0d\012    ATLW2AHELPER((LPSTR) alloca(_convert), _lpw, _convert, _acp)))\x0d\x0a\x0d\012#define A2CW(lpa) ((LPCWSTR)A2W(lpa))\x0d\012#define W2CA(lpw) ((LPCSTR)W2A(lpw))\x0d\x0a\x0d\012#if defined(_UNICODE)\x0d\012// in these cases the"; if (iIndex == index) return buffer; index++;
      buffer = " default (TCHAR) is the same as OLECHAR\x0d\012  inline int ocslen(LPCOLESTR x) throw() { return lstrlenW(x); }\x0d\012  inline OLECHAR* ocscpy(LPOLESTR dest, LPCOLESTR src) throw() { return lstrcpyW(dest, src); "; if (iIndex == index) return buffer; index++;
      buffer = "}\x0d\012  inline OLECHAR* ocscat(LPOLESTR dest, LPCOLESTR src) throw() { return lstrcatW(dest, src); }\x0d\012  \x0d\012  inline LPCOLESTR T2COLE_EX(LPCTSTR lp, UINT) { return lp; }\x0d\012  inline LPCTSTR OLE2CT_EX(LPCOLES"; if (iIndex == index) return buffer; index++;
      buffer = "TR lp, UINT) { return lp; }\x0d\012  inline LPOLESTR T2OLE_EX(LPTSTR lp, UINT) { return lp; }\x0d\012  inline LPTSTR OLE2T_EX(LPOLESTR lp, UINT) { return lp; }  \x0d\x0a\x0d\012  #ifndef _ATL_EX_CONVERSION_MACROS_ONLY\x0d\x0a\x0d\012   "; if (iIndex == index) return buffer; index++;
      buffer = " inline LPCOLESTR T2COLE(LPCTSTR lp) { return lp; }\x0d\012    inline LPCTSTR OLE2CT(LPCOLESTR lp) { return lp; }\x0d\012    inline LPOLESTR T2OLE(LPTSTR lp) { return lp; }\x0d\012    inline LPTSTR OLE2T(LPOLESTR lp) {"; if (iIndex == index) return buffer; index++;
      buffer = " return lp; }\x0d\012    inline LPOLESTR CharNextO(LPCOLESTR lp) throw() {return CharNextW(lp);}\x0d\x0a\x0d\012  #endif   // _ATL_EX_CONVERSION_MACROS_ONLY\x0d\x0a\x0d\012#else\x0d\012  inline int ocslen(LPCOLESTR x) throw() { return l"; if (iIndex == index) return buffer; index++;
      buffer = "strlenW(x); }\x0d\012  //lstrcpyW doesn't work on Win95, so we do this\x0d\012  inline OLECHAR* ocscpy(LPOLESTR dest, LPCOLESTR src) throw()\x0d\012  {return (LPOLESTR) memcpy(dest, src, (lstrlenW(src)+1)*sizeof(WCHAR)"; if (iIndex == index) return buffer; index++;
      buffer = ");}\x0d\012  inline OLECHAR* ocscat(LPOLESTR dest, LPCOLESTR src) throw() { return ocscpy(dest+ocslen(dest), src); }\x0d\012  //CharNextW doesn't work on Win95 so we use this\x0d\012  \x0d\012  #define T2COLE_EX(lpa, nChar) "; if (iIndex == index) return buffer; index++;
      buffer = "A2CW_EX(lpa, nChar)\x0d\012  #define T2OLE_EX(lpa, nChar) A2W_EX(lpa, nChar)\x0d\012  #define OLE2CT_EX(lpo, nChar) W2CA_EX(lpo, nChar)\x0d\012  #define OLE2T_EX(lpo, nChar) W2A_EX(lpo, nChar)\x0d\x0a\x0d\012  #ifndef _ATL_EX_CONV"; if (iIndex == index) return buffer; index++;
      buffer = "ERSION_MACROS_ONLY\x0d\x0a\x0d\012    #define T2COLE(lpa) A2CW(lpa)\x0d\012    #define T2OLE(lpa) A2W(lpa)\x0d\012    #define OLE2CT(lpo) W2CA(lpo)\x0d\012    #define OLE2T(lpo) W2A(lpo)\x0d\x0a\x0d\012  #endif  // _ATL_EX_CONVERSION_MACROS_O"; if (iIndex == index) return buffer; index++;
      oLength = 111;
      buffer = "NLY\x0d\x0a\x0d\012  inline LPOLESTR CharNextO(LPCOLESTR lp) throw() {return (LPOLESTR) ((*lp) ? (lp+1) : lp);}\x0d\x0a\x0d\012#endif\x0d\x0a"; if (iIndex == index) return buffer; index++;
      oLength = 0;
      return NULL;
    }
    virtual const char * getMd5() { return "b3c689ca01b530324283203644374ef1"; }
    virtual char * newBuffer()
    {
      size_t size = getSize();
      char * buffer = new char[size];
      if (buffer == NULL)
        return NULL;
      size_t numSegments = getNumSegments();
      size_t segmentLength = 0;
      size_t index = 0;
      for(size_t i=0; i<numSegments; i++)
      {
        const char * segmentBuffer = getSegment(i, segmentLength);
        memcpy(&buffer[index], segmentBuffer, segmentLength);
        index += segmentLength;
      }
      return buffer;
    }
    virtual bool save(const char * iFilename)
    {
      FILE * f = fopen(iFilename, "wb");
      if (!f) return false;
      size_t numSegments = getNumSegments();
      size_t segmentLength = 0;
      const char * buffer = NULL;
      for(size_t i=0; i<numSegments; i++)
      {
        buffer = getSegment(i, segmentLength);
        fwrite(buffer, 1, segmentLength, f);
      }
      fclose(f);
      return true;
    }
  };
  File & getSmartPointersFile() { static SmartPointersFile _instance; return _instance; }
}; //bin2cpp
