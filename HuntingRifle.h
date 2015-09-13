//
//  HuntingRifle.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"GunWeapon.h"

class HuntingRifle : public GunWeapon
{
protected:
public:
    //Default constructor
    HuntingRifle();
    
    //Init constructor
    HuntingRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_HuntingRifle_h
#define FalloutPennState_HuntingRifle_h



#endif
*/