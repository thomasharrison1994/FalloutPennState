//
//  Minigun.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Minigun.h"

Minigun::Minigun()
{
    itemName = "Minigun";
    weaponRoundType = "5mm";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 50;
    weaponActionPointCost = 45;
    weaponRoundCost = 10;
}

Minigun::Minigun(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 10;
}