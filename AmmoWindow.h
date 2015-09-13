//
//  AmmoWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_AmmoWindow_h
#define MenuEfficient_AmmoWindow_h

#pragma once

#include "ItemsSubWindow.h"

class AmmoWindow : public ItemsSubWindow
{
protected:
    
    vector<Ammo*> scholarAmmo;
    vector<TextBox> ammoNames;    
    
    int scrollTop;
    int scrollBottom;
    
public:
    
    //Default Constructor
    AmmoWindow();
    
    //Default Destructor
    ~AmmoWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
