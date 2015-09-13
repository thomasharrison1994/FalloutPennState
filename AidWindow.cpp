//
//  AidWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/26/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "AidWindow.h"

AidWindow::AidWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 430;
    activeRectDimensions.y = 790;
    activeRectDimensions.w = 82;
    activeRectDimensions.h = 45;
    
    activeRectCoordinates.x = 481;
    activeRectCoordinates.y = 567;
    
    scrollTop = 0;
    scrollBottom = 7;    
}

AidWindow::~AidWindow()
{
    
}

void AidWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        
        int listLength;
        
        if (aidNames.size() <= 7)
        {
            listLength = (((aidNames.size() + 2) * 50) -4);
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
                    
                    else if (scrollTop != 0 && aidNames.size() > 6)
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
                    
                    else if (scrollBottom != aidNames.size() && aidNames.size() > 6)
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

void AidWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    scholarAid.clear();
    aidNames.clear();
    itemValues.clear();
    itemWeights.clear();
    
    for (int i = 0; i < theScholar.getInventory().size(); i++)
    {
        if (theScholar.getInventory()[i]->getItemType() == "Aid")
        {
            scholarAid.push_back(dynamic_cast<Aid*>(theScholar.getInventory()[i]));
        }
    }
    
    for (int i = 0; i < scholarAid.size(); i++)
    {
        aidNames.push_back(TextBox(scholarAid[i]->getAidName()));
        itemValues.push_back(TextBox(toString(scholarAid[i]->getItemValue())));
        itemWeights.push_back(TextBox(toString(scholarAid[i]->getItemWeight())));
    }
    
    //Blit loop, modify with scroll regulators
    
    if (aidNames.size() > 6)
    {
        for (int i = scrollTop; i < scrollBottom; i++)
        {
            aidNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
            //theScholarSkills[i].applyTextBox(screen, 400, 150, 0, 50, (i - scrollTop));
        }
    }
    else if(aidNames.size() != 0)
    {
        for (int i = 0; i < aidNames.size(); i++)
        {
            aidNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
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
    
    if (aidNames.size() != 0)
    {
    activeItemInQueue = ((((rectangleCoordinates.y + 4) / 50) - 3) + scrollTop);
    
    itemWeights[activeItemInQueue].applyTextBox(screen, 890, 460);
    itemValues[activeItemInQueue].applyTextBox(screen, 1025, 460);    
    
    SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates); 
    }
}

void AidWindow::deactivateWindow()
{
    
}