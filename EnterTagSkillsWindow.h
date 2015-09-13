//
//  EnterTagSkillsWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 7/9/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_EnterTagSkillsWindow_h
#define FalloutPennState_EnterTagSkillsWindow_h

#pragma once

#include "GameSubWindow.h"
#include "TextBox.h"

class EnterTagSkillsWindow : public GameSubWindow
{
protected:
    
    //TextBox SPECIALS[7];
    vector<TextBox> Skills;
    //vector<int> skillValues;
    int skillValues[13];
    TextBox skillValueGraphics[13];
    bool tagSwitches[13];
    
    int tagsRemaining;
    
    int scrollTop;
    int scrollBottom;
    
    vector<SDL_Rect> tagCoordinates;
    
    bool isDone;
    
    TextBox completed;
    
    SDL_Rect completedDimensions;
    SDL_Rect completedCoordinates;
    
public:
    
    //Default Constructor
    EnterTagSkillsWindow();
    
    //Default Destructor
    ~EnterTagSkillsWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();
    
};

#endif
