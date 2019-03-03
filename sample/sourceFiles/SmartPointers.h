#pragma once

#define _T(expression) (expression)
#define ATLASSERT(expression) assert(expression)
#define CComBSTR BSTR
#define ATLA2WHELPER AtlA2WHelper
#define ATLW2AHELPER AtlW2AHelper

/////////////////////////////////////////////////////////////////////////////
// COM Smart pointers

template <class T>
class _NoAddRefReleaseOnCComPtr : public T
{
  private:
    STDMETHOD_(ULONG, AddRef)()=0;
    STDMETHOD_(ULONG, Release)()=0;
};

//CComPtrBase provides the basis for all other smart pointers
//The other smartpointers add their own constructors and operators
template <class T>
class CComPtrBase
{
protected:
  CComPtrBase() throw()
  {
    p = NULL;
  }
  CComPtrBase(int nNull) throw()
  {
    ATLASSERT(nNull == 0);
    (void)nNull;
    p = NULL;
  }
  CComPtrBase(T* lp) throw()
  {
    p = lp;
    if (p != NULL)
      p->AddRef();
  }
public:
  typedef T _PtrClass;
  ~CComPtrBase() throw()
  {
    if (p)
      p->Release();
  }
  operator T*() const throw()
  {
    return p;
  }
  T& operator*() const throw()
  {
    ATLASSERT(p!=NULL);
    return *p;
  }
  //The assert on operator& usually indicates a bug.  If this is really
  //what is needed, however, take the address of the p member explicitly.
  T** operator&() throw()
  {
    ATLASSERT(p==NULL);
    return &p;
  }
  _NoAddRefReleaseOnCComPtr<T>* operator->() const throw()
  {
    ATLASSERT(p!=NULL);
    return (_NoAddRefReleaseOnCComPtr<T>*)p;
  }
  bool operator!() const throw()
  {
    return (p == NULL);
  }
  bool operator<(T* pT) const throw()
  {
    return p < pT;
  }
  bool operator==(T* pT) const throw()
  {
    return p == pT;
  }

  // Release the interface and set to NULL
  void Release() throw()
  {
    T* pTemp = p;
    if (pTemp)
    {
      p = NULL;
      pTemp->Release();
    }
  }
  // Compare two objects for equivalence
  bool IsEqualObject(IUnknown* pOther) throw()
  {
    if (p == NULL && pOther == NULL)
      return true;  // They are both NULL objects

    if (p == NULL || pOther == NULL)
      return false;  // One is NULL the other is not

    CComPtr<IUnknown> punk1;
    CComPtr<IUnknown> punk2;
    p->QueryInterface(__uuidof(IUnknown), (void**)&punk1);
    pOther->QueryInterface(__uuidof(IUnknown), (void**)&punk2);
    return punk1 == punk2;
  }
  // Attach to an existing interface (does not AddRef)
  void Attach(T* p2) throw()
  {
    if (p)
      p->Release();
    p = p2;
  }
  // Detach the interface (does not Release)
  T* Detach() throw()
  {
    T* pt = p;
    p = NULL;
    return pt;
  }
  HRESULT CopyTo(T** ppT) throw()
  {
    ATLASSERT(ppT != NULL);
    if (ppT == NULL)
      return E_POINTER;
    *ppT = p;
    if (p)
      p->AddRef();
    return S_OK;
  }
  HRESULT SetSite(IUnknown* punkParent) throw()
  {
    return AtlSetChildSite(p, punkParent);
  }
  HRESULT Advise(IUnknown* pUnk, const IID& iid, LPDWORD pdw) throw()
  {
    return AtlAdvise(p, pUnk, iid, pdw);
  }
  HRESULT CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL) throw()
  {
    ATLASSERT(p == NULL);
    return ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, __uuidof(T), (void**)&p);
  }
  HRESULT CoCreateInstance(LPCOLESTR szProgID, LPUNKNOWN pUnkOuter = NULL, DWORD dwClsContext = CLSCTX_ALL) throw()
  {
    CLSID clsid;
    HRESULT hr = CLSIDFromProgID(szProgID, &clsid);
    ATLASSERT(p == NULL);
    if (SUCCEEDED(hr))
      hr = ::CoCreateInstance(clsid, pUnkOuter, dwClsContext, __uuidof(T), (void**)&p);
    return hr;
  }
  template <class Q>
  HRESULT QueryInterface(Q** pp) const throw()
  {
    ATLASSERT(pp != NULL);
    return p->QueryInterface(__uuidof(Q), (void**)pp);
  }
  T* p;
};

