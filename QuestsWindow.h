//
//  QuestsWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 7/4/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_QuestsWindow_h
#define MenuEfficient_QuestsWindow_h

#pragma once

#include "DataSubWindow.h"

class QuestsWindow : public DataSubWindow
{
protected:
    
public:
    
    //Default Constructor
    QuestsWindow();
    
    //Default Destructor
    ~QuestsWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
