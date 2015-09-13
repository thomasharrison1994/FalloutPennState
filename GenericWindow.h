//
//  GenericWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_GenericWindow_h
#define MenuEfficient_GenericWindow_h

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"
#include "SDL_mixer/SDL_mixer.h"
#include "IntelligentEntity.h"

using namespace std;

class GenericWindow
{
protected:
    
    //Flag representing if window in question is active
    bool isActive;
    
    //Vector of image files
    vector<SDL_Surface*> graphics;
    
    //Vector of dimensions from taken image
    vector<SDL_Rect*> graphicDimensions;
    
    //Vector of position coordinates for destination surface, should correspond with other two vectors
    vector<SDL_Rect*> graphicCoordinates;
    
public:
    
    //Default constructor
    //GenericWindow();
    
    //Function to return value of isActive
    bool isIsActive();
    
    //Function to set value of isActive
    void setIsActive(bool activity);
    
    //Getter for image
    SDL_Surface* getGraphic(int vectorPosition);
    
    //Getter for image dimensions (clip)
    SDL_Rect* getDimensions(int vectorPosition);
    
    //Getter for image coordinates (position on screen)
    SDL_Rect* getCoordinates(int vectorPosition);    
    
    //Function to put a single graphic on a surface
    virtual void displayGraphic(int triVectorDesignation, SDL_Surface* destination);
    
    //Adding intelligent entity parameter
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar) = 0;
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow() = 0;
    
    //Adding intelligent entity parameter
    //Detect and handle an SDL event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar) = 0;
    
    //To string function
    
    string toString(int myInt);
};

#endif
