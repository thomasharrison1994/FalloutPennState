//
//  LionPaw.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"UnarmedWeapon.h"

class LionPaw : public UnarmedWeapon
{
protected:
public:
    //Default constructor
    LionPaw();
    
    //Init constructor
    LionPaw(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_LionPaw_h
#define FalloutPennState_LionPaw_h



#endif
*/