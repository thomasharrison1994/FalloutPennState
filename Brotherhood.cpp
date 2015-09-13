//
//  Brotherhood.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "Brotherhood.h"
#include <iostream>

Brotherhood::Brotherhood()
{
    faction = "Brotherhood";
    name = faction;
    
    S = 8;
    P = 9;
    E = 8;
    C = 3;
    I = 6;
    A = 1;
    L = 2;
    
    health = 100 + E*20;
    actualHealth = health;
    actionPoints = 65 + A*2;
    actualActionPoints = actionPoints;
    carryWeight = 150 + S*10;
    
    level = 1;
    
    damageResistance = 1;
    
    inventory.clear();
    
    caps = 0;
    
    inventory.push_back(new GatlingLaser);
    inventory.push_back(new BrassKnuckles);
    inventory.push_back(new Armor("Power Armor", 15));
    inventory.push_back(new PreWarFood);
    inventory.push_back(new PostWarFood);
    inventory.push_back(new ElectronChargePack);
    /*
    for (int i = 0; i<50; i++)
    {
        inventory.push_back(new ElectronChargePack);
        //cout<<"generating ammo\n";
    }
    */
    caps = 21;
    
    Barter = setSkill(C, level);
    EnergyWeapons = setNPCSkill(P, level, TAG);
    Explosives = setSkill(P, level);
    Guns = setSkill(A, level);
    Lockpick = setSkill(P, level);
    Medicine = setSkill(I, level);
    MeleeWeapons = setSkill(S, level);
    Repair = setSkill(I, level);
    Science = setSkill(I, level);
    Sneak = setSkill(A, level);
    Speech = setSkill(C, level);
    Survival = setSkill(E, level);
    Unarmed = setSkill(E, level);    
}