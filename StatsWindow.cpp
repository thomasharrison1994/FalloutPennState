//
//  StatsWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/24/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "StatsWindow.h"

StatsWindow::StatsWindow()
{
    isActive = false;
    
    identity = STATS;
    
    navSubWindows = 0;
    
    subWindows.push_back(new StatusWindow);
    subWindows.push_back(new SPECIALWindow);
    subWindows.push_back(new SkillsWindow);
    subWindows.push_back(new PerksWindow);
    subWindows.push_back(new GeneralWindow);
    
    //Button
    graphics.push_back(IMG_Load("PipBoyButtonSheet.bmp"));    
    
    //SDL_Rect buttonRect;
    
    buttonRect.x = 106;
    buttonRect.y = 0;
    buttonRect.w = 110;
    buttonRect.h = 75;
    
    graphicDimensions.push_back(&buttonRect);
    
    //SDL_Rect buttonCoordinates;
    
    buttonCoordinates.x = 515;
    buttonCoordinates.y = 667;
    buttonCoordinates.w = 100;
    buttonCoordinates.h = 75;
    
    graphicCoordinates.push_back(&buttonCoordinates);
    
    //Screen
    graphics.push_back(IMG_Load("StatsButtonGeneral.png"));
    
    //SDL_Rect mainScreen;
    
    mainScreen.x = 23;
    mainScreen.y = 52;
    mainScreen.w = 1150;
    mainScreen.h = 545;
    
    graphicDimensions.push_back(&mainScreen);
    
    //SDL_Rect mainScreenCoordinates;
    
    mainScreenCoordinates.x = 34;
    mainScreenCoordinates.y = 55;
    
    graphicCoordinates.push_back(&mainScreenCoordinates);
}

StatsWindow::~StatsWindow()
{
    
}

void StatsWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
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

void StatsWindow::activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar)
{
    /*
    statValues[0] = toString(theScholar.getLevel());
    statValues[1] = toString(theScholar.actualHealth);    
    statValues[2] = toString(theScholar.getHealth());
    statValues[3] = toString(theScholar.actualActionPoints);    
    statValues[4] = toString(theScholar.getActionPoints());    
    statValues[5] = toString(theScholar.getXP());
    statValues[6] = toString(theScholar.getXPForNextLevel());
     */
    
    statValues[0] = toString(theScholar.getLevel());
    
    healthRatio = toString(theScholar.actualHealth) + "/" + toString(theScholar.getHealth());
    
    statValues[1] = healthRatio;
    
    actionPointRatio = toString(theScholar.actualActionPoints) + "/" + toString(theScholar.getActionPoints());
    
    statValues[2] = actionPointRatio;
    
    XPRatio = toString(theScholar.getXP()) + "/" + toString(theScholar.getXPForNextLevel());
    
    statValues[3] = XPRatio;
    
    
    for (int i = 0; i < graphics.size(); i++)
    {
        displayGraphic(i, screen);
    }
    
    statValues[0].applyTextBox(screen, 320, 74);
    statValues[1].applyTextBox(screen, 465, 74);
    //statValues[2].applyTextBox(screen, 540, 74);
    statValues[2].applyTextBox(screen, 700, 74);
    //statValues[4].applyTextBox(screen, 775, 74);
    statValues[3].applyTextBox(screen, 930, 74);
    //statValues[6].applyTextBox(screen, 1050, 74);
    
}

void StatsWindow::deactivateWindow()
{
    for (int i = 0; i < graphics.size(); i++)
    {
        SDL_FreeSurface(graphics[i]);
    }
}