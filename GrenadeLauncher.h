//
//  GrenadeLauncher.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"ExplosiveWeapon.h"

class GrenadeLauncher : public ExplosiveWeapon
{
protected:
public:
    //Default constructor
    GrenadeLauncher();
    
    //Init constructor
    GrenadeLauncher(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};



/*
#ifndef FalloutPennState_GrenadeLauncher_h
#define FalloutPennState_GrenadeLauncher_h



#endif
*/