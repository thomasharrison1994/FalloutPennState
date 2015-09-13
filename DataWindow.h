//
//  DataWindow.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/25/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_DataWindow_h
#define MenuEfficient_DataWindow_h

#pragma once

#include "MasterButtonWindow.h"
#include "LocalAreasWindow.h"
#include "WorldMapWindow.h"
#include "QuestsWindow.h"
#include "NotesWindow.h"
#include "RadioWindow.h"

class DataWindow : public MasterButtonWindow
{
private:
    
    int navSubWindows;
    
    //String that goes into the information feed
    //string informationFeedString;
    
    //Test data
    SDL_Rect buttonRect;
    SDL_Rect buttonCoordinates;
    SDL_Rect mainScreen;    
    SDL_Rect mainScreenCoordinates;    
    
public:
    
    //Constructor for the DataWindow button
    DataWindow();
    
    //Destructor for the DataWindow button
    ~DataWindow();
    
    //Overloaded manageEvent
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    virtual void deactivateWindow();
};

#endif
