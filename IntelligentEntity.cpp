//
//  IntelligentEntity.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "IntelligentEntity.h"

//Default constructor
IntelligentEntity::IntelligentEntity()
{
    /*
    PipBoy.push_back(new GameWindow);
    PipBoy.push_back(new StatsWindow);
    PipBoy.push_back(new DataWindow);
    PipBoy.push_back(new ItemsWindow);
     */
    
    level = 1;
    xpValue = 0;
    xpForNextLevel = 200;
    
    damageResistance = 0;
    
    xCoordinate = 3;
    yCoordinate = 3;
    
    actualTotalWeight = 0;
    
    caps = 1000;
    
    //TEST
    //actualHealth = 50;
    
    //Inventory tests
    inventory.push_back(new MissileLauncher);
    //inventory.push_back(new Minigun);
    inventory.push_back(new SuperSledge);
    inventory.push_back(new LaserPistol);
    inventory.push_back(new BrassKnuckles);
    inventory.push_back(new SniperRifle);
    inventory.push_back(new CombatKnife);
    inventory.push_back(new PlasmaRifle);
    inventory.push_back(new PowerFist);
    //inventory.push_back(new Armor("Power Armor"));
    /*
    inventory.push_back(new PreWarFood);
    inventory.push_back(new PostWarFood);
    inventory.push_back(new PreWarFood);
    inventory.push_back(new PostWarFood);    
    inventory.push_back(new PreWarFood);
    inventory.push_back(new PostWarFood);
    inventory.push_back(new PreWarFood);
    inventory.push_back(new PostWarFood);
    
    inventory.push_back(new Gun5mmRound);
    inventory.push_back(new Gun5mmRound);    
    inventory.push_back(new Gun5mmRound);
    inventory.push_back(new Gun5mmRound);
    inventory.push_back(new Gun5mmRound);
    inventory.push_back(new Gun5mmRound);
    inventory.push_back(new Gun5mmRound);    
    inventory.push_back(new Gun5mmRound);
    inventory.push_back(new Gun5mmRound);
    inventory.push_back(new Gun5mmRound);
    inventory.push_back(new Gun5mmRound);*/
}

IntelligentEntity::IntelligentEntity(entityClass classType)
{
    /*
     WASTELANDER
     BROTHERHOOD
     ZETA
     ALPHA
     ENCLAVE
     TRISIG
     NCR
     GRIDIRON
     CGC
     TRIBAL
     */
    switch (classType)
    {
        case WASTELANDER:
            
            S = 6;
            P = 5;
            E = 4;
            C = 4;
            I = 4;
            A = 6;
            L = 4;
            
            break;
            
        case BROTHERHOOD:
            
            break;
            
        case ZETA:
            
            break;
            
        case ALPHA:
            
            break;
            
        case ENCLAVE:
            
            break;
            
        case TRISIG:
            
            break;
            
        case NCR:
            
            break;
            
        case GRIDIRON:
            
            break;
            
        case CGC:
            
            break;
            
        case TRIBAL:
            
            break;
            
        default:
            
            break;
    }
}

