//
//  Aid.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Aid.h"

Aid::Aid()
{
    itemType = "Aid";
}

int Aid::getAidEffect() const
{
    return aidEffect;
}

void Aid::setAidEffect(int theAidEffect)
{
    aidEffect = theAidEffect;
}

string Aid::getAidType() const
{
    return aidType;
}

void Aid::setAidType(string theAidType)
{
    aidType = theAidType;
}

string Aid::getAidName() const
{
    return aidName;
}

void Aid::setAidName(string theAidName)
{
    aidName = theAidName;
}

int Aid::getAidActionPointCost() const
{
    return aidActionPointCost;
}

void Aid::setAidActionPointCost(int theAidActionPointCost)
{
    aidActionPointCost = theAidActionPointCost;
}