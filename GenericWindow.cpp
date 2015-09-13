//
//  GenericWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GenericWindow.h"
/*
GenericWindow::GenericWindow()
{
    
}
*/
bool GenericWindow::isIsActive()
{
    return isActive;
}

void GenericWindow::setIsActive(bool activity)
{
    isActive = activity;
}

SDL_Surface* GenericWindow::getGraphic(int vectorPosition)
{
    return graphics[vectorPosition];
}

SDL_Rect* GenericWindow::getDimensions(int vectorPosition)
{
    return graphicDimensions[vectorPosition];
}

SDL_Rect* GenericWindow::getCoordinates(int vectorPosition)
{
    return graphicCoordinates[vectorPosition];
}


void GenericWindow::displayGraphic(int triVectorDesignation, SDL_Surface* destination)
{
    //cout<<"Displaying graphic";
    SDL_Rect toPlace;
    
    toPlace.x = graphicCoordinates[triVectorDesignation]->x;
    toPlace.y = graphicCoordinates[triVectorDesignation]->y;
    
    //SDL_BlitSurface(graphics[triVectorDesignation], graphicDimensions[triVectorDesignation], destination, graphicCoordinates[triVectorDesignation]);
    
    SDL_BlitSurface(graphics[triVectorDesignation], graphicDimensions[triVectorDesignation], destination, graphicCoordinates[triVectorDesignation]);    
}

string GenericWindow::toString(int myInt)
{
    return static_cast<ostringstream*>( &(ostringstream() << myInt) )->str();
}