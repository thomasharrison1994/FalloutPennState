
//
//  Item.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Item.h"

using namespace std;

Item::Item()
{
    itemVal = 76;
    itemWeight = 40;
}

void Item::dummy()
{
    
}

int Item::getItemWeight() const
{
    return itemWeight;
}

void Item::setItemWeight(int theItemWeight)
{
    itemWeight = theItemWeight;
}

int Item::getItemValue() const
{
    return itemVal;
}

void Item::setItemValue(int theItemValue)
{
    itemVal = theItemValue;
}

string Item::getItemType() const
{
    return itemType;
}

void Item::setItemType(string theItemType)
{
    itemType = theItemType;
}

string Item::getItemDescription() const
{
    return itemDescription;
}

string Item::getItemName() const
{
    return itemName;
}

void Item::setItemName(string theItemName)
{
    itemName = theItemName;
}