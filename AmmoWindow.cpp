//
//  AmmoWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "AmmoWindow.h"

AmmoWindow::AmmoWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 820;
    activeRectDimensions.y = 790;
    activeRectDimensions.w = 212;
    activeRectDimensions.h = 45;
    
    activeRectCoordinates.x = 917;
    activeRectCoordinates.y = 568;
}

AmmoWindow::~AmmoWindow()
{
    
}

void AmmoWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        
        int listLength;
        
        if (ammoNames.size() <= 7)
        {
            listLength = (((ammoNames.size() + 2) * 50) -4);
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
                    
                    else if (scrollTop != 0 && ammoNames.size() > 6)
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
                    
                    else if (scrollBottom != ammoNames.size() && ammoNames.size() > 6)
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

void AmmoWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    scholarAmmo.clear();
    ammoNames.clear();
    itemValues.clear();
    itemWeights.clear();
    
    for (int i = 0; i < theScholar.getInventory().size(); i++)
    {
        if (theScholar.getInventory()[i]->getItemType() == "Ammo")
        {
            scholarAmmo.push_back(dynamic_cast<Ammo*>(theScholar.getInventory()[i]));
        }
    }
    
    for (int i = 0; i < scholarAmmo.size(); i++)
    {
        ammoNames.push_back(TextBox(scholarAmmo[i]->getItemName()));
        itemValues.push_back(TextBox(toString(scholarAmmo[i]->getItemValue())));
        itemWeights.push_back(TextBox(toString(scholarAmmo[i]->getItemWeight())));
    }
    
    //Blit loop, modify with scroll regulators
    
    if (ammoNames.size() > 6)
    {
        for (int i = scrollTop; i < scrollBottom; i++)
        {
            ammoNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
            //theScholarSkills[i].applyTextBox(screen, 400, 150, 0, 50, (i - scrollTop));
        }
    }
    else if(ammoNames.size() != 0)
    {
        for (int i = 0; i < ammoNames.size(); i++)
        {
            ammoNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
            //theScholarSkills[i].applyTextBox(screen, 400, 150, 0, 50, (i - scrollTop));
        }
    }     
    
    SDL_BlitSurface(imageWell, &activeRectDimensions, screen, &activeRectCoordinates);
    
    for (int i = 0; i < 2; i++)
    {
        SDL_BlitSurface(imageWell, &statRectDimensions, screen, &statRectCoordinates[i]);
        SDL_BlitSurface(imageWell, &statRectDataTypeDimensions[i], screen, &statRectDataTypeCoordinates[i]);
    }
    
    SDL_BlitSurface(imageWell, &descriptionLineDimensions, screen, &descriptionLineCoordinates);
    
    if (ammoNames.size() != 0)
    {
        activeItemInQueue = ((((rectangleCoordinates.y + 4) / 50) - 3) + scrollTop);
        
        itemWeights[activeItemInQueue].applyTextBox(screen, 890, 460);
        itemValues[activeItemInQueue].applyTextBox(screen, 1025, 460);    
        
        SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
    }    
}

void AmmoWindow::deactivateWindow()
{
    
}