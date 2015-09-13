//
//  SniperRifle.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SniperRifle.h"

SniperRifle::SniperRifle()
{
    itemName = "Sniper rifle";
    weaponRoundType = ".308";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 45;
    weaponActionPointCost = 20;
    weaponRoundCost = 1;
}

SniperRifle::SniperRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 1;
}