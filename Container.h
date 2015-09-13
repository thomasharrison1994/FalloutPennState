//
//  Container.h
//  FalloutPennState
//
//  Created by Tom Harrison on 8/4/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_Container_h
#define FalloutPennState_Container_h

#pragma once
#include<string>
#include<vector>
#include"IntelligentEntity.h"
#include"Item.h"

using namespace std;

class Container
{
protected:
    
    //The items in the container
    vector<Item*> itemsWithin;
    
    //Name of the container
    string containerName;
    
public:
    
    //Default constructor
    Container();
    
    //Init with name constructor
    Container(string theContainerName);
    
    //Init with name and items constructor
    Container(string theContainerName, vector<Item*> itemsWithin);
    
    //Function to get the container name
    string getContainerName();
    
    //Function to set the name of the container
    void setContainerName(string theContainerName);
    
    //Function to get the items within the container
    vector<Item*> getContainerItems();
    
    //Function to set the items of for the container
    void setContainerItems(vector<Item*> fillContainer);
    
};

#endif
