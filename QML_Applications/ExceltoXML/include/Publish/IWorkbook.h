#pragma once
#include "Aspose.Cells.Systems/Object.h"
#include "Aspose.Cells.Systems/String.h"
#include "Aspose.Cells.Systems/IO/Stream.h"
#include "Aspose.Cells.Systems/IO/MemoryStream.h"
#include "Aspose.Cells.Systems/Int32.h"
#include "Aspose.Cells.Systems/Double.h"
#include "Aspose.Cells.Systems/Array1D.h"
#include "Aspose.Cells.Systems/Drawing/Color.h"
#include "Aspose.Cells.Systems/IDisposable.h"

#include "FileFormatType.h"
#include "SaveFormat.h"
#include "BuiltinStyleType.h"
#include "EncryptionType.h"
#include "ProtectionType.h"
#include "ThemeColorType.h"
namespace Aspose {
	namespace Cells {
		class IWorkbookSettings;
		enum FileFormatType;
		class ILoadOptions;
		enum SaveFormat;
		class ISaveOptions;
		class IWorksheetCollection;
		class IStyleCollection;
		class IStyle;
		enum BuiltinStyleType;
		class ICellsColor;
		class IReplaceOptions;
		class IWorkbook;
		class IFont;
		class ICustomFunction;
		class ICalculationOptions;
		enum EncryptionType;
		enum ProtectionType;
		class IDataSorter;
		enum ThemeColorType;
	}
}
namespace Aspose {
	namespace Cells {
		namespace Vba {
			class IVbaProject;
		}
	}
}
namespace Aspose {
	namespace Cells {
		namespace Properties {
			class IBuiltInDocumentPropertyCollection;
			class ICustomDocumentPropertyCollection;
			class IContentTypePropertyCollection;
		}
	}
}
namespace Aspose {
	namespace Cells {
		namespace DigitalSignatures {
			class IDigitalSignatureCollection;
		}
	}
}
namespace Aspose{
namespace Cells{
			/// <summary>
			///  Represents a root object to create an Excel spreadsheet. 	
			///  </summary>
			/// 
			/// <remarks>The IWorkbook class denotes an Excel spreadsheet. Each spreadsheet can contain multiple worksheets.
			///  The basic feature of the class is to open and save native excel files.
			///  The class has some advanced features like copying data from other Workbooks, combining two Workbooks and protecting the Excel spreadsheet.
			///  </remarks>
			/// 
			/// <example>
			///  The following example opens a file named designer.xls. It replaces two string values with an Integer value and string value respectively within the spreadsheet.
			///  In order to run this case normally, you should create a file named designer.xls using MS Excels, and set two string values "OldInt" and "OldString"  between any two cells
			///  then save it in the root directory of your D: drive.
			///  <code>
			///		
			///  [C++]
			///  //Open a file named designer.xls
			///  StringPtr mapPath = new String("D:");
			///  StringPtr designerFile = mapPath->StringAppend(new String("\\designer.xls"));
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook(designerFile);
			///    
			///  //Replace the placeholder string with new values
			///  int newInt = 100;
			///  workbook->Replace(new String("OldInt"), newInt);
			///  
			///  StringPtr newString = new String("Hello!");
			///  workbook->Replace((StringPtr)(new String("OldString")), (StringPtr)newString);
			///  workbook->Save(designerFile);
			///      
			///  </code>
			/// 
			///  </example>
			/// 
			/// 
	class ASPOSE_CELLS_API IWorkbook : public Aspose::Cells::Systems::IDisposable , public Aspose::Cells::Systems::Object
	{
		public:
			/// <summary>
			/// Represents the workbook settings.
			/// </summary>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::IWorkbookSettings> 		GetISettings()=0;
			/// <summary>
			/// Initialize the workbook object.
			/// </summary>
			/// 
			/// <remarks>NOTE: This member is now obsolete. Instead, 
			/// please use Factory::CreateIWorkbook().</remarks>
			/// 
			/// 
			 virtual void Initialize()=0;
			 
