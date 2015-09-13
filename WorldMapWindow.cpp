//
//  WorldMapWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/3/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "WorldMapWindow.h"

WorldMapWindow::WorldMapWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 322; //70
    activeRectDimensions.y = 710; //710
    activeRectDimensions.w = 189; //190
    activeRectDimensions.h = 50; //45
    
    activeRectCoordinates.x = 341; //341
    activeRectCoordinates.y = 562; //452
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

WorldMapWindow::~WorldMapWindow()
{
    
}

void WorldMapWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    
}

void WorldMapWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
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

void WorldMapWindow::deactivateWindow()
{
    
}