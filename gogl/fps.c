//
//  fps.c
//  gogl
//
//  Created by eastany on 15/4/10.
//  Copyright (c) 2015年 eastany. All rights reserved.
//

#include "fps.h"

double CalFrequency()
{
    static int count;
    static double save;
    static clock_t last, current;
    double timegap;
    
    ++count;
    if( count <= 50 )
        return save;
    count = 0;
    last = current;
    current = clock();
    timegap = (current-last);
    save = 50.0/timegap;
    return save;
}