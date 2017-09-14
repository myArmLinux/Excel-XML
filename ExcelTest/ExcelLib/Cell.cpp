//
//  Cell.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Cell.h"

Cell::Cell() {
    this->_styleID = 0;
    this->_contentsOfCell = Data();
    this->MergeAcross = "";
    this->MergeDown = "";
}

Cell::Cell(Data Contents, int styleID) {
    this->setStyle(styleID);
    this->setContents(Contents);
}

void Cell::setStyle(int ID) {
    this->_styleID = ID;
}

int Cell::getStyle() {
    return this->_styleID;
}

void Cell::setContents(Data contents) {
    this->_contentsOfCell = contents;
}

void Cell::setMergeAcross(int acrossCnt)
{
    this->MergeAcross = std::to_string(acrossCnt);

}

void Cell::setMergeDown(int downCnt)
{
    this->MergeDown = std::to_string(downCnt);
}



Data* Cell::getContents() {
    return &_contentsOfCell;
}

string Cell::getXML(string cellIndex) {
//    string temp = "<Cell ss:StyleID=\"";
//    temp += to_string(_styleID);
//    temp += "\">";
    string temp = "    <Cell";
    
    
    temp += " ss:Index=\"" + cellIndex +"\"";
    if("" != this->MergeAcross)
    {
        temp+= " ss:MergeAcross=\""+this->MergeAcross+"\" ";
    }
    if("" != this->MergeDown )
    {
        temp+= " ss:MergeDown=\""+this->MergeDown+"\" ";
    } 
    switch(this->_styleID)
    {
        case TOP_ALIGN:
        {
           temp += " ss:StyleID=\"s51\" "; 
           break; 
        }
        case MIDDLE_ALIGN:
        {
            temp += " ss:StyleID=\"s52\" "; 
            break;
        } 
        case DEFAULT_ALIGN:
        {

            break;
        }
        case LIFT_ALIGN:
        {
            temp += " ss:StyleID=\"s53\" "; 
            break;
        }
        case NORMAL_MIDDLE_ALIGN:
        {
            temp += " ss:StyleID=\"s54\" "; 
            break;
        }
        case RIGHT_ALIGN:
        {
            temp += " ss:StyleID=\"s55\" "; 
            break;
        }
        case AUTO_ALIGN:
        {
            temp += " ss:StyleID=\"s56\" "; 
            break;
        }
        case MIDDLE_MIDDLE_ALIGN:
        {
            temp += " ss:StyleID=\"s58\" "; 
            break;
        }
        default:break;
    }
    temp += ">";   
    temp += _contentsOfCell.getXML();
    temp += "</Cell>\n";
    return temp;
}
