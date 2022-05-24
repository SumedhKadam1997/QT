#ifndef _SYSTEM_RUNTIME_SERIALIZATION_STREAMINGCONTEXT_H_
#define _SYSTEM_RUNTIME_SERIALIZATION_STREAMINGCONTEXT_H_

#include "Aspose.Cells.Systems/Object.h"
#include "Aspose.Cells.Systems/Runtime/Serialization/StreamingContextStates.h"

using namespace Aspose::Cells::Systems;

namespace Aspose { 
namespace Cells { 
namespace Systems{
namespace Runtime {
namespace Serialization {
	class StreamingContext: public Object
	{
		private:

		public:
			StreamingContext(StreamingContextStates state);
        	StreamingContext(StreamingContextStates state, Object* additional);

	};
}
}
}
}
}
#endif//_SYSTEM_RUNTIME_SERIALIZATION_STREAMINGCONTEXT_H_