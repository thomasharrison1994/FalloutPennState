//
//  CombatWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 7/28/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CombatWindow.h"

CombatWindow::CombatWindow()
{
    //isActive = true;
    
    selfIdentity = COMBAT;
    nextIdentity = selfIdentity;
    
    isPlayerTurn = true;
    
    //action = ATTACK;
    /*
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 465;
    rectangleDimensions.h = 45;
    */
    
    rectangleDimensions.x = 1050; //1050
    rectangleDimensions.y = 10; //10
    rectangleDimensions.w = 210; //200
    rectangleDimensions.h = 45; //45
    
    rectangleCoordinates.x = 530; //530, good for tactics
    rectangleCoordinates.y = 160; //165
    
    rectangleCoordinates.x = 670; //670, good for items
    
    rectangleCoordinates.x = 530;
    
    selectionRectanglesDimensions[0].x = 1050;
    selectionRectanglesDimensions[0].y = 55;
    selectionRectanglesDimensions[0].w = 129;
    selectionRectanglesDimensions[0].h = 45;
    
    selectionRectanglesCoordinates[0].x = 530;
    selectionRectanglesCoordinates[0].y = 160;
    /*
     Use for targets
    selectionRectanglesDimensions[1].x = 1050;
    selectionRectanglesDimensions[1].y = 10;
    selectionRectanglesDimensions[1].w = 230;
    selectionRectanglesDimensions[1].h = 45; 
    */
    
    selectionRectanglesDimensions[1].x = 1020;
    selectionRectanglesDimensions[1].y = 110;
    selectionRectanglesDimensions[1].w = 260;
    selectionRectanglesDimensions[1].h = 45;
    
    selectionRectanglesCoordinates[1].x = 666; //670
    selectionRectanglesCoordinates[1].y = 160;
    
    selectionRectanglesDimensions[2].x = 1050;
    selectionRectanglesDimensions[2].y = 8; //10
    selectionRectanglesDimensions[2].w = 210; //210
    selectionRectanglesDimensions[2].h = 45; //45
    
    selectionRectanglesCoordinates[2].x = 930;
    selectionRectanglesCoordinates[2].y = 160; //162 
    
    choices[0] = TextBox("Attack", 24);
    choices[1] = TextBox("Use Aid", 24);
    choices[2] = TextBox("End Turn", 24);
    
    turnControl = 0;
    commandPathControl = TACTIC;
    
    for (int i = 0; i < 3; i++)
    {
        scrollTop[i] = 0;
        scrollBottom[i] = 5;
        listPlaceHolders[i] = 0;
    }
}

CombatWindow::~CombatWindow()
{
    
}

void CombatWindow::setTeams(vector<IntelligentEntity*>& player, vector<IntelligentEntity*>& enemy)
{
    cleanUp(player, enemy);
    
    scholarTeam = player;
    enemyTeam = enemy;
    
    //cleanUp();
}

void CombatWindow::takeAction()
{
    if (action == ATTACK)
    {
        attack();
        //Analyze cleanUp function, should only need to be called after an attack
        //cleanUp();
        
        if (cleanUp() == true)
        {
            endBattle();
        }
    }
    
    else if (action == AID)
    {
        heal();
    }
    
    else if (action == END_TURN)
    {
        endTurn();
    }
}

