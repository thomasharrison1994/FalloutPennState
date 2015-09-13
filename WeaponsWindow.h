//
//  WeaponsWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/25/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_WeaponsWindow_h
#define MenuEfficient_WeaponsWindow_h

#pragma once

#include "ItemsSubWindow.h"
#include "TextBox.h"

class WeaponsWindow : public ItemsSubWindow
{
protected:
    //BEGIN TEST CODE
    vector<Weapon*> scholarWeapons;
    vector<TextBox> weaponNames;
    vector<TextBox> weaponDamages;
    
    int scrollTop;
    int scrollBottom;
    
    
    //END TEST CODE
    
public:
    
    //Default Constructor
    WeaponsWindow();
    
    //Default Destructor
    ~WeaponsWindow();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
};

#endif
