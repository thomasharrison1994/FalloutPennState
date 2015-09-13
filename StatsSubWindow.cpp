//
//  StatsSubWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "StatsSubWindow.h"

StatsSubWindow::StatsSubWindow()
{
    imageWell = IMG_Load("StatsButtonGeneral.png");
    rectangles = IMG_Load("Rectangles.png");
    
    //Uint32 colorkey = SDL_MapRGB(rectangles->format, 186, 3, 207);
    
    //SDL_SetColorKey(rectangles, SDL_SRCCOLORKEY, colorkey);
    
    /*
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 600;
    rectangleDimensions.h = 60;
    
    rectangleCoordinates.x = 80;
    rectangleCoordinates.y = 146;
     */
}