void CombatWindow::attack()
{
    int baseDamage;
    int finalDamage;
    Weapon* weaponInUse = relevantWeaponsList[listPlaceHolders[ITEM_SELECTED]];
    //cout<<"Point1\n";
    int totalAmountOfAmmo = scholarTeam[turnControl]->getTotalAmmo(weaponInUse->getWeaponRoundType());
    int weaponsRoundCost = weaponInUse->getWeaponRoundCost();
    //"Point2\n";
    //int attackingWeapon;
    
    //attackingWeapon = getSubInventory(attackingIntelligentEntity, "Weapon");
    
    if((scholarTeam[turnControl]->actualActionPoints - weaponInUse->getWeaponActionPointCost()) < 0)
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
        
        scholarTeam[turnControl]->actualActionPoints -= weaponInUse->getWeaponActionPointCost();
        
        if (theWeaponType == "Gun")
        {
            finalDamage = baseDamage + baseDamage*(scholarTeam[turnControl]->getGuns()/100.0);
        }
        else if(theWeaponType == "Melee")
        {
            finalDamage = baseDamage + baseDamage*(scholarTeam[turnControl]->getMeleeWeapons()/100.0);
        }
        else if(theWeaponType == "Energy")
        {
            finalDamage = baseDamage + baseDamage*(scholarTeam[turnControl]->getEnergyWeapons()/100.0);
        }
        else if(theWeaponType == "Explosive")
        {
            finalDamage = baseDamage + baseDamage*(scholarTeam[turnControl]->getExplosives()/100.0);
        }
        else
        {
            finalDamage = baseDamage + baseDamage*(scholarTeam[turnControl]->getUnarmed()/100.0);
        }
        
        //finalDamage -= defend(defendingIntelligentEntity);
        finalDamage -= enemyTeam[listPlaceHolders[TARGET_SELECTED]]->getDamageResistance();
        
        if (finalDamage<=0)
        {
            finalDamage=1;
        }
        
        //defendingIntelligentEntity.actualHealth-=finalDamage;
        enemyTeam[listPlaceHolders[TARGET_SELECTED]]->actualHealth -= finalDamage;
        
        int inventoryCount = 0;
        while (weaponsRoundCost>0)
        {
            //cout<<"gets to the while loop\n";
            if (scholarTeam[turnControl]->getInventory()[inventoryCount]->getItemType()=="Ammo")
            {
                //cout<<"confirms item type\n";
                
                if ((dynamic_cast<Ammo*>(scholarTeam[turnControl]->getInventory()[inventoryCount]))->getRoundType()==weaponInUse->getWeaponRoundType())
                {
                    //cout<<"Finds the round\n";
                    scholarTeam[turnControl]->removeFromInventory(inventoryCount);
                    weaponsRoundCost--;
                    --inventoryCount;
                }
            }
            inventoryCount++;
        }
    }
}

void CombatWindow::heal()
{
    int baseHeal;
    int finalHeal;
    //int attackingWeapon;
    
    //attackingWeapon = getSubInventory(attackingIntelligentEntity, "Weapon");
    
    if(scholarTeam[turnControl]->actualActionPoints - relevantAidsList[listPlaceHolders[ITEM_SELECTED]]->getAidActionPointCost() < 0)
    {
        //cout<<"Not enough action points to use this item\n";
        return;
    }
    
    baseHeal = relevantAidsList[listPlaceHolders[ITEM_SELECTED]]->getAidEffect();
    
    string theAidType = relevantAidsList[listPlaceHolders[ITEM_SELECTED]]->getAidType();
    
    scholarTeam[turnControl]->actualActionPoints -= relevantAidsList[listPlaceHolders[ITEM_SELECTED]]->getAidActionPointCost();
    
    if (theAidType=="Food")
    {
        finalHeal = baseHeal + baseHeal*(scholarTeam[turnControl]->getSurvival()/100.0);
    }
    else
    {
        finalHeal = baseHeal + baseHeal*(scholarTeam[turnControl]->getMedicine()/100.0);
    }
    
    scholarTeam[listPlaceHolders[TARGET_SELECTED]]->actualHealth+=finalHeal;
    
    if (scholarTeam[listPlaceHolders[TARGET_SELECTED]]->actualHealth > scholarTeam[listPlaceHolders[TARGET_SELECTED]]->getHealth())
    {
        scholarTeam[listPlaceHolders[TARGET_SELECTED]]->actualHealth = scholarTeam[listPlaceHolders[TARGET_SELECTED]]->getHealth();
    }
    
    //Experiment with this line
    scholarTeam[turnControl]->removeFromInvenrory(relevantAidsList[listPlaceHolders[ITEM_SELECTED]]->getItemName());    
    //healer.removeFromInventory(aidCoordinate);//this doesn't work
}

void CombatWindow::endTurn()
{
    if (selectionRectanglesCoordinates[TARGET_SELECTED].y == 210)
    {
        scholarTeam[turnControl]->actualActionPoints = 0;
        ++turnControl;
    }
    
    if (turnControl >= scholarTeam.size())
    {
        isPlayerTurn = false;
        
        for (int i = 0; i < scholarTeam.size(); i++)
        {
            scholarTeam[i]->actualActionPoints = scholarTeam[i]->getActionPoints();
        }
        
        turnControl = 0;
        
        commandPathControl = 0;
        
        for (int j = 0; j < 3; j++)
        {
            listPlaceHolders[j] = 0;
            selectionRectanglesCoordinates[j].y = 160;
            scrollTop[j] = 0;
            scrollBottom[j] = 5;
        }        
    }
}

