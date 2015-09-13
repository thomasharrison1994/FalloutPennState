//
//  PerksWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_PerksWindow_h
#define MenuEfficient_PerksWindow_h

#pragma once

#include "StatsSubWindow.h"

class PerksWindow : public StatsSubWindow
{
protected:
    
public:
    
    //Default Constructor
    PerksWindow();
    
    //Default Destructor
    ~PerksWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
