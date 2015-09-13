//
//  Location.h
//  FalloutPennState
//
//  Created by Tom Harrison on 2/18/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include<string>
#include<vector>
#include"IntelligentEntity.h"
#include"SubLocation.h"
#include "SuperMutant.h"
#include "Container.h"

using namespace std;

class Location
{
protected:
    
    //name of location
    string name;
    
    //description of the location
    string description;
    
    //whether or not the location is the active one
    bool isActive;
    
    //List of sub-locations within the main location
    vector<SubLocation*> subLocations;
    
public:
    
    //Default constructor
    Location();
    
    //init constructor
    Location(string locationName);
    
    //function to return name of the location
    string getName();
    
    //function to set the name of the location
    void setName(string locationName);
    
    //function to return a location's activity
    bool isIsActive();
    
    //function to set a location's activity
    void setIsActive(bool activity);
    
    //Function that returns the active subLocation
    SubLocation getActiveSubLocation();
    
    //Function that returns all of the subLocations in the location
    vector<SubLocation*> getAllSubLocations();
    
    //Function to set all of the subLocations of the location
    void setAllSubLocations(vector<SubLocation*> subLocationList);
    
};
/*
#ifndef FalloutPennState_Location_h
#define FalloutPennState_Location_h



#endif
*/