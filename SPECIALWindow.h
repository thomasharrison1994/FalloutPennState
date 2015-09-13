//
//  SPECIALWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_SPECIALWindow_h
#define MenuEfficient_SPECIALWindow_h

#pragma once

#include "StatsSubWindow.h"
#include "TextBox.h"

class SPECIALWindow : public StatsSubWindow
{
protected:
    
    //TextBox SPECIALS[7];
    vector<TextBox> SPECIALS;
    TextBox theScholarSPECIAL[7];
    
public:
    
    //Default Constructor
    SPECIALWindow();
    
    //Default Destructor
    ~SPECIALWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();
    
};

#endif
