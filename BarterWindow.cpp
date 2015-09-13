//
//  BarterWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 8/9/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "BarterWindow.h"

BarterWindow::BarterWindow()
{
    selfIdentity = BARTER;
    nextIdentity = selfIdentity;
    totalCaps = 0;
    
    isTradeInProgress = false;
    isTradeAccepted = false;
    isTradeConcluded = false;
    
    acceptDecline[0] = TextBox("Accept A)");
    acceptDecline[1] = TextBox("Decline D)");
}

BarterWindow::~BarterWindow()
{
    
}

void BarterWindow::setInventories(IntelligentEntity player, IntelligentEntity trader)
{
    
    calculateBuySellValue(player.getBarter());
    
    scholarItemList.clear();
    vendorItemList.clear();
    
    totalCaps = 0;
    scholarsCaps = player.getCaps();
    
    scholarCaps = TextBox("Caps " + toString(player.getCaps()), 24);
    vendorCaps = TextBox("Caps " + toString(trader.getCaps()), 24);
    
    capTotal = TextBox(toString(totalCaps) + " Caps", 24);
    
    scholarsInventory = player.getInventory();
    vendorInventory = trader.getInventory();
    
    listNames[SCHOLAR] = TextBox(player.getName());
    listNames[VENDOR] = TextBox(trader.getName());
    
    for (int i = 0; i < scholarsInventory.size(); i++)
    {
        scholarItemList.push_back(TextBox(scholarsInventory[i]->getItemName(), 24));
        scholarItemValueList.push_back(TextBox((toString(scholarsInventory[i]->getItemValue() * saleValue)), 24));
    }
    
    for (int i = 0; i < vendorInventory.size(); i++)
    {
        vendorItemList.push_back(TextBox(vendorInventory[i]->getItemName(), 24));
        vendorItemValueList.push_back(TextBox((toString(vendorInventory[i]->getItemValue() * buyValue)), 24));
    }
    
    isTradeInProgress = true;
    isTradeAccepted = false;
    isTradeConcluded = false;
    
    nextIdentity = BARTER;
}

void BarterWindow::scopeSet()
{
    scholarItemList.clear();
    vendorItemList.clear();
    
    capTotal = TextBox(toString(abs(totalCaps)) + " Caps", 24);
    
    for (int i = 0; i < scholarsInventory.size(); i++)
    {
        scholarItemList.push_back(TextBox(scholarsInventory[i]->getItemName(), 24));
        scholarItemValueList.push_back(TextBox((toString(scholarsInventory[i]->getItemValue() * saleValue)), 24));
    }
    
    for (int i = 0; i < vendorInventory.size(); i++)
    {
        vendorItemList.push_back(TextBox(vendorInventory[i]->getItemName(), 24));
        vendorItemValueList.push_back(TextBox((toString(vendorInventory[i]->getItemValue() * buyValue)), 24));
    }
}

void BarterWindow::resetInventories(IntelligentEntity& player, IntelligentEntity& trader)
{
    player.setInventory(scholarsInventory);
    trader.setInventory(vendorInventory);
    
    player.addCaps(totalCaps);
    trader.addCaps(-totalCaps);
}

void BarterWindow::confirmTrade(IntelligentEntity& player, IntelligentEntity& trader)
{
    if (isTradeAccepted == true)
    {
        resetInventories(player, trader);
        isTradeInProgress = false;
        isTradeConcluded = false;
        isTradeAccepted = false;
    }
    else
    {
        isTradeInProgress = false;
        isTradeConcluded = false;
        isTradeAccepted = false;
        nextIdentity = NAVIGATION;
    }
}

void BarterWindow::calculateBuySellValue(int playerBarterSkill)
{
    saleValue = .45 + (playerBarterSkill * .0045);
    buyValue = 1.55 - (playerBarterSkill * .0045);
}

bool BarterWindow::getIsTradeInProgress()
{
    return isTradeInProgress;
}

bool BarterWindow::getIsTradeAccepted()
{
    return isTradeAccepted;
}

bool BarterWindow::getIsTradeConcluded()
{
    return isTradeConcluded;
}

void BarterWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
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
        
        if (vendorItemList.size() < 5)
        {
            listLength[VENDOR] = ((vendorItemList.size() * 50) + 183);
        }
        else
        {
            listLength[VENDOR] = 433;
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
                
                if (onList == VENDOR)
                {
                    currentListLength = vendorItemList.size();
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
                    if (vendorInventory.size() != 0)
                    {
                        rectangleCoordinates.x += 300;
                        rectangleCoordinates.y = 233;
                        
                        ++onList;
                        
                        scrollTop[onList] = 0;
                        scrollBottom[onList] = 5;
                    }
                }
                
                break;
                
            case SDLK_LEFT:
                
                if (onList == VENDOR)
                {
                    if (scholarsInventory.size() != 0)
                    {
                        rectangleCoordinates.x -= 300;
                        rectangleCoordinates.y = 233;
                        
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
                    
                    vendorInventory.push_back(scholarsInventory[onSpace]);
                    totalCaps += (scholarsInventory[onSpace]->getItemValue() * saleValue);
                    
                    if (totalCaps > 0)
                    {
                        arrowDimensions.x = 134;
                    }
                    else
                    {
                        arrowDimensions.x = 160;
                    }
                    
                    scholarsInventory.erase(scholarsInventory.begin() + onSpace);
                    
                    //Precaution for when the inventory is empty
                    if (scholarsInventory.size() == 0)
                    {
                        rectangleCoordinates.x += 300;
                        rectangleCoordinates.y = 233;
                        //arrowDimensions.x -=26;
                        ++onList;
                        
                        scrollTop[onList] = 0;
                        scrollBottom[onList] = 5;
                    }
                }
                else if (onList == VENDOR)
                {
                    if (onSpace == vendorInventory.size() - 1 && vendorInventory.size() <= 5)
                    {
                        rectangleCoordinates.y -= 50;
                    }
                    else if (vendorInventory.size() > 5 && scrollTop[onList] > 0)
                    {
                        --scrollTop[onList];
                        --scrollBottom[onList];
                    }
                    
                    scholarsInventory.push_back(vendorInventory[onSpace]);
                    totalCaps -= (vendorInventory[onSpace]->getItemValue() * buyValue);
                    
                    if (totalCaps > 0)
                    {
                        arrowDimensions.x = 134;
                    }
                    else
                    {
                        arrowDimensions.x = 160;
                    }                    
                    
                    vendorInventory.erase(vendorInventory.begin() + onSpace);
                    
                    //Precaution for when the inventory is empty
                    if (vendorInventory.size() == 0)
                    {
                        rectangleCoordinates.x -= 300;
                        rectangleCoordinates.y = 233;
                        //arrowDimensions.x += 26;
                        --onList;
                        
                        scrollTop[onList] = 0;
                        scrollBottom[onList] = 5;
                    }
                }
                
                break;
                
            case SDLK_a:
                
                if (scholarsCaps + totalCaps >= 0)
                {
                    isTradeConcluded = true;
                    isTradeAccepted = true;
                }
                
                break;
                
            case SDLK_d:
                
                isTradeConcluded = true;
                isTradeAccepted = false;
                
                break;
                
            default:
                
                break;
        }
    }    
}

void BarterWindow::activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar)
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
    else if (onList == VENDOR)
    {
        val = toString(vendorInventory[onSpace]->getItemValue());
        weight = toString(vendorInventory[onSpace]->getItemWeight());
        
        if (vendorInventory[onSpace]->getItemType() == "Weapon")
        {
            eitherDRorDAM = toString(dynamic_cast<Weapon*>(vendorInventory[onSpace])->getWeaponDamage());
            type = "Weapon";
        }
        else if (vendorInventory[onSpace]->getItemType() == "Armor")
        {
            eitherDRorDAM = toString(dynamic_cast<Armor*>(vendorInventory[onSpace])->getArmorDamageResistance());
            type = "Armor";
        }
    }
    
    
    //weightRatio.applyTextBox(screen, 540, 115); //540, 115
    scholarCaps.applyTextBox(screen, 540, 165);
    vendorCaps.applyTextBox(screen, 880, 165);
    
    
    listNames[SCHOLAR].applyTextBox(screen, 540, 190); //170
    listNames[VENDOR].applyTextBox(screen, 845, 190); //840, 170
    
    if (scholarItemList.size() != 0)
    {
        if (scholarItemList.size() > 5)
        {
            for (int i = scrollTop[SCHOLAR]; i < scrollBottom[SCHOLAR]; i++)
            {
                scholarItemList[i].applyTextBox(screen, 540, 240, 0, 50, (i-scrollTop[SCHOLAR])); //220, 170
                scholarItemValueList[i].applyTextBox(screen, 800, 240, 0, 50, (i-scrollTop[SCHOLAR]));                
            }
        }
        else
        {
            for (int i = 0; i < scholarItemList.size(); i++)
            {
                scholarItemList[i].applyTextBox(screen, 540, 240, 0, 50, i); //220, 170
                scholarItemValueList[i].applyTextBox(screen, 800, 240, 0, 50, (i-scrollTop[SCHOLAR]));                
            }
        }
    }
    
    if (vendorItemList.size() != 0)
    {
        if (vendorItemList.size() > 5)
        {
            for (int i = scrollTop[VENDOR]; i < scrollBottom[VENDOR]; i++)
            {
                vendorItemList[i].applyTextBox(screen, 845, 240, 0, 50, (i-scrollTop[VENDOR])); //840, 170
                vendorItemValueList[i].applyTextBox(screen, 1105, 240, 0, 50, (i-scrollTop[VENDOR]));                
                
            }
        }
        else
        {
            for (int i = 0; i < vendorItemList.size(); i++)
            {
                vendorItemList[i].applyTextBox(screen, 845, 240, 0, 50, i); //840, 170
                vendorItemValueList[i].applyTextBox(screen, 1105, 240, 0, 50, (i-scrollTop[VENDOR]));                
            }
        }
    }
    /*
     if (vendorItemList.size() != 0)
     {
     for (int i = 0; i < vendorItemList.size(); i++)
     {
     vendorItemList[i].applyTextBox(screen, 840, 170, 0, 50, i);
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
    
    capTotal.applyTextBox(screen, 745, 110);
    acceptDecline[0].applyTextBox(screen, 540, 115);
    acceptDecline[1].applyTextBox(screen, 950, 115);
}

void BarterWindow::deactivateWindow()
{
    
}