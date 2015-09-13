//
//  AssaultRifle.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"GunWeapon.h"

class AssaultRifle : public GunWeapon
{
protected:
public:
    //Default constructor
    AssaultRifle();
    
    //Init constructor
    AssaultRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_AssaultRifle_h
#define FalloutPennState_AssaultRifle_h



#endif
*/