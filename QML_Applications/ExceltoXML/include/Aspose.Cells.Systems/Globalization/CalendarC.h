#ifndef _SYSTEM_GLOBALIZATION_CALENDAR_H_
#define _SYSTEM_GLOBALIZATION_CALENDAR_H_

#include "Aspose.Cells.Systems/Object.h"
#include "Aspose.Cells.Systems/ICloneable.h"
#include "unicode/datefmt.h"

using namespace Aspose::Cells::Systems;
#ifdef WIN32
	using namespace icucells;
#else
	using namespace icu;

#endif 

namespace Aspose { 
	namespace Cells { 
		namespace Systems {
			namespace Globalization {
				class ASPOSE_CELLS_API CalendarC: public ICloneable, public Object
				{
					protected:
#ifdef WIN32
						icucells::DateFormat* m_DateFormat;
#else
						icu::DateFormat* m_DateFormat;

#endif 
					public:
						virtual ~CalendarC();
						virtual void add_ref() {
							++ref_count_;
						}

						virtual int release_ref() {
							return --ref_count_;
						}
				};
				typedef intrusive_ptr<CalendarC> CalendarCPtr;
			}
		}
	}
}
#endif//_SYSTEM_GLOBALIZATION_CALENDAR_H_