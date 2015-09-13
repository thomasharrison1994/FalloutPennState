//
//  Screen.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Screen.h"

Screen::Screen()
{
    screenClipXCoordinate = 0;
    screenClipYCoordinate = 0;
    screenClipWidth = 110;
    screenClipHeight = 75;
    
    screenImage = IMG_Load("PipBoyButtonSheet.bmp");
    
    screenImageClip.x = screenClipXCoordinate;
    screenImageClip.y = screenClipYCoordinate;    
    screenImageClip.w = screenClipWidth;
    screenImageClip.h = screenClipHeight;
    
    screenXCoordinate = 300;
    screenYCoordinate = 300;
    screenWidth = 110;
    screenHeight = 75;
    
    screenDimensions.x = screenXCoordinate;
    screenDimensions.y = screenYCoordinate;    
    screenDimensions.w = screenWidth;
    screenDimensions.h = screenHeight;    
}

Screen::Screen(int x, int y, int w, int h, SDL_Surface* surface, SDL_Rect myClip)
{
    screenXCoordinate = x;
    screenYCoordinate = y;
    screenWidth = w;
    screenHeight = h;
    
    screenDimensions.x = screenXCoordinate;
    screenDimensions.y = screenYCoordinate;
    screenDimensions.w = screenWidth;
    screenDimensions.h = screenHeight;
    
    screenImage = surface;
    
    screenImageClip = myClip;
}

void Screen::applyScreen(SDL_Surface *screenDestination)
{
    SDL_BlitSurface(screenImage, &screenImageClip, screenDestination, &screenDimensions);
}