void CombatWindow::enemyTakeAction()
{
    bool canAid = false;
    bool canAttack = false;
    
    relevantItemsList.clear();
    
    if ((isTeammateInjured() == true) &&((enemyTeam[turnControl]->getAids()).size() != 0))
    {
        //cout<<"Has Aids"<<endl;
        for (int i = 0; i < enemyTeam[turnControl]->getAids().size(); i++)
        {
            if (enemyTeam[turnControl]->getAids()[i]->getAidActionPointCost() < enemyTeam[turnControl]->actualActionPoints)
            {
                canAid = true;
            }
        }
    }
    
    if (enemyTeam[turnControl]->getWeapons().size() != 0)
    {
        for (int i = 0; i < enemyTeam[turnControl]->getWeapons().size(); i++)
        {
            if (enemyTeam[turnControl]->getWeapons()[i]->getWeaponActionPointCost() < enemyTeam[turnControl]->actualActionPoints)
            {
                canAttack = true;
            }
        }
    }
    
    if (canAid == true)
    {
        //Aid teammate (enemyHeal)
        enemyHeal();
        cout<<"Heals"<<endl;
    }
    else if (canAttack == true)
    {
        //Attack enemy (enemyAttack)
        enemyAttack();
        cout<<"Attacks"<<endl;
    }
    else
    {
        //End turn (enemyEndTurn)
        enemyEndTurn();
        cout<<"Ends turn"<<endl;
    }
    
    
}

void CombatWindow::enemyAttack()
{
    Weapon* weaponInUse;
    int weaponTarget = 0;
    
    for (int i = 0; i < enemyTeam[turnControl]->getWeapons().size(); i++)
    {
        if (enemyTeam[turnControl]->getWeapons()[i]->getWeaponActionPointCost() < enemyTeam[turnControl]->actualActionPoints)
        {
            weaponInUse = enemyTeam[turnControl]->getWeapons()[i];
        }
    }
    //Redo loop here with comparisons to action point cost and damage values to pick a better weapon
    
    for (int i = 0; i < scholarTeam.size(); i++)
    {
        if (scholarTeam[i]->actualHealth > scholarTeam[weaponTarget]->actualHealth)
        {
            weaponTarget = i;
        }
    }
    
    
    int baseDamage;
    int finalDamage;
    //Weapon* weaponInUse = relevantWeaponsList[listPlaceHolders[ITEM_SELECTED]];
    //cout<<"Point1\n";
    //int totalAmountOfAmmo = scholarTeam[turnControl]->getTotalAmmo(weaponInUse->getWeaponRoundType());
    //int weaponsRoundCost = weaponInUse->getWeaponRoundCost();
    //"Point2\n";
    //int attackingWeapon;
    
    //attackingWeapon = getSubInventory(attackingIntelligentEntity, "Weapon");
    /*
    if((scholarTeam[turnControl]->actualActionPoints - weaponInUse->getWeaponActionPointCost()) < 0)
    {
        cout<<"Not enough action points to use this item\n";
        //return;
    }
    else if ((totalAmountOfAmmo - weaponInUse->getWeaponRoundCost()) < 0)
    {
        cout<<"Not enough ammo to use this item\n";
    }
     */
    baseDamage = weaponInUse->getWeaponDamage();
        
    string theWeaponType = weaponInUse->getWeaponType();
        
    enemyTeam[turnControl]->actualActionPoints -= weaponInUse->getWeaponActionPointCost();
        
    if (theWeaponType == "Gun")
    {
        finalDamage = baseDamage + baseDamage*(enemyTeam[turnControl]->getGuns()/100.0);
    }
    else if(theWeaponType == "Melee")
    {
        finalDamage = baseDamage + baseDamage*(enemyTeam[turnControl]->getMeleeWeapons()/100.0);
    }
    else if(theWeaponType == "Energy")
    {
        finalDamage = baseDamage + baseDamage*(enemyTeam[turnControl]->getEnergyWeapons()/100.0);
    }
    else if(theWeaponType == "Explosive")
    {
        finalDamage = baseDamage + baseDamage*(enemyTeam[turnControl]->getExplosives()/100.0);
    }
    else
    {
        finalDamage = baseDamage + baseDamage*(enemyTeam[turnControl]->getUnarmed()/100.0);
    }
        
    //finalDamage -= defend(defendingIntelligentEntity);
    finalDamage -= scholarTeam[weaponTarget]->getDamageResistance();
        
    if (finalDamage<=0)
    {
        finalDamage=1;
    }
        
    //defendingIntelligentEntity.actualHealth-=finalDamage;
    scholarTeam[weaponTarget]->actualHealth -= finalDamage;
    
    /*
    int inventoryCount = 0;
    while (weaponsRoundCost>0)
    {
        //cout<<"gets to the while loop\n";
        if (scholarTeam[turnControl]->getInventory()[inventoryCount]->getItemType()=="Ammo")
        {
            //cout<<"confirms item type\n";
                
            if ((dynamic_cast<Ammo*>(scholarTeam[turnControl]->getInventory()[inventoryCount]))->getRoundType()==weaponInUse->getWeaponRoundType())
            {
                //cout<<"Finds the round\n";
                scholarTeam[turnControl]->removeFromInventory(inventoryCount);
                weaponsRoundCost--;
                --inventoryCount;
            }
        }
        inventoryCount++;
    }
     */
}

