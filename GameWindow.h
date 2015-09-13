//
//  GameWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_GameWindow_h
#define MenuEfficient_GameWindow_h

#pragma once

#include "MasterButtonWindow.h"
#include "EnterNameWindow.h"
#include "EnterSPECIALWindow.h"
#include "EnterTagSkillsWindow.h"
#include "GoBackWindow.h"
#include "NavigationWindow.h"
#include "CombatWindow.h"
#include "StorageWindow.h"
#include "BarterWindow.h"
#include "ExploreWindow.h"

class GameWindow : public MasterButtonWindow
{
private:
    
    //Put one of these in GameSubWindow, have each manage event for gameSubwindow
    gameWindowIdentity nextWindow;
    
    int navSubWindows;
    
    bool* activeWindow;
    
    //String that goes into the information feed
    //string informationFeedString;
    
    //Test data
    SDL_Rect buttonRect;
    SDL_Rect buttonCoordinates;    
    SDL_Rect mainScreen;    
    SDL_Rect mainScreenCoordinates;
    
public:
    
    //Constructor for the GameWindow button
    GameWindow();
    
    //Destructor for the GameWindow Button
    ~GameWindow();
    
    void determineActiveSubWindow();
    
    gameWindowIdentity getNextWindow();
    
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    virtual void deactivateWindow();
};

#endif
