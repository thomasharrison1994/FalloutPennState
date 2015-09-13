//
//  GrenadeMachinegun.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"ExplosiveWeapon.h"

class GrenadeMachinegun : public ExplosiveWeapon
{
protected:
public:
    //Default constructor
    GrenadeMachinegun();
    
    //Init constructor
    GrenadeMachinegun(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};



/*
#ifndef FalloutPennState_GrenadeMachinegun_h
#define FalloutPennState_GrenadeMachinegun_h



#endif
*/