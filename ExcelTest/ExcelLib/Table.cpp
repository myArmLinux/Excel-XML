//
//  Table.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//
#include <string.h>
#include "Table.h"

int getMaxCellCount(vector<Row> table) {
    int max = 0;
    for (int rowNum = 0; rowNum < table.size(); rowNum++) {
        if(table[rowNum].getNumberOfCells() > max) {
            max = table[rowNum].getNumberOfCells();
        }
    }
    return max;
}

Table::Table() {
    _contentsOfTable = vector<Row>();
    _widthsOfRows = vector<Column>();
    memset(&CellBitMap[0], 0xFF, sizeof(CellBitMap));
}

Table::~Table() {
}

Table::Table(Row data[], int numOfRows) {
    for (int rowNum =  0; rowNum < numOfRows; rowNum++) {
        _contentsOfTable.push_back(data[rowNum]);
        _widthsOfRows.push_back(Column());
    }
}

void Table::addRow(Row newRow) {
    _contentsOfTable.push_back(newRow);
    _widthsOfRows.push_back(Column());
}

void Table::removeRow(int index) {
    _contentsOfTable.erase(_contentsOfTable.begin() + index);
    _widthsOfRows.erase(_widthsOfRows.begin() + index);
}

void Table::setRow(Row newRow, int index) {
    _contentsOfTable[index] = newRow;
}

Row* Table::getRow(int index) {
    return &_contentsOfTable[index];
}

int Table::getNumberOfRows() {
    return (int) _contentsOfTable.size();
}

void Table::addRow(Row newRow, Column newColumn) {
    addRow(newRow);
    _widthsOfRows.push_back(newColumn);
}

void Table::setRow(Row newRow, Column newColumn, int index) {
    _contentsOfTable[index] = newRow;
    _widthsOfRows[index] = newColumn;
}

void Table::setRowWidth(int width, int index) {
    _widthsOfRows[index].setWidth(width);
}

int Table::getRowWidth(int index) {
    return _widthsOfRows[index].getWidth();
}

string Table::getXML() {
    string temp = "  <Table ss:ExpandedColumnCount=\"";
    temp += to_string(getMaxCellCount(_contentsOfTable));
    temp += "\" ss:ExpandedRowCount=\"";
    temp += to_string(_contentsOfTable.size());
    temp += "\" x:FullColumns=\"1\"\n   x:FullRows=\"1\" ss:DefaultColumnWidth=\"65\" ss:DefaultRowHeight=\"15\">\n";
    for (int rowNum = 0; rowNum < _contentsOfTable.size(); rowNum++) {
        temp += _contentsOfTable[rowNum].getXML(CellBitMap[rowNum]);
    }
    temp += "  </Table>\n";
    return temp;
}

void Table::setCellBitMap(int row, int column)
{
    unsigned int temp;
    temp = 1<< column;
    temp = ~temp;
    CellBitMap[row-1]&=temp; 
}

int Table::getCellBitMap(int row, int column)
{
    unsigned int temp;
    temp = 1<< column;

    if(0 != CellBitMap[row-1] & temp)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}


void Table::setMergeAcross(int rowNumber, int begin, int end)
{
    _contentsOfTable[rowNumber-1].setMergeAcross(begin-1,end-1); 
    for(int i=begin; i<end+1; i++)
    {
        setCellBitMap(rowNumber-1,i);
    }
}
    void Table::setMergeDown(int cloumnNumber, int begin, int end)
{
    _contentsOfTable[begin-1].setMergeDown(cloumnNumber,begin,end); 
    for(int i=begin; i<end+1; i++)
    {
        setCellBitMap(i, cloumnNumber-1);
    }
}

