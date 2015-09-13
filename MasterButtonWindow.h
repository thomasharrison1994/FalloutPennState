//
//  MasterButtonWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_MasterButtonWindow_h
#define MenuEfficient_MasterButtonWindow_h

#pragma once

#include "GenericWindow.h"

enum windowIdentity {GAME, STATS, DATA, ITEMS};

class MasterButtonWindow : public GenericWindow
{
protected:
    
    vector<GenericWindow*> subWindows;
    
    windowIdentity identity;
    
public:
    
    //Default function
    //MasterButtonWindow();
    
    int getSubWindowSize();
    
    windowIdentity getIdentity();
    
    GenericWindow* getActiveSubWindow();
    
    GenericWindow* getSubWindow(int i);
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar) = 0;
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow() = 0;    
};

#endif
