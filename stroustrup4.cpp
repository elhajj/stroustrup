//
//  stroustrup4.cpp
//  stroustrup
//
//  Created by Tim Elhajj on 5/10/15.
//  Copyright (c) 2015 Tim Elhajj. All rights reserved.
//
#include "TestHarness.h"
#include <stdio.h>
#include "std_lib_facilities.h" // stroustrup recommends using this header for early chapters



TEST(while, loop)
{

int i = 0;
    
while (i<100)
{
    cout<< i << '\t' << sqrt(i) << '\n'; // changed square() to sqrt() 
    ++i;
    
    }
    
}
