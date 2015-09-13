//
//  StatsWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/24/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_StatsWindow_h
#define MenuEfficient_StatsWindow_h

#pragma once

#include "MasterButtonWindow.h"
#include "StatusWindow.h"
#include "SPECIALWindow.h"
#include "SkillsWindow.h"
#include "PerksWindow.h"
#include "GeneralWindow.h"

class StatsWindow : public MasterButtonWindow
{
private:
    
    int navSubWindows;
    
    //String that goes into the information feed
    //string informationFeedString;
    
    //Test data
    SDL_Rect buttonRect;
    SDL_Rect buttonCoordinates;
    SDL_Rect mainScreen;    
    SDL_Rect mainScreenCoordinates;
    /*
    int level;
    int HP;
    int totalHP;
    int AP;
    int totalAP;
    int XP;
    int XPTilNextLevel;
    */
    //TextBox statValues[7];
    TextBox statValues[4];
    
    string healthRatio;
    string actionPointRatio;
    string XPRatio;
    
public:
    
    //Constructor for the StatsWindow button
    StatsWindow();
    
    //Destructor for the StatsWindow button
    ~StatsWindow();
    
    //Overloaded manageEvent
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    virtual void deactivateWindow();
};

#endif
