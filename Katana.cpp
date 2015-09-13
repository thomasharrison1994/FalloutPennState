//
//  Katana.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Katana.h"

Katana::Katana()
{
    itemName = "Combat knife";
    //weaponRoundType = "Electron charge pack";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 11;
    weaponActionPointCost = 7;
    //weaponRoundCost = 12;
}

Katana::Katana(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
}