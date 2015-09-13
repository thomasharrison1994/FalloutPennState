//
//  Aid.h
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"Item.h"

class Aid : public Item
{
protected:
    string aidType;
    string aidName;
    string aidDescription;
    int aidEffect;
    int aidActionPointCost;
public:
    //Default constructor
    Aid();
    
    Aid(string myAidName, int myAidEffect, int myAidActionPointCost);
    
    //Returns the weapon's damage
    int getAidEffect() const;
    
    //Sets the weapon's damage
    void setAidEffect(int theAidEffect);
    
    //Returns the weapon's type
    string getAidType() const;
    
    //Sets the weapon's type
    void setAidType(string theAidType); 
    
    //Returns the weapon's name
    string getAidName() const;
    
    //Sets the weapon's name
    void setAidName(string theAidName);    
    
    //Returns the weapon's action point cost
    int getAidActionPointCost() const;
    
    //Sets the weapon's action point cost (now unnecessary)
    void setAidActionPointCost(int theAidActionPointCost);    
};

/*
#ifndef FalloutPennState_Aid_h
#define FalloutPennState_Aid_h



#endif
*/