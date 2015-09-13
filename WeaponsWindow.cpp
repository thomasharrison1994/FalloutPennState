//
//  WeaponsWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/25/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "WeaponsWindow.h"

WeaponsWindow::WeaponsWindow()
{
    isActive = true;
    
    activeRectDimensions.x = 80;
    activeRectDimensions.y = 790;
    activeRectDimensions.w = 160;
    activeRectDimensions.h = 45;
    
    activeRectCoordinates.x = 84;
    activeRectCoordinates.y = 564;
    
    //DAM box modifications
    statRectDataTypeDimensions[2].x = 475;
    statRectDataTypeDimensions[2].w = 73;
    
    scrollTop = 0;
    scrollBottom = 7;
}

WeaponsWindow::~WeaponsWindow()
{
    
}

void WeaponsWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        
        int listLength;
        
        if (weaponNames.size() <= 7)
        {
            listLength = (((weaponNames.size() + 2) * 50) -4);
        }
        else
        {
            listLength = 446;
        }        
        
        if (isActive == true)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    
                    if (rectangleCoordinates.y != 146)
                    {
                        rectangleCoordinates.y -= 50;
                    }
                    
                    else if (scrollTop != 0 && weaponNames.size() > 6)
                    {
                        --scrollTop;
                        --scrollBottom;
                    }                    
                    
                    break;
                    
                case SDLK_DOWN:
                    
                    if (rectangleCoordinates.y != listLength)
                    {
                        rectangleCoordinates.y += 50;
                    }
                    
                    else if (scrollBottom != weaponNames.size() && weaponNames.size() > 6)
                    {
                        ++scrollTop;
                        ++scrollBottom;
                    }                    
                    
                    break;
                    
                default:
                    ;
                    
                    break;
            }
        }        
    }
}

void WeaponsWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    scholarWeapons.clear();
    weaponNames.clear();
    itemValues.clear();
    itemWeights.clear();
    weaponDamages.clear();
    
    for (int i = 0; i < theScholar.getInventory().size(); i++)
    {
        if (theScholar.getInventory()[i]->getItemType() == "Weapon")
        {
            scholarWeapons.push_back(dynamic_cast<Weapon*>(theScholar.getInventory()[i]));
        }
    }
    
    for (int i = 0; i < scholarWeapons.size(); i++)
    {
        weaponNames.push_back(TextBox(scholarWeapons[i]->getWeaponName()));
        itemValues.push_back(TextBox(toString(scholarWeapons[i]->getItemValue())));
        itemWeights.push_back(TextBox(toString(scholarWeapons[i]->getItemWeight())));
        weaponDamages.push_back(TextBox(toString(scholarWeapons[i]->getWeaponDamage())));
    }
    
    //Blit loop, modify with scroll regulators
    
    if (weaponNames.size() > 6)
    {
        for (int i = scrollTop; i < scrollBottom; i++)
        {
            weaponNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
            //theScholarSkills[i].applyTextBox(screen, 400, 150, 0, 50, (i - scrollTop));
        }
    }
    else if(weaponNames.size() != 0)
    {
        for (int i = 0; i < weaponNames.size(); i++)
        {
            weaponNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
            //theScholarSkills[i].applyTextBox(screen, 400, 150, 0, 50, (i - scrollTop));
        }
    }
    
    SDL_BlitSurface(imageWell, &activeRectDimensions, screen, &activeRectCoordinates);
    
    for (int i = 0; i < 3; i++)
    {
        SDL_BlitSurface(imageWell, &statRectDimensions, screen, &statRectCoordinates[i]);
        SDL_BlitSurface(imageWell, &statRectDataTypeDimensions[i], screen, &statRectDataTypeCoordinates[i]);
    }
    
    SDL_BlitSurface(imageWell, &descriptionLineDimensions, screen, &descriptionLineCoordinates);
    
    if (weaponNames.size() != 0)
    {
    activeItemInQueue = ((((rectangleCoordinates.y + 4) / 50) - 3) + scrollTop);
    
    weaponDamages[activeItemInQueue].applyTextBox(screen, 670, 460);
    itemWeights[activeItemInQueue].applyTextBox(screen, 890, 460);
    itemValues[activeItemInQueue].applyTextBox(screen, 1025, 460);    
    
    SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
    }
}

void WeaponsWindow::deactivateWindow()
{
    
}