//
//  GameSubWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 7/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_GameSubWindow_h
#define FalloutPennState_GameSubWindow_h

#pragma once

#include "GenericWindow.h"
#include "TextBox.h"

enum gameWindowIdentity {ENTER_NAME, ENTER_SPECIAL, ENTER_TAG_SKILLS, GO_BACK, NAVIGATION, COMBAT, STORAGE, BARTER, EXPLORE};

class GameSubWindow : public GenericWindow
{
protected:
    
    //it's own identity
    gameWindowIdentity selfIdentity;
    
    //Identity of the next window
    gameWindowIdentity nextIdentity;
    
    //Main source of images
    SDL_Surface* imageWell;
    SDL_Surface* rectangles;
    SDL_Surface* statRects;
    
    //Currently active indicators
    SDL_Rect activeRectDimensions;
    SDL_Rect activeRectCoordinates;
    
    //Highlighting rectangle
    SDL_Rect rectangleDimensions;
    SDL_Rect rectangleCoordinates;
    
    //Selected square
    SDL_Rect squareDimensions;
    SDL_Rect squareCoordinates;
    
    //Hollow circle
    SDL_Rect circleDimensions;
    SDL_Rect circleCoordinates;
    
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
    
    
public:
    
    //Default function
    GameSubWindow();
    
    //Default destructor
    ~GameSubWindow();
    
    gameWindowIdentity getIdentity();
    
    gameWindowIdentity getNextIdentity();
    
    void setNextIdentity(gameWindowIdentity theNextIdentity);
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar) = 0;
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar) = 0;
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow() = 0;    
};

#endif
