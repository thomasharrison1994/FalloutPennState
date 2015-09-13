//
//  Location.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/18/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Location.h"

using namespace std;

Location::Location()
{
    isActive = false;
    
    subLocations.push_back(new SubLocation);
}

Location::Location(string locationName)
{
    name = locationName;
    
    isActive = false;
    
    subLocations.push_back(new SubLocation);
}

string Location::getName()
{
    return name;
}

void Location::setName(string locationName)
{
    name = locationName;
}

bool Location::isIsActive()
{
    return isActive;
}

void Location::setIsActive(bool activity)
{
    isActive = activity;
}

SubLocation Location::getActiveSubLocation()
{
    for (int i = 0; i < subLocations.size(); i++)
    {
        if (subLocations[i]->getIsActive() == true)
        {
            return *subLocations[i];
        }
    }
}

vector<SubLocation*> Location::getAllSubLocations()
{
    return subLocations;
}

void Location::setAllSubLocations(vector<SubLocation *> subLocationList)
{
    subLocations = subLocationList;
}