//
//  SkillsWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_SkillsWindow_h
#define MenuEfficient_SkillsWindow_h

#pragma once

#include "StatsSubWindow.h"
#include "TextBox.h"


class SkillsWindow : public StatsSubWindow
{
protected:
    
    vector<TextBox> Skills;
    TextBox theScholarSkills[13];    
    
    int scrollTop;
    int scrollBottom;
    
public:
    
    //Default Constructor
    SkillsWindow();
    
    //Default Destructor
    ~SkillsWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