			/// <summary>
			/// Saves Excel file to a MemoryStream object and returns it.
			/// </summary>
			/// 
			/// <returns>MemoryStream object which contains an Excel file.</returns>
			/// 
			/// <remarks>
			/// 
			/// This method provides same function as Save method and only save the workbook as Excel97-2003 xls file. 
			/// It's mainly for calling from COM clients.</remarks>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::Systems::IO::MemoryStream> SaveToStream()=0;
			/// <summary>
			/// Creates and saves the specified file to the disk.
			/// </summary>
			/// 
			/// <param name="fileName" >The name of created file.</param>
			/// 
			/// <remarks><p>File format is according to file extension.</p>
			/// 
			/// After calling Save method, data in Workbook instance will be reset.</remarks>
			/// 
			/// 
			 virtual void Save(intrusive_ptr<Aspose::Cells::Systems::String> fileName)=0;
			/// <summary>
			/// Saves the workbook to the disk.
			/// </summary>
			/// 
			/// <param name="fileName" >The file name.</param>
			/// 
			/// <param name="saveFormat" >The save format type.</param>
			/// 
			/// 
			 virtual void Save(intrusive_ptr<Aspose::Cells::Systems::String> fileName , Aspose::Cells::SaveFormat saveFormat)=0;
			/// <summary>
			/// Saves the workbook to the disk.
			/// </summary>
			/// 
			/// <param name="fileName" >The file name.</param>
			/// 
			/// <param name="saveOptions" >The save options.</param>
			/// 
			/// 
			 virtual void Save(intrusive_ptr<Aspose::Cells::Systems::String> fileName , intrusive_ptr<Aspose::Cells::ISaveOptions> saveOptions)=0;
			/// <summary>
			/// Saves the workbook to the stream.
			/// </summary>
			/// 
			/// <param name="stream" >The file stream.</param>
			/// 
			/// <param name="saveFormat" >The save file format type.</param>
			/// 
			/// 
			 virtual void Save(intrusive_ptr<Aspose::Cells::Systems::IO::Stream> stream , Aspose::Cells::SaveFormat saveFormat)=0;
			/// <summary>
			/// Saves the workbook to the stream.
			/// </summary>
			/// 
			/// <param name="stream" >The file stream.</param>
			/// 
			/// <param name="saveOptions" >The save options.</param>
			/// 
			/// 
			 virtual void Save(intrusive_ptr<Aspose::Cells::Systems::IO::Stream> stream , intrusive_ptr<Aspose::Cells::ISaveOptions> saveOptions)=0;
			/// <summary>
			/// Gets the <see cref="WorksheetCollection" />
			///  collection in the spreadsheet.
			/// </summary>
			/// 
			/// <returns><see cref="IWorksheetCollection" />
			///  collection</returns>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::IWorksheetCollection> 		GetIWorksheets()=0;
			/// <summary>
			/// Indicates whether license is set.
			/// </summary>
			/// 
			/// 
			 virtual bool IsLicensed()=0;
	
