//
//  GatlingLaser.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/28/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"EnergyWeapon.h"

class GatlingLaser : public EnergyWeapon
{
protected:
public:
    //Default constructor
    GatlingLaser();
    
    //Init constructor
    GatlingLaser(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_GatlingLaser_h
#define FalloutPennState_GatlingLaser_h



#endif
*/