//
//  Weapon.h
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"Item.h"

class Weapon : public Item
{
protected:
    string weaponType;
    string weaponName;
    string weaponRoundType;
    int weaponDamage;
    int weaponActionPointCost;
    int weaponRoundCost;
public:
    //Default constructor
    Weapon();
    
    Weapon(const string& myWeaponType, const string& myWeaponName, const string& weaponRoundType, const int& myWeaponDamage, const int& myWeaponActionPointCost, const int& myWeaponRoundCost);
    
    Weapon(const string& myWeaponName, const string& myWeaponType, const string& myItemDescription, const string& myWeaponRoundType, const int& myItemValue, const int& myItemWeight, const int& myWeaponDamage, const int& myWeaponActionPointCost, const int& myWeaponRoundCost);
    
    //Returns the weapon's damage
    int getWeaponDamage() const;
    
    //Sets the weapon's damage
    void setWeaponDamage(int theWeaponDamage);
    
    //Returns the weapon's type
    string getWeaponType() const;
    
    //Sets the weapon's type
    void setWeaponType(string theWeaponType); 
    
    //Returns the weapon's name
    string getWeaponName() const;
    
    //Returns the weapon's round type
    string getWeaponRoundType() const;
    
    //Returns the weapon's round cost
    int getWeaponRoundCost() const;
    
    //Sets the weapon's name
    void setWeaponName(string theWeaponName);    
    
    //Returns the weapon's action point cost
    int getWeaponActionPointCost() const;
    
    //Sets the weapon's action point cost (now unnecessary)
    void setWeaponActionPointCost(int theWeaponActionPointCost);    
};

/*
#ifndef FalloutPennState_Weapon_h
#define FalloutPennState_Weapon_h



#endif
*/