void CombatWindow::enemyHeal()
{
    Aid* aidItem;
    int aidTarget;
    
    for (int i = 0; i < enemyTeam[turnControl]->getAids().size(); i++)
    {
        if (enemyTeam[turnControl]->getAids()[i]->getAidActionPointCost() < enemyTeam[turnControl]->actualActionPoints)
        {
            aidItem = enemyTeam[turnControl]->getAids()[i];
        }
    }
    
    for (int i = enemyTeam.size() - 1; i >= 0; i--)
    {
        if (enemyTeam[i]->actualHealth < enemyTeam[i]->getHealth())
        {
            aidTarget = i;
        }
    }
    
    int baseHeal;
    int finalHeal;
    
    baseHeal = aidItem->getAidEffect();
    
    string theAidType = aidItem->getAidType();
    
    enemyTeam[turnControl]->actualActionPoints -= aidItem->getAidActionPointCost();
    
    if (theAidType=="Food")
    {
        finalHeal = baseHeal + baseHeal*(enemyTeam[turnControl]->getSurvival()/100.0);
    }
    else
    {
        finalHeal = baseHeal + baseHeal*(enemyTeam[turnControl]->getMedicine()/100.0);
    }
    
    enemyTeam[aidTarget]->actualHealth+=finalHeal;
    
    if (enemyTeam[aidTarget]->actualHealth > enemyTeam[aidTarget]->getHealth())
    {
        enemyTeam[aidTarget]->actualHealth = enemyTeam[aidTarget]->getHealth();
    }
    
    //Experiment with this line
    enemyTeam[turnControl]->removeFromInvenrory(aidItem->getItemName());
}

bool CombatWindow::isTeammateInjured()
{
    bool injuredTeammate = false;
    
    for (int i = 0; i < enemyTeam.size(); i++)
    {
        if (enemyTeam[i]->actualHealth < enemyTeam[i]->getHealth())
        {
            injuredTeammate = true;
        }
    }
    
    return injuredTeammate;
}

void CombatWindow::enemyEndTurn()
{
    ++turnControl;
    
    if (turnControl >= enemyTeam.size())
    {
        isPlayerTurn = true;
        
        for (int i = 0; i < enemyTeam.size(); i++)
        {
            enemyTeam[i]->actualActionPoints = enemyTeam[i]->getActionPoints();
        }
        
        turnControl = 0;
    }    
    
    
    /*
    if (selectionRectanglesCoordinates[TARGET_SELECTED].y == 210)
    {
        scholarTeam[turnControl]->actualActionPoints = 0;
        ++turnControl;
    }
    
    if (turnControl >= scholarTeam.size())
    {
        isPlayerTurn = false;
        
        for (int i = 0; i < scholarTeam.size(); i++)
        {
            scholarTeam[i]->actualActionPoints = scholarTeam[i]->getActionPoints();
        }
        
        turnControl = 0;
    }
     */
}

void CombatWindow::printTacticalChoices(SDL_Surface *screen)
{
    for (int i = 0; i < 3; i++)
    {
        choices[i].applyTextBox(screen, 540, 170, 0, 50, i);
    }
}

