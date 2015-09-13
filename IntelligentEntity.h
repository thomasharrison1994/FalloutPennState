//
//  IntelligentEntity.h
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include<string>
#include <vector>
#include <iostream>
//#include "Item.h"
/*
#include "GenericWindow.h"
#include "MasterButtonWindow.h"
#include "GameWindow.h"
#include "StatsWindow.h"
#include "DataWindow.h"
#include "ItemsWindow.h"
 */
#include "Minigun.h"
#include "GatlingLaser.h"
#include "HuntingRifle.h"
#include "Gun308Round.h"
#include "AssaultRifle.h"
#include "Gun556mmRound.h"
#include "Sledgehammer.h"
#include "SuperSledge.h"
#include "Armor.h"
#include "PostWarFood.h"
#include "PreWarFood.h"
#include "ElectronChargePack.h"
#include "Gun5mmRound.h"
#include "LaserPistol.h"
#include "Gun10mmPistol.h"
#include "CombatKnife.h"
#include "BrassKnuckles.h"
#include "Gun10mmRound.h"
#include "EnergyCell.h"
#include "SniperRifle.h"
#include "PlasmaRifle.h"
#include "PowerFist.h"
#include "MissileLauncher.h"
#include "MiscItem.h"
#include "Flamer.h"
#include "LaserRifle.h"
#include "PlasmaPistol.h"
#include "Katana.h"


using namespace std;

#define TAG true

//Expand the shit out of this (scribe, knight, pledge, pledge captain
enum entityClass {WASTELANDER, BROTHERHOOD, ZETA, ALPHA, ENCLAVE, TRISIG, NCR, GRIDIRON, CGC, TRIBAL, CREATURE};
enum entityServices {NONE, MERCHANT, DOCTOR, SPEAKER, FIGHTER, COMPANION};


class IntelligentEntity
{
protected:
    
    /*enum skill {BARTER, ENERGYWEAPONS, EXPLOSIVES, GUNS, LOCKPICK, MEDICINE, MELEEWEAPONS, REPAIR, SCIENCE, SNEAK, SPEECH, SURVIVAL, UNARMED};*/
    //create skill structure, has int value, bool tag, corresponding special value. Uncomment enum?
    //why did i want to make a skill structure
    /*
     struct skillStruct
     {
         int skillLevel;
         int specialSkill;
         bool tag;
     };
    */
    
    //vector<MasterButtonWindow*> PipBoy;
    
    int health;
    int actionPoints;
    int level;
    int damageResistance;
    int carryWeight;
    int skillPointsPerLevel;
    
    string type;
    string species;
    string name;
    
    //S.P.E.C.I.A.L. values
    int S; //Strength
    int P; //Perception
    int E; //Endurance
    int C; //Charisma
    int I; //Intelligence
    int A; //Agility
    int L; //Luck
    
    //Skills
    int Barter;
    int EnergyWeapons;
    int Explosives;
    int Guns;
    int Lockpick;
    int Medicine;
    int MeleeWeapons;
    int Repair;
    int Science;
    int Sneak;
    int Speech;
    int Survival;
    int Unarmed;
    
    //Inventory
    int caps;
    int xpValue;
    int xpForNextLevel;
    vector<Item*> inventory;
    
    //Current coordinates
    int xCoordinate;
    int yCoordinate;
    
    //Variant designation
    //int variantClass;
     
public:   
    int actualHealth;
    int actualTotalWeight;
    int actualActionPoints;
    
    //int caps;
    //vector<Item*> inventory;
    
    //int actualActionPoints;
    //Default constructor
    IntelligentEntity();
    
    //Test constructor for "custom class" enumeration parameter
    IntelligentEntity(entityClass classType);
    
    //Player character constructor
    IntelligentEntity(const bool& isPlayerCharacter);
    
    //Constructor for unique characters
    IntelligentEntity(const int& myHealth, const int& myActionPoints, const int& myLevel, const int& myDamageResistance,  const int& myCarryWeight, const string& myName, const int& myStrength, const int& myPerception, const int& myEndurance, const int& myCharisma, const int& myIntelligence, const int& myAgility, const int& myLuck, const int& myBarter, const int& myExplosives, const int& myGuns, const int& myLockpick, const int& myMedicine, const int& myMeleeWeapons, const int& myRepair, const int& myScience, const int& mySneak, const int& mySpeech, const int& mySurvival, const int& myUnarmed, const int& myCaps, const int& myXPValue, const vector<Item*>& myInventory);
    
