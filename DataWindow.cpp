//
//  DataWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/25/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "DataWindow.h"

DataWindow::DataWindow()
{
    isActive = false;
    
    identity = DATA;
    
    navSubWindows = 0;
    
    subWindows.push_back(new LocalAreasWindow);
    subWindows.push_back(new WorldMapWindow);
    subWindows.push_back(new QuestsWindow);
    subWindows.push_back(new NotesWindow);
    subWindows.push_back(new RadioWindow);
    
    //Button
    graphics.push_back(IMG_Load("PipBoyButtonSheet.bmp"));    
    
    //SDL_Rect buttonRect;
    
    buttonRect.x = 106;
    buttonRect.y = 0;
    buttonRect.w = 110;
    buttonRect.h = 75;
    
    graphicDimensions.push_back(&buttonRect);
    
    //SDL_Rect buttonCoordinates;
    
    buttonCoordinates.x = 622;
    buttonCoordinates.y = 666;
    buttonCoordinates.w = 100;
    buttonCoordinates.h = 75;
    
    graphicCoordinates.push_back(&buttonCoordinates);
    
    //Screen
    graphics.push_back(IMG_Load("DataButtonGeneral.png"));
    
    //SDL_Rect mainScreen;
    
    mainScreen.x = 23; //23
    mainScreen.y = 79; //52
    mainScreen.w = 1150; //1150
    mainScreen.h = 546; //546
    
    graphicDimensions.push_back(&mainScreen);
    
    //SDL_Rect mainScreenCoordinates;
    
    mainScreenCoordinates.x = 37; //34
    mainScreenCoordinates.y = 57; //55
    
    graphicCoordinates.push_back(&mainScreenCoordinates);
}

DataWindow::~DataWindow()
{
    
}

void DataWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
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
    else if(event.type == SDL_KEYDOWN)
    {
        if (isActive == true)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                    
                    subWindows[navSubWindows]->setIsActive(false);
                    
                    if (++navSubWindows == subWindows.size())
                    {
                        navSubWindows = 0;
                    }
                    
                    subWindows[navSubWindows]->setIsActive(true);
                    
                    break;
                    
                case SDLK_LEFT:
                    
                    subWindows[navSubWindows]->setIsActive(false);
                    
                    if (--navSubWindows < 0)
                    {
                        navSubWindows = subWindows.size() - 1;
                    }
                    
                    subWindows[navSubWindows]->setIsActive(true);
                    
                    break;
                    
                default:
                    ;
                    
                    break;
            }
        }        
    }
}

void DataWindow::activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar)
{
    for (int i = 0; i < graphics.size(); i++)
    {
        displayGraphic(i, screen);
    }
}

void DataWindow::deactivateWindow()
{
    for (int i = 0; i < graphics.size(); i++)
    {
        SDL_FreeSurface(graphics[i]);
    }
}