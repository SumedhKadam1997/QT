#ifndef _SYSTEM_DRAWING_COMISTREAMWRAPPER_H_
#define _SYSTEM_DRAWING_COMISTREAMWRAPPER_H_
#ifdef WIN32
#include <windows.h>
#include <gdiplus.h>
#else

#endif // WIN32

#include "Aspose.Cells.Systems/IO/Stream.h"

using namespace Aspose::Cells::Systems;
using namespace Aspose::Cells::Systems::IO;

namespace Aspose {
	namespace Cells {
		namespace Systems {
			namespace Drawing {
#ifdef WIN32
				class ComIStreamWrapper : public IStream, public reference_counter
				{
				private:
					intrusive_ptr<Stream> _baseStream;
					Int64 _position;
					LONG _refcount;
#else
				class ComIStreamWrapper : /*public IStream, */public reference_counter //Linux
				{
				private:
					intrusive_ptr<Stream> _baseStream;
					Int64 _position;
					long _refcount;
#endif
				public:
					ComIStreamWrapper(intrusive_ptr<Stream> stream);
					virtual ~ComIStreamWrapper();
#ifdef WIN32
					virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void ** ppvObject);
					virtual ULONG STDMETHODCALLTYPE AddRef(void);
					virtual ULONG STDMETHODCALLTYPE Release(void);

					// ISequentialStream Interface
					virtual HRESULT STDMETHODCALLTYPE Read(void* pv, ULONG cb, ULONG* pcbRead);
					virtual HRESULT STDMETHODCALLTYPE Write(void const* pv, ULONG cb, ULONG* pcbWritten);

					// IStream Interface
					virtual HRESULT STDMETHODCALLTYPE SetSize(ULARGE_INTEGER);
					virtual HRESULT STDMETHODCALLTYPE CopyTo(IStream*, ULARGE_INTEGER, ULARGE_INTEGER*,
						ULARGE_INTEGER*);
					virtual HRESULT STDMETHODCALLTYPE Commit(DWORD);
					virtual HRESULT STDMETHODCALLTYPE Revert(void);
					virtual HRESULT STDMETHODCALLTYPE LockRegion(ULARGE_INTEGER, ULARGE_INTEGER, DWORD);
					virtual HRESULT STDMETHODCALLTYPE UnlockRegion(ULARGE_INTEGER, ULARGE_INTEGER, DWORD);
					virtual HRESULT STDMETHODCALLTYPE Clone(IStream **);
					virtual HRESULT STDMETHODCALLTYPE Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin,
						ULARGE_INTEGER* plibNewPosition);
					virtual HRESULT STDMETHODCALLTYPE Stat(STATSTG* pStatstg, DWORD grfStatFlag);
#endif
				private:
					void SetSizeToPosition();

				};

			}
		}
	}
}
#endif