void CombatWindow::printRelevantItems(SDL_Surface *screen)
{
    itemChoiceList.clear();
    relevantWeaponsList.clear();
    relevantAidsList.clear();
    
    if (action == ATTACK)
    {
        relevantWeaponsList = scholarTeam[turnControl]->getWeapons();
        
        for (int i = 0; i < relevantWeaponsList.size(); i++)
        {
            itemChoiceList.push_back(TextBox(relevantWeaponsList[i]->getItemName(), 24));
        }
    }
    
    else if (action == AID)
    {
        relevantAidsList = scholarTeam[turnControl]->getAids();
        
        for (int i = 0; i < relevantAidsList.size(); i++)
        {
            itemChoiceList.push_back(TextBox(relevantAidsList[i]->getItemName(), 24));
        }        
    }
    
    else if (action == END_TURN)
    {
        itemChoiceList.push_back(TextBox("Are you sure?", 24));
    }
    
    if (itemChoiceList.size() > 5)
    {
        for (int i = scrollTop[ITEM_SELECTED]; i < scrollBottom[ITEM_SELECTED]; i++)
        {
            itemChoiceList[i].applyTextBox(screen, 676, 170, 0, 50, (i-scrollTop[ITEM_SELECTED]));
        }
    }
    else
    {
        for (int i = 0; i < itemChoiceList.size(); i++)
        {
            itemChoiceList[i].applyTextBox(screen, 676, 170, 0, 50, i); //730, 170, 0, 50, i
        }
    }
}

void CombatWindow::printRelevantTargets(SDL_Surface *screen)
{
    relevantTeamList.clear();
    
    if (action == ATTACK)
    {
        for (int i = 0; i < enemyTeam.size(); i++)
        {
            relevantTeamList.push_back(TextBox(enemyTeam[i]->getName(), 24));
        }
    }
    
    else if(action == AID)
    {
        for (int i = 0; i < scholarTeam.size(); i++)
        {
            relevantTeamList.push_back(TextBox(scholarTeam[i]->getName(), 24));
        }
    }
    
    else if(action == END_TURN)
    {
        relevantTeamList.push_back(TextBox("No", 24));
        relevantTeamList.push_back(TextBox("Yes", 24));
    }
    
    if (relevantTeamList.size() > 5)
    {
        for (int i = scrollTop[TARGET_SELECTED]; i < scrollBottom[TARGET_SELECTED]; i++)
        {
            relevantTeamList[i].applyTextBox(screen, 940, 170, 0, 50, (i-scrollTop[TARGET_SELECTED]));
        }
    }
    else
    {
        for (int i = 0; i < relevantTeamList.size(); i++)
        {
            relevantTeamList[i].applyTextBox(screen, 940, 170, 0, 50, i); //730, 170, 0, 50, i
        }
    }    
    /*
    for (int i = 0; i < relevantTeamList.size(); i++)
    {
        relevantTeamList[i].applyTextBox(screen, 940, 170, 0, 50, i);
    }
     */
}

bool CombatWindow::cleanUp()
{
    for (int i = 0; i < scholarTeam.size(); i++)
    {
        if (scholarTeam[i]->actualHealth <= 0)
        {
            scholarTeam.erase(scholarTeam.begin() + i);
            --i;
        }
    }
    
    for (int i = 0; i < enemyTeam.size(); i++)
    {
        if (enemyTeam[i]->actualHealth <= 0)
        {
            enemyTeam.erase(enemyTeam.begin() + i);
            //cout<<enemyTeam.size();
            
            //compensate for vector re-size
            --i;
            
            //UNSURE OF FOLLOWING FOUR LINES
            /*
            listPlaceHolders[commandPathControl] = 0;
            selectionRectanglesCoordinates[commandPathControl].y = 160;
            scrollTop[commandPathControl] = 0;
            scrollBottom[commandPathControl] = 5;
             */
            
            //TEST 2
            for (int j = 0; j < 3; j++)
            {
                listPlaceHolders[j] = 0;
                selectionRectanglesCoordinates[j].y = 160;
                scrollTop[j] = 0;
                scrollBottom[j] = 5;
            }
            
        }
    }
    
    if (enemyTeam.size() == 0)
    {
        return true;
    }
    
    else
    {
        return false;
    }
    
}

