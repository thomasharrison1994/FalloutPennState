//
//  ItemsSubWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/25/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_ItemsSubWindow_h
#define MenuEfficient_ItemsSubWindow_h

#pragma once

#include "GenericWindow.h"
#include "TextBox.h"

class ItemsSubWindow : public GenericWindow
{
protected:
    
    //Main source of images
    SDL_Surface* imageWell;
    SDL_Surface* rectangles;
    
    //Currently active indicators
    SDL_Rect activeRectDimensions;
    SDL_Rect activeRectCoordinates;
    
    //Small rectangle for values
    SDL_Rect statRectDimensions;
    
    //Coordinate array exclusively for the stat rect
    SDL_Rect statRectCoordinates [4];
    
    //Arrays for the stat rect data type dimensions and coordinates
    SDL_Rect statRectDataTypeDimensions[4];
    SDL_Rect statRectDataTypeCoordinates[4];
    
    //Description line
    SDL_Rect descriptionLineDimensions;
    SDL_Rect descriptionLineCoordinates;
    
    SDL_Rect rectangleDimensions;
    SDL_Rect rectangleCoordinates;
    
    vector<TextBox> itemValues;
    vector<TextBox> itemWeights;
    
    int activeItemInQueue;
    
    //Item description
    //string itemDescription;
    
    //Item weight
    //int itemWG;
    
    //Item value
    //int itemVAL;
    
public:
    
    //Default function
    ItemsSubWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar) = 0;
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar) = 0;
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow() = 0;    
};

#endif
