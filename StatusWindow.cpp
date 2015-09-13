//
//  StatusWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "StatusWindow.h"

StatusWindow::StatusWindow()
{
    isActive = true;
    
    activeRectDimensions.x = 80; //70
    activeRectDimensions.y = 670; //670
    activeRectDimensions.w = 132; //142
    activeRectDimensions.h = 45; //45
    
    activeRectCoordinates.x = 92; //85
    activeRectCoordinates.y = 565; //562
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

StatusWindow::~StatusWindow()
{
    
}

void StatusWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    
}

void StatusWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
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

void StatusWindow::deactivateWindow()
{
    
}