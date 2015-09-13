//
//  EnterNameWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 7/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_EnterNameWindow_h
#define FalloutPennState_EnterNameWindow_h

#pragma once

#include "GenericWindow.h"
#include "GameSubWindow.h"
#include "TextBox.h"
#include "InputWindow.h"

class EnterNameWindow : public GameSubWindow
{
protected:
    
    //prompt for name
    TextBox prompt;
    
    //place to enter name
    InputWindow playerName;
    
    //checks to see whether the name has been entered or not
    bool nameEntered;
    
public:
    
    //Default Constructor
    EnterNameWindow();
    
    //Default Destructor
    ~EnterNameWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
