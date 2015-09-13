//
//  ApparelWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/26/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ApparelWindow.h"

ApparelWindow::ApparelWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 250;
    activeRectDimensions.y = 790;
    activeRectDimensions.w = 160;
    activeRectDimensions.h = 45;
    
    activeRectCoordinates.x = 282;
    activeRectCoordinates.y = 565;
    
    scrollTop = 0;
    scrollBottom = 7;    
    
}

ApparelWindow::~ApparelWindow()
{
    
}

void ApparelWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        
        int listLength;
        
        if (armorNames.size() <= 7)
        {
            listLength = (((armorNames.size() + 2) * 50) -4);
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
                    
                    else if (scrollTop != 0 && armorNames.size() > 6)
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
                    
                    else if (scrollBottom != armorNames.size() && armorNames.size() > 6)
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

void ApparelWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    scholarArmors.clear();
    armorNames.clear();
    itemValues.clear();
    itemWeights.clear();
    armorDamageResistances.clear();
    
    for (int i = 0; i < theScholar.getInventory().size(); i++)
    {
        if (theScholar.getInventory()[i]->getItemType() == "Armor")
        {
            scholarArmors.push_back(dynamic_cast<Armor*>(theScholar.getInventory()[i]));
        }
    }
    
    for (int i = 0; i < scholarArmors.size(); i++)
    {
        armorNames.push_back(TextBox(scholarArmors[i]->getArmorName()));
        itemValues.push_back(TextBox(toString(scholarArmors[i]->getItemValue())));
        itemWeights.push_back(TextBox(toString(scholarArmors[i]->getItemWeight())));
        armorDamageResistances.push_back(TextBox(toString(scholarArmors[i]->getArmorDamageResistance())));
    }
    
    //Blit loop, modify with scroll regulators
    
    if (armorNames.size() > 6)
    {
        for (int i = scrollTop; i < scrollBottom; i++)
        {
            armorNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
            //theScholarSkills[i].applyTextBox(screen, 400, 150, 0, 50, (i - scrollTop));
        }
    }
    else if(armorNames.size() != 0)
    {
        for (int i = 0; i < armorNames.size(); i++)
        {
            armorNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
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
    
    if (armorNames.size() != 0)
    {
    activeItemInQueue = ((((rectangleCoordinates.y + 4) / 50) - 3) + scrollTop);
    
    armorDamageResistances[activeItemInQueue].applyTextBox(screen, 670, 460);
    itemWeights[activeItemInQueue].applyTextBox(screen, 890, 460);
    itemValues[activeItemInQueue].applyTextBox(screen, 1025, 460);    
    
    SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates); 
    }
}

void ApparelWindow::deactivateWindow()
{
    
}