//
//  CombatKnife.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"MeleeWeapon.h"

class CombatKnife : public MeleeWeapon
{
protected:
public:
    //Default constructor
    CombatKnife();
    
    //Init constructor
    CombatKnife(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_CombatKnife_h
#define FalloutPennState_CombatKnife_h



#endif
*/