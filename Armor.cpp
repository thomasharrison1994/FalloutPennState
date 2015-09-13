//
//  Armor.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Armor.h"

Armor::Armor()
{
    itemType = "Armor";
    armorDamageResistance = 99;
}

Armor::Armor(string theArmorName)
{
    itemType = "Armor";
    armorDamageResistance = 99;
    armorName = theArmorName;
    itemName = armorName;
}

Armor::Armor(string theArmorName, int theArmorDamageResistance)
{
    itemType = "Armor";
    armorName = theArmorName;
    itemName = armorName;
    armorDamageResistance = theArmorDamageResistance;
}

int Armor::getArmorDamageResistance()
{
    return armorDamageResistance;
}

string Armor::getArmorName()
{
    return armorName;
}