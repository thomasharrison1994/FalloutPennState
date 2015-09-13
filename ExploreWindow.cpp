//
//  ExploreWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 8/11/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ExploreWindow.h"

ExploreWindow::ExploreWindow()
{
    selfIdentity = EXPLORE;
    nextIdentity = selfIdentity;
    
    options[SPEAK_WITH] = TextBox("Speak with: ", 24);
    options[INTERACT_WITH] = TextBox("Interact with: ", 24);
    options[BARTER_WITH] = TextBox("Barter with: ", 24);
    options[SCAVENGE] = TextBox("Scavenge: ", 24);
    options[ATTACK] = TextBox("Attack: ", 24);
    options[EXIT_TO] = TextBox("Exit to: ", 24);
    
    yesNo[0] = TextBox("Yes ", 24);
    yesNo[1] = TextBox("No ", 24);
    
    mainMenuRectDimensions.x = 682;
    mainMenuRectDimensions.y = 210;
    mainMenuRectDimensions.w = 205;
    mainMenuRectDimensions.h = 45;
    
    mainMenuRectCoordinates.x = 530;
    mainMenuRectCoordinates.y = 143;
    
    subMenuRectDimensions.x = 682; //115;
    subMenuRectDimensions.y = 262; //210;
    subMenuRectDimensions.w = 406; //311;
    subMenuRectDimensions.h = 45; //45;
    
    subMenuRectCoordinates.x = 735; //530
    subMenuRectCoordinates.y = 143; //143
    
    scrollTop = 0;
    scrollBottom = 6;
}

ExploreWindow::~ExploreWindow()
{
    
}

void ExploreWindow::setCurrentLocation(Location worldLocation)
{
    currentLocation = worldLocation;
    setSubLocations();
    setEntities();
    setContainers();
}

void ExploreWindow::setSubLocations()
{
    currentSubLocations = currentLocation.getAllSubLocations();
}

void ExploreWindow::setEntities()
{
    currentIntelligentEntities = currentLocation.getActiveSubLocation().getEntitiesInSubLocation();
}

void ExploreWindow::setContainers()
{
    currentContainers = currentLocation.getActiveSubLocation().getContainersInSubLocation();
}

void ExploreWindow::resetCurrentLocation(Location &worldLocation)
{
    resetContainers();
    resetEntities();
    resetSubLocations();
    worldLocation = currentLocation;
}

Location ExploreWindow::resetCurrentLocation()
{
    resetContainers();
    resetEntities();
    resetSubLocations();
    
    return currentLocation;
}

void ExploreWindow::resetSubLocations()
{
    currentLocation.setAllSubLocations(currentSubLocations);
}

void ExploreWindow::resetEntities()
{
    for (int i = 0; i < currentSubLocations.size(); i++)
    {
        if (currentSubLocations[i]->getIsActive() == true)
        {
            currentSubLocations[i]->setEntitiesInSubLocation(currentIntelligentEntities);
        }
    }
}

void ExploreWindow::resetContainers()
{
    for (int i = 0; i < currentSubLocations.size(); i++)
    {
        if (currentSubLocations[i]->getIsActive() == true)
        {
            currentSubLocations[i]->setContainersInSubLocation(currentContainers);
        }
    }
}

void ExploreWindow::manageEvent(SDL_Event event, IntelligentEntity &theScholar)
{
    
}

void ExploreWindow::activateWindow(SDL_Surface *screen, IntelligentEntity &theScholar)
{
    for (int i = 0; i < 6; i++)
    {
        options[i].applyTextBox(screen, 540, 100, 0, 50, i);
    }
}

void ExploreWindow::deactivateWindow()
{
    
}