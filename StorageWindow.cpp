//
//  StorageWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 8/4/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "StorageWindow.h"

StorageWindow::StorageWindow()
{
    //isActive = true;
    //isDone = false;
    
    selfIdentity = STORAGE;
    nextIdentity = selfIdentity;
    /*
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 465;
    rectangleDimensions.h = 45;*/
    
    rectangleDimensions.x = 115;
    rectangleDimensions.y = 210;
    rectangleDimensions.w = 311; //300
    rectangleDimensions.h = 45;    
    
    /*
    //These are good for left side
    rectangleCoordinates.x = 530;
    rectangleCoordinates.y = 165;
     */
    //Good for right side
    rectangleCoordinates.x = 530; //530, 830
    rectangleCoordinates.y = 233; //213
    
    //Arrow dimensions
    arrowDimensions.x = 160; //115
    arrowDimensions.y = 260; //260
    arrowDimensions.w = 140; //200
    arrowDimensions.h = 50; //60
    
    //Arrow coordinates
    arrowCoordinates.x = 730; //840
    arrowCoordinates.y = 140; //125
    
    scrollTop[SCHOLAR] = 0;
    scrollTop[CONTAINER] = 0;
    scrollBottom[SCHOLAR] = 5;
    scrollTop[CONTAINER] = 5;
    
    onList = SCHOLAR;
}

StorageWindow::~StorageWindow()
{
    
}

void StorageWindow::setInventories(vector<Item*> player, Container theContainer)
{
    scholarItemList.clear();
    containerItemList.clear();
    
    scholarsInventory = player;
    containerInventory = theContainer.getContainerItems();
    
    listNames[SCHOLAR] = TextBox("ITEMS");
    listNames[CONTAINER] = TextBox(theContainer.getContainerName());
    
    for (int i = 0; i < scholarsInventory.size(); i++)
    {
        scholarItemList.push_back(TextBox(scholarsInventory[i]->getItemName(), 24));
    }
    
    for (int i = 0; i < containerInventory.size(); i++)
    {
        containerItemList.push_back(TextBox(containerInventory[i]->getItemName(), 24));
    }
}

void StorageWindow::setInventories(IntelligentEntity player, Container theContainer)
{
    scholarItemList.clear();
    containerItemList.clear();
    
    weightRatio = TextBox("Wg: " + toString(player.actualTotalWeight) + "/" + toString(player.getCarryWeight()), 24);
    
    scholarsInventory = player.getInventory();
    containerInventory = theContainer.getContainerItems();
    
    listNames[SCHOLAR] = TextBox(player.getName());
    listNames[CONTAINER] = TextBox(theContainer.getContainerName());
    
    for (int i = 0; i < scholarsInventory.size(); i++)
    {
        scholarItemList.push_back(TextBox(scholarsInventory[i]->getItemName(), 24));
    }
    
    for (int i = 0; i < containerInventory.size(); i++)
    {
        containerItemList.push_back(TextBox(containerInventory[i]->getItemName(), 24));
    }
}

void StorageWindow::resetInventories(IntelligentEntity &player, Container &theContainer)
{
    //player.getInventory() = scholarsInventory;
    //theContainer.getContainerItems() = containerInventory;
    
    player.setInventory(scholarsInventory);
    theContainer.setContainerItems(containerInventory);
}

void StorageWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if (event.type == SDL_KEYDOWN)
    {
        int listLength[2];
        
        int onSpace = ((rectangleCoordinates.y - 233) / 50) + scrollTop[onList];
        
        //cout<<onSpace<<endl;
        
            if (scholarItemList.size() < 5)
            {
                listLength[SCHOLAR] = ((scholarItemList.size() * 50) + 183);
            }
            else
            {
                listLength[SCHOLAR] = 433;
            }
        
            if (containerItemList.size() < 5)
            {
                listLength[CONTAINER] = ((containerItemList.size() * 50) + 183);
            }
            else
            {
                listLength[CONTAINER] = 433;
            }
        
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                
                if (rectangleCoordinates.y != 233)
                {
                    rectangleCoordinates.y -= 50;
                }
                
                else if (scrollTop[onList] != 0 && (listLength[onList] == 433))
                {
                    --scrollTop[onList];
                    --scrollBottom[onList];
                }                
                
                break;
                
            case SDLK_DOWN:
                
                int currentListLength;
                
                if (onList == SCHOLAR)
                {
                    currentListLength = scholarItemList.size();
                }
                
                if (onList == CONTAINER)
                {
                    currentListLength = containerItemList.size();
                }
                
                if (rectangleCoordinates.y != listLength[onList]) //260
                {
                    rectangleCoordinates.y += 50;
                }
                
                //NOT SUPPOSED TO BE listLength[commandPathControl] for first part of else!!!
                else if (scrollBottom[onList] != currentListLength/*13*/ && (listLength[onList] == 433))
                {
                    ++scrollTop[onList];
                    ++scrollBottom[onList];
                }                
                
                break;
                
            case SDLK_RIGHT:
                
                if (onList == SCHOLAR)
                {
                    if (containerInventory.size() != 0)
                    {
                        rectangleCoordinates.x += 300;
                        rectangleCoordinates.y = 233;
                        arrowDimensions.x -=26;
                        ++onList;
                        
                        scrollTop[onList] = 0;
                        scrollBottom[onList] = 5;
                    }
                }
                
                break;
                
            case SDLK_LEFT:
                
                if (onList == CONTAINER)
                {
                    if (scholarsInventory.size() != 0)
                    {
                        rectangleCoordinates.x -= 300;
                        rectangleCoordinates.y = 233;
                        arrowDimensions.x += 26;
                        --onList;
                        
                        scrollTop[onList] = 0;
                        scrollBottom[onList] = 5;
                    }
                }
                
                break;
                
            case SDLK_RETURN:
                
                if (onList == SCHOLAR)
                {
                    if (onSpace == scholarsInventory.size() - 1 && scholarsInventory.size() <= 5)
                    {
                        rectangleCoordinates.y -= 50;
                    }
                    else if (scholarsInventory.size() > 5 && scrollTop[onList] > 0)
                    {
                        --scrollTop[onList];
                        --scrollBottom[onList];
                    }
                    
                    containerInventory.push_back(scholarsInventory[onSpace]);
                    scholarsInventory.erase(scholarsInventory.begin() + onSpace);
                    
                    //Precaution for when the inventory is empty
                    if (scholarsInventory.size() == 0)
                    {
                        rectangleCoordinates.x += 300;
                        rectangleCoordinates.y = 233;
                        arrowDimensions.x -=26;
                        ++onList;
                        
                        scrollTop[onList] = 0;
                        scrollBottom[onList] = 5;
                    }
                }
                else if (onList == CONTAINER)
                {
                    if (onSpace == containerInventory.size() - 1 && containerInventory.size() <= 5)
                    {
                        rectangleCoordinates.y -= 50;
                    }
                    else if (containerInventory.size() > 5 && scrollTop[onList] > 0)
                    {
                        --scrollTop[onList];
                        --scrollBottom[onList];
                    }
                    
                    scholarsInventory.push_back(containerInventory[onSpace]);
                    containerInventory.erase(containerInventory.begin() + onSpace);
                    
                    //Precaution for when the inventory is empty
                    if (containerInventory.size() == 0)
                    {
                        rectangleCoordinates.x -= 300;
                        rectangleCoordinates.y = 233;
                        arrowDimensions.x += 26;
                        --onList;
                        
                        scrollTop[onList] = 0;
                        scrollBottom[onList] = 5;
                    }
                }
                
                cout<<scrollTop[onList]<<endl;
                cout<<scrollBottom[onList]<<endl;
                cout<<endl;
                
                break;
                
            default:
                
                break;
        }
    }
}

void StorageWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    int onSpace = ((rectangleCoordinates.y - 233) / 50) + scrollTop[onList];
    
    string type = "Other";
    
    if (onList == SCHOLAR)
    {
        val = toString(scholarsInventory[onSpace]->getItemValue());
        weight = toString(scholarsInventory[onSpace]->getItemWeight());
        
        if (scholarsInventory[onSpace]->getItemType() == "Weapon")
        {
            eitherDRorDAM = toString(dynamic_cast<Weapon*>(scholarsInventory[onSpace])->getWeaponDamage());
            type = "Weapon";
        }
        else if (scholarsInventory[onSpace]->getItemType() == "Armor")
        {
            eitherDRorDAM = toString(dynamic_cast<Armor*>(scholarsInventory[onSpace])->getArmorDamageResistance());
            type = "Armor";
        }
    }
    else if (onList == CONTAINER)
    {
        val = toString(containerInventory[onSpace]->getItemValue());
        weight = toString(containerInventory[onSpace]->getItemWeight());
        
        if (containerInventory[onSpace]->getItemType() == "Weapon")
        {
            eitherDRorDAM = toString(dynamic_cast<Weapon*>(containerInventory[onSpace])->getWeaponDamage());
            type = "Weapon";
        }
        else if (containerInventory[onSpace]->getItemType() == "Armor")
        {
            eitherDRorDAM = toString(dynamic_cast<Armor*>(containerInventory[onSpace])->getArmorDamageResistance());
            type = "Armor";
        }
    }
        
    
    weightRatio.applyTextBox(screen, 540, 115); //540, 115
    
    listNames[SCHOLAR].applyTextBox(screen, 540, 190); //170
    listNames[CONTAINER].applyTextBox(screen, 845, 190); //840, 170
    
    if (scholarItemList.size() != 0)
    {
        if (scholarItemList.size() > 5)
        {
            for (int i = scrollTop[SCHOLAR]; i < scrollBottom[SCHOLAR]; i++)
            {
                scholarItemList[i].applyTextBox(screen, 540, 240, 0, 50, (i-scrollTop[SCHOLAR])); //220, 170
            }
        }
        else
        {
            for (int i = 0; i < scholarItemList.size(); i++)
            {
                scholarItemList[i].applyTextBox(screen, 540, 240, 0, 50, i); //220, 170
            }
        }
    }
    
    if (containerItemList.size() != 0)
    {
        if (containerItemList.size() > 5)
        {
            for (int i = scrollTop[CONTAINER]; i < scrollBottom[CONTAINER]; i++)
            {
                containerItemList[i].applyTextBox(screen, 845, 240, 0, 50, (i-scrollTop[CONTAINER])); //840, 170
            }
        }
        else
        {
            for (int i = 0; i < containerItemList.size(); i++)
            {
                containerItemList[i].applyTextBox(screen, 845, 240, 0, 50, i); //840, 170
            }
        }
    }
    /*
    if (containerItemList.size() != 0)
    {
        for (int i = 0; i < containerItemList.size(); i++)
        {
            containerItemList[i].applyTextBox(screen, 840, 170, 0, 50, i);
        }
    }
     */
    
    /*
     0 = VAL
     1 = WG
     2 = DR
     3 = DAM
     */
    
    SDL_BlitSurface(statRects, &statRectDimensions, screen, &statRectCoordinates[VAL]);
    SDL_BlitSurface(statRects, &statRectDataTypeDimensions[VAL], screen, &statRectDataTypeCoordinates[VAL]);
    val.applyTextBox(screen, 1015, 485);
    
    SDL_BlitSurface(statRects, &statRectDimensions, screen, &statRectCoordinates[WG]);
    SDL_BlitSurface(statRects, &statRectDataTypeDimensions[WG], screen, &statRectDataTypeCoordinates[WG]);
    weight.applyTextBox(screen, 880, 485);
    
    if (type == "Armor")
    {
        SDL_BlitSurface(statRects, &statRectDimensions, screen, &statRectCoordinates[DR]);
        SDL_BlitSurface(statRects, &statRectDataTypeDimensions[DR], screen, &statRectDataTypeCoordinates[DR]);
        eitherDRorDAM.applyTextBox(screen, 680, 485);
    }
    else if (type == "Weapon")
    {
        SDL_BlitSurface(statRects, &statRectDimensions, screen, &statRectCoordinates[DAM]);
        SDL_BlitSurface(statRects, &statRectDataTypeDimensions[DAM], screen, &statRectDataTypeCoordinates[DAM]);
        eitherDRorDAM.applyTextBox(screen, 680, 485);
    }
    
    /*
    for (int i = 0; i < 3; i++) //3
    {
        if (i == 2) //3
        {
            SDL_BlitSurface(statRects, &statRectDimensions, screen, &statRectCoordinates[i+1]);
            SDL_BlitSurface(statRects, &statRectDataTypeDimensions[i+1], screen, &statRectDataTypeCoordinates[i+1]);
        }
        else
        {
            SDL_BlitSurface(statRects, &statRectDimensions, screen, &statRectCoordinates[i]);
            SDL_BlitSurface(statRects, &statRectDataTypeDimensions[i], screen, &statRectDataTypeCoordinates[i]);
        }
    }
     */
    
    SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
    SDL_BlitSurface(rectangles, &arrowDimensions, screen, &arrowCoordinates);
}

void StorageWindow::deactivateWindow()
{
    
}