IntelligentEntity::IntelligentEntity(const bool& isPlayerCharacter)
{
    
    int tag1;
    int tag2;
    int tag3;
    
    S=1;
    P=1;
    E=1;
    C=1;
    I=1;
    A=1;
    L=1;
    
    level = 1;
    
    xpValue = 0;
    
back1:
    
    cout<<"Enter your name:\n";
    getline(cin, name);
    
    
    int totalSPECIAL=33;
    int allocator;
    int yesNo = 2;    
    
back2:
    
    while (totalSPECIAL>0 || yesNo!=1)
    {    
        cout<<"Choose your SPECIAL:\n Points remaining: "<<totalSPECIAL<<endl<<endl;
        cout<<"1. Strength: "<<S<<endl;
        cout<<"2. Perception: "<<P<<endl;    
        cout<<"3. Endurance: "<<E<<endl;
        cout<<"4. Charisma: "<<C<<endl;
        cout<<"5. Intelligence: "<<I<<endl;
        cout<<"6. Agility: "<<A<<endl;    
        cout<<"7. Luck: "<<L<<endl;
        cin>>allocator;
    
        switch (allocator)
        {
        case 1:
            do 
            {
            cout<<"Allocate to Strength:\n";
            cin>>allocator;
                if (allocator<1 || allocator>10 || allocator-S>totalSPECIAL)
                {
                    cout<<"Invalid SPECIAL value, re-enter number between 1 and 10 that does not exceed the remaining number of SPECIAL points:\n";
                }
                /*else if(allocator>S)
                {
                    S-=allocator;
                    totalSPECIAL+=allocator;
                }*/
                else
                {
                    totalSPECIAL+=(S-allocator);
                    S=allocator;
                }
            }while (allocator<1 || allocator>10 || allocator-S>totalSPECIAL);
            break;
        case 2:
            do 
            {
                cout<<"Allocate to Perception:\n";
                cin>>allocator;
                if (allocator<1 || allocator>10 || allocator-P>totalSPECIAL)
                {
                    cout<<"Invalid SPECIAL value, re-enter number between 1 and 10 that does not exceed the remaining number of SPECIAL points:\n";
                }
                /*else if(allocator>S)
                 {
                 S-=allocator;
                 totalSPECIAL+=allocator;
                 }*/
                else
                {
                    totalSPECIAL+=(P-allocator);
                    P=allocator;
                }
            }while (allocator<1 || allocator>10 || allocator-P>totalSPECIAL);
            break;
        case 3:
            do 
            {
                cout<<"Allocate to Endurance:\n";
                cin>>allocator;
                if (allocator<1 || allocator>10 || allocator-E>totalSPECIAL)
                {
                    cout<<"Invalid SPECIAL value, re-enter number between 1 and 10 that does not exceed the remaining number of SPECIAL points:\n";
                }
                /*else if(allocator>S)
                 {
                 S-=allocator;
                 totalSPECIAL+=allocator;
                 }*/
                else
                {
                    totalSPECIAL+=(E-allocator);
                    E=allocator;
                }
            }while (allocator<1 || allocator>10 || allocator-E>totalSPECIAL);            
            break;
        case 4:
            do 
            {
                cout<<"Allocate to Charisma:\n";
                cin>>allocator;
                if (allocator<1 || allocator>10 || allocator-C>totalSPECIAL)
                {
                    cout<<"Invalid SPECIAL value, re-enter number between 1 and 10 that does not exceed the remaining number of SPECIAL points:\n";
                }
                /*else if(allocator>S)
                 {
                 S-=allocator;
                 totalSPECIAL+=allocator;
                 }*/
                else
                {
                    totalSPECIAL+=(C-allocator);
                    C=allocator;
                }
            }while (allocator<1 || allocator>10 || allocator-C>totalSPECIAL);
            break; 
        case 5:
            do 
            {
                cout<<"Allocate to Intelligence:\n";
                cin>>allocator;
                if (allocator<1 || allocator>10 || allocator-I>totalSPECIAL)
                {
                    cout<<"Invalid SPECIAL value, re-enter number between 1 and 10 that does not exceed the remaining number of SPECIAL points:\n";
                }
                /*else if(allocator>S)
                 {
                 S-=allocator;
                 totalSPECIAL+=allocator;
                 }*/
                else
                {
                    totalSPECIAL+=(I-allocator);
                    I=allocator;
                }
            }while (allocator<1 || allocator>10 || allocator-I>totalSPECIAL);
            break;
        case 6:
            do 
            {
                cout<<"Allocate to Agility:\n";
                cin>>allocator;
                if (allocator<1 || allocator>10 || allocator-A>totalSPECIAL)
                {
                    cout<<"Invalid SPECIAL value, re-enter number between 1 and 10 that does not exceed the remaining number of SPECIAL points:\n";
                }
                /*else if(allocator>S)
                 {
                 S-=allocator;
                 totalSPECIAL+=allocator;
                 }*/
                else
                {
                    totalSPECIAL+=(A-allocator);
                    A=allocator;
                }
            }while (allocator<1 || allocator>10 || allocator-A>totalSPECIAL);
            break;
        case 7:
            do 
            {
                cout<<"Allocate to Luck:\n";
                cin>>allocator;
                if (allocator<1 || allocator>10 || allocator-L>totalSPECIAL)
                {
                    cout<<"Invalid SPECIAL value, re-enter number between 1 and 10 that does not exceed the remaining number of SPECIAL points:\n";
                }
                /*else if(allocator>S)
                 {
                 S-=allocator;
                 totalSPECIAL+=allocator;
                 }*/
                else
                {
                    totalSPECIAL+=(L-allocator);
                    L=allocator;
                }
            }while (allocator<1 || allocator>10 || allocator-L>totalSPECIAL);
            break;            
        default:
            cout<<"Invalid option.\n";
            break;
        }
        if (totalSPECIAL==0)
        {
            cout<<"Final SPECIAL:\n";
            outSpecial();
            cout<<"Is this correct?:\n1. Yes\n2. No\n";
            cin>>yesNo;
        }
    }
    
back3:
    
    yesNo = 2;
    
    while (yesNo==2)
    {
    Barter = setSkill(C, level);
    EnergyWeapons = setSkill(P, level);
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
    
    int numTags = 3;
    
    while (numTags>0)
    {
        if (numTags==3)
        {
            cout<<"Choose your Tag! skills:\nTags remaining: "<<numTags<<endl;
            outSkills(1);
            cin>>tag1;
        }
        do 
        {
            numTags--;
            cout<<"Choose your Tag! skills:\nTags remaining: "<<numTags<<endl;
            outSkills(1);
            cin>>tag2;
            if (tag1==tag2)
            {
                cout<<"Skill has already been tagged\n";
            }
        } while (tag1==tag2);
        do 
        {
            numTags--;
            cout<<"Choose your Tag! skills:\nTags remaining: "<<numTags<<endl;
            outSkills(1);
            cin>>tag3;
            if (tag3==tag2 || tag3==tag1)
            {
                cout<<"Skill has already been tagged\n";
            }
        } while (tag3==tag2 || tag3==tag1); 
        
        numTags--;
    }
    /*
    cout<<"Skills that have been tagged are:\n";
    switch (tag1)
    {
        case 1:
            cout<<"Barter\n";
            Barter = setSkill(C, level, TAG);            
            break;
        case 2:
            cout<<"Energy Weapons\n";
            EnergyWeapons = setSkill(P, level, TAG);
            break;
        case 3:
            cout<<"Explosives\n";
            Explosives = setSkill(P, level, TAG);            
            break;
        case 4:
            cout<<"Guns\n";
            Guns = setSkill(A, level, TAG);            
            break;            
        case 5:
            cout<<"Lockpick\n";
            Lockpick = setSkill(P, level, TAG);            
            break;
        case 6:
            cout<<"Medicine\n";
            Medicine = setSkill(I, level, TAG);            
            break;
        case 7:
            cout<<"Melee Weapons\n";
            MeleeWeapons = setSkill(S, level, TAG);            
            break;
        case 8:
            cout<<"Repair\n";
            Repair = setSkill(I, level, TAG);            
            break;
        case 9:
            cout<<"Science\n";
            Science = setSkill(I, level, TAG);            
            break;
        case 10:
            cout<<"Sneak\n";
            Sneak = setSkill(A, level, TAG);            
            break;
        case 11:
            cout<<"Speech\n";
            Speech = setSkill(C, level, TAG);            
            break;
        case 12:
            cout<<"Survival\n";
            Survival = setSkill(E, level, TAG);            
            break;             
        case 13:
            cout<<"Unarmed\n";
            Unarmed = setSkill(E, level, TAG);            
            break;            
        default:
            break;
    }
    
    switch (tag2)
    {
        case 1:
            cout<<"Barter\n";
            Barter = setSkill(C, level, TAG);            
            break;
        case 2:
            cout<<"Energy Weapons\n";
            EnergyWeapons = setSkill(P, level, TAG);
            break;
        case 3:
            cout<<"Explosives\n";
            Explosives = setSkill(P, level, TAG);            
            break;
        case 4:
            cout<<"Guns\n";
            Guns = setSkill(A, level, TAG);            
            break;            
        case 5:
            cout<<"Lockpick\n";
            Lockpick = setSkill(P, level, TAG);            
            break;
        case 6:
            cout<<"Medicine\n";
            Medicine = setSkill(I, level, TAG);            
            break;
        case 7:
            cout<<"Melee Weapons\n";
            MeleeWeapons = setSkill(S, level, TAG);            
            break;
        case 8:
            cout<<"Repair\n";
            Repair = setSkill(I, level, TAG);            
            break;
        case 9:
            cout<<"Science\n";
            Science = setSkill(I, level, TAG);            
            break;
        case 10:
            cout<<"Sneak\n";
            Sneak = setSkill(A, level, TAG);            
            break;
        case 11:
            cout<<"Speech\n";
            Speech = setSkill(C, level, TAG);            
            break;
        case 12:
            cout<<"Survival\n";
            Survival = setSkill(E, level, TAG);            
            break;             
        case 13:
            cout<<"Unarmed\n";
            Unarmed = setSkill(E, level, TAG);            
            break;            
        default:
            break;
    }
    
    switch (tag3)
    {
        case 1:
            cout<<"Barter\n";
            Barter = setSkill(C, level, TAG);            
            break;
        case 2:
            cout<<"Energy Weapons\n";
            EnergyWeapons = setSkill(P, level, TAG);
            break;
        case 3:
            cout<<"Explosives\n";
            Explosives = setSkill(P, level, TAG);            
            break;
        case 4:
            cout<<"Guns\n";
            Guns = setSkill(A, level, TAG);            
            break;            
        case 5:
            cout<<"Lockpick\n";
            Lockpick = setSkill(P, level, TAG);            
            break;
        case 6:
            cout<<"Medicine\n";
            Medicine = setSkill(I, level, TAG);            
            break;
        case 7:
            cout<<"Melee Weapons\n";
            MeleeWeapons = setSkill(S, level, TAG);            
            break;
        case 8:
            cout<<"Repair\n";
            Repair = setSkill(I, level, TAG);            
            break;
        case 9:
            cout<<"Science\n";
            Science = setSkill(I, level, TAG);            
            break;
        case 10:
            cout<<"Sneak\n";
            Sneak = setSkill(A, level, TAG);            
            break;
        case 11:
            cout<<"Speech\n";
            Speech = setSkill(C, level, TAG);            
            break;
        case 12:
            cout<<"Survival\n";
            Survival = setSkill(E, level, TAG);            
            break;             
        case 13:
            cout<<"Unarmed\n";
            Unarmed = setSkill(E, level, TAG);            
            break;            
        default:
            break;
    }
        
        cout<<endl;
    */
    outSkills();
    
    cout<<"Is this correct?:\n1. Yes\n2. No\n";
    cin>>yesNo; 
    }
    
    cout<<"Begin journey or go back and edit character?\n1. Edit name\n2. Edit SPECIAL\n3. Edit Tag! skills\n4. Begin your journey\n";
    cin>>allocator;
    
    switch (allocator)
    {
        case 1:
            goto back1;
            break;
        case 2:
            goto back2;
        case 3:
            goto back3;
        default:
            int maxCombatSkill=EnergyWeapons;
            int maxCombatSkillIndex=0;
            int combatSkills[4] = {EnergyWeapons, Guns, MeleeWeapons, Unarmed};
            
            for (int q = 0; q<4; q++)
            {
                if (maxCombatSkill<combatSkills[q])
                {
                    maxCombatSkill=combatSkills[q];
                    maxCombatSkillIndex=q;
                }
            }
            
            switch (maxCombatSkillIndex)
        {
                case 0:
                inventory.push_back(new LaserPistol());
                //Add rounds
                    break;
                    
                default:
                    break;
            }
            
            
            
            break;
    }
}


