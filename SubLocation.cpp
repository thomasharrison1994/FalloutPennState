//
//  SubLocation.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 8/13/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SubLocation.h"

SubLocation::SubLocation()
{
    entitiesInSubLocation.push_back(new SuperMutant);
    containersInSubLocation.push_back(new Container);
}

SubLocation::~SubLocation()
{
    
}

string SubLocation::getName()
{
    return name;
}

string SubLocation::getDescription()
{
    return description;
}

bool SubLocation::getIsActive()
{
    return isActive;
}

void SubLocation::setIsActive(bool activity)
{
    isActive = activity;
}

vector<IntelligentEntity*> SubLocation::getEntitiesInSubLocation()
{
    return entitiesInSubLocation;
}

void SubLocation::setEntitiesInSubLocation(vector<IntelligentEntity *> entityVector)
{
    entitiesInSubLocation = entityVector;
}

vector<Container*> SubLocation::getContainersInSubLocation()
{
    return containersInSubLocation;
}

void SubLocation::setContainersInSubLocation(vector<Container *> containerVector)
{
    containersInSubLocation = containerVector;
}