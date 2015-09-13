//
//  LaserPistol.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"EnergyWeapon.h"

class LaserPistol : public EnergyWeapon
{
protected:
public:
    //Default constructor
    LaserPistol();
    
    //Init constructor
    LaserPistol(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_LaserPistol_h
#define FalloutPennState_LaserPistol_h



#endif
*/