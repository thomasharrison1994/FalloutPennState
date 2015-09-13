//
//  SubLocation.h
//  FalloutPennState
//
//  Created by Tom Harrison on 8/13/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef FalloutPennState_SubLocation_h
#define FalloutPennState_SubLocation_h

#pragma once
#include "IntelligentEntity.h"
#include "SuperMutant.h"
#include "Container.h"


class SubLocation
{
protected:
    
    //name of location
    string name;
    
    //description of the location
    string description;
    
    //whether or not the location is the active one
    bool isActive;
    
    //Intelligent Entities in the sublocation
    vector<IntelligentEntity*> entitiesInSubLocation;
    
    //Containers in the sublocation
    vector<Container*> containersInSubLocation;
    
public:
    
    //Default constructor
    SubLocation();
    
    //Default destructor
    ~SubLocation();
    
    //Get the sublocations name
    string getName();
    
    //Get the sublocations description
    string getDescription();
    
    //Get whether or not the sublocation is active
    bool getIsActive();
    
    //Function to set the activity of a sublocation
    void setIsActive(bool activity);
    
    //Get the list of entities in the sublocation
    vector<IntelligentEntity*> getEntitiesInSubLocation();
    
    //Set the list of intelligent entities in the sublocation
    void setEntitiesInSubLocation(vector<IntelligentEntity*> entityVector);
    
    //Get the list of containers in the sublocation
    vector<Container*> getContainersInSubLocation();
    
    //Set the list of containers in the sublocation
    void setContainersInSubLocation(vector<Container*> containerVector);
    
};
#endif
