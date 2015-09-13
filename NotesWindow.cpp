//
//  NotesWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/5/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "NotesWindow.h"

NotesWindow::NotesWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 745; //554
    activeRectDimensions.y = 710; //710
    activeRectDimensions.w = 110; //135
    activeRectDimensions.h = 45; //50
    
    activeRectCoordinates.x = 759; //572
    activeRectCoordinates.y = 567; //565
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

NotesWindow::~NotesWindow()
{
    
}

void NotesWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    
}

void NotesWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
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

void NotesWindow::deactivateWindow()
{
    
}