//Constructor for unique entities (Rodney, Elder Berkowitz, The Guardian, etc.)
IntelligentEntity::IntelligentEntity(const int& myHealth, const int& myActionPoints, const int& myLevel, const int& myDamageResistance,  const int& myCarryWeight, const string& myName, const int& myStrength, const int& myPerception, const int& myEndurance, const int& myCharisma, const int& myIntelligence, const int& myAgility, const int& myLuck, const int& myBarter, const int& myExplosives, const int& myGuns, const int& myLockpick, const int& myMedicine, const int& myMeleeWeapons, const int& myRepair, const int& myScience, const int& mySneak, const int& mySpeech, const int& mySurvival, const int& myUnarmed, const int& myCaps, const int& myXPValue, const vector<Item*>& myInventory)
{
    health = myHealth;
    actionPoints = myActionPoints;
    level = myLevel;
    damageResistance = myDamageResistance;
    carryWeight = myCarryWeight;
    name = myName;
    
    S = myStrength;
    P = myPerception;
    E = myEndurance;
    C = myCharisma;
    I = myIntelligence;
    A = myAgility;
    L = myLuck;
    
    Barter = myBarter;
    Explosives = myExplosives;
    Guns = myGuns;
    Lockpick = myLockpick;
    Medicine = myMedicine;
    MeleeWeapons = myMeleeWeapons;
    Repair = myRepair;
    Science = myScience;
    Sneak = mySneak;
    Speech = mySpeech;
    Survival = mySurvival;
    Unarmed = myUnarmed;
    
    caps = myCaps;
    xpValue = myXPValue;
    inventory = myInventory;
}

