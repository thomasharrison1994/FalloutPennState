//
//  BarterWindow.h
//  FalloutPennState
//
//  Created by Tom Harrison on 8/9/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_BarterWindow_h
#define FalloutPennState_BarterWindow_h

#define VENDOR 1

#pragma once

#include "StorageWindow.h"

class BarterWindow : public StorageWindow//, public ItemsSubWindow
{
protected:
    
    //Inventory of the vendor
    vector<Item*> vendorInventory;
    
    //Text boxes for the vendors inventory
    vector<TextBox> vendorItemList;
    
    //Text box for the scholars caps
    TextBox scholarCaps;
    
    //Text box for the vendors caps
    TextBox vendorCaps;
    
    //Total caps in exchange
    int totalCaps;
    
    //Number of caps the scholar has
    int scholarsCaps;
    
    //The sale value for the item
    double saleValue;
    
    //The buy value for the item
    double buyValue;
    
    //Text box for total caps (make absolute value)
    TextBox capTotal;
    
    //Text box for the values for the scholars items
    vector<TextBox> scholarItemValueList;
    
    //Text box for the values of the vendors items
    vector<TextBox> vendorItemValueList;
    
    //Boolean flag for whether or not trade is in progress
    bool isTradeInProgress;
    
    //Boolean flag for whether or not trade is accepted
    bool isTradeAccepted;
    
    //Boolean flag to see if the trade has come to a conclusion
    bool isTradeConcluded;
    
    //Text box array that contains textboxes for accept or decline
    TextBox acceptDecline[2];
    
public:
    
    //Default Constructor
    BarterWindow();
    
    //Default Destructor
    ~BarterWindow();
    
    //Function to set the inventories
    void setInventories(IntelligentEntity player, IntelligentEntity trader);
    
    //Function that sets the information graphically, and without re-introducing numbers from the two entities
    void scopeSet();
    
    //Function to reset the inventories
    void resetInventories(IntelligentEntity& player, IntelligentEntity& trader);
    
    //Function to confirm the trade
    void confirmTrade(IntelligentEntity& player, IntelligentEntity& trader);
    
    //Function to calculate the sale and buy values
    void calculateBuySellValue(int playerBarterSkill);
    
    //Function to get the value of isTradeInProgress
    bool getIsTradeInProgress();
    
    //Function to get the value of isTradeAccepted
    bool getIsTradeAccepted();
    
    //Function to get the value of isTradeConcluded
    bool getIsTradeConcluded();
    
    //Function to manage the event
    virtual void manageEvent(SDL_Event event, IntelligentEntity& theScholar);
    
    //Function to display the window in it's entirety
    virtual void activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar);
    
    //Function to remove a window in it's entirety
    virtual void deactivateWindow();    
    
};

#endif
