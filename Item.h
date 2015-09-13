//
//  Item.h
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include<string>

using namespace std;

class Item
{
protected:
    int itemWeight;
    int itemVal;
    
    string itemType;
    string itemName;
    string itemDescription;
    
public:
    //Default constructor
    Item();
    
    virtual void dummy();
    
    //Returns the item's weight
    int getItemWeight() const;
    
    //Sets the item's weight
    void setItemWeight(int theItemWeight);
    
    //Returns the item's value
    int getItemValue() const;
    
    //Sets the item's value
    void setItemValue(int theItemValue);
    
    //Returns the item's type
    string getItemType() const;
    
    //Sets the item's type
    void setItemType(string theItemType);
    
    string getItemDescription() const;
    
    //Returns the item's name
    string getItemName() const;
    
    //Sets the item's name
    void setItemName(string theItemName);
};
/*
#ifndef FalloutPennState_Item_h
#define FalloutPennState_Item_h



#endif
*/