int IntelligentEntity::getXCoordinate()
{
    return xCoordinate;
}

void IntelligentEntity::setXCoordinate(const int& newXCoordinate)
{
    xCoordinate = newXCoordinate;
}

int IntelligentEntity::getYCoordinate()
{
    return yCoordinate;
}

void IntelligentEntity::setYCoordinate(const int& newYCoordinate)
{
    yCoordinate = newYCoordinate;
}

void IntelligentEntity::outSpecial()
{
    cout<<"Strength: "<<S<<endl;
    cout<<"Perception: "<<P<<endl; 
    cout<<"Endurance: "<<E<<endl;
    cout<<"Charisma: "<<C<<endl;  
    cout<<"Intelligence: "<<I<<endl;
    cout<<"Agility: "<<A<<endl; 
    cout<<"Luck: "<<L<<endl;
}

void IntelligentEntity::outSpecial(const int& number)
{
    cout<<"1. Strength: "<<S<<endl;
    cout<<"2. Perception: "<<P<<endl; 
    cout<<"3. Endurance: "<<E<<endl;
    cout<<"4. Charisma: "<<C<<endl;  
    cout<<"5. Intelligence: "<<I<<endl;
    cout<<"6. Agility: "<<A<<endl; 
    cout<<"7. Luck: "<<L<<endl;
}


