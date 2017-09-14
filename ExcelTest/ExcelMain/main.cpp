//
//  main.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

//MySQL Query to check last time the database was updated
//"SELECT UPDATE_TIME FROM information_schema.tables WHERE  TABLE_SCHEMA = 'dbName' AND TABLE_NAME = 'tableName'"

#include <iostream>
#include "Excel.h"

int main(int argc, const char * argv[]) {
    //Create an Excel Document
    Excel spreadsheet("./Test1.xls");
    Row *row;
//    Excel spreadsheet;
//    spreadsheet.open("/Users/deisterhold/Desktop/Test.xls");
    
    //Get the main workbook (Excel only has a single workbook)
    Workbook *workbook = spreadsheet.getWorkbook();
    
    //Set Author and Company (Optional)
    workbook->setAuthor("Name Here");
    workbook->setCompany("Company Name");
    
    //Add a worksheet to the workbook
    workbook->addWorksheet(Worksheet("Sheet1"));
    
    //Get the newly created worksheet
    Worksheet *worksheet = workbook->getWorksheet(0);
    
    //Add a table to the worksheet
    worksheet->addTable(Table());

  
    //worksheet->addTable(Table());
    
    //Get the newly created table
    Table *table = worksheet->getTable(0);
#if 0      
    //Add a row to the table
    table->addRow(Row());
    
    //Get the newly create row
    Row *row = table->getRow(0);
    
    //Add a cell to the row
    row->addCell(Cell());
    row->addCell(Cell());
    
    //Get the newly created cell
    Cell *cell = row->getCell(0);
    
    //Put a data item in the cell (In this example we create a cell to hold a string)
    //There are currently three data types DATATYPE_STRING, DATATYPE_NUMBER, DATATYPE_DATETIME
    //All data is given as a string even if a number or time
    cell->setContents(Data("Hello", DATATYPE_STRING)); //If no data type is given the data is assumed to be a string
    //Equivalent to above "cell->setContents(Data("Hello"));"
    
    cell = row->getCell(1);
    cell->setContents(Data("New Column"));


    table->addRow(Row());
    table->setRowWidth(1600,0);
    table->setRowWidth(8000,1);
    row = table->getRow(1);
    row->addCell(Cell());
    cell = row->getCell(0);
    cell->setContents(Data("test result 111", DATATYPE_STRING));
#endif

    for (int i = 0; i < 16; i++)
    {
        table->addRow(Row());
        row = table->getRow(i);
        for (int m = 0; m < 16; m++)
        {
            row->addCell(Cell());///sa
        }
        
    }

    table->setMergeAcross(2,1,16);

    table->setMergeDown(1,2,3);


    //table->setMergeDown(1,4,10);
    //table->getRow(1)->getCell(0)->setStyle(TOP_ALIGN);  //set cell need Style.cpp work
    table->getRow(1)->getCell(0)->setContents(Data("chip 1903 test report"));

    table->getRow(4)->getCell(0)->setContents(Data("module_name"));
    table->getRow(4)->getCell(1)->setContents(Data("sub_item"));
    table->getRow(4)->getCell(2)->setContents(Data("test_result"));
    table->getRow(4)->getCell(3)->setContents(Data("note"));
    table->getRow(4)->getCell(4)->setContents(Data("date"));

    //Saves the data in xml to the file
    spreadsheet.save();
    
    //Closes the file
    spreadsheet.close();
    
    //Optionally output
//    cout<<spreadsheet.getXML()<<endl;
    return 0;
}
