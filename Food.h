//
//  Food.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/29/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"Aid.h"
#include<cstdlib>
#include<ctime>

class Food : public Aid
{
protected:
    int randFood;
public:
    //Default constructor
    Food();
};


/*
#ifndef FalloutPennState_Food_h
#define FalloutPennState_Food_h



#endif
*/