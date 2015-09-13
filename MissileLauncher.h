//
//  MissileLauncher.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"ExplosiveWeapon.h"

class MissileLauncher : public ExplosiveWeapon
{
protected:
public:
    //Default constructor
    MissileLauncher();
    
    //Init constructor
    MissileLauncher(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_MissileLauncher_h
#define FalloutPennState_MissileLauncher_h



#endif
*/