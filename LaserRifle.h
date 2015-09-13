//
//  LaserRifle.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"EnergyWeapon.h"

class LaserRifle : public EnergyWeapon
{
protected:
public:
    //Default constructor
    LaserRifle();
    
    //Init constructor
    LaserRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_LaserRifle_h
#define FalloutPennState_LaserRifle_h



#endif
*/