//
//  BrassKnuckles.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"UnarmedWeapon.h"

class BrassKnuckles : public UnarmedWeapon
{
protected:
public:
    //Default constructor
    BrassKnuckles();
    
    //Init constructor
    BrassKnuckles(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_BrassKnuckles_h
#define FalloutPennState_BrassKnuckles_h



#endif
*/