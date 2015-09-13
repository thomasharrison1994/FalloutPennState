//
//  DataSubWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 7/3/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_DataSubWindow_h
#define MenuEfficient_DataSubWindow_h

#pragma once

#include "GenericWindow.h"

class DataSubWindow : public GenericWindow
{
protected:
    
    //Main source of images
    SDL_Surface* imageWell;
    SDL_Surface* rectangles;
    
    //Currently active indicators
    SDL_Rect activeRectDimensions;
    SDL_Rect activeRectCoordinates;
    
    //Highlighting rectangle
    SDL_Rect rectangleDimensions;
    SDL_Rect rectangleCoordinates;
    
    //Selected square
    SDL_Rect squareDimensions;
    SDL_Rect squareCoordinates;
    
public:
    
    //Default function
    DataSubWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar) = 0;
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar) = 0;
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow() = 0;    
};

#endif
