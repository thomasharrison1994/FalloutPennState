//
//  Minigun.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"GunWeapon.h"

class Minigun : public GunWeapon
{
protected:
public:
    //Default constructor
    Minigun();
    
    //Init constructor
    Minigun(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_Minigun_h
#define FalloutPennState_Minigun_h



#endif
*/