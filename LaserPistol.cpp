//
//  LaserPistol.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LaserPistol.h"

LaserPistol::LaserPistol()
{
    itemName = "Laser pistol";
    weaponRoundType = "Energy cell";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 60;
    weaponActionPointCost = 7;
    weaponRoundCost = 1;
}

LaserPistol::LaserPistol(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 1;
}