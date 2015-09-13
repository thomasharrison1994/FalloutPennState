//
//  RadioWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 7/1/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_RadioWindow_h
#define MenuEfficient_RadioWindow_h

#pragma once

#include "DataSubWindow.h"
#include "Radio.h"
#include "TextBox.h"

class RadioWindow : public DataSubWindow
{
protected:
    
    Radio myRadio;
    
    vector<TextBox> onOff;
    
    bool isOn;
    
public:
    
    //Default Constructor
    RadioWindow();
    
    //Default Destructor
    ~RadioWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();
    
    void playStation();
};

#endif
