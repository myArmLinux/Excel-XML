//
//  Row.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Row.h"
#include <sstream>

Row::Row() {
    _contentsOfRow = vector<Cell>();
}

Row::Row(Cell data[], int numOfCells) {
    for (int cellNum = 0; cellNum < numOfCells; cellNum++) {
        addCell(data[cellNum]);
    }
}

void Row::addCell(Cell newCell) {
    _contentsOfRow.push_back(newCell);
    
}

void Row::removeCell(int index) {
    _contentsOfRow.erase(_contentsOfRow.begin() + index);
}

void Row::setCell(Cell newCell, int index) {
    _contentsOfRow[index] = newCell;
}

Cell* Row::getCell(int index) {
    return &_contentsOfRow[index];
}

int Row::getNumberOfCells() {
    return (int) _contentsOfRow.size();
}

string Row::getXML(unsigned int rowBitMap) {
//    string temp = "   <Row>\n";
    stringstream tmpStream;
    string cellIndexStr;
    string temp = "   <Row ss:AutoFitHeight=\"0\">\n";
    
    for (int cellNum = 0; cellNum < _contentsOfRow.size(); cellNum++) {
        if(0 == rowBitMap & (1<<cellNum))
        continue;
        //tmpStream << cellNum;
        //tmpStream >> cellIndexStr;
        cellIndexStr = std::to_string(cellNum+1);
        printf("cellNum is :%d, cellIndexStr is:%s\n",cellNum, cellIndexStr.c_str());
        temp += _contentsOfRow[cellNum].getXML(cellIndexStr);
    }
    
    temp += "   </Row>\n";
    return temp;
}

void Row::setMergeAcross(int begin, int end)
{
    _contentsOfRow[begin].setMergeAcross(end-begin);
}

void Row::setMergeDown(int cloumn,int begin, int end)
{
    _contentsOfRow[cloumn-1].setMergeDown(end - begin);
}

