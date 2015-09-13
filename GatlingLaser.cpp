//
//  GatlingLaser.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/28/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GatlingLaser.h"

GatlingLaser::GatlingLaser()
{
    itemName = "Gatling Laser";
    weaponRoundType = "Electron charge pack";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 60;
    weaponActionPointCost = 40;
    weaponRoundCost = 12;
}

GatlingLaser::GatlingLaser(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponRoundType = "Electron charge pack";
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 12;
}