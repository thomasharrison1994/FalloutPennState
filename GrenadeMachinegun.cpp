//
//  GrenadeMachinegun.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GrenadeMachinegun.h"

GrenadeMachinegun::GrenadeMachinegun()
{
    itemName = "Grenade machinegun";
    weaponRoundType = "25mm grenade";
    weaponName = itemName;
    itemDescription = weaponName;
    weaponDamage = 60;
    weaponActionPointCost = 40;
    weaponRoundCost = 3;
}

GrenadeMachinegun::GrenadeMachinegun(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost)
{
    itemName = myWeaponName;
    weaponName = itemName;
    weaponDamage = myWeaponDamage;
    itemDescription = myWeaponDescription;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = 3;
}