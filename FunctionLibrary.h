//
//  FunctionLibrary.h
//  FalloutPennState
//
//  Created by Tom Harrison on 3/22/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
//template function for outputting lists
//Revamp battle, need to be able to sift through menus at will, can't get from select weapon back to target

int getSubInventory(const IntelligentEntity& selectingEntity, const string& listType)
{
    int listNum = 1;
    vector<int> positionList;
    
    cout<<"Select "<<listType<<":\n";
    cout<<"0. Back\n";
    for (int i = 0; i<selectingEntity.getInventory().size(); i++)
    {
        if (selectingEntity.getInventory()[i]->getItemType()==listType)
        {
            cout<<listNum<<". "<<selectingEntity.getInventory()[i]->getItemName()<<endl;
            positionList.push_back(i);
            listNum++;
        }
    }
    cin>>listNum;
    
    if (listNum==0)
    {
        return -1;
    }
    else
    {
        return positionList[listNum-1];
    }
}

int defend(const IntelligentEntity& defendingIntelligentEntity)
{
    int finalDamageResistance = defendingIntelligentEntity.getDamageResistance();
    
    if (defendingIntelligentEntity.findItem("Armor")==true)
    {
        finalDamageResistance+=defendingIntelligentEntity.getArmor()->getArmorDamageResistance();
    }
    //cout<<"damage resistance of armor is "<<defendingIntelligentEntity.getArmor()->getArmorDamageResistance();
    return finalDamageResistance;
}

void attack(IntelligentEntity& attackingIntelligentEntity, IntelligentEntity& defendingIntelligentEntity, const int& attackingWeapon, int& apCost)
{
    int baseDamage;
    int finalDamage;
    Weapon* weaponInUse = dynamic_cast<Weapon*>(attackingIntelligentEntity.getInventory()[attackingWeapon]);
    //cout<<"Point1\n";
    int totalAmountOfAmmo = attackingIntelligentEntity.getTotalAmmo(weaponInUse->getWeaponRoundType());
    int weaponsRoundCost = weaponInUse->getWeaponRoundCost();
    //"Point2\n";
    //int attackingWeapon;
    
    //attackingWeapon = getSubInventory(attackingIntelligentEntity, "Weapon");
    
    if((apCost - weaponInUse->getWeaponActionPointCost()) < 0)
    {
        cout<<"Not enough action points to use this item\n";
        //return;
    }
    else if ((totalAmountOfAmmo - weaponInUse->getWeaponRoundCost()) < 0)
    {
        cout<<"Not enough ammo to use this item\n";
    }
    else
    {
    baseDamage = weaponInUse->getWeaponDamage();
    
    string theWeaponType = weaponInUse->getWeaponType();
    
    apCost -= weaponInUse->getWeaponActionPointCost();
    
    if (theWeaponType=="Gun")
    {
        finalDamage = baseDamage + baseDamage*(attackingIntelligentEntity.getGuns()/100.0);
    }
    else if(theWeaponType == "Melee")
    {
        finalDamage = baseDamage + baseDamage*(attackingIntelligentEntity.getMeleeWeapons()/100.0);
    }
    else if(theWeaponType == "Energy")
    {
        finalDamage = baseDamage + baseDamage*(attackingIntelligentEntity.getEnergyWeapons()/100.0);
    }
    else if(theWeaponType == "Explosive")
    {
        finalDamage = baseDamage + baseDamage*(attackingIntelligentEntity.getExplosives()/100.0);
    }
    else
    {
        finalDamage = baseDamage + baseDamage*(attackingIntelligentEntity.getUnarmed()/100.0);
    }
    
    finalDamage -= defend(defendingIntelligentEntity);
    
    if (finalDamage<=0)
    {
        finalDamage=1;
    }
    
    defendingIntelligentEntity.actualHealth-=finalDamage;
    
        int inventoryCount = 0;
        while (weaponsRoundCost>0)
        {
            //cout<<"gets to the while loop\n";
            if (attackingIntelligentEntity.getInventory()[inventoryCount]->getItemType()=="Ammo")
            {
                if ((dynamic_cast<Ammo*>(attackingIntelligentEntity.getInventory()[inventoryCount]))->getRoundType()==weaponInUse->getWeaponRoundType())
                {
                    //cout<<"Finds the round\n";
                    attackingIntelligentEntity.removeFromInventory(inventoryCount);
                    weaponsRoundCost--;
                }
            }
            inventoryCount++;
        }
    }
}