void CombatWindow::cleanUp(vector<IntelligentEntity*>& player, vector<IntelligentEntity*>& enemy)
{
    for (int i = 0; i < player.size(); i++)
    {
        if (player[i]->actualHealth <= 0)
        {
            
        }
    }
    
    for (int i = 0; i < enemy.size(); i++)
    {
        if (enemy[i]->actualHealth <= 0)
        {
            enemy.erase(enemy.begin() + i);
            //cout<<enemyTeam.size();
            
            //compensate for vector re-size
            --i;
            
            //UNSURE OF FOLLOWING FOUR LINES
            /*
             listPlaceHolders[commandPathControl] = 0;
             selectionRectanglesCoordinates[commandPathControl].y = 160;
             scrollTop[commandPathControl] = 0;
             scrollBottom[commandPathControl] = 5;
             */
            
            //TEST 2
            for (int j = 0; j < 3; j++)
            {
                listPlaceHolders[j] = 0;
                selectionRectanglesCoordinates[j].y = 160;
                scrollTop[j] = 0;
                scrollBottom[j] = 5;
            }
            
        }
    }
    
}

void CombatWindow::endBattle()
{
    nextIdentity = NAVIGATION;
}

bool CombatWindow::getIsPlayerTurn()
{
    return isPlayerTurn;
}

void CombatWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
        if (event.type == SDL_KEYDOWN)
        {
            int listLength[3];
            
            listLength[TACTIC] = 260;
            
            if (commandPathControl >= ITEM_SELECTED)
            {
                if (itemChoiceList.size() < 5)
                {
                    listLength[ITEM_SELECTED] = ((itemChoiceList.size() * 50) + 110);
                }
                else
                {
                    listLength[ITEM_SELECTED] = 360;
                }
            }
            
            if (commandPathControl >= TARGET_SELECTED)
            {
                if (relevantTeamList.size() < 5)
                {
                    listLength[TARGET_SELECTED] = ((relevantTeamList.size() * 50) + 110);
                }
                else
                {
                    listLength[TARGET_SELECTED] = 360;
                }
            }
            
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    
                    if (selectionRectanglesCoordinates[commandPathControl].y != 160)
                    {
                        selectionRectanglesCoordinates[commandPathControl].y -= 50;
                    }
                    
                    else if (scrollTop[commandPathControl] != 0 && (listLength[commandPathControl] == 360))
                    {
                        --scrollTop[commandPathControl];
                        --scrollBottom[commandPathControl];
                    }
                    
                    break;
                    
                case SDLK_DOWN:
                    
                    int currentListLength;
                    
                    switch (commandPathControl)
                {
                    case TACTIC:
                        
                        currentListLength = 3;
                        
                        break;
                        
                    case ITEM_SELECTED:
                        
                        currentListLength = itemChoiceList.size();
                        
                        break;
                        
                    case TARGET_SELECTED:
                        
                        currentListLength = relevantTeamList.size();
                        
                        break;
                        
                    default:
                        break;
                }                
                    
                    if (selectionRectanglesCoordinates[commandPathControl].y != listLength[commandPathControl]) //260
                    {
                        selectionRectanglesCoordinates[commandPathControl].y += 50;
                    }
                    
                    //NOT SUPPOSED TO BE listLength[commandPathControl] for first part of else!!!
                    else if (scrollBottom[commandPathControl] != currentListLength/*13*/ && (listLength[commandPathControl] == 360))
                    {
                        ++scrollTop[commandPathControl];
                        ++scrollBottom[commandPathControl];
                    }
                    
                    break;
                    
                case SDLK_RIGHT:
                    
                    if (commandPathControl < TARGET_SELECTED)
                    {
                        if (commandPathControl == TACTIC)
                        {
                            switch (listPlaceHolders[TACTIC])
                            {
                                case 0:
                                    
                                    action = ATTACK;
                                    
                                    break;
                                    
                                case 1:
                                    
                                    action = AID;
                                    
                                    break;
                                    
                                case 2:
                                    
                                    action = END_TURN;
                                    
                                default:
                                    break;
                            }
                        }
                        
                        ++commandPathControl;
                        
                        //TEST CODE
                        listPlaceHolders[commandPathControl] = 0;
                        selectionRectanglesCoordinates[commandPathControl].y = 160;
                        scrollTop[commandPathControl] = 0;
                        scrollBottom[commandPathControl] = 5;
                    }
                    
                    break;
                    
                case SDLK_LEFT:
                    
                    if (commandPathControl > TACTIC)
                    {
                        --commandPathControl;
                        
                        //TEST CODE
                        listPlaceHolders[commandPathControl] = 0;
                        selectionRectanglesCoordinates[commandPathControl].y = 160;
                        scrollTop[commandPathControl] = 0;
                        scrollBottom[commandPathControl] = 5;
                    }
                    
                    break;
                    
                case SDLK_RETURN:
                    
                    if (commandPathControl == TARGET_SELECTED)
                    {
                        takeAction();
                    }
                    
                    break;
                    
                default:
                    break;
            }
            
            //BEGIN TEST CODE
            
            listPlaceHolders[commandPathControl] = (((selectionRectanglesCoordinates[commandPathControl].y - 160) / 50) + scrollTop[commandPathControl]);
            
            //END TEST CODE
            
            //Analyze cleanUp function
            //cleanUp();        
        }
}

void CombatWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    nextIdentity = selfIdentity;
    
    turnTakingEntity = TextBox(scholarTeam[turnControl]->getName(), 28);
    turnTakingEntityActionPointRatio = TextBox("AP: " + toString(scholarTeam[turnControl]->actualActionPoints) + "/" + toString(scholarTeam[turnControl]->getActionPoints()), 28);
    turnTakingEntityHealthRatio = TextBox("HP: " + toString(scholarTeam[turnControl]->actualHealth) + "/" + toString(scholarTeam[turnControl]->getHealth()), 28);
    
    turnTakingEntity.applyTextBox(screen, 540, 500);
    turnTakingEntityHealthRatio.applyTextBox(screen, 770, 500);
    turnTakingEntityActionPointRatio.applyTextBox(screen, 990, 500);
    
    printTacticalChoices(screen);
    
    SDL_BlitSurface(rectangles, &selectionRectanglesDimensions[0], screen, &selectionRectanglesCoordinates[0]);
    
    if (commandPathControl > TACTIC)
    {
        printRelevantItems(screen);
        SDL_BlitSurface(rectangles, &selectionRectanglesDimensions[1], screen, &selectionRectanglesCoordinates[1]);        
    }
    
    if (commandPathControl > ITEM_SELECTED)
    {
        printRelevantTargets(screen);
        SDL_BlitSurface(rectangles, &selectionRectanglesDimensions[2], screen, &selectionRectanglesCoordinates[2]);
        
        if (action == ATTACK)
        {
            targetedEntity = TextBox(enemyTeam[listPlaceHolders[TARGET_SELECTED]]->getName(), 28);
            targetedEntityActionPointRatio = TextBox("AP: " + toString(enemyTeam[listPlaceHolders[TARGET_SELECTED]]->actualActionPoints) + "/" + toString(enemyTeam[listPlaceHolders[TARGET_SELECTED]]->getActionPoints()), 28);
            targetedEntityHealthRatio = TextBox("HP: " + toString(enemyTeam[listPlaceHolders[TARGET_SELECTED]]->actualHealth) + "/" + toString(enemyTeam[listPlaceHolders[TARGET_SELECTED]]->getHealth()), 28);
        }
        
        else if (action == AID)
        {
            targetedEntity = TextBox(scholarTeam[listPlaceHolders[TARGET_SELECTED]]->getName(), 28);
            targetedEntityActionPointRatio = TextBox("AP: " + toString(scholarTeam[listPlaceHolders[TARGET_SELECTED]]->actualActionPoints) + "/" + toString(scholarTeam[listPlaceHolders[TARGET_SELECTED]]->getActionPoints()), 28);
            targetedEntityHealthRatio = TextBox("HP: " + toString(scholarTeam[listPlaceHolders[TARGET_SELECTED]]->actualHealth) + "/" + toString(scholarTeam[listPlaceHolders[TARGET_SELECTED]]->getHealth()), 28);
        }
        
        if (action == ATTACK || action == AID)
        {
            targetedEntity.applyTextBox(screen, 540, 450);
            targetedEntityHealthRatio.applyTextBox(screen, 770, 450);
            targetedEntityActionPointRatio.applyTextBox(screen, 990, 450);
        }
    }
}

void CombatWindow::deactivateWindow()
{
    
}