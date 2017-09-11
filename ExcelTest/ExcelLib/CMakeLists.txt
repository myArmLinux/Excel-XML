INCLUDE_DIRECTORIES(/usr/include)
if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-std=c++11)
    message(STATUS "optional:-std=c++11")   
endif(CMAKE_COMPILER_IS_GNUCXX)
set(LIB_SRC 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Cell.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Column.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Data.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/DocumentProperties.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Excel.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/ExcelWorkbook.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/OfficeDocumentSettings.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Pane.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Row.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Style.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Table.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Workbook.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/Worksheet.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/WorksheetOptions.cpp 
/home/seanwon/workSpce/excelLibPrj/Excel-XML/ExcelTest/ExcelLib/XMLParser.cpp
)
add_library(libExcelLib ${LIB_SRC})
set_target_properties(libExcelLib PROPERTIES OUTPUT_NAME "ExcelLib")