//
//  ApparelWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/26/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_ApparelWindow_h
#define MenuEfficient_ApparelWindow_h

#pragma once

#include "ItemsSubWindow.h"

class ApparelWindow : public ItemsSubWindow
{
protected:
    
    vector<Armor*> scholarArmors;
    vector<TextBox> armorNames;
    vector<TextBox> armorDamageResistances;
    
    int scrollTop;
    int scrollBottom;    
    
    
public:
    
    //Default Constructor
    ApparelWindow();
    
    //Default Destructor
    ~ApparelWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
