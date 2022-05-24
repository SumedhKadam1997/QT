#ifndef _SYSTEM_INT16_H_
#define _SYSTEM_INT16_H_

#ifdef WIN32
#include "Aspose.Cells.Systems/BaseNumber.h"
#include "Aspose.Cells.Systems/Object.h"
#endif

namespace Aspose {
	namespace Cells {
		namespace Systems {
#ifdef WIN32
			typedef int16_t Int16;
#else
            typedef short Int16;
#endif
		}
	}
}	// namespace Systems

#endif	// _SYSTEM_INT16_H_
