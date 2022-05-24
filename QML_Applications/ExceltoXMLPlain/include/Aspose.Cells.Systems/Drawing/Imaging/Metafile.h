#ifndef _SYSTEM_DRAWING_IMAGING_METAFILE_H_
#define _SYSTEM_DRAWING_IMAGING_METAFILE_H_

#ifdef WIN32
#include <windows.h>
#include <gdiplus.h>

#else
//#include "GdiPlusFlat.h"
#include "gdipenums.h"
#endif // WIN32

#include "Aspose.Cells.Systems/Drawing/Image.h"
#include "Aspose.Cells.Systems/Drawing/Rectangle.h"
#include "Aspose.Cells.Systems/Drawing/RectangleF.h"
#include "Aspose.Cells.Systems/Object.h"
#include "Aspose.Cells.Systems/String.h"
#include "Aspose.Cells.Systems/IO/Stream.h"
#include "Aspose.Cells.Systems/Drawing/Imaging/MetafileFrameUnit.h"
#include "Aspose.Cells.Systems/IntegerPtr.h"
#include "Aspose.Cells.Systems/Drawing/Imaging/EmfType.h"
#include "Aspose.Cells.Systems/Drawing/ComIStreamWrapper.h"
using namespace Aspose::Cells::Systems;
using namespace Aspose::Cells::Systems::Drawing;
using namespace Aspose::Cells::Systems::IO;

namespace Aspose {
	namespace Cells {
		namespace Systems {
			namespace Drawing {
				namespace Imaging {
					class ASPOSE_CELLS_API Metafile : public Image
					{
					private:
						//void* nativeObject;			// should be removed when added to Image class
						//intrusive_ptr<Stream> stream;	// should be removed when added to Image class

						/*
						  Can not define IStream * _istreamWrapper = NULL
						  cause if do this the ~ComIStreamWrapper can not be called
						  (the destructor of IStream is not virtual  )
						 */

						ComIStreamWrapper* _istreamWrapper = NULL;
					public:
						virtual ~Metafile();
						Metafile(intrusive_ptr<IntegerPtr> ptr, intrusive_ptr<Stream> stream);
						Metafile(intrusive_ptr<Stream> stream);
						Metafile(StringPtr filename);
						Metafile(HENHMETAFILE henhmetafile, bool deleteEmf);
#ifdef WIN32
						Metafile(HDC referenceHdc, Gdiplus::EmfType emfType);
					    Metafile(HENHMETAFILE hmetafile, Gdiplus::WmfPlaceableFileHeader wmfHeader);
						Metafile(HDC referenceHdc, Gdiplus::EmfType emfType, StringPtr description);
						Metafile(HENHMETAFILE hmetafile, Gdiplus::WmfPlaceableFileHeader wmfHeader, bool deleteWmf);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, Gdiplus::EmfType type);
						Metafile(StringPtr fileName, HDC referenceHdc, Gdiplus::EmfType type);
						Metafile(HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type);
						Metafile(HDC referenceHdc, intrusive_ptr<RectangleF> frameRect, Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, Gdiplus::EmfType type, StringPtr description);
						Metafile(StringPtr fileName, HDC referenceHdc, Gdiplus::EmfType type, StringPtr description);
						Metafile(HDC referenceHdc, intrusive_ptr<Rectangle> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type, StringPtr description);
						Metafile(HDC referenceHdc, intrusive_ptr<RectangleF> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type, StringPtr description);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect, Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect, Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type, StringPtr description);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type, StringPtr description);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type, StringPtr description);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Gdiplus::EmfType type, StringPtr description);
#else
						Metafile(HDC referenceHdc, ::EmfType emfType);
						Metafile(HENHMETAFILE hmetafile,  WmfPlaceableFileHeader wmfHeader);
						Metafile(HDC referenceHdc, ::EmfType emfType, StringPtr description);
						Metafile(HENHMETAFILE hmetafile, WmfPlaceableFileHeader wmfHeader, bool deleteWmf);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, ::EmfType type);
						Metafile(StringPtr fileName, HDC referenceHdc, ::EmfType type);
						Metafile(HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit,  ::EmfType type);
						Metafile(HDC referenceHdc, intrusive_ptr<RectangleF> frameRect, Imaging::MetafileFrameUnit frameUnit, ::EmfType type);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, ::EmfType type, StringPtr description);
						Metafile(StringPtr fileName, HDC referenceHdc, ::EmfType type, StringPtr description);
						Metafile(HDC referenceHdc, intrusive_ptr<Aspose::Cells::Systems::Drawing::Rectangle> frameRect,
							Imaging::MetafileFrameUnit frameUnit, ::EmfType type, StringPtr description);
						Metafile(HDC referenceHdc, intrusive_ptr<RectangleF> frameRect,
							Imaging::MetafileFrameUnit frameUnit, ::EmfType type, StringPtr description);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit, ::EmfType type);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect, Imaging::MetafileFrameUnit frameUnit, ::EmfType type);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit,::EmfType type);
						
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect, Imaging::MetafileFrameUnit frameUnit, ::EmfType type);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect,
							Imaging::MetafileFrameUnit frameUnit, ::EmfType type, StringPtr description);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect,
							Imaging::MetafileFrameUnit frameUnit, ::EmfType type, StringPtr description);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect,
							Imaging::MetafileFrameUnit frameUnit, ::EmfType type, StringPtr description);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect,
							Imaging::MetafileFrameUnit frameUnit, ::EmfType type, StringPtr description);
