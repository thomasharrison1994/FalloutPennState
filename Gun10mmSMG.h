//
//  Gun10mmSMG.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"GunWeapon.h"

class Gun10mmSMG : public GunWeapon
{
protected:
public:
    //Default constructor
    Gun10mmSMG();
    
    //Init constructor
    Gun10mmSMG(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_Gun10mmSMG_h
#define FalloutPennState_Gun10mmSMG_h



#endif
*/