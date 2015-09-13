//
//  ExploreWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 8/11/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_ExploreWindow_h
#define FalloutPennState_ExploreWindow_h

#pragma once

#define SPEAK_WITH 0
#define INTERACT_WITH 1
#define BARTER_WITH 2
#define SCAVENGE 3
#define ATTACK 4
#define EXIT_TO 5

#include "GameSubWindow.h"
#include "TextBox.h"
#include "Location.h"
#include "Container.h"
#include "IntelligentEntity.h"

class ExploreWindow : public GameSubWindow
{
protected:
    
    //Textbox containing the options of what one can do
    TextBox options[6];
    
    //Textbox containing yes or no
    TextBox yesNo[2];
    
    //The current main location of the player, draw sublocations, entities, and containers via this location
    Location currentLocation;
    
    //The list of sublocations in the currently active location
    vector<SubLocation*> currentSubLocations;
    
    //The list of intelligent entities in the currently active sublocation
    vector<IntelligentEntity*> currentIntelligentEntities;
    
    //The list of contianers in the currently active sublocation
    vector<Container*> currentContainers;
    
    //Dimensions for the main menu rectangle
    SDL_Rect mainMenuRectDimensions;
    
    //Coordinates for the main menu rectangle
    SDL_Rect mainMenuRectCoordinates;
    
    //Dimensions for the sub menu rectangle
    SDL_Rect subMenuRectDimensions;
    
    //Coordinates for the sub menu rectangle
    SDL_Rect subMenuRectCoordinates;
    
    //Scroll control
    int scrollTop;
    int scrollBottom;
    
    //Further control in regards to the textbox
    int minListLength;
    
public:
    
    //Default Constructor
    ExploreWindow();
    
    //Default Destructor
    ~ExploreWindow();
    
    //Function that sets the currentLocation with the active world location for operation upon
    void setCurrentLocation(Location worldLocation);
    
    //Function to set the list of sublocations
    void setSubLocations();
    
    //Function to set the list of intelligent entities
    void setEntities();
    
    //Function to set the list of containers
    void setContainers();
    
    //Function to reset the location through reference
    void resetCurrentLocation(Location& worldLocation);
    
    //Function to reset the location through return value
    Location resetCurrentLocation();
    
    //Function to reset the list of sublocations
    void resetSubLocations();
    
    //Function to reset the list of intelligent entities
    void resetEntities();
    
    //Function to reset the list of containers
    void resetContainers();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();
    
};

#endif
