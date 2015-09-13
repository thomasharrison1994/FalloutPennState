//
//  SuperMutant.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SuperMutant.h"

SuperMutant::SuperMutant()
{
    species = "Super Mutant";
    name = species;
    
    S = 8;
    P = 2;
    E = 8;
    C = 1;
    I = 2;
    A = 4;
    L = 4;
    
    health = 100 + E*20;
    actualHealth = health;
    actionPoints = 65 + A*2;
    actualActionPoints = actionPoints;
    carryWeight = 150 + S*10;
    
    level = 1;
    
    damageResistance = 3;
    
    inventory.clear();
    
    inventory.push_back(new Minigun);
    inventory.push_back(new PreWarFood);
    inventory.push_back(new PostWarFood);
    
    for (int i = 0; i<100; i++)
    {
        inventory.push_back(new Gun5mmRound);
    }
    
    caps = 13;
    xpValue = 10;
    
    Barter = setSkill(C, level);
    EnergyWeapons = setSkill(P, level);
    Explosives = setSkill(P, level);
    Guns = setNPCSkill(A, level, TAG);
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

SuperMutant::SuperMutant(int classIdentifier)
{
    S = 8;
    P = 2;
    E = 8;
    C = 1;
    I = 2;
    A = 4;
    L = 4;
    
    health = 100 + E*20;
    actualHealth = health;
    actionPoints = 65 + A*2;
    carryWeight = 150 + S*10;    
    
    switch (classIdentifier)
    {
        case 1:
            species = "Super Mutant";
            name = species;
            
            level = 1;
            
            damageResistance = 3;
            
            inventory.push_back(new HuntingRifle);
            inventory.push_back(new PreWarFood);
            inventory.push_back(new PostWarFood);
            
            for (int i = 0; i<20; i++)
            {
                inventory.push_back(new Gun308Round);
            }
            
            caps = 13;
            xpValue = 10;
            
            break;
            
        case 2:
            species = "Super Mutant";
            name = "Super Mutant Brute";
            
            level = 3;
            
            damageResistance = 6;
            
            inventory.push_back(new AssaultRifle);
            inventory.push_back(new Sledgehammer);
            inventory.push_back(new PreWarFood);
            inventory.push_back(new PostWarFood);
            
            for (int i = 0; i<60; i++)
            {
                inventory.push_back(new Gun556mmRound);
            }
            
            caps = 60;
            xpValue = 30;
            
            break; 
            
        case 3:
            species = "Super Mutant";
            name = "Super Mutant Master";
            
            level = 5;
            
            damageResistance = 12;
            
            inventory.push_back(new Minigun);
            inventory.push_back(new SuperSledge);
            inventory.push_back(new PreWarFood);
            inventory.push_back(new PostWarFood);
            
            for (int i = 0; i<100; i++)
            {
                inventory.push_back(new Gun5mmRound);
            }
            
            caps = 90;
            xpValue = 50;
            
            break;            
            
        default:
            break;
            
    Barter = setSkill(C, level);
    EnergyWeapons = setSkill(P, level);
    Explosives = setNPCSkill(P, level, TAG);
    Guns = setNPCSkill(A, level, TAG);
    Lockpick = setSkill(P, level);
    Medicine = setSkill(I, level);
    MeleeWeapons = setNPCSkill(S, level, TAG);
    Repair = setSkill(I, level);
    Science = setSkill(I, level);
    Sneak = setSkill(A, level);
    Speech = setSkill(C, level);
    Survival = setSkill(E, level);
    Unarmed = setSkill(E, level);            
            
    }
    
    actualHealth = health;
    actualActionPoints = actionPoints;
}
