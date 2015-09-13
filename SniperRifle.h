//
//  SniperRifle.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"GunWeapon.h"

class SniperRifle : public GunWeapon
{
protected:
public:
    //Default constructor
    SniperRifle();
    
    //Init constructor
    SniperRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_SniperRifle_h
#define FalloutPennState_SniperRifle_h



#endif
*/