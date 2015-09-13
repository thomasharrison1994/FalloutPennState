//
//  Flamer.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"EnergyWeapon.h"

class Flamer : public EnergyWeapon
{
protected:
public:
    //Default constructor
    Flamer();
    
    //Init constructor
    Flamer(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};



/*
#ifndef FalloutPennState_Flamer_h
#define FalloutPennState_Flamer_h



#endif
*/