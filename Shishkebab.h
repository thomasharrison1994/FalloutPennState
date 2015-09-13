//
//  Shishkebab.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"MeleeWeapon.h"

class Shishkebab : public MeleeWeapon
{
protected:
public:
    //Default constructor
    Shishkebab();
    
    //Init constructor
    Shishkebab(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_Shishkebab_h
#define FalloutPennState_Shishkebab_h



#endif
*/