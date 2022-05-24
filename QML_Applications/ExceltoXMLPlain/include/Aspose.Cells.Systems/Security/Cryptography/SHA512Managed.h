#ifndef _SYSTEM_SECURITY_CRYPTOGRAPHY_SHA512MANAGED_H_
#define _SYSTEM_SECURITY_CRYPTOGRAPHY_SHA512MANAGED_H_

#include "Aspose.Cells.Systems/Security/Cryptography/SHA512.h"
#include "Aspose.Cells.Systems/Array1D.h"
#include "Aspose.Cells.Systems/NotSupportedException.h"
using namespace Aspose::Cells::Systems;

namespace Aspose {
	namespace Cells {
		namespace Systems {
			namespace Security {
				namespace Cryptography {

					class ASPOSE_CELLS_API SHA512Managed : public SHA512  //to do
					{
					public:
						SHA512Managed(){}
						void Initialize(){}

					protected:
						void HashCore(intrusive_ptr<Array1D<Byte>> rgb, int ibStart, int cbSize){
							throw NotSupportedException("SHA512Managed::HashCore is not supported!");
						
						}
						intrusive_ptr<Array1D<Byte>> HashFinal(){
							throw NotSupportedException("SHA512Managed::HashFinal is not supported!");					
						}

					};
				} // namespace Cryptography
			}	// namespace Security
		}	// namespace Systems
	}
}
#endif