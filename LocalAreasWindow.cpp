//
//  LocalAreasWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/3/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LocalAreasWindow.h"

LocalAreasWindow::LocalAreasWindow()
{
    isActive = true;
    
    activeRectDimensions.x = 70; //80
    activeRectDimensions.y = 710; //790
    activeRectDimensions.w = 222; //160
    activeRectDimensions.h = 45; //45
    
    activeRectCoordinates.x = 85; //84
    activeRectCoordinates.y = 562; //564
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

LocalAreasWindow::~LocalAreasWindow()
{
    
}

void LocalAreasWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    
}

void LocalAreasWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
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

void LocalAreasWindow::deactivateWindow()
{
    
}