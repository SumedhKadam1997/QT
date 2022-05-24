#ifndef _SYSTEM_WIN32_REGISTRY_H_
#define _SYSTEM_WIN32_REGISTRY_H_

#include "Aspose.Cells.Systems/Object.h"
#include "Aspose.Cells.Systems/Win32/RegistryKey.h"

using namespace Aspose::Cells::Systems;

#ifdef WIN32
namespace Aspose { 
	namespace Cells { 
		namespace Systems {
			namespace Win32 {
				class ASPOSE_CELLS_API Registry : public Object
				{
				private:

				protected:

				public:
					static intrusive_ptr<RegistryKey> LocalMachine;
				};
			}
		}
	}
}
#endif // WIN32
#endif//_SYSTEM_WIN32_REGISTRY_H_