//
//  ObjectLibrary.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

//Define all objects of all types in this header file, import to main to make that less of a clusterfuck

#pragma once
#include <string>
#include <vector>
//#include "Weapon.h"
//#include "Creature.h"
#include "Armor.h"
#include "SuperMutant.h"
#include "Brotherhood.h"
#include "GatlingLaser.h"
#include "Minigun.h"
#include "Gun10mmPistol.h"
#include "SniperRifle.h"
#include "Katana.h"
#include "Flamer.h"
#include "HuntingRifle.h"
#include "BrassKnuckles.h"
#include "CombatKnife.h"
#include "Shishkebab.h"
#include "MissileLauncher.h"
#include "IntelligentEntity.h"

using namespace std;

//SuperMutant* gruntMutant = new SuperMutant;
//Brotherhood* paladin = new Brotherhood;

//Define game class
//put variables in class
//define the global in game class

vector<IntelligentEntity*> playerPlatoon;
vector<IntelligentEntity*> enemyPlatoon;

//IntelligentEntity theScholar(true);

Minigun ZionsRedemption("Zion's Redemption", "\"Now comes with justice!\"", 75, 30);

GatlingLaser TheUltraMax3000("The UltraMax 3000", "\"Russia's finest in ass-kicking technology.\"", 80, 10);

CombatKnife BrocksCombatKnife("Brock's Combat Knife", "\"Holy shit! Its Brock fucking Sampson!\"", 12, 3);

Gun10mmPistol Dual10mmPistols("Dual 10mm pistols", "\"Two headshots are better than one.\"", 8, 2);

SniperRifle ThePeeper("The Peeper", "\"The scope's to see if they're hot, the trigger's for when they're not.\"", 40, 10);

Katana DualKatanas("Dual Katanas", "\"For when one samurai sword isn't badass enough.\"", 22, 7);

Flamer Barbie("Barbie", "\"Hey good lookin', what's cookin'?\"", 55, 14);

BrassKnuckles Galvaknuckles("Galvaknuckles", "\"The latest in hand-to-hand zombie combat.\"", 15, 4);

HuntingRifle ClydesHuntingRifle("Clyde's Hunting Rifle", "\"Bang! click. Bang! click. Bang! click...\"", 30, 10);

Shishkebab Prometheus("Prometheus", "\"A gift from the gods... use it wisely.\"", 50, 20);

MissileLauncher DangerClose("Danger Close", "\"Watch for impact...\"", 120, 60);

//Armor powerArmor("Power Armor", 15);

/*
#ifndef FalloutPennState_ObjectLibrary_h
#define FalloutPennState_ObjectLibrary_h



#endif
*/