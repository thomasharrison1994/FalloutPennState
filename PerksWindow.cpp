//
//  PerksWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "PerksWindow.h"

PerksWindow::PerksWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 700; //700
    activeRectDimensions.y = 670; //670
    activeRectDimensions.w = 111; //111
    activeRectDimensions.h = 45; //45
    
    activeRectCoordinates.x = 774; //774
    activeRectCoordinates.y = 566; //566
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

PerksWindow::~PerksWindow()
{
    
}

void PerksWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    
}

void PerksWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    SDL_BlitSurface(imageWell, &activeRectDimensions, screen, &activeRectCoordinates);
    
    /*
     for (int i = 0; i < 3; i++)
     {
     //SDL_BlitSurface(imageWell, &statRectDimensions, screen, &statRectCoordinates[i]);
     //SDL_BlitSurface(imageWell, &statRectDataTypeDimensions[i], screen, &statRectDataTypeCoordinates[i]);
     }
     */
    //SDL_BlitSurface(imageWell, &descriptionLineDimensions, screen, &descriptionLineCoordinates);
    
    
    
}

void PerksWindow::deactivateWindow()
{
    
}