void IntelligentEntity::outSkills()
{
    cout<<"Barter: "<<Barter<<endl;
    cout<<"Energy Weapons: "<<EnergyWeapons<<endl; 
    cout<<"Explosives: "<<Explosives<<endl;
    cout<<"Guns: "<<Guns<<endl;  
    cout<<"Lockpick: "<<Lockpick<<endl;
    cout<<"Medicine: "<<Medicine<<endl; 
    cout<<"Melee Weapons: "<<MeleeWeapons<<endl;
    cout<<"Repair: "<<Repair<<endl;
    cout<<"Science: "<<Science<<endl; 
    cout<<"Sneak: "<<Sneak<<endl;
    cout<<"Speech: "<<Speech<<endl;  
    cout<<"Survival: "<<Survival<<endl;
    cout<<"Unarmed: "<<Unarmed<<endl;
}

void IntelligentEntity::outSkills(const int& number)
{
    cout<<"1. Barter: "<<Barter<<endl;
    cout<<"2. Energy Weapons: "<<EnergyWeapons<<endl; 
    cout<<"3. Explosives: "<<Explosives<<endl;
    cout<<"4. Guns: "<<Guns<<endl;  
    cout<<"5. Lockpick: "<<Lockpick<<endl;
    cout<<"6. Medicine: "<<Medicine<<endl; 
    cout<<"7. Melee Weapons: "<<MeleeWeapons<<endl;
    cout<<"8. Repair: "<<Repair<<endl;
    cout<<"9. Science: "<<Science<<endl; 
    cout<<"10. Sneak: "<<Sneak<<endl;
    cout<<"11. Speech: "<<Speech<<endl;  
    cout<<"12. Survival: "<<Survival<<endl;
    cout<<"13. Unarmed: "<<Unarmed<<endl;
}

int IntelligentEntity::setSkill(const int& correspondingSpecial)
{
    return (2 + (correspondingSpecial*2) + (L/2));
}

int IntelligentEntity::setSkill(const int& correspondingSpecial, const bool& tag)
{
    if (tag == true)
    {
        return (17 + (correspondingSpecial*2) + (L/2) /*+ isTag*/);
    }
    else
    {
        return (2 + (correspondingSpecial*2) + (L/2));
    }
    
}

int IntelligentEntity::setNPCSkill(const int& correspondingSpecial, const int& theLevel)
{
    return (2 + (correspondingSpecial*2) + (theLevel*5) + (L/2));
}

int IntelligentEntity::setNPCSkill(const int& correspondingSpecial, const int& theLevel, const bool& tag)
{
    if (tag == true)
    {
        return (17 + (correspondingSpecial*2) + (theLevel*5) + (L/2) /*+ isTag*/);
    }
    else
    {
        return (2 + (correspondingSpecial*2) + (theLevel*5) + (L/2));
    }
    
}

int IntelligentEntity::tag(const int& skill, const bool& tag)
{
    if (tag == true)
    {
        return (skill + 15);
    }
    else
    {
        return skill;
    }
}


//Level up for player is 25(3n+2)(n-1);


