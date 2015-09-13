//
//  NavigationWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 7/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_NavigationWindow_h
#define FalloutPennState_NavigationWindow_h

#pragma once

#include "GameSubWindow.h"
#include "TextBox.h"
#include "Location.h"

// 0 = WEST
// 1 = EAST
// 2 = NORTH
// 3 = SOUTH

const int WEST = 0;
const int EAST = 1;
const int NORTH = 2;
const int SOUTH = 3;

enum direction {dEXPLORE, dNORTH, dNORTHEAST, dEAST, dSOUTHEAST, dSOUTH, dSOUTHWEST, dWEST, dNORTHWEST};

class NavigationWindow : public GameSubWindow
{
protected:
    
    vector<TextBox> choiceList;
    
    vector<direction> directionList;
    
    //What the player can do
    TextBox choiceType[9];
    
    //Number of things the player can do
    int numChoices;
    
    //boundary flags
    bool bounded[4];
    
    //Scroll control
    int scrollTop;
    int scrollBottom;
    
    //location coordinates
    int currentX;
    int currentY;
    
    int scrollSupplement;
    
    //Used to control variable sizes of scrolling
    //int listLength;
    
public:
    
    //Default Constructor
    NavigationWindow();
    
    //Default Destructor
    ~NavigationWindow();
    
    //Sets coordinates of active location
    void getCoordinates(Location worldMap[][5]);
    
    //Sets the list of choices
    void setList();
    
    //Function to set a combat team to oppose the scholar
    void setEnemyBattleTeam(vector<IntelligentEntity*>& enemyTeam);
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();
    
};

#endif
