//
//  GeneralWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GeneralWindow.h"

GeneralWindow::GeneralWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 830; //700
    activeRectDimensions.y = 670; //670
    activeRectDimensions.w = 151; //111
    activeRectDimensions.h = 45; //45
    
    activeRectCoordinates.x = 954; //774
    activeRectCoordinates.y = 567; //566
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

GeneralWindow::~GeneralWindow()
{
    
}

void GeneralWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    
}

void GeneralWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
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

void GeneralWindow::deactivateWindow()
{
    
}