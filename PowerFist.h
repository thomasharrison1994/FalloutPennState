//
//  PowerFist.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"UnarmedWeapon.h"

class PowerFist : public UnarmedWeapon
{
protected:
public:
    //Default constructor
    PowerFist();
    
    //Init constructor
    PowerFist(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_PowerFist_h
#define FalloutPennState_PowerFist_h



#endif
*/