    //Accesses the vector of pip boy windows
    //vector<MasterButtonWindow*> accessPipBoy();
    
    //Gets current xCoordinate of the entity
    int getXCoordinate();
    
    //Sets the xCoordinate of the entity
    void setXCoordinate(const int& newXCoordinate);
    
    //Gets current yCoordinate of the entity
    int getYCoordinate();
    
    //Sets the yCoordinate of the entity
    void setYCoordinate(const int& newYCoordinate);
    
    //Prints SPECIAL
    void outSpecial();
    
    //Prints SPECIAL (numbered)
    void outSpecial(const int& number);    
    
    //Prints skills
    void outSkills();
    
    //Prints skills (numbered)
    void outSkills(const int& number);
    
    //Sets each skill
    int setSkill(const int& correspondingSpecial);
    
    //Sets each skill (with tag!)
    int setSkill(const int& correspondingSpecial, const bool& tag);    
    
    //Sets each skill
    int setNPCSkill(const int& correspondingSpecial, const int& theLevel);
    
    //Sets each skill (with tag!)
    int setNPCSkill(const int& correspondingSpecial, const int& theLevel, const bool& tag);
    
    //tags a skill
    int tag(const int& skill, const bool& tag);
    
    //Returns the entity's Strength
    int getS() const;
    
    //Sets the entity's Strength
    void setS(int theS);  
    
    //Returns the entity's Perception
    int getP() const;
    
    //Sets the entity's Perception
    void setP(int theP); 
    
    //Returns the entity's Endurance
    int getE() const;
    
    //Sets the entity's Endurance
    void setE(int theE);  
    
    //Returns the entity's Charisma
    int getC() const;
    
    //Sets the entity's Charisma
    void setC(int theC);
    
    //Returns the entity's Intelligence
    int getI() const;
    
    //Sets the entity's Intelligence
    void setI(int theI); 
    
    //Returns the entity's Agility
    int getA() const;
    
    //Sets the entity's Agility
    void setA(int theA); 
    
    //Returns the entity's Luck
    int getL() const;
    
    //Sets the entity's Luck
    void setL(int theL);
    /*
    //Returns skill
    skill getSkill(skill theSkill) const;
    
    //Sets skill
    void setSkill(skill theSkill, int skillValue);
     */
    
    //Returns the entity's Barter
    int getBarter() const;
    
    //Sets the entity's Barter
    void setBarter(int theBarter);
    
    //Returns the entity's Energy Weaopns
    int getEnergyWeapons() const;
    
    //Sets the entity's Energy Weapons
    void setEnergyWeapons(int theEnergyWeapons);
    
    //Returns the entity's Explosives
    int getExplosives() const;
    
    //Sets the entity's Explosives
    void setExplosives(int theExplosives);  
    
    //Returns the entity's Guns
    int getGuns() const;
    
    //Sets the entity's Guns
    void setGuns(int theGuns);   
    
    //Returns the entity's Lockpick
    int getLockpick() const;
    
    //Sets the entity's Lockpick
    void setLockpick(int theLockpick); 
    
    //Returns the entity's Medicine
    int getMedicine() const;
    
    //Sets the entity's Medicine
    void setMedicine(int theMedicine);  
    
    //Returns the entity's Melee Weapons
    int getMeleeWeapons() const;
    
    //Sets the entity's Melee Weapons
    void setMeleeWeapons(int theMeleeWeapons);
    
    //Returns the entity's Repair
    int getRepair() const;
    
    //Sets the entity's Repair
    void setRepair(int theRepair);  
    
    //Returns the entity's Science
    int getScience() const;
    
    //Sets the entity's Science
    void setScience(int theScience); 
    
    //Returns the entity's Sneak
    int getSneak() const;
    
    //Sets the entity's Sneak
    void setSneak(int theSneak);  
    
    //Returns the entity's Speech
    int getSpeech() const;
    
    //Sets the entity's Speech
    void setSpeech(int theSpeech);   
    
    //Returns the entity's Survival
    int getSurvival() const;
    
