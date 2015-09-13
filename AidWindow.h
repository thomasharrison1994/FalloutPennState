//
//  AidWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/26/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_AidWindow_h
#define MenuEfficient_AidWindow_h

#pragma once

#include "ItemsSubWindow.h"

class AidWindow : public ItemsSubWindow
{
protected:
    
    vector<Aid*> scholarAid;
    vector<TextBox> aidNames;    
    
    int scrollTop;
    int scrollBottom;    
    
public:
    
    //Default Constructor
    AidWindow();
    
    //Default Destructor
    ~AidWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
