//
//  StorageWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 8/4/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_StorageWindow_h
#define FalloutPennState_StorageWindow_h

#define SCHOLAR 0
#define CONTAINER 1

#define VAL 0
#define WG 1
#define DR 2
#define DAM 3

#pragma once

#include "GameSubWindow.h"
//#include "ItemsSubWindow.h"
#include "TextBox.h"
#include "Container.h"

class StorageWindow : public GameSubWindow//, public ItemsSubWindow
{
protected:
    
    //Copy of the scholar's inventory
    vector<Item*> scholarsInventory;
    
    //Copy of the inventory of the storage container
    vector<Item*> containerInventory;
    
    //Textboxes for scholar's inventory
    vector<TextBox> scholarItemList;
    
    //Textboxes for the container's inventory
    vector<TextBox> containerItemList;
    
    TextBox listNames[2];
    
    //Scroll control
    int scrollTop[2];
    int scrollBottom[2];
    //int listHolder[2];
    
    //Designates which list is being searched
    int onList;
    
    //Weight ratio of the entity
    TextBox weightRatio;
    
    //Item properties
    
    TextBox val;
    TextBox weight;
    TextBox eitherDRorDAM;
    
    //Arrow dimensions and coordinates
    SDL_Rect arrowDimensions;
    SDL_Rect arrowCoordinates;
    
public:
    
    //Default Constructor
    StorageWindow();
    
    //Default Destructor
    ~StorageWindow();
    
    //Function to set the inventories
    void setInventories(vector<Item*> player, Container theContainer);
    
    //Overloaded function that accepts intelligent entity instead of item vector
    void setInventories(IntelligentEntity player, Container theContainer);
    
    //Function to reset the inventories of the two things after completion of the trading process
    void resetInventories(IntelligentEntity& player, Container& theContainer);
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
    
};

#endif
