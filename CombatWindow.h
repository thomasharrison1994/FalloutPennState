//
//  CombatWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 7/28/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_CombatWindow_h
#define FalloutPennState_CombatWindow_h

#define TACTIC 0
#define ITEM_SELECTED 1
#define TARGET_SELECTED 2

#pragma once

#include "GameSubWindow.h"
#include "TextBox.h"

enum actionType {ATTACK, AID, END_TURN};

class CombatWindow : public GameSubWindow
{
protected:
    
    vector<IntelligentEntity*> scholarTeam;
    vector<IntelligentEntity*> enemyTeam;
    
    vector<Item*> relevantItemsList;
    
    vector<Weapon*> relevantWeaponsList;
    vector<Aid*> relevantAidsList;
    
    //vector<TextBox> scholarTeamList;
    //vector<TextBox> enemyTeamList;
    vector<TextBox> relevantTeamList;
    vector<TextBox> itemChoiceList;
    
    //Scroll control
    int scrollTop[3];
    int scrollBottom[3];
    
    //Used to navigate both vectors entity vectors
    int turnControl;
    
    //Attack, aid, end turn graphic text
    TextBox choices[3];
    
    //Name of the entity currently taking turn
    TextBox turnTakingEntity;
    
    //Name of the entity being targeted
    TextBox targetedEntity;
    
    //Action point ratio of the turn taking entity
    TextBox turnTakingEntityActionPointRatio;
    
    //Action point ratio of the targeted entity
    TextBox targetedEntityActionPointRatio;
    
    //Health of the turn taking entity
    TextBox turnTakingEntityHealthRatio;
    
    //Health of the targeted entity
    TextBox targetedEntityHealthRatio;
    
    //Attack, aid, end turn flag
    actionType action;
    
    //Flags for combatPaths
    bool commandFlags[3];
    
    //Identifies the current command path
    int commandPathControl;
    
    //Green rectangles for selection designation
    SDL_Rect selectionRectanglesDimensions[3];
    
    //Coordinates for above rectangles
    SDL_Rect selectionRectanglesCoordinates[3];
    
    //Used to hold the values of the list positions
    int listPlaceHolders[3];
    
    //Switch for determining whether it is the player's turn or the AI's turn
    bool isPlayerTurn;
    
public:
    
    //Default Constructor
    CombatWindow();
    
    //Default Destructor
    ~CombatWindow();
    
    //Function to set the teams for combat
    void setTeams(vector<IntelligentEntity*>& player, vector<IntelligentEntity*>& enemy);
    
    //General function for managing various actions
    void takeAction();
    
    //Function that attacks a targeted enemy
    void attack();
    
    //Function that heals a targeted teammate
    void heal();
    
    //Function to end turn
    void endTurn();
    
    //AI versions of the previous four functions
    //Function for various actions for AI
    void enemyTakeAction();
    
    //Function for AI attack
    void enemyAttack();
    
    //Function for enemy to heal
    void enemyHeal();
    
    //Function to check if an (enemy) teammate has been injured. For use with enemyHeal
    bool isTeammateInjured();
    
    //Function for enemy to end turn
    void enemyEndTurn();
    
    //Prints choices array
    void printTacticalChoices(SDL_Surface* screen);
    
    //Prints the list of relevant items for selection
    void printRelevantItems(SDL_Surface* screen);
    
    //Prints the list of relevant targets
    void printRelevantTargets(SDL_Surface* screen);
    
    //Function to remove dead entities from vectors
    bool cleanUp();
    //void cleanUp();
    
    //Overloaded function to remove dead entities from vectors
    void cleanUp(vector<IntelligentEntity*>& player, vector<IntelligentEntity*>& enemy);
    
    //Function that resolves the battle (awards xp, loot, redirects to navigation window)
    void endBattle();
    
    //Returns isPlayerTurn
    bool getIsPlayerTurn();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();
    
};

#endif
