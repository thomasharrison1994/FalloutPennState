//
//  Gun10mmPistol.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"GunWeapon.h"

class Gun10mmPistol : public GunWeapon
{
protected:
public:
    //Default constructor
    Gun10mmPistol();
    
    //Init constructor
    Gun10mmPistol(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_Gun10mmPistol_h
#define FalloutPennState_Gun10mmPistol_h



#endif
*/