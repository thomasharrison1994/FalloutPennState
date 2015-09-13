//
//  Gun10mmPistol.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Gun10mmPistol.h"

Gun10mmPistol::Gun10mmPistol()
{
    itemName = "Gun10mmPistol";
    weaponRoundType = "10mm";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 4;
    weaponActionPointCost = 2;
    weaponRoundCost = 1;
}

Gun10mmPistol::Gun10mmPistol(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 1;
}