/*
 int IntelligentEntity::setSkillForPlayer(const int& correspondingSpecial, const int& theLevel)
 {
 return (2 + (correspondingSpecial*2) + (theLevel*5) + (L/2));
 }
 
 int IntelligentEntity::setSkill(const int& correspondingSpecial, const int& theLevel, const bool& tag)
 {
 return (17 + (correspondingSpecial*2) + (theLevel*5) + (L/2) + isTag);
} 
 */

//Returns the entity's Strength
int IntelligentEntity::getS() const
{
    return S;
}

//Sets the entity's Strength
void IntelligentEntity::setS(int theS)
{
    S = theS;
}

//Returns the entity's Perception
int IntelligentEntity::getP() const
{
    return P;
}

//Sets the entity's Perception
void IntelligentEntity::setP(int theP)
{
    P = theP;
}

//Returns the entity's Endurance
int IntelligentEntity::getE() const
{
    return E;
}

//Sets the entity's Endurance
void IntelligentEntity::setE(int theE)
{
    E = theE;
}

//Returns the entity's Charisma
int IntelligentEntity::getC() const
{
    return C;
}

//Sets the entity's Charisma
void IntelligentEntity::setC(int theC)
{
    C = theC;
}

//Returns the entity's Intelligence
int IntelligentEntity::getI() const
{
    return I;
}

//Sets the entity's Intelligence
void IntelligentEntity::setI(int theI)
{
    I = theI;
}

//Returns the entity's Agility
int IntelligentEntity::getA() const
{
    return A;
}

//Sets the entity's Agility
void IntelligentEntity::setA(int theA)
{
    A = theA;
}

//Returns the entity's Luck
int IntelligentEntity::getL() const
{
    return L;
}

//Sets the entity's Luck
void IntelligentEntity::setL(int theL)
{
    L = theL;
}
/*
//Returns skill
skill IntelligentEntity::getSkill(skill theSkill, int skillValue) const
{
    return theSkill;
}

//Sets skill
void setSkill(skill theSkill)
{
    
}
 */
//Returns the entity's Barter
int IntelligentEntity::getBarter() const
{
    return Barter;
}

//Sets the entity's Barter
void IntelligentEntity::setBarter(int theBarter)
{
    Barter = theBarter;
}

//Returns the entity's Energy Weaopns
int IntelligentEntity::getEnergyWeapons() const
{
    return EnergyWeapons;
}

//Sets the entity's Energy Weapons
void IntelligentEntity::setEnergyWeapons(int theEnergyWeapons)
{
    EnergyWeapons = theEnergyWeapons;
}

//Returns the entity's Explosives
int IntelligentEntity::getExplosives() const
{
    return Explosives;
}

//Sets the entity's Explosives
void IntelligentEntity::setExplosives(int theExplosives)
{
    Explosives = theExplosives;
}

//Returns the entity's Guns
int IntelligentEntity::getGuns() const
{
    return Guns;
}

//Sets the entity's Guns
void IntelligentEntity::setGuns(int theGuns)
{
    Guns = theGuns;
}

//Returns the entity's Lockpick
int IntelligentEntity::getLockpick() const
{
    return Lockpick;
}

//Sets the entity's Lockpick
void IntelligentEntity::setLockpick(int theLockpick)
{
    Lockpick = theLockpick;
}

//Returns the entity's Medicine
int IntelligentEntity::getMedicine() const
{
    return Medicine;
}

//Sets the entity's Medicine
void IntelligentEntity::setMedicine(int theMedicine)
{
    Medicine = theMedicine;
}

//Returns the entity's Melee Weapons
int IntelligentEntity::getMeleeWeapons() const
{
    return MeleeWeapons;
}

//Sets the entity's Melee Weapons
void IntelligentEntity::setMeleeWeapons(int theMeleeWeapons)
{
    MeleeWeapons = theMeleeWeapons;
}

//Returns the entity's Repair
int IntelligentEntity::getRepair() const
{
    return Repair;
}

//Sets the entity's Repair
void IntelligentEntity::setRepair(int theRepair)
{
    Repair = theRepair;
}

//Returns the entity's Science
int IntelligentEntity::getScience() const
{
    return Science;
}

//Sets the entity's Science
void IntelligentEntity::setScience(int theScience)
{
    Science = theScience;
}

//Returns the entity's Sneak
int IntelligentEntity::getSneak() const
{
    return Sneak;
}

//Sets the entity's Sneak
void IntelligentEntity::setSneak(int theSneak)
{
    Sneak = theSneak;
}

//Returns the entity's Speech
int IntelligentEntity::getSpeech() const
{
    return Speech;
}

//Sets the entity's Speech
void IntelligentEntity::setSpeech(int theSpeech)
{
    Speech = theSpeech;
}

