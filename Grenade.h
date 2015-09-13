//
//  Grenade.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"ExplosiveWeapon.h"

class Grenade : public ExplosiveWeapon
{
protected:
public:
    //Default constructor
    Grenade();
    
    //Init constructor
    Grenade(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_Grenade_h
#define FalloutPennState_Grenade_h



#endif
*/