//
//  EnterSPECIALWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 7/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_EnterSPECIALWindow_h
#define FalloutPennState_EnterSPECIALWindow_h

#pragma once

#include "GameSubWindow.h"
#include "TextBox.h"

class EnterSPECIALWindow : public GameSubWindow
{
protected:
    
    //TextBox SPECIALS[7];
    vector<TextBox> SPECIALS;
    vector<int> SPECIALValues;
    TextBox SPECIALValueGraphics[7];
    
    int SPECIALPointsRemaining;
    
public:
    
    //Default Constructor
    EnterSPECIALWindow();
    
    //Default Destructor
    ~EnterSPECIALWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();
    
};

#endif
