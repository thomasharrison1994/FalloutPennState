//
//  Ammo.h
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include"Item.h"

class Ammo : public Item
{
protected:
    //int roundVal;
    string roundType;
    string weaponTypeFor;
public:
    //Default constructor
    Ammo();
    
    string getRoundType() const;
    
    string getWeaponTypeFor() const;
};

/*
#ifndef FalloutPennState_Ammo_h
#define FalloutPennState_Ammo_h



#endif
*/