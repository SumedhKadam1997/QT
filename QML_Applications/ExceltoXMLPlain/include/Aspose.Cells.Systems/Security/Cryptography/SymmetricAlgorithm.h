#ifndef _SYSTEM_SECURITY_CRYPTOGRAPHY_SYMMETRICALGORITHM_H_
#define _SYSTEM_SECURITY_CRYPTOGRAPHY_SYMMETRICALGORITHM_H_

#include "Aspose.Cells.Systems/Object.h"
#include "Aspose.Cells.Systems/String.h"
#include "Aspose.Cells.Systems/IDisposable.h"
#include "Aspose.Cells.Systems/Array1D.h"
#include "Aspose.Cells.Systems/Security/Cryptography/ICryptoTransform.h"
#include "Aspose.Cells.Systems/NotSupportedException.h"
using namespace Aspose::Cells::Systems;

namespace Aspose {
	namespace Cells {
		namespace Systems {
			namespace Security {
				namespace Cryptography {

					class ASPOSE_CELLS_API SymmetricAlgorithm : public Object, public IDisposable  //to do
					{
					public:
						void Dispose(){}
					
						virtual intrusive_ptr<ICryptoTransform> CreateDecryptor(){ 
							throw NotSupportedException("SymmetricAlgorithm::CreateDecryptor is not supported!");
						}
						virtual intrusive_ptr<ICryptoTransform> CreateDecryptor(intrusive_ptr<Array1D<Byte>> rgbKey, intrusive_ptr<Array1D<Byte>> rgbIV) = 0;
						virtual intrusive_ptr<ICryptoTransform> CreateEncryptor(){ 
							throw NotSupportedException("SymmetricAlgorithm::CreateEncryptor is not supported!");
						}
						virtual intrusive_ptr<ICryptoTransform> CreateEncryptor(intrusive_ptr<Array1D<Byte>> rgbKey, intrusive_ptr<Array1D<Byte>> rgbIV) = 0;

					public:
						virtual void add_ref() {
							++ref_count_;
						}
						virtual int release_ref() {
							return --ref_count_;
						}

					};
				} // namespace Cryptography
			}	// namespace Security
		}	// namespace Systems
	}
}
#endif