template <class T>
class CComPtr : public CComPtrBase<T>
{
public:
  CComPtr() throw()
  {
  }
  CComPtr(int nNull) throw() :
    CComPtrBase<T>(nNull)
  {
  }
  /*
  template <typename Q>
  CComPtr(Q* lp)
  {
    if (lp != NULL)
      lp->QueryInterface(__uuidof(Q), (void**)&p);
    else
      p = NULL;
  }
  template <>
  */
  CComPtr(T* lp) throw() :
    CComPtrBase<T>(lp)

  {
  }
  CComPtr(const CComPtr<T>& lp) throw() :
    CComPtrBase<T>(lp.p)
  {
  }
//  template<>
  /*
  T* operator=(void* lp)
  {
    return (T*)AtlComPtrAssign((IUnknown**)&p, (T*)lp);
  }
  */
  /*
  template <typename Q>
  T* operator=(Q* lp)
  {
    return (T*)AtlComQIPtrAssign((IUnknown**)&p, lp, __uuidof(T));
  }
  template <>
  */
  T* operator=(T* lp) throw()
  {
    return static_cast<T*>(AtlComPtrAssign((IUnknown**)&p, lp));
  }
  template <typename Q>
  T* operator=(const CComPtr<Q>& lp) throw()
  {
    return static_cast<T*>(AtlComQIPtrAssign((IUnknown**)&p, lp, __uuidof(T)));
  }

  //if before VS2005 (all versions of VS2003)
  #if (_MSC_VER < 1400)
  template <>
  T* operator=(const CComPtr<T>& lp) throw()
  {
    return static_cast<T*>(AtlComPtrAssign((IUnknown**)&p, lp));
  }
  #endif
};


//ATL replacement macros
#ifndef _DEBUG
  #define USES_CONVERSION int _convert; (_convert); UINT _acp = /*ATL::_AtlGetConversionACP()*/ CP_THREAD_ACP; (_acp); LPCWSTR _lpw; (_lpw); LPCSTR _lpa; (_lpa)
#else
  #define USES_CONVERSION int _convert = 0; (_convert); UINT _acp = /*ATL::_AtlGetConversionACP()*/ CP_THREAD_ACP; (_acp); LPCWSTR _lpw = NULL; (_lpw); LPCSTR _lpa = NULL; (_lpa)
#endif

/////////////////////////////////////////////////////////////////////////////
// Global UNICODE<>ANSI translation helpers
inline LPWSTR WINAPI AtlA2WHelper(LPWSTR lpw, LPCSTR lpa, int nChars, UINT acp) throw()
{
  ATLASSERT(lpa != NULL);
  ATLASSERT(lpw != NULL);
  if (lpw == NULL || lpa == NULL)
    return NULL;
  // verify that no illegal character present
  // since lpw was allocated based on the size of lpa
  // don't worry about the number of chars
  lpw[0] = '\0';
  int ret = MultiByteToWideChar(acp, 0, lpa, -1, lpw, nChars);
  if(ret == 0)
  {
    ATLASSERT(FALSE);
    return NULL;
  }    
  return lpw;
}

inline LPSTR WINAPI AtlW2AHelper(LPSTR lpa, LPCWSTR lpw, int nChars, UINT acp) throw()
{
  ATLASSERT(lpw != NULL);
  ATLASSERT(lpa != NULL);
  if (lpa == NULL || lpw == NULL)
    return NULL;
  // verify that no illegal character present
  // since lpa was allocated based on the size of lpw
  // don't worry about the number of chars
  lpa[0] = '\0';
  int ret = WideCharToMultiByte(acp, 0, lpw, -1, lpa, nChars, NULL, NULL);
  if(ret == 0)
  {
    ATLASSERT(FALSE);
    return NULL;
  }
  return lpa;
}
inline LPWSTR WINAPI AtlA2WHelper(LPWSTR lpw, LPCSTR lpa, int nChars) throw()
{
  return AtlA2WHelper(lpw, lpa, nChars, CP_ACP);
}