			/// <summary>
			/// Gets the <see cref="IStyleCollection"/> collection.
			/// </summary>
			/// <remarks>
			/// NOTE: This class is now obsolete. Instead, 
			/// please use CreateIStyle() to create and manipulate style for workbook instead of Add() method of IStyleCollection
			/// and use GetNamedIStyle(StringPtr) to get named style instead of GetObjectByIndex(StringPtr) in IStyleCollection.</remarks>		 
			 virtual intrusive_ptr<Aspose::Cells::IStyleCollection> 		GetIStyles()=0;
			/// <summary>
			/// Remove all unused styles.
			/// </summary>
			/// 
			/// 
			 virtual void RemoveUnusedStyles()=0;
			/// <summary>
			/// Creates a new style.
			/// </summary>
			/// 
			/// <returns>Returns a style object.</returns>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::IStyle> 		CreateIStyle()=0;
			/// <summary>
			/// Creates built-in style by given type.
			/// </summary>
			/// 
			/// <param name="type" />
			/// 
			/// <returns>IStyle object</returns>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::IStyle> 		CreateBuiltinIStyle(Aspose::Cells::BuiltinStyleType type)=0;
			/// <summary>
			/// Creates an <see cref="ICellsColor" />
			///  object.
			/// </summary>
			/// <returns>Returns an <see cref="ICellsColor" />
			///  object.</returns>
			 virtual intrusive_ptr<Aspose::Cells::ICellsColor> 		CreateICellsColor()=0;
			/// <summary>
			///  Replaces a cell's value with a new string.
			/// </summary>
			/// 
			/// <example>
			///  <code>
			///  [C++]
			///  
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook();
			///  ......
			///  workbook->Replace((StringPtr)new String("AnOldValue"), (StringPtr)new String("NewValue"));
			///  
			///  </code>
			/// 
			///  </example>
			/// 
			/// <param name="placeHolder" >Cell placeholder</param>
			/// 
			/// <param name="newValue" >String value to replace</param>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 Replace(intrusive_ptr<Aspose::Cells::Systems::String> placeHolder , intrusive_ptr<Aspose::Cells::Systems::String> newValue)=0;
			/// <summary>
			///  Replaces a cell's value with a new integer.
			/// </summary>
			/// 
			/// <example>
			///  <code>
			///  [C++]
			///  
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook();
			///  ......
			///  int newValue = 100;
			///  workbook->Replace(StringPtr)new String("AnOldValue"), newValue);
			///  
			///  </code>
			/// 
			///  </example>
			/// 
			/// <param name="placeHolder" >Cell placeholder</param>
			/// 
			/// <param name="newValue" >Integer value to replace</param>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 Replace(intrusive_ptr<Aspose::Cells::Systems::String> placeHolder , Aspose::Cells::Systems::Int32 newValue)=0;
			/// <summary>
			///  Replaces a cell's value with a new double.
			/// </summary>
			/// 
			/// <example>
			///  <code>
			///  
			///  [C++]
			///  
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook();
			///  ......
			///  double newValue = 100.0;
			///  workbook.Replace(new String("AnOldValue"), newValue);
			///  
			///  </code>
			/// 
			///  </example>
			/// 
			/// <param name="placeHolder" >Cell placeholder</param>
			/// 
			/// <param name="newValue" >Double value to replace</param>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 Replace(intrusive_ptr<Aspose::Cells::Systems::String> placeHolder , Aspose::Cells::Systems::Double newValue)=0;
			/// <summary>
			///  Replaces a cell's value with a new string array.
			/// </summary>
			/// 
			/// <example>
			///  <code>
			///  
			///  [C++]
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook();
			///  intrusive_ptr<Array1D<String*>> newValues = new Array1D<String*>(3);
			///  newValues->SetValue(new String("Tom"), 0);
			///  newValues->SetValue(new String("Alice"), 1);
			///  newValues->SetValue(new String("Jerry"), 2);
			///  workbook->Replace(new String("AnOldValue"), newValues, true);
			///  
			///  </code>
			/// 
			///  </example>
			/// 
			/// <param name="placeHolder" >Cell placeholder</param>
			/// 
			/// <param name="newValues" >String array to replace</param>
			/// 
			/// <param name="isVertical" >True - Vertical, False - Horizontal</param>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 Replace(intrusive_ptr<Aspose::Cells::Systems::String> placeHolder , intrusive_ptr<Aspose::Cells::Systems::Array1D<Aspose::Cells::Systems::String*>> newValues , bool isVertical)=0;
			/// <summary>
			///  Replaces cells' values with an integer array.
			/// </summary>
			/// 
			/// <example>
			///  <code>
			///  [C++]
			///  
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook();
			///  ......
			///  intrusive_ptr<Array1D<int>> newValues = new Array1D<int>(3);
			///  newValues->SetValue(1, 0);
			///  newValues->SetValue(2, 1);
			///  newValues->SetValue(3, 2);
			///  workbook->Replace(new String("AnOldValue"), newValues, true);
			///  </code>
			/// 
			///  </example>
			/// 
			/// <param name="placeHolder" >Cell placeholder</param>
			/// 
			/// <param name="newValues" >Integer array to replace</param>
			/// 
			/// <param name="isVertical" >True - Vertical, False - Horizontal</param>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 Replace(intrusive_ptr<Aspose::Cells::Systems::String> placeHolder , intrusive_ptr<Aspose::Cells::Systems::Array1D<Aspose::Cells::Systems::Int32>> newValues , bool isVertical)=0;
			/// <summary>
			///  Replaces cells' values with a double array.
			/// </summary>
			/// 
			/// <example>
			///  <code>
			///  
			///  [C++]
			///  
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook();
			///  ......
			///  intrusive_ptr<Array1D<double>> newValues = new Array1D<double>(3);
			///  newValues->SetValue(1.23, 0);
			///  newValues->SetValue(2.56, 1);
			///  newValues->SetValue(3.14159, 2);
			///  workbook->Replace(new String("AnOldValue"), newValues, true);
			///  
			///  </code>
			/// 
			///  </example>
			/// 
			/// <param name="placeHolder" >Cell placeholder</param>
			/// 
			/// <param name="newValues" >Double array to replace</param>
			/// 
			/// <param name="isVertical" >True - Vertical, False - Horizontal</param>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 Replace(intrusive_ptr<Aspose::Cells::Systems::String> placeHolder , intrusive_ptr<Aspose::Cells::Systems::Array1D<Aspose::Cells::Systems::Double>> newValues , bool isVertical)=0;
			/// <summary>
			/// Replaces cells' values with new data.
			/// </summary>
			/// 
			/// <param name="boolValue" >The boolean value to be replaced.</param>
			/// 
			/// <param name="newValue" >New value. Can be string, integer, double or DateTime value.</param>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 Replace(bool boolValue , intrusive_ptr<Aspose::Cells::Systems::Object> newValue)=0;
			/// <summary>
			/// Replaces cells' values with new data.
			/// </summary>
			/// 
			/// <param name="intValue" >The integer value to be replaced.</param>
			/// 
			/// <param name="newValue" >New value. Can be string, integer, double or DateTime value.</param>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 Replace(Aspose::Cells::Systems::Int32 intValue , intrusive_ptr<Aspose::Cells::Systems::Object> newValue)=0;
			/// <summary>
			///  Replaces a cell's value with a new string.
			/// </summary>
			/// <param name="placeHolder" >Cell placeholder</param>
			/// <param name="newValue" >String value to replace</param>
			/// <param name="options" > The replace options</param>
			 virtual Aspose::Cells::Systems::Int32 Replace(intrusive_ptr<Aspose::Cells::Systems::String> placeHolder , intrusive_ptr<Aspose::Cells::Systems::String> newValue , intrusive_ptr<Aspose::Cells::IReplaceOptions> options)=0;
			/// <summary>
			/// Copies data from a source Workbook object.
			/// </summary>
			/// 
			/// <param name="source" >Source Workbook object.</param>
			/// 
			/// 
			 virtual void Copy(intrusive_ptr<Aspose::Cells::IWorkbook> source)=0;
			/// <summary>
			/// Combines another Workbook object.
			/// </summary>
			/// 
			/// <param name="secondWorkbook" >Another Workbook object.</param>
			/// 
			/// <remarks>Currently, only cell data and cell style of the second Workbook object can be combined. Images, charts and other drawing objects are not supported.
			/// </remarks>
			/// 
			/// 
			 virtual void Combine(intrusive_ptr<Aspose::Cells::IWorkbook> secondWorkbook)=0;
			/// <summary>
			/// Returns colors in the palette for the spreadsheet. 
			/// </summary>
			/// 
			/// <remarks>The palette has 56 entries, each represented by an RGB value.</remarks>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::Systems::Array1D<Aspose::Cells::Systems::Drawing::Color*>> GetColors()=0;
			/// <summary>
			/// Gets the style in the style pool.
			/// All styles in the workbook will be gathered into a pool.
			/// There is only a simple reference index in the cells.
			/// </summary>
			/// 
			/// <param name="index" >The index.</param>
			/// 
			/// <returns>
			/// The style in the pool corresponds to given index, may be null.
			/// </returns>
			/// 
			/// <remarks>
			/// If the returned style is changed, the style of all cells(which refers to this style) will be changed.
			/// </remarks>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::IStyle> 		GetIStyleInPool(Aspose::Cells::Systems::Int32 index)=0;
			/// <summary>
			/// Gets number of the styles in the style pool.
			/// </summary>
			/// 
			/// 
			 virtual Aspose::Cells::Systems::Int32 GetCountOfStylesInPool()=0;
			/// <summary>
			/// Gets number of the styles in the style pool.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::Systems::Array1D<Aspose::Cells::IFont*>> 		GetIFonts()=0;
			/// <summary>
			/// Gets the named style in the style pool.
			/// </summary>
			/// 
			/// <param name="name" >name of the style</param>
			/// 
			/// <returns>named style, maybe null.</returns>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::IStyle> 		GetNamedIStyle(intrusive_ptr<Aspose::Cells::Systems::String> name)=0;
			/// <summary>
			///  Changes the palette for the spreadsheet in the specified index.
			///  </summary>
			/// 
			/// <param name="color" >Color structure.</param>
			/// 
			/// <param name="index" >Palette index, 0 - 55.</param>
			/// 
			/// 
			/// 
			 virtual void ChangePalette(intrusive_ptr<Aspose::Cells::Systems::Drawing::Color> color , Aspose::Cells::Systems::Int32 index)=0;
			/// <summary>
			/// Checks if a color is in the palette for the spreadsheet.
			/// </summary>
			/// 
			/// <param name="color" >Color structure.</param>
			/// 
			/// <returns>Returns true if this color is in the palette. Otherwise, returns false</returns>
			/// 
			/// 
			 virtual bool IsColorInPalette(intrusive_ptr<Aspose::Cells::Systems::Drawing::Color> color)=0;
			/// <summary>
			///  Calculates the result of formulas
			///  </summary>
			/// 
			 virtual void CalculateFormula()=0;
			/// <summary>
			/// Calculates the result of formulas
			/// </summary>
			/// 
			/// <param name="ignoreError" >Indicates if hide the error in calculating formulas. The error may be unsupported function, external links, etc.</param>
			/// 
			/// 
			 virtual void CalculateFormula(bool ignoreError)=0;
			/// <summary>
			/// Calculates the result of formulas.
			/// </summary>
			/// <param name="ignoreError" >Indicates if hide the error in calculating formulas. The error may be unsupported function, external links, etc.</param>
			/// <param name="customFunction" >The custom formula calculation functions to extend the calculation engine.</param>
			 virtual void CalculateFormula(bool ignoreError , intrusive_ptr<Aspose::Cells::ICustomFunction> customFunction)=0;
			/// <summary>
			/// Calcualting formulas in this workbook.
			/// </summary>
			/// <param name="options" >Options for calculation</param>
			 virtual void 		CalculateFormula(intrusive_ptr<Aspose::Cells::ICalculationOptions> options)=0;
			/// <summary>
			///  Gets the default <see cref="IStyle" />
			///  object of the workbook.
			///  </summary>
			/// 
			/// <remarks>
			///  The DefaultStyle is useful to implement an IStyle for the whole Workbook. 
			///  </remarks>
			/// 
			/// <example>
			///  The following code creates and instantiates a new Workbook and sets a default <see cref="IStyle" />
			///  to it.
			///  <code>
			///  [C++]
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook();
			///  intrusive_ptr<IStyle> defaultStyle = workbook->GetDefaultIStyle();
			///  defaultStyle->GetIFont()->SetName(new String("Tahoma"));
			///  workbook->SetDefaultIStyle(defaultStyle);
			/// 
			///  </code>
			/// 
			///  </example>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::IStyle> 		GetDefaultIStyle()=0;
			/// <summary>
			///  Sets the default <see cref="IStyle" />
			///  object of the workbook.
			///  </summary>
			/// 
			/// <remarks>
			///  The DefaultStyle is useful to implement an IStyle for the whole Workbook. 
			///  </remarks>
			/// 
			/// <example>
			///  The following code creates and instantiates a new Workbook and sets a default <see cref="IStyle" />
			///  to it.
			///  <code>
			///  [C++]
			///  intrusive_ptr<IWorkbook> workbook = Factory::CreateIWorkbook();
			///  intrusive_ptr<IStyle> defaultStyle = workbook->GetDefaultIStyle();
			///  defaultStyle->GetIFont()->SetName(new String("Tahoma"));
			///  workbook->SetDefaultIStyle(defaultStyle);
			/// 
			///  </code>
			/// 
			///  </example>
			/// 
			/// 
			 virtual void SetDefaultIStyle(intrusive_ptr<Aspose::Cells::IStyle> value)=0;
			/// <summary>
			/// Checks if a formula is valid.
			/// </summary>
			/// 
			/// <param name="formula" >Formula string.</param>
			/// 
			/// <returns>True: valid formula. False: invalid formula or unsupported function.</returns>
			/// 
			/// <remarks>
			/// NOTE: This member is now obsolete. Instead, 
			/// please use GetFormula() of ICell method.</remarks>
			/// 
			/// 
			 virtual bool ValidateFormula(intrusive_ptr<Aspose::Cells::Systems::String> formula)=0;
			/// <summary>
			/// Find best matching Color in current palette.
			/// </summary>
			/// 
			/// <param name="rawColor" >Raw color.</param>
			/// 
			/// <returns>Best matching color.</returns>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::Systems::Drawing::Color> GetMatchingColor(intrusive_ptr<Aspose::Cells::Systems::Drawing::Color> rawColor)=0;
			/// <summary>
			/// Indicates if this spreadsheet is digitally signed.
			/// </summary>
			/// 
			/// 
			 virtual bool IsDigitallySigned()=0;
			/// <summary>
			/// Set Encryption Options.
			/// </summary>
			/// <param name="encryptionType" >The encryption type.</param>
			/// <param name="keyLength" >The key length.</param>
			 virtual void SetEncryptionOptions(Aspose::Cells::EncryptionType encryptionType , Aspose::Cells::Systems::Int32 keyLength)=0;
			/// <summary>
			/// Protects a workbook.
			/// </summary>
			/// <param name="protectionType" >Protection type.</param>
			/// <param name="password" >Password to protect the workbook.</param>
			 virtual void Protect(Aspose::Cells::ProtectionType protectionType , intrusive_ptr<Aspose::Cells::Systems::String> password)=0;
			/// <summary>
			/// Unprotects a workbook.
			/// </summary>
			/// <param name="password" >Password to unprotect the workbook.</param>
			 virtual void Unprotect(intrusive_ptr<Aspose::Cells::Systems::String> password)=0;
			/// <summary>
			/// Removes VBA/macro from this spreadsheet.
			/// </summary>
			 virtual void RemoveMacro()=0;
			/// <summary>
			/// Gets the <see cref="IVbaProject" />
			///  in a spreadsheet.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::Vba::IVbaProject> 		GetIVbaProject()=0;
			/// <summary>
			/// Removes digital signature from this spreadsheet.
			/// </summary>
			 virtual void RemoveDigitalSignature()=0;
			/// <summary>
			/// Accepts all tracked changes in the workbook. 
			/// </summary>
			 virtual void AcceptAllRevisions()=0;
			/// <summary>
			/// Indicates if this spreadsheet contains macro/VBA.
			/// </summary>
			 virtual bool HasMacro()=0;
			/// <summary>
			/// Gets if the workbook has any tracked changes
			/// </summary>
			 virtual bool HasRevisions()=0;
			/// <summary>
			/// Gets current file name of this workbook.
			/// </summary>
			/// <remarks>
			/// If this workbook is used as external data source for another workbook which contains some external formula references,
			/// please set correct value for this property.
			/// The set value(combined with CellsHelper.StartupPath,CellsHelper.AltStartPath,CellsHelper.LibraryPath if those properties exist)
			/// should be same with the external reference defined in the formula.
			/// </remarks>
			/// <seealso cref="IUpdateLinkedDataSource" />
			/// 
			 virtual intrusive_ptr<Aspose::Cells::Systems::String> GetFileName()=0;
			/// <summary>
			/// Sets current file name of this workbook.
			/// </summary>
			/// <remarks>
			/// If this workbook is used as external data source for another workbook which contains some external formula references,
			/// please set correct value for this property.
			/// The set value(combined with CellsHelper.StartupPath,CellsHelper.AltStartPath,CellsHelper.LibraryPath if those properties exist)
			/// should be same with the external reference defined in the formula.
			/// </remarks>
			/// <seealso cref="IUpdateLinkedDataSource" />
			/// 
			 virtual void SetFileName(intrusive_ptr<Aspose::Cells::Systems::String> value)=0;
			/// <summary>
			/// Gets a DataSorter object to sort data.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::IDataSorter> 		GetIDataSorter()=0;
			/// <summary>
			/// Removes all external links in the workbook.
			/// </summary>
			 virtual void RemoveExternalLinks()=0;
			/// <summary>
			/// Gets theme color.
			/// </summary>
			/// <param name="type" >The theme color type.</param>
			/// <returns>The theme color.</returns>
			 virtual intrusive_ptr<Aspose::Cells::Systems::Drawing::Color> GetThemeColor(Aspose::Cells::ThemeColorType type)=0;
			/// <summary>
			/// Sets the theme color
			/// </summary>
			/// <param name="type" >The theme color type.</param>
			/// <param name="color" >the theme color</param>
			 virtual void SetThemeColor(Aspose::Cells::ThemeColorType type , intrusive_ptr<Aspose::Cells::Systems::Drawing::Color> color)=0;
			/// <summary>
			/// Gets the theme name. 
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::Systems::String> GetTheme()=0;
			/// <summary>
			/// Customs the theme.
			/// </summary>
			/// <param name="themeName" >The theme name</param>
			/// <param name="colors" >The theme colors</param>