//Returns the entity's Survival
int IntelligentEntity::getSurvival() const
{
    return Survival;
}

//Sets the entity's Survival
void IntelligentEntity::setSurvival(int theSurvival)
{
    Survival = theSurvival;
}

//Returns the entity's Unarmed
int IntelligentEntity::getUnarmed() const
{
    return Unarmed;
}

//Sets the entity's Unarmed
void IntelligentEntity::setUnarmed(int theUnarmed)
{
    Unarmed = theUnarmed;
}

//Returns the entity's health
int IntelligentEntity::getHealth() const
{
    return health;
}

//Sets the entity's health
void IntelligentEntity::setHealth(int theHealth)
{
    health = theHealth;
}

int IntelligentEntity::getDamageResistance() const
{
    return damageResistance;
}

void IntelligentEntity::setDamageResistance(int theDamageResistance)
{
    damageResistance = theDamageResistance;
}

//Returns the entity's action points
int IntelligentEntity::getActionPoints() const
{
    return actionPoints;
}

//Sets the entity's action points
void IntelligentEntity::setActionPoints(int theActionPoints)
{
    actionPoints = theActionPoints;
}

int IntelligentEntity::getCarryWeight() const
{
    return carryWeight;
}

void IntelligentEntity::setCarryWeight(int theCarryWeight)
{
    carryWeight = theCarryWeight;
}

//Returns the entity's type
string IntelligentEntity::getType() const
{
    return type;
}

//Sets the entity's type
void IntelligentEntity::setType(string theType)
{
    type = theType;
}

//Returns the entity's species
string IntelligentEntity::getSpecies() const
{
    return species;
}

//Sets the entity's species
void IntelligentEntity::setSpecies(string theSpecies)
{
    species = theSpecies;
}

//Returns the entity's name
string IntelligentEntity::getName() const
{
    return name;
}

//Sets the entity's name
void IntelligentEntity::setName(string theName)
{
    name = theName;
}

vector<Item*> IntelligentEntity::getInventory() const
{
    return inventory;
}

void IntelligentEntity::setInventory(vector<Item *> theInventory)
{
    inventory = theInventory;
}

bool IntelligentEntity::findItem(const string& typeToFind) const
{
    bool isThere=false;
    
    for (int i = 0; i<inventory.size(); i++)
    {
        if (inventory[i]->getItemType()==typeToFind)
        {
            isThere=true;
        }
    }
    return isThere;
}

void IntelligentEntity::removeFromInventory(const int& itemCoordinate)
{
    inventory.erase(inventory.begin()+itemCoordinate);
}

void IntelligentEntity::removeFromInvenrory(const string &removeName)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i]->getItemName() == removeName)
        {
            inventory.erase(inventory.begin()+i);
            
            return ;
        }
    }
}

void IntelligentEntity::addItem(const Item& addItem, const int& addQuantity)
{
    for (int i = 0; i<addQuantity; i++)
    {
       // inventory.push_back(addItem);
    }
}

//Finds an item in the entity's inventory
//Make this template function
Item* IntelligentEntity::getItem(const int& inventoryPosition) const
{
    return inventory[inventoryPosition];
}

//Finds the entity's weapon
Weapon* IntelligentEntity::getWeapon() const
{
    int i = 0;
    while (inventory[i]->getItemType()!="Weapon")
    {
        i++;
    }
    return dynamic_cast<Weapon*>(inventory[i]);
}

vector<Weapon*> IntelligentEntity::getWeapons() const
{
    vector<Weapon*> entityWeaponList;
    
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i]->getItemType() == "Weapon")
        {
            entityWeaponList.push_back(dynamic_cast<Weapon*>(inventory[i]));
        }
    }
    
    return entityWeaponList;
}

//Finds the entity's armor
Armor* IntelligentEntity::getArmor() const
{
    int i = 0;
    while (inventory[i]->getItemType()!="Armor")
    {
        i++;
    }
    return dynamic_cast<Armor*>(inventory[i]);
}

vector<Armor*> IntelligentEntity::getArmors() const
{
    vector<Armor*> entityArmorList;
    
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i]->getItemType() == "Armor")
        {
            entityArmorList.push_back(dynamic_cast<Armor*>(inventory[i]));
        }
    }
    
    return entityArmorList;
}

Aid* IntelligentEntity::getAid() const
{
    int i = 0;
    while (inventory[i]->getItemType()!="Aid")
    {
        i++;
    }
    return dynamic_cast<Aid*>(inventory[i]);
}

