//
//  QuestsWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/4/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "QuestsWindow.h"

QuestsWindow::QuestsWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 554; //70
    activeRectDimensions.y = 710; //710
    activeRectDimensions.w = 135; //190
    activeRectDimensions.h = 50; //45
    
    activeRectCoordinates.x = 572; //341
    activeRectCoordinates.y = 565; //562
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

QuestsWindow::~QuestsWindow()
{
    
}

void QuestsWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    
}

void QuestsWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
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

void QuestsWindow::deactivateWindow()
{
    
}