    //Sets the entity's Survival
    void setSurvival(int theSurvival); 
    
    //Returns the entity's Unarmed
    int getUnarmed() const;
    
    //Sets the entity's Unarmed
    void setUnarmed(int theUnarmed);  
    
    //Returns the entity's health
    int getHealth() const;
    
    //Sets the entity's health
    void setHealth(int theHealth);  
    
    //Returns the entity's action points
    int getActionPoints() const;
    
    //Sets the entity's action points
    void setActionPoints(int theActionPoints);
    
    //Returns the entity's damage resistance
    int getDamageResistance() const;
    
    //Sets the entity's damage resistance
    void setDamageResistance(int theDamageResistance);
    
    //Returns the entity's carrying capacity
    int getCarryWeight() const;
    
    //Sets the entity's carrying capacity
    void setCarryWeight(int theCarryWeight);
    
    //Returns the entity's type
    string getType() const;
    
    //Sets the entity's type
    void setType(string theType);
    
    //Returns the entity's species
    string getSpecies() const;
    
    //Sets the entity's species
    void setSpecies(string theSpecies);
    
    //Returns the entity's name
    string getName() const;
    
    //Sets the entity's name
    void setName(string theName);
    
    //Returns the entire inventory
    vector<Item*> getInventory() const;
    
    //Sets the inventory of the scholar
    void setInventory(vector<Item*> theInventory);
    
    bool findItem(const string& typeToFind) const;
    
    void removeFromInventory(const int& itemCoordinate);
    
    void removeFromInvenrory(const string& removeName);
    
    void addItem(const Item& addItem, const int& addQuantity);
    
    //Finds an item in the entity's inventory
    Item* getItem(const int& inventoryPosition) const;
    
    //Finds the entity's weapon
    Weapon* getWeapon() const;
    
    //Returns all weapons in the entity's inventory
    vector<Weapon*> getWeapons() const;
    
    //Finds the entity's armor
    Armor* getArmor() const;
    
    //Returns all armor in the entity's inventory
    vector<Armor*> getArmors() const;
    
    //Finds the entity's aid
    Aid* getAid() const;
    
    //Returns all aids in the entity's inventory
    vector<Aid*> getAids() const;
    
    //Finds the entity's ammo
    Ammo* getAmmo() const;
    
    //Counts the ammo quantity in the entity's inventory
    int getTotalAmmo(const string& weaponAmmoTypeToCount) const;
    
    //Gets XP
    int getXP() const;
    
    //Gets the amount of XP for next level
    int getXPForNextLevel() const;
    
    //Returns level
    int getLevel() const;
    
    //Increases level
    void levelUp();
    
    //Gets amount of caps
    int getCaps() const;
    
    //Adds caps to total
    int addCaps(int capsIncrement);
    
    /*Statistics calculators*/
    /*
    //Calculates the entity's skill level for X skill
    int calculateSkillLevel(int& skill, const int& specialValue, const int& luckValue); //add tag! feature
    
    //Calculates the entity's health
    int calculateHealth(int& health, const int& enduranceValue); //add base health variable
    
    //Calculates the entity's action points
    int calculateActionPoints(int& actionPoints, const int& agilityValue); //add base action point variable
    
    //Calculates the entity's carry weight value
    int calculateCarryWeight(int& carryWeight, const int& strengthValue); //add base carry weight variable
     */
    
    //Calculates the entity's skill level for X skill
    int calculateSkillLevel(const int& specialValue, const int& luckValue); //add tag! feature
    
    //Calculates the entity's health
    int calculateHealth(const int& enduranceValue); //add base health variable
    
    //Calculates the entity's action points
    int calculateActionPoints(const int& agilityValue); //add base action point variable
    
    //Calculates the entity's carry weight value
    int calculateCarryWeight(const int& strengthValue); //add base carry weight variable
    
    int calculateSkillPoints(const int& intelligenceValue);
    
    
    
    //ostream& operator << (ostream& out, const IntelligentEntity& outIntelligentEntity);    
};

ostream& operator << (ostream& out, const IntelligentEntity& outIntelligentEntity);

/*
#ifndef FalloutPennState_IntelligentEntity_h
#define FalloutPennState_IntelligentEntity_h



#endif
*/