//
//  AssaultRifle.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "AssaultRifle.h"

AssaultRifle::AssaultRifle()
{
    itemName = "Assault rifle";
    weaponRoundType = "5.56mm";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 20;
    weaponActionPointCost = 15;
    weaponRoundCost = 3;
}

AssaultRifle::AssaultRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 3;
}