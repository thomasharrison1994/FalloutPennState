//
//  MiscWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "MiscWindow.h"

MiscWindow::MiscWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 525;
    activeRectDimensions.y = 790;
    activeRectDimensions.w = 271;
    activeRectDimensions.h = 45;
    
    activeRectCoordinates.x = 607;
    activeRectCoordinates.y = 566;
}

MiscWindow::~MiscWindow()
{
    
}

void MiscWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        
        int listLength;
        
        if (miscItemNames.size() <= 7)
        {
            listLength = (((miscItemNames.size() + 2) * 50) -4);
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
                    
                    else if (scrollTop != 0 && miscItemNames.size() > 6)
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
                    
                    else if (scrollBottom != miscItemNames.size() && miscItemNames.size() > 6)
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

void MiscWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    scholarMiscItems.clear();
    miscItemNames.clear();
    itemValues.clear();
    itemWeights.clear();
    
    for (int i = 0; i < theScholar.getInventory().size(); i++)
    {
        if (theScholar.getInventory()[i]->getItemType() == "MiscItem")
        {
            scholarMiscItems.push_back(dynamic_cast<MiscItem*>(theScholar.getInventory()[i]));
        }
    }
    
    for (int i = 0; i < scholarMiscItems.size(); i++)
    {
        miscItemNames.push_back(TextBox(scholarMiscItems[i]->getItemName()));
        itemValues.push_back(TextBox(toString(scholarMiscItems[i]->getItemValue())));
        itemWeights.push_back(TextBox(toString(scholarMiscItems[i]->getItemWeight())));
    }
    
    //Blit loop, modify with scroll regulators
    
    if (miscItemNames.size() > 6)
    {
        for (int i = scrollTop; i < scrollBottom; i++)
        {
            miscItemNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
            //theScholarSkills[i].applyTextBox(screen, 400, 150, 0, 50, (i - scrollTop));
        }
    }
    else if(miscItemNames.size() != 0)
    {
        for (int i = 0; i < miscItemNames.size(); i++)
        {
            miscItemNames[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
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
    
    if (miscItemNames.size() != 0)
    {
        activeItemInQueue = ((((rectangleCoordinates.y + 4) / 50) - 3) + scrollTop);
        
        itemWeights[activeItemInQueue].applyTextBox(screen, 890, 460);
        itemValues[activeItemInQueue].applyTextBox(screen, 1025, 460);    
        
        SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
    }
}

void MiscWindow::deactivateWindow()
{
    
}