void heal(IntelligentEntity& healer, IntelligentEntity& recipient, const int& aidCoordinate, int& apCost)
{
    int baseHeal;
    int finalHeal;
    //int attackingWeapon;
    
    //attackingWeapon = getSubInventory(attackingIntelligentEntity, "Weapon");
    
    if((apCost - dynamic_cast<Aid*>(healer.getInventory()[aidCoordinate])->getAidActionPointCost()) < 0)
    {
        cout<<"Not enough action points to use this item\n";
        return;
    }
    
    baseHeal = dynamic_cast<Aid*>(healer.getInventory()[aidCoordinate])->getAidEffect();
    
    string theAidType = dynamic_cast<Aid*>(healer.getInventory()[aidCoordinate])->getAidType();
    
    apCost -= dynamic_cast<Aid*>(healer.getInventory()[aidCoordinate])->getAidActionPointCost();
    
    if (theAidType=="Food")
    {
        finalHeal = baseHeal + baseHeal*(healer.getSurvival()/100.0);
    }
    else
    {
        finalHeal = baseHeal + baseHeal*(healer.getMedicine()/100.0);
    }
    
    recipient.actualHealth+=finalHeal;
    
    if (recipient.actualHealth>recipient.getHealth())
    {
        recipient.actualHealth=recipient.getHealth();
    }
    
    healer.removeFromInventory(aidCoordinate);//this doesn't work
}

void target(const vector<IntelligentEntity*>& targets, int& targetCoordinate)
{
    cout<<"Select target:\n";
    cout<<"0. Back"<<endl;
    for (int targetCount = 0; targetCount < targets.size(); targetCount++)
    {
        cout<<targetCount+1<<". "<<*targets[targetCount]<<endl;
    }
    cin>>targetCoordinate;
    targetCoordinate--;
}

void takeTurn(IntelligentEntity& movingEntity, vector<IntelligentEntity*>& enemyIntelligentEntitySquad, vector<IntelligentEntity*>& friendlyIntelligentEntitySquad)
{
    int currentEntityActionPoints = movingEntity.getActionPoints();
    int decision;
    int entityCoordinate;
    
    while (currentEntityActionPoints>0)
    {
    back1:
        cout<<"Choose move:AP remaining: "<<currentEntityActionPoints<<"\n0. End turn\n1. Attack enemy\n2. Aid teammate\n";
        cin>>decision;
        
        if (decision==0)
        {
            currentEntityActionPoints=0;
        }
        else if(decision==1)
        {
        back2:
            target(enemyIntelligentEntitySquad, decision);
            if (decision==-1)
            {
                goto back1;
            }
            else
            {
                entityCoordinate = decision;
                decision = getSubInventory(movingEntity, "Weapon");
                if (decision==-1)
                {
                    goto back2;
                }
                else
                {
                    attack(movingEntity, *enemyIntelligentEntitySquad[entityCoordinate], decision, currentEntityActionPoints);
                
                    if (enemyIntelligentEntitySquad[entityCoordinate]->actualHealth<=0)
                    {
                        //Add XP of deceased either directly to player character or a "pot"
                        //Same with inventory
                        enemyIntelligentEntitySquad.erase(enemyIntelligentEntitySquad.begin()+entityCoordinate);//Remove entity from vector
                    }
                }
            }
        }
        else if(decision==2)//Heal
        {
        back3:
            target(friendlyIntelligentEntitySquad, decision);
            if (decision==-1)
            {
                goto back1;
            }
            else
            {
                entityCoordinate = decision;
                decision = getSubInventory(movingEntity, "Aid");
                if (decision==-1)
                {
                    goto back3;
                }
                else
                {
                    heal(movingEntity, *friendlyIntelligentEntitySquad[entityCoordinate], decision, currentEntityActionPoints);
                    
                    if (friendlyIntelligentEntitySquad[entityCoordinate]->actualHealth>friendlyIntelligentEntitySquad[entityCoordinate]->getHealth())
                    {
                        friendlyIntelligentEntitySquad[entityCoordinate]->actualHealth = friendlyIntelligentEntitySquad[entityCoordinate]->getHealth();
                    }
                }
            }            
            
        }
    }
}

void battle(vector<IntelligentEntity*>& playerCharacterTeam, vector<IntelligentEntity*>& enemyTeam)
{
    int xpPot = 0;
    int capsPot = 0;
    vector<Item*> spoils;
    
    for (int i=0; i<enemyTeam.size(); i++)
    {
        xpPot += enemyTeam[i]->getXP();
        capsPot += enemyTeam[i]->getCaps();
    }
    
    while ((playerCharacterTeam.size()!=0) && (enemyTeam.size()!=0))
    {
        for (int teamList = 0; teamList<playerCharacterTeam.size(); teamList++)
        {
            takeTurn(*playerCharacterTeam[teamList], enemyTeam, playerCharacterTeam);
        }
        for (int teamList = 0; teamList<enemyTeam.size(); teamList++)
        {
            takeTurn(*enemyTeam[teamList], playerCharacterTeam, enemyTeam);
        }        
    }
    /*
    if (enemyTeam.size()==0)
    {
        playerCharacterTeam[0]
    }
     */
}
/*
#ifndef FalloutPennState_FunctionLibrary_h
#define FalloutPennState_FunctionLibrary_h



#endif
*/