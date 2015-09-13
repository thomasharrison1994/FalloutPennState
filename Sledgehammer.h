//
//  Sledgehammer.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"MeleeWeapon.h"

class Sledgehammer : public MeleeWeapon
{
protected:
public:
    //Default constructor
    Sledgehammer();
    
    //Init constructor
    Sledgehammer(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


#ifndef FalloutPennState_Sledgehammer_h
#define FalloutPennState_Sledgehammer_h



#endif
