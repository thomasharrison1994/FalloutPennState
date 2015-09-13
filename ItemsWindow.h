//
//  ItemsWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/25/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_ItemsWindow_h
#define MenuEfficient_ItemsWindow_h

#pragma once

#include "MasterButtonWindow.h"
#include "WeaponsWindow.h"
#include "ApparelWindow.h"
#include "AidWindow.h"
#include "MiscWindow.h"
#include "AmmoWindow.h"

class ItemsWindow : public MasterButtonWindow
{
private:
    
    int navSubWindows;
    
    //Test data
    SDL_Rect buttonRect;
    SDL_Rect buttonCoordinates;    
    SDL_Rect mainScreen;    
    SDL_Rect mainScreenCoordinates;
    
    TextBox itemsValues[4];
    
    string weightRatio;
    string healthRatio;
    
public:
    
    //Constructor for the ItemsWindow button
    ItemsWindow();
    
    //Destructor for the ItemsWindow Button
    ~ItemsWindow();
    
    //Overloaded manageEvent
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    virtual void deactivateWindow();
};

#endif
