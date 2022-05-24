#include <iostream>
#include "Aspose.Cells.h"

using namespace std;
using namespace Aspose::Cells;

int main()
{
    intrusive_ptr<IWorkbook> wkb = Factory::CreateIWorkbook(new String("C:\\Users\\UxoriousGhost-WorkPC\\Downloads\\HMI Settings List R1 SR24 2A (October 20 2021).xlsx"));

    wkb->Save(new String("C:\\Users\\UxoriousGhost-WorkPC\\Downloads\\convertedFile.xml"), SaveFormat::SaveFormat_SpreadsheetML);

    return 0;
}
