//
//  ZapGlove.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"UnarmedWeapon.h"

class ZapGlove : public UnarmedWeapon
{
protected:
public:
    //Default constructor
    ZapGlove();
    
    //Init constructor
    ZapGlove(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_ZapGlove_h
#define FalloutPennState_ZapGlove_h



#endif
*/