//
//  PlasmaPistol.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"EnergyWeapon.h"

class PlasmaPistol : public EnergyWeapon
{
protected:
public:
    //Default constructor
    PlasmaPistol();
    
    //Init constructor
    PlasmaPistol(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_PlasmaPistol_h
#define FalloutPennState_PlasmaPistol_h



#endif
*/