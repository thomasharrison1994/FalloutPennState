//
//  Weapon.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Weapon.h"

Weapon::Weapon()
{
    itemType = "Weapon";
}

Weapon::Weapon(const string& myWeaponName, const string& myWeaponType, const string& myItemDescription, const string& myWeaponRoundType, const int& myItemValue, const int& myItemWeight, const int& myWeaponDamage, const int& myWeaponActionPointCost, const int& myWeaponRoundCost)
{
    weaponName = myWeaponName;
    itemName = weaponName;
    itemType = "Weapon";
    weaponType = myWeaponType;
    itemDescription = myItemDescription;
    weaponRoundType = myWeaponRoundType;
    itemVal = myItemValue;
    itemWeight = myItemWeight;
    weaponDamage = myWeaponDamage;
    weaponActionPointCost = myWeaponActionPointCost;
    weaponRoundCost = myWeaponRoundCost;
}

int Weapon::getWeaponDamage() const
{
    return weaponDamage;
}

void Weapon::setWeaponDamage(int theWeaponDamage)
{
    weaponDamage = theWeaponDamage;
}

string Weapon::getWeaponType() const
{
    return weaponType;
}

void Weapon::setWeaponType(string theWeaponType)
{
    weaponType = theWeaponType;
}

string Weapon::getWeaponName() const
{
    return weaponName;
}

string Weapon::getWeaponRoundType() const
{
    return weaponRoundType;
}

//Returns the weapon's round cost
int Weapon::getWeaponRoundCost() const
{
    return weaponRoundCost;
}

void Weapon::setWeaponName(string theWeaponName)
{
    weaponName = theWeaponName;
}

int Weapon::getWeaponActionPointCost() const
{
    return weaponActionPointCost;
}

void Weapon::setWeaponActionPointCost(int theWeaponActionPointCost)
{
    weaponActionPointCost = theWeaponActionPointCost;
}