			 virtual void CustomTheme(intrusive_ptr<Aspose::Cells::Systems::String> themeName , intrusive_ptr<Aspose::Cells::Systems::Array1D<Aspose::Cells::Systems::Drawing::Color*>> colors)=0;
			/// <summary>
			/// Copies the theme from another workbook.
			/// </summary>
			/// <param name="source" >Source workbook.</param>
			 virtual void 		CopyITheme(intrusive_ptr<Aspose::Cells::IWorkbook> source)=0;
			/// <summary>
			/// Indicates whether this workbook contains external links to other data sources.
			/// </summary>
			/// <returns>Whether this workbook contains external links to other data sources.</returns>
			 virtual bool HasExernalLinks()=0;
			/// <summary>
			/// If this workbook contains external links to other data source,
			/// Aspose.Cells will attempt to retrieve the latest data.
			/// </summary>
			/// <param name="exteralWorkbooks" >
			/// External workbooks are referred by this workbook.
			/// If it's null, we will directly open the external linked files..
			/// If it's not null, 
			/// we will check whether the external link in the array first;
			/// if not, we will open the external linked files again.
			/// </param>
			/// <remarks>
			/// If the method is not called before calculating formulas,
			/// Aspose.Cells will use the previous information(cached in the file);
			/// Please set ICellsHelper::GetStartupPath(), ICellsHelper::GetAltStartPath(), ICellsHelper::GetLibraryPath(). 
			/// And please set the FilePath of Workbook if this workbook is from a stream,
			/// otherwise Aspose.Cells could not get the external link full path sometimes.
			/// </remarks>
			/// 
			/// 
			 virtual void UpdateLinkedDataSource(intrusive_ptr<Aspose::Cells::Systems::Array1D<Aspose::Cells::IWorkbook*>> exteralWorkbooks)=0;
			/// <summary>
			/// Returns an IDocumentProperty collection that represents all the built-in document properties of the spreadsheet. 
			/// </summary>
			/// <remarks>A new property cannot be added to built-in document properties list. You can only get a built-in property and change its value.
			/// The following is the built-in properties name list:
			/// <p>Title</p>
			/// <p>Subject</p>
			/// <p>Author</p>
			/// <p>Keywords</p>
			/// <p>Comments</p>
			/// <p>Template</p>
			/// <p>Last Author</p>
			/// <p>Revision Number</p>
			/// <p>Application Name</p>
			/// <p>Last Print Date</p>
			/// <p>Creation Date</p>
			/// <p>Last Save Time</p>
			/// <p>Total Editing Time</p>
			/// <p>Number of Pages</p>
			/// <p>Number of Words</p>
			/// <p>Number of Characters</p>
			/// <p>Security</p>
			/// <p>Category</p>
			/// <p>Format</p>
			/// <p>Manager</p>
			/// <p>Company</p>
			/// <p>Number of Bytes</p>
			/// <p>Number of Lines</p>
			/// <p>Number of Paragraphs</p>
			/// <p>Number of Slides</p>
			/// <p>Number of Notes</p>
			/// <p>Number of Hidden Slides</p>
			/// <p>Number of Multimedia Clips</p>
			/// </remarks>
			/// <example><code>
			/// [C++]
			/// intrusive_ptr<Aspose::Cells::IWorkbook> workbook = Factory::CreateIWorkbook();
			/// intrusive_ptr<Aspose::Cells::Properties::IDocumentProperty> doc = 
			/// workbook->GetIWorksheets()->GetIBuiltInDocumentProperties()->GetObjectByIndex(new String("Author"));
			/// doc->SetValue(new String("John Smith"));
			/// 
			/// </code>
			/// </example>
			 virtual intrusive_ptr<Aspose::Cells::Properties::IBuiltInDocumentPropertyCollection> 		GetIBuiltInDocumentProperties()=0;
			/// <summary>
			/// Returns an ICustomDocumentPropertyCollection that represents all the custom document properties of the spreadsheet. 
			/// </summary>
			/// <example><code>
			/// [C++]
			/// intrusive_ptr<Aspose::Cells::IWorkbook> workbook = Factory::CreateIWorkbook();
			/// intrusive_ptr<Aspose::Cells::Properties::ICustomDocumentPropertyCollection> doc =
			/// 	workbook->GetIWorksheets()->GetICustomDocumentProperties();
			/// doc->AddLinkToContentProperty(new String("Checked by"), new String("Jane"));
			/// 
			/// </code>
			/// </example>
			 virtual intrusive_ptr<Aspose::Cells::Properties::ICustomDocumentPropertyCollection> 		GetICustomDocumentProperties()=0;
			/// <summary>
			/// Gets and sets the file format.
			/// </summary>
			/// 
			/// 
			 virtual Aspose::Cells::FileFormatType GetFileFormat()=0;
			/// <summary>
			/// Gets and sets the file format.
			/// </summary>
			/// 
			/// 
			 virtual void SetFileFormat(Aspose::Cells::FileFormatType value)=0;
			/// <summary>
			/// Gets the IContentTypePropertyCollection in the workbook.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::Properties::IContentTypePropertyCollection> 		GetIContentTypeProperties()=0;
			/// <summary>
			/// Gets and sets the XML file that defines the Ribbon UI.
			/// </summary>
			/// 
			/// 
			 virtual intrusive_ptr<Aspose::Cells::Systems::String> GetRibbonXml()=0;
			/// <summary>
			/// Gets and sets the XML file that defines the Ribbon UI.
			/// </summary>
			/// 
			/// 
			 virtual void SetRibbonXml(intrusive_ptr<Aspose::Cells::Systems::String> value)=0;
			/// <summary>
			/// Gets the Absolute path of the file.
			/// </summary>
			/// <remarks>
			/// Only used for external links.
			/// </remarks>
			 virtual intrusive_ptr<Aspose::Cells::Systems::String> GetAbsolutePath()=0;
			/// <summary>
			/// Sets the Absolute path of the file.
			/// </summary>
			/// <remarks>
			/// Only used for external links.
			/// </remarks>
			 virtual void SetAbsolutePath(intrusive_ptr<Aspose::Cells::Systems::String> value)=0;
			/// <summary>
			/// Imports an xml file into the workbook.
			/// </summary>
			/// <param name="url" >the path of the xml file.</param>
			/// <param name="sheetName" >the destination sheet name .</param>
			/// <param name="row" >the destination row of the xml.</param>
			/// <param name="col" >the destination column of the xml.</param>
			 virtual void ImportXml(intrusive_ptr<Aspose::Cells::Systems::String> url , intrusive_ptr<Aspose::Cells::Systems::String> sheetName , Aspose::Cells::Systems::Int32 row , Aspose::Cells::Systems::Int32 col)=0;
			/// <summary>
			/// Export XML data.
			/// </summary>
			/// <param name="mapName" >name of the XML map that need to be exported</param>
			/// <param name="path" >the export path</param>
			 virtual void ExportXml(intrusive_ptr<Aspose::Cells::Systems::String> mapName , intrusive_ptr<Aspose::Cells::Systems::String> path)=0;
			/// <summary>
			/// Sets digital signature to an OOXML spreadsheet file (Excel2007 and later).
			/// </summary>
			/// <param name="digitalSignature" />
			/// 
			/// <remarks>Only support adding digital signature to OOXML file.</remarks>
			 virtual void 		SetIDigitalSignature(intrusive_ptr<Aspose::Cells::DigitalSignatures::IDigitalSignatureCollection> digitalSignature)=0;
			/// <summary>
			/// Gets digital signature from file.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::DigitalSignatures::IDigitalSignatureCollection> 		GetIDigitalSignature()=0;
			/// <summary>
			/// Performs application-defined tasks associated with freeing, releasing, or
			/// resetting unmanaged resources.
			/// </summary>
			 virtual void Dispose()=0;
public:
		public:
			virtual void add_ref() {++ref_count_;}
			virtual int release_ref() {return --ref_count_;}

	};
}
}
