//
//  MasterButtonWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "MasterButtonWindow.h"

/*
MasterButtonWindow::MasterButtonWindow()
{
    SDL_Rect buttonRect;
    
    buttonRect.x = 106;
    buttonRect.y = 0;
    buttonRect.w = 110;
    buttonRect.h = 75;
    
    graphics.push_back(IMG_Load("PipBoyButtonSheet.bmp"));
    graphicDimensions.push_back(&buttonRect);
    
    //cout<<graphicDimensions[0]->x<<endl;
    
    //graphicCoordinates.push_back(&buttonRect);
}
*/

int MasterButtonWindow::getSubWindowSize()
{
    return subWindows.size();
}

windowIdentity MasterButtonWindow::getIdentity()
{
    return identity;
}

GenericWindow* MasterButtonWindow::getActiveSubWindow()
{
    for (int i = 0; i < subWindows.size(); i++)
    {
        if (subWindows[i]->isIsActive() == true)
        {
            return subWindows[i];
        }
    }
}

GenericWindow* MasterButtonWindow::getSubWindow(int i)
{
    return subWindows[i];
}

void MasterButtonWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    //The mouse offsets
    int x = 0, y = 0;    
    
    //If the mouse was pressed
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        //If the left mouse button was pressed
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            //Get the mouse offsets
            x = event.motion.x;
            y = event.motion.y;
            
            //If the mouse is over the button
            if ((x > graphicCoordinates[0]->x) && (x < graphicCoordinates[0]->x + graphicCoordinates[0]->w) && (y > graphicCoordinates[0]->y) && (y < graphicCoordinates[0]->y + graphicCoordinates[0]->h))
            {
                isActive = true;
                //activateWindow(screen);
            }
            
            else
            {
                isActive = false;
                //deactivateWindow();
            }
        }
    }    
}