vector<Aid*> IntelligentEntity::getAids() const
{
    vector<Aid*> entityAidList;
    
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i]->getItemType() == "Aid")
        {
            entityAidList.push_back(dynamic_cast<Aid*>(inventory[i]));
        }
    }
    
    return entityAidList;
}

//Finds the entity's ammo
Ammo* IntelligentEntity::getAmmo() const
{
    int i = 0;
    while (inventory[i]->getItemType()!="Ammo")
    {
        i++;
    }
    return dynamic_cast<Ammo*>(inventory[i]);    
}

//Counts the ammo quantity in the entity's inventory
int IntelligentEntity::getTotalAmmo(const string& weaponAmmoTypeToCount) const
{
    int ammoCount=0;
    Ammo ammoInInventory;
    
    for (int i=0; i<inventory.size(); i++)
    {
        if (inventory[i]->getItemType()=="Ammo")
        {
            ammoInInventory = *dynamic_cast<Ammo*>(inventory[i]);
            
            if (ammoInInventory.getRoundType()==weaponAmmoTypeToCount)
            {
                ammoCount++;
            }
        }
    }
    return ammoCount;
}

int IntelligentEntity::getXP() const
{
    return xpValue;
}

int IntelligentEntity::getXPForNextLevel() const
{
    return xpForNextLevel;
}

int IntelligentEntity::getLevel() const
{
    return level;
}

//Level up for player is 25(3n+2)(n-1);

void IntelligentEntity::levelUp()
{
    ++level;
    
    xpForNextLevel = 25*((3*(level+1))+2)*((level+1)-1);
}

int IntelligentEntity::getCaps() const
{
    return caps;
}

int IntelligentEntity::addCaps(int capsIncrement)
{
    caps += capsIncrement;
}

/*Statistc Calculators*/
/*
//Calculates the entity's skill level
int IntelligentEntity::calculateSkillLevel(int& skill, const int& specialValue, const int& luckValue)
{
    skill = 2 + specialValue*2 + luckValue/2;
    
    return skill;
}

//Calculates the entity's health
int IntelligentEntity::calculateHealth(int& health, const int& enduranceValue)
{
    health = enduranceValue*20 + 100; //Change 100 to base value for health, should be different for each type of intelligent entity
    
    return health;
}

//Calculates the entity's action points
int IntelligentEntity::calculateActionPoints(int& actionPoints, const int& agilityValue)
{
    actionPoints = agilityValue*2 + 65; //Change 65 to base value for action points, should be different for each type of intelligent entity
    
    return actionPoints;
}

//Calculates the entity's carry weight value
int IntelligentEntity::calculateCarryWeight(int& carryWeight, const int& strengthValue)
{
    carryWeight = strengthValue*10 + 100; //Change 100 to base value for carry weight, should be different for each type of intelligent entity
    
    return carryWeight;
}
*/

//Calculates the entity's skill level
int IntelligentEntity::calculateSkillLevel(const int& specialValue, const int& luckValue)
{
    int skill;
    
    skill = 2 + specialValue*2 + luckValue/2;
    
    return skill;
}

//Calculates the entity's health
int IntelligentEntity::calculateHealth(const int& enduranceValue)
{
    health = enduranceValue*20 + 100; //Change 100 to base value for health, should be different for each type of intelligent entity
    
    return health;
}

//Calculates the entity's action points
int IntelligentEntity::calculateActionPoints(const int& agilityValue)
{
    actionPoints = agilityValue*2 + 65; //Change 65 to base value for action points, should be different for each type of intelligent entity
    
    return actionPoints;
}

//Calculates the entity's carry weight value
int IntelligentEntity::calculateCarryWeight(const int& strengthValue)
{
    carryWeight = strengthValue*10 + 150; //Change 100 to base value for carry weight, should be different for each type of intelligent entity
    
    return carryWeight;
}

int IntelligentEntity::calculateSkillPoints(const int& intelligenceValue)
{
    skillPointsPerLevel = intelligenceValue + 10;
    
    return skillPointsPerLevel;
}

ostream& operator << (ostream& out, const IntelligentEntity& outIntelligentEntity)
{
	return out << outIntelligentEntity.getName() << "| Health: " << outIntelligentEntity.actualHealth << "| Equipped weapon: " << outIntelligentEntity.getWeapon()->getWeaponName() << "| Action points: " << outIntelligentEntity.getActionPoints();
}
