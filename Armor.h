//
//  Armor.h
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"Item.h"

class Armor : public Item
{
protected:
    string armorName;
    int armorDamageResistance;
public:
    //Default constructor
    Armor();
    
    Armor(string theArmorName);
    
    Armor(string theArmorName, int theArmorDamageResistance);
    
    int getArmorDamageResistance();
    
    string getArmorName();
};

/*
#ifndef FalloutPennState_Armor_h
#define FalloutPennState_Armor_h



#endif
*/