//
//  Cell.h
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#ifndef __Excel__Cell__
#define __Excel__Cell__

#include <stdio.h>
#include "Data.h"

#ifndef TOP_ALIGN
#define TOP_ALIGN 51
#define MIDDLE_ALIGN 52
#define DEFAULT_ALIGN 0
#define LIFT_ALIGN   53
#define NORMAL_MIDDLE_ALIGN 54
#define RIGHT_ALIGN  55
#define AUTO_ALIGN   56
#define MIDDLE_MIDDLE_ALIGN  58

#endif

class Cell {
    int _styleID;
    string MergeAcross;
    string MergeDown;
    Data _contentsOfCell;
public:
    Cell();
    Cell(Data Contents, int styleID);
    
    void setStyle(int ID);
    int getStyle();
    
    void setContents(Data contents);
    Data* getContents();
    string getXML(string cellIndex);
    void setMergeAcross(int acrossCnt);
    void setMergeDown(int downCnt);
};

#endif /* defined(__Excel__Cell__) */
