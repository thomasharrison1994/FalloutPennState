//
//  PlasmaRifle.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"EnergyWeapon.h"

class PlasmaRifle : public EnergyWeapon
{
protected:
public:
    //Default constructor
    PlasmaRifle();
    
    //Init constructor
    PlasmaRifle(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_PlasmaRifle_h
#define FalloutPennState_PlasmaRifle_h



#endif
*/