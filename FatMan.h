//
//  FatMan.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"ExplosiveWeapon.h"

class FatMan : public ExplosiveWeapon
{
protected:
public:
    //Default constructor
    FatMan();
    
    //Init constructor
    FatMan(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_FatMan_h
#define FalloutPennState_FatMan_h



#endif
*/