//
//  GoBackWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 7/12/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_GoBackWindow_h
#define FalloutPennState_GoBackWindow_h

#pragma once

#include "GameSubWindow.h"
#include "TextBox.h"

class GoBackWindow : public GameSubWindow
{
protected:
    
    TextBox choices[4];
    
    bool isDone;
    
    int toWhere;
    
public:
    
    //Default Constructor
    GoBackWindow();
    
    //Default Destructor
    ~GoBackWindow();
    
    //Returns isDone
    bool getIsDone();
    
    //Returns isWhere
    int getToWhere();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();
    
};

#endif
