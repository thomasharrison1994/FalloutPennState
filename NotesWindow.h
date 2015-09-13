//
//  NotesWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 7/5/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_NotesWindow_h
#define MenuEfficient_NotesWindow_h

#pragma once

#include "DataSubWindow.h"

class NotesWindow : public DataSubWindow
{
protected:
    
public:
    
    //Default Constructor
    NotesWindow();
    
    //Default Destructor
    ~NotesWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
