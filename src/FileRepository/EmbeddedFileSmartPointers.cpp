/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'SmartPointers.h', last modified 1552247130.
 * Do not modify this file.
 */
#include "EmbeddedFileSmartPointers.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class SmartPointersFile : public virtual bin2cpp::File
  {
  public:
    SmartPointersFile() { build(); }
    virtual ~SmartPointersFile() {}
    virtual size_t getSize() const { return 9311; }
    virtual const char * getFilename() const { return "SmartPointers.h"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("#pragma once\r\n\r\n#define _T(expression) (expression)\r\n#define ATLASSERT(expression) assert(expression)\r\n#define CComBSTR BSTR\r\n#define ATLA2WHELPER AtlA2WHelper\r\n#define ATLW2AHELPER AtlW2AHelper\r\n\r\n//", 200);
      mBuffer.append("///////////////////////////////////////////////////////////////////////////\r\n// COM Smart pointers\r\n\r\ntemplate <class T>\r\nclass _NoAddRefReleaseOnCComPtr : public T\r\n{\r\n  private:\r\n    STDMETHOD_(ULON", 200);
      mBuffer.append("G, AddRef)()=0;\r\n    STDMETHOD_(ULONG, Release)()=0;\r\n};\r\n\r\n//CComPtrBase provides the basis for all other smart pointers\r\n//The other smartpointers add their own constructors and operators\r\ntemplate ", 200);
      mBuffer.append("<class T>\r\nclass CComPtrBase\r\n{\r\nprotected:\r\n  CComPtrBase() throw()\r\n  {\r\n    p = NULL;\r\n  }\r\n  CComPtrBase(int nNull) throw()\r\n  {\r\n    ATLASSERT(nNull == 0);\r\n    (void)nNull;\r\n    p = NULL;\r\n  }\r\n", 200);
      mBuffer.append("  CComPtrBase(T* lp) throw()\r\n  {\r\n    p = lp;\r\n    if (p != NULL)\r\n      p->AddRef();\r\n  }\r\npublic:\r\n  typedef T _PtrClass;\r\n  ~CComPtrBase() throw()\r\n  {\r\n    if (p)\r\n      p->Release();\r\n  }\r\n  ope", 200);
      mBuffer.append("rator T*() const throw()\r\n  {\r\n    return p;\r\n  }\r\n  T& operator*() const throw()\r\n  {\r\n    ATLASSERT(p!=NULL);\r\n    return *p;\r\n  }\r\n  //The assert on operator& usually indicates a bug.  If this is r", 200);
      mBuffer.append("eally\r\n  //what is needed, however, take the address of the p member explicitly.\r\n  T** operator&() throw()\r\n  {\r\n    ATLASSERT(p==NULL);\r\n    return &p;\r\n  }\r\n  _NoAddRefReleaseOnCComPtr<T>* operator", 200);
      mBuffer.append("->() const throw()\r\n  {\r\n    ATLASSERT(p!=NULL);\r\n    return (_NoAddRefReleaseOnCComPtr<T>*)p;\r\n  }\r\n  bool operator!() const throw()\r\n  {\r\n    return (p == NULL);\r\n  }\r\n  bool operator<(T* pT) const ", 200);
      mBuffer.append("throw()\r\n  {\r\n    return p < pT;\r\n  }\r\n  bool operator==(T* pT) const throw()\r\n  {\r\n    return p == pT;\r\n  }\r\n\r\n  // Release the interface and set to NULL\r\n  void Release() throw()\r\n  {\r\n    T* pTemp ", 200);
      mBuffer.append("= p;\r\n    if (pTemp)\r\n    {\r\n      p = NULL;\r\n      pTemp->Release();\r\n    }\r\n  }\r\n  // Compare two objects for equivalence\r\n  bool IsEqualObject(IUnknown* pOther) throw()\r\n  {\r\n    if (p == NULL && p", 200);
      mBuffer.append("Other == NULL)\r\n      return true;  // They are both NULL objects\r\n\r\n    if (p == NULL || pOther == NULL)\r\n      return false;  // One is NULL the other is not\r\n\r\n    CComPtr<IUnknown> punk1;\r\n    CCo", 200);
      mBuffer.append("mPtr<IUnknown> punk2;\r\n    p->QueryInterface(__uuidof(IUnknown), (void**)&punk1);\r\n    pOther->QueryInterface(__uuidof(IUnknown), (void**)&punk2);\r\n    return punk1 == punk2;\r\n  }\r\n  // Attach to an e", 200);
      mBuffer.append("xisting interface (does not AddRef)\r\n  void Attach(T* p2) throw()\r\n  {\r\n    if (p)\r\n      p->Release();\r\n    p = p2;\r\n  }\r\n  // Detach the interface (does not Release)\r\n  T* Detach() throw()\r\n  {\r\n   ", 200);
      mBuffer.append(" T* pt = p;\r\n    p = NULL;\r\n    return pt;\r\n  }\r\n  HRESULT CopyTo(T** ppT) throw()\r\n  {\r\n    ATLASSERT(ppT != NULL);\r\n    if (ppT == NULL)\r\n      return E_POINTER;\r\n    *ppT = p;\r\n    if (p)\r\n      p-", 200);
      mBuffer.append(">AddRef();\r\n    return S_OK;\r\n  }\r\n  HRESULT SetSite(IUnknown* punkParent) throw()\r\n  {\r\n    return AtlSetChildSite(p, punkParent);\r\n  }\r\n  HRESULT Advise(IUnknown* pUnk, const IID& iid, LPDWORD pdw) ", 200);
      mBuffer.append("throw()\r\n  {\r\n    return AtlAdvise(p, pUnk, iid, pdw);\r\n  }\r\n  HRESULT CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL) throw()\r\n  {\r\n    ATLASSERT(p == N", 200);
      mBuffer.append("ULL);\r\n    return ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, __uuidof(T), (void**)&p);\r\n  }\r\n  HRESULT CoCreateInstance(LPCOLESTR szProgID, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CL", 200);
      mBuffer.append("SCTX_ALL) throw()\r\n  {\r\n    CLSID clsid;\r\n    HRESULT hr = CLSIDFromProgID(szProgID, &clsid);\r\n    ATLASSERT(p == NULL);\r\n    if (SUCCEEDED(hr))\r\n      hr = ::CoCreateInstance(clsid, pUnkOuter, dwClsC", 200);
      mBuffer.append("ontext, __uuidof(T), (void**)&p);\r\n    return hr;\r\n  }\r\n  template <class Q>\r\n  HRESULT QueryInterface(Q** pp) const throw()\r\n  {\r\n    ATLASSERT(pp != NULL);\r\n    return p->QueryInterface(__uuidof(Q),", 200);
      mBuffer.append(" (void**)pp);\r\n  }\r\n  T* p;\r\n};\r\n\r\ntemplate <class T>\r\nclass CComPtr : public CComPtrBase<T>\r\n{\r\npublic:\r\n  CComPtr() throw()\r\n  {\r\n  }\r\n  CComPtr(int nNull) throw() :\r\n    CComPtrBase<T>(nNull)\r\n  {\r", 200);
      mBuffer.append("\n  }\r\n  /*\r\n  template <typename Q>\r\n  CComPtr(Q* lp)\r\n  {\r\n    if (lp != NULL)\r\n      lp->QueryInterface(__uuidof(Q), (void**)&p);\r\n    else\r\n      p = NULL;\r\n  }\r\n  template <>\r\n  */\r\n  CComPtr(T* l", 200);
      mBuffer.append("p) throw() :\r\n    CComPtrBase<T>(lp)\r\n\r\n  {\r\n  }\r\n  CComPtr(const CComPtr<T>& lp) throw() :\r\n    CComPtrBase<T>(lp.p)\r\n  {\r\n  }\r\n//  template<>\r\n  /*\r\n  T* operator=(void* lp)\r\n  {\r\n    return (T*)Atl", 200);
      mBuffer.append("ComPtrAssign((IUnknown**)&p, (T*)lp);\r\n  }\r\n  */\r\n  /*\r\n  template <typename Q>\r\n  T* operator=(Q* lp)\r\n  {\r\n    return (T*)AtlComQIPtrAssign((IUnknown**)&p, lp, __uuidof(T));\r\n  }\r\n  template <>\r\n  *", 200);
      mBuffer.append("/\r\n  T* operator=(T* lp) throw()\r\n  {\r\n    return static_cast<T*>(AtlComPtrAssign((IUnknown**)&p, lp));\r\n  }\r\n  template <typename Q>\r\n  T* operator=(const CComPtr<Q>& lp) throw()\r\n  {\r\n    return sta", 200);
      mBuffer.append("tic_cast<T*>(AtlComQIPtrAssign((IUnknown**)&p, lp, __uuidof(T)));\r\n  }\r\n\r\n  //if before VS2005 (all versions of VS2003)\r\n  #if (_MSC_VER < 1400)\r\n  template <>\r\n  T* operator=(const CComPtr<T>& lp) th", 200);
      mBuffer.append("row()\r\n  {\r\n    return static_cast<T*>(AtlComPtrAssign((IUnknown**)&p, lp));\r\n  }\r\n  #endif\r\n};\r\n\r\n\r\n//ATL replacement macros\r\n#ifndef _DEBUG\r\n  #define USES_CONVERSION int _convert; (_convert); UINT ", 200);
      mBuffer.append("_acp = /*ATL::_AtlGetConversionACP()*/ CP_THREAD_ACP; (_acp); LPCWSTR _lpw; (_lpw); LPCSTR _lpa; (_lpa)\r\n#else\r\n  #define USES_CONVERSION int _convert = 0; (_convert); UINT _acp = /*ATL::_AtlGetConver", 200);
      mBuffer.append("sionACP()*/ CP_THREAD_ACP; (_acp); LPCWSTR _lpw = NULL; (_lpw); LPCSTR _lpa = NULL; (_lpa)\r\n#endif\r\n\r\n/////////////////////////////////////////////////////////////////////////////\r\n// Global UNICODE<>", 200);
      mBuffer.append("ANSI translation helpers\r\ninline LPWSTR WINAPI AtlA2WHelper(LPWSTR lpw, LPCSTR lpa, int nChars, UINT acp) throw()\r\n{\r\n  ATLASSERT(lpa != NULL);\r\n  ATLASSERT(lpw != NULL);\r\n  if (lpw == NULL || lpa == ", 200);
      mBuffer.append("NULL)\r\n    return NULL;\r\n  // verify that no illegal character present\r\n  // since lpw was allocated based on the size of lpa\r\n  // don\'t worry about the number of chars\r\n  lpw[0] = \'\\0\';\r\n  int ret =", 200);
      mBuffer.append(" MultiByteToWideChar(acp, 0, lpa, -1, lpw, nChars);\r\n  if(ret == 0)\r\n  {\r\n    ATLASSERT(FALSE);\r\n    return NULL;\r\n  }    \r\n  return lpw;\r\n}\r\n\r\ninline LPSTR WINAPI AtlW2AHelper(LPSTR lpa, LPCWSTR lpw,", 200);
      mBuffer.append(" int nChars, UINT acp) throw()\r\n{\r\n  ATLASSERT(lpw != NULL);\r\n  ATLASSERT(lpa != NULL);\r\n  if (lpa == NULL || lpw == NULL)\r\n    return NULL;\r\n  // verify that no illegal character present\r\n  // since ", 200);
      mBuffer.append("lpa was allocated based on the size of lpw\r\n  // don\'t worry about the number of chars\r\n  lpa[0] = \'\\0\';\r\n  int ret = WideCharToMultiByte(acp, 0, lpw, -1, lpa, nChars, NULL, NULL);\r\n  if(ret == 0)\r\n  ", 200);
      mBuffer.append("{\r\n    ATLASSERT(FALSE);\r\n    return NULL;\r\n  }\r\n  return lpa;\r\n}\r\ninline LPWSTR WINAPI AtlA2WHelper(LPWSTR lpw, LPCSTR lpa, int nChars) throw()\r\n{\r\n  return AtlA2WHelper(lpw, lpa, nChars, CP_ACP);\r\n}", 200);
      mBuffer.append("\r\n\r\ninline LPSTR WINAPI AtlW2AHelper(LPSTR lpa, LPCWSTR lpw, int nChars) throw()\r\n{\r\n  return AtlW2AHelper(lpa, lpw, nChars, CP_ACP);\r\n}\r\n\r\n#define A2W(lpa) (\\\r\n  ((_lpa = lpa) == NULL) \? NULL : (\\\r\n ", 200);
      mBuffer.append("   _convert = (lstrlenA(_lpa)+1),\\\r\n    ATLA2WHELPER((LPWSTR) alloca(_convert*2), _lpa, _convert, _acp)))\r\n\r\n#define W2A(lpw) (\\\r\n  ((_lpw = lpw) == NULL) \? NULL : (\\\r\n    _convert = (lstrlenW(_lpw)+1", 200);
      mBuffer.append(")*2,\\\r\n    ATLW2AHELPER((LPSTR) alloca(_convert), _lpw, _convert, _acp)))\r\n\r\n#define A2CW(lpa) ((LPCWSTR)A2W(lpa))\r\n#define W2CA(lpw) ((LPCSTR)W2A(lpw))\r\n\r\n#if defined(_UNICODE)\r\n// in these cases the", 200);
      mBuffer.append(" default (TCHAR) is the same as OLECHAR\r\n  inline int ocslen(LPCOLESTR x) throw() { return lstrlenW(x); }\r\n  inline OLECHAR* ocscpy(LPOLESTR dest, LPCOLESTR src) throw() { return lstrcpyW(dest, src); ", 200);
      mBuffer.append("}\r\n  inline OLECHAR* ocscat(LPOLESTR dest, LPCOLESTR src) throw() { return lstrcatW(dest, src); }\r\n  \r\n  inline LPCOLESTR T2COLE_EX(LPCTSTR lp, UINT) { return lp; }\r\n  inline LPCTSTR OLE2CT_EX(LPCOLES", 200);
      mBuffer.append("TR lp, UINT) { return lp; }\r\n  inline LPOLESTR T2OLE_EX(LPTSTR lp, UINT) { return lp; }\r\n  inline LPTSTR OLE2T_EX(LPOLESTR lp, UINT) { return lp; }  \r\n\r\n  #ifndef _ATL_EX_CONVERSION_MACROS_ONLY\r\n\r\n   ", 200);
      mBuffer.append(" inline LPCOLESTR T2COLE(LPCTSTR lp) { return lp; }\r\n    inline LPCTSTR OLE2CT(LPCOLESTR lp) { return lp; }\r\n    inline LPOLESTR T2OLE(LPTSTR lp) { return lp; }\r\n    inline LPTSTR OLE2T(LPOLESTR lp) {", 200);
      mBuffer.append(" return lp; }\r\n    inline LPOLESTR CharNextO(LPCOLESTR lp) throw() {return CharNextW(lp);}\r\n\r\n  #endif   // _ATL_EX_CONVERSION_MACROS_ONLY\r\n\r\n#else\r\n  inline int ocslen(LPCOLESTR x) throw() { return l", 200);
      mBuffer.append("strlenW(x); }\r\n  //lstrcpyW doesn\'t work on Win95, so we do this\r\n  inline OLECHAR* ocscpy(LPOLESTR dest, LPCOLESTR src) throw()\r\n  {return (LPOLESTR) memcpy(dest, src, (lstrlenW(src)+1)*sizeof(WCHAR)", 200);
      mBuffer.append(");}\r\n  inline OLECHAR* ocscat(LPOLESTR dest, LPCOLESTR src) throw() { return ocscpy(dest+ocslen(dest), src); }\r\n  //CharNextW doesn\'t work on Win95 so we use this\r\n  \r\n  #define T2COLE_EX(lpa, nChar) ", 200);
      mBuffer.append("A2CW_EX(lpa, nChar)\r\n  #define T2OLE_EX(lpa, nChar) A2W_EX(lpa, nChar)\r\n  #define OLE2CT_EX(lpo, nChar) W2CA_EX(lpo, nChar)\r\n  #define OLE2T_EX(lpo, nChar) W2A_EX(lpo, nChar)\r\n\r\n  #ifndef _ATL_EX_CONV", 200);
      mBuffer.append("ERSION_MACROS_ONLY\r\n\r\n    #define T2COLE(lpa) A2CW(lpa)\r\n    #define T2OLE(lpa) A2W(lpa)\r\n    #define OLE2CT(lpo) W2CA(lpo)\r\n    #define OLE2T(lpo) W2A(lpo)\r\n\r\n  #endif  // _ATL_EX_CONVERSION_MACROS_O", 200);
      mBuffer.append("NLY\r\n\r\n  inline LPOLESTR CharNextO(LPCOLESTR lp) throw() {return (LPOLESTR) ((*lp) \? (lp+1) : lp);}\r\n\r\n#endif\r\n", 111);
    }
    virtual bool save(const char * iFilename) const
    {
      FILE * f = fopen(iFilename, "wb");
      if (!f) return false;
      size_t fileSize = getSize();
      const char * buffer = getBuffer();
      fwrite(buffer, 1, fileSize, f);
      fclose(f);
      return true;
    }
  private:
    std::string mBuffer;
  };
  const File & getSmartPointersFile() { static SmartPointersFile _instance; return _instance; }
}; //bin2cpp
