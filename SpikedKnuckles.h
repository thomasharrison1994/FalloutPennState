//
//  SpikedKnuckles.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"UnarmedWeapon.h"

class SpikedKnuckles : public UnarmedWeapon
{
protected:
public:
    //Default constructor
    SpikedKnuckles();
    
    //Init constructor
    SpikedKnuckles(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_SpikedKnuckles_h
#define FalloutPennState_SpikedKnuckles_h



#endif
*/