inline LPSTR WINAPI AtlW2AHelper(LPSTR lpa, LPCWSTR lpw, int nChars) throw()
{
  return AtlW2AHelper(lpa, lpw, nChars, CP_ACP);
}

#define A2W(lpa) (\
  ((_lpa = lpa) == NULL) ? NULL : (\
    _convert = (lstrlenA(_lpa)+1),\
    ATLA2WHELPER((LPWSTR) alloca(_convert*2), _lpa, _convert, _acp)))

#define W2A(lpw) (\
  ((_lpw = lpw) == NULL) ? NULL : (\
    _convert = (lstrlenW(_lpw)+1)*2,\
    ATLW2AHELPER((LPSTR) alloca(_convert), _lpw, _convert, _acp)))

#define A2CW(lpa) ((LPCWSTR)A2W(lpa))
#define W2CA(lpw) ((LPCSTR)W2A(lpw))

#if defined(_UNICODE)
// in these cases the default (TCHAR) is the same as OLECHAR
  inline int ocslen(LPCOLESTR x) throw() { return lstrlenW(x); }
  inline OLECHAR* ocscpy(LPOLESTR dest, LPCOLESTR src) throw() { return lstrcpyW(dest, src); }
  inline OLECHAR* ocscat(LPOLESTR dest, LPCOLESTR src) throw() { return lstrcatW(dest, src); }
  
  inline LPCOLESTR T2COLE_EX(LPCTSTR lp, UINT) { return lp; }
  inline LPCTSTR OLE2CT_EX(LPCOLESTR lp, UINT) { return lp; }
  inline LPOLESTR T2OLE_EX(LPTSTR lp, UINT) { return lp; }
  inline LPTSTR OLE2T_EX(LPOLESTR lp, UINT) { return lp; }  

  #ifndef _ATL_EX_CONVERSION_MACROS_ONLY

    inline LPCOLESTR T2COLE(LPCTSTR lp) { return lp; }
    inline LPCTSTR OLE2CT(LPCOLESTR lp) { return lp; }
    inline LPOLESTR T2OLE(LPTSTR lp) { return lp; }
    inline LPTSTR OLE2T(LPOLESTR lp) { return lp; }
    inline LPOLESTR CharNextO(LPCOLESTR lp) throw() {return CharNextW(lp);}

  #endif   // _ATL_EX_CONVERSION_MACROS_ONLY

#else
  inline int ocslen(LPCOLESTR x) throw() { return lstrlenW(x); }
  //lstrcpyW doesn't work on Win95, so we do this
  inline OLECHAR* ocscpy(LPOLESTR dest, LPCOLESTR src) throw()
  {return (LPOLESTR) memcpy(dest, src, (lstrlenW(src)+1)*sizeof(WCHAR));}
  inline OLECHAR* ocscat(LPOLESTR dest, LPCOLESTR src) throw() { return ocscpy(dest+ocslen(dest), src); }
  //CharNextW doesn't work on Win95 so we use this
  
  #define T2COLE_EX(lpa, nChar) A2CW_EX(lpa, nChar)
  #define T2OLE_EX(lpa, nChar) A2W_EX(lpa, nChar)
  #define OLE2CT_EX(lpo, nChar) W2CA_EX(lpo, nChar)
  #define OLE2T_EX(lpo, nChar) W2A_EX(lpo, nChar)

  #ifndef _ATL_EX_CONVERSION_MACROS_ONLY

    #define T2COLE(lpa) A2CW(lpa)
    #define T2OLE(lpa) A2W(lpa)
    #define OLE2CT(lpo) W2CA(lpo)
    #define OLE2T(lpo) W2A(lpo)

  #endif  // _ATL_EX_CONVERSION_MACROS_ONLY

  inline LPOLESTR CharNextO(LPCOLESTR lp) throw() {return (LPOLESTR) ((*lp) ? (lp+1) : lp);}

#endif
