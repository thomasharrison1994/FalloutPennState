//
//  WorldMapWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 7/3/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_WorldMapWindow_h
#define MenuEfficient_WorldMapWindow_h

#pragma once

#include "DataSubWindow.h"

class WorldMapWindow : public DataSubWindow
{
protected:
    
public:
    
    //Default Constructor
    WorldMapWindow();
    
    //Default Destructor
    ~WorldMapWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
