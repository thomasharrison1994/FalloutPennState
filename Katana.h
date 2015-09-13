//
//  Katana.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/30/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"MeleeWeapon.h"

class Katana : public MeleeWeapon
{
protected:
public:
    //Default constructor
    Katana();
    
    //Init constructor
    Katana(const string& myWeaponName, const string& myWeaponDescription, const int& myWeaponDamage, const int& myWeaponActionPointCost);
};


/*
#ifndef FalloutPennState_Katana_h
#define FalloutPennState_Katana_h



#endif
*/