//
//  Gun10mmSMG.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Gun10mmSMG.h"

Gun10mmSMG::Gun10mmSMG()
{
    itemName = "Gun10mmSMG";
    weaponRoundType = "10mm";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 50;
    weaponActionPointCost = 45;
    weaponRoundCost = 5;
}

Gun10mmSMG::Gun10mmSMG(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 5;
}