//
//  Human.h
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"IntelligentEntity.h"

class Human : public IntelligentEntity
{
protected:
    string faction;
public:
    //Default constructor
    Human();
    
    Human(entityClass classType);
};

/*
#ifndef FalloutPennState_Human_h
#define FalloutPennState_Human_h



#endif
*/