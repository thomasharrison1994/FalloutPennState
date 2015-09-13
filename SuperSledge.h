//
//  SuperSledge.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"MeleeWeapon.h"

class SuperSledge : public MeleeWeapon
{
protected:
public:
    //Default constructor
    SuperSledge();
    
    //Init constructor
    SuperSledge(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};

/*
#ifndef FalloutPennState_SuperSledge_h
#define FalloutPennState_SuperSledge_h



#endif
*/