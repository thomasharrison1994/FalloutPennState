//
//  Container.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 8/4/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Container.h"

Container::Container()
{
    //itemsWithin.push_back(new MissileLauncher);
    itemsWithin.push_back(new Flamer);
    itemsWithin.push_back(new PreWarFood);
    itemsWithin.push_back(new Armor("Combat Armor"));
    itemsWithin.push_back(new PlasmaRifle);
    itemsWithin.push_back(new LaserPistol);
    //itemsWithin.push_back(new LaserRifle);
    itemsWithin.push_back(new PlasmaPistol);
    itemsWithin.push_back(new LaserRifle);
    itemsWithin.push_back(new SuperSledge);
    itemsWithin.push_back(new BrassKnuckles);
    itemsWithin.push_back(new PreWarFood);
    itemsWithin.push_back(new PostWarFood);
    
    containerName = "Fire Hose Box";
}

Container::Container(string theContainerName)
{
    containerName = theContainerName;
}

Container::Container(string theContainerName, vector<Item*> theItemsWithin)
{
    containerName = theContainerName;
    itemsWithin = theItemsWithin;
}

string Container::getContainerName()
{
    return containerName;
}

void Container::setContainerName(string theContainerName)
{
    containerName = theContainerName;
}

vector<Item*> Container::getContainerItems()
{
    return itemsWithin;
}

void Container::setContainerItems(vector<Item*> fillContainer)
{
    itemsWithin = fillContainer;
}