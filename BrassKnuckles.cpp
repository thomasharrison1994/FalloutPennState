//
//  BrassKnuckles.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "BrassKnuckles.h"

BrassKnuckles::BrassKnuckles()
{
    itemName = "Brass knuckles";
    //weaponRoundType = "Electron charge pack";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 60;
    weaponActionPointCost = 10;
    //weaponRoundCost = 12;
}

BrassKnuckles::BrassKnuckles(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
}