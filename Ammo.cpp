//
//  Ammo.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Ammo.h"

Ammo::Ammo()
{
    itemType = "Ammo";
    itemWeight = 0;
    itemName = "Ammo";
}


string Ammo::getRoundType() const
{
    return roundType;
}

string Ammo::getWeaponTypeFor() const
{
    return weaponTypeFor;
}