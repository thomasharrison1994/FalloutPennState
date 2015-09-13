//
//  HuntingRifle.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "HuntingRifle.h"

HuntingRifle::HuntingRifle()
{
    itemName = "Hunting rifle";
    weaponRoundType = ".308";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 12;
    weaponActionPointCost = 9;
    weaponRoundCost = 1;
}

HuntingRifle::HuntingRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 1;
}