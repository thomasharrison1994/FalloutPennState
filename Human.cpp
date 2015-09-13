//
//  Human.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Human.h"

Human::Human()
{
    type = "Human";
    species = type;
}

Human::Human(entityClass classType) : IntelligentEntity(classType)
{
    name = "Wastelander";
}