#endif
						Metafile(HDC referenceHdc, intrusive_ptr<Aspose::Cells::Systems::Drawing::Rectangle> frameRect);
						Metafile(HDC referenceHdc, intrusive_ptr<Aspose::Cells::Systems::Drawing::RectangleF> frameRect);

						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc);
						Metafile(StringPtr fileName, HDC referenceHdc);

						Metafile(HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit);
						Metafile(HDC referenceHdc, intrusive_ptr<RectangleF> frameRect, Imaging::MetafileFrameUnit frameUnit);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit);
						Metafile(intrusive_ptr<Stream> stream, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect, Imaging::MetafileFrameUnit frameUnit);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect,Imaging::MetafileFrameUnit frameUnit);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<Rectangle> frameRect, Imaging::MetafileFrameUnit frameUnit, StringPtr description);
						Metafile(StringPtr fileName, HDC referenceHdc, intrusive_ptr<RectangleF> frameRect,Imaging::MetafileFrameUnit frameUnit, StringPtr description);


						Metafile(intrusive_ptr<Stream> stream, intrusive_ptr<IntegerPtr> referenceHdc, intrusive_ptr<Rectangle> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Systems::Drawing::Imaging::EmfType type);
						Metafile(intrusive_ptr<Stream> stream, intrusive_ptr<IntegerPtr> referenceHdc, intrusive_ptr<RectangleF> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Imaging::EmfType type);
						Metafile(intrusive_ptr<Stream> stream, intrusive_ptr<IntegerPtr> referenceHdc, intrusive_ptr<Rectangle> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Imaging::EmfType type, StringPtr description);
						Metafile(intrusive_ptr<Stream> stream, intrusive_ptr<IntegerPtr> referenceHdc, intrusive_ptr<RectangleF> frameRect,
							Imaging::MetafileFrameUnit frameUnit, Imaging::EmfType type, StringPtr description);

						intrusive_ptr<IntegerPtr> GetHenhmetafile();
#ifdef WIN32
						Gdiplus::MetafileHeader GetMetafileHeader();//for VS2017 remove "Aspose::Cells::Systems::Drawing::Imaging::Metafile::" @20190122
						/*static*/ Gdiplus::MetafileHeader GetMetafileHeader(HENHMETAFILE henhmetafile);
						/*static*/ Gdiplus::MetafileHeader GetMetafileHeader(intrusive_ptr<Stream> stream);
						/*static*/ Gdiplus::MetafileHeader GetMetafileHeader(StringPtr fileName);
						/*static*/ Gdiplus::MetafileHeader GetMetafileHeader(HENHMETAFILE henhmetafile, Gdiplus::WmfPlaceableFileHeader wmfHeader);
						void PlayRecord(Gdiplus::EmfPlusRecordType recordType, int flags, int dataSize, byte* data);
#else
						MetafileHeader GetMetafileHeader();//for VS2017 remove "Aspose::Cells::Systems::Drawing::Imaging::Metafile::" @20190122
						/*static*/ MetafileHeader GetMetafileHeader(HENHMETAFILE henhmetafile);
						/*static*/ MetafileHeader GetMetafileHeader(intrusive_ptr<Stream> stream);
						/*static*/ MetafileHeader GetMetafileHeader(StringPtr fileName);
						/*static*/ MetafileHeader GetMetafileHeader(HENHMETAFILE henhmetafile, WmfPlaceableFileHeader wmfHeader);
						void PlayRecord(EmfPlusRecordType recordType, int flags, int dataSize, byte* data);
#endif
					public://private before
						Metafile(intrusive_ptr<IntegerPtr> ptr);
					};
				}
			}
		}
	}
}
#endif

