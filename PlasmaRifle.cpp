//
//  PlasmaRifle.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "PlasmaRifle.h"

PlasmaRifle::PlasmaRifle()
{
    itemName = "Plasma rifle";
    weaponRoundType = "Microfusion cell";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 60;
    weaponActionPointCost = 40;
    weaponRoundCost = 12;
}

PlasmaRifle::PlasmaRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 1;
}