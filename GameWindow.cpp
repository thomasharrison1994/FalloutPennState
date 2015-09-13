//
//  GameWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/21/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GameWindow.h"

GameWindow::GameWindow()
{
    isActive = true;
    
    identity = GAME;
    
    nextWindow = ENTER_NAME;
    
    navSubWindows = 0;
    
    subWindows.push_back(new EnterNameWindow);
    subWindows.push_back(new EnterSPECIALWindow);
    subWindows.push_back(new EnterTagSkillsWindow);
    subWindows.push_back(new GoBackWindow);
    subWindows.push_back(new NavigationWindow);
    subWindows.push_back(new CombatWindow);
    subWindows.push_back(new StorageWindow);
    subWindows.push_back(new BarterWindow);
    subWindows.push_back(new ExploreWindow);
    
    //Button
    graphics.push_back(IMG_Load("PipBoyButtonSheet.bmp"));    
    
    //SDL_Rect buttonRect;
    
    buttonRect.x = 106;
    buttonRect.y = 0;
    buttonRect.w = 110;
    buttonRect.h = 75;
    
    graphicDimensions.push_back(&buttonRect);
    
    //SDL_Rect buttonCoordinates;
    
    buttonCoordinates.x = 400;
    buttonCoordinates.y = 667;
    buttonCoordinates.w = 100;
    buttonCoordinates.h = 75;
    
    graphicCoordinates.push_back(&buttonCoordinates);
    
    //Screen
    graphics.push_back(IMG_Load("GameButtonGeneral.png"));
    
    //SDL_Rect mainScreen;
    
    mainScreen.x = 40;
    mainScreen.y = 135;
    mainScreen.w = 1150;
    mainScreen.h = 540;
    
    graphicDimensions.push_back(&mainScreen);
    
    //SDL_Rect mainScreenCoordinates;
    
    mainScreenCoordinates.x = 34;
    mainScreenCoordinates.y = 55;
    
    graphicCoordinates.push_back(&mainScreenCoordinates);
}

GameWindow::~GameWindow()
{
    
}

void GameWindow::determineActiveSubWindow()
{
    for (int i = 0; i < subWindows.size(); i++)
    {
        if (subWindows[i]->isIsActive() == true)
        {
            nextWindow = dynamic_cast<GameSubWindow*>(subWindows[i])->getNextIdentity();
        }
        
        subWindows[i]->setIsActive(false);
    }
    
    for (int i = 0; i < subWindows.size(); i++)
    {
        if (dynamic_cast<GameSubWindow*>(subWindows[i])->getIdentity() == nextWindow)
        {
            subWindows[i]->setIsActive(true);
        }
    }
    
    /*
    if (subWindows[3]->isIsActive() == false && dynamic_cast<GoBackWindow*>(subWindows[3])->getIsDone() == false)
    {
        for (int i = dynamic_cast<GoBackWindow*>(subWindows[3])->getToWhere(); i < subWindows.size(); i++)
        {
            subWindows[i]->setIsActive(true);
        }
    }
     */
}

gameWindowIdentity GameWindow::getNextWindow()
{
    return nextWindow;
}

void GameWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
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
                case SDLK_RETURN:
                    
                    bool isTotallyInactive = true;
                    
                    for (int i = 0; i < subWindows.size(); i++)
                    {
                        if (subWindows[i]->isIsActive() == true)
                        {
                            isTotallyInactive = false;
                        }
                    }
                    
                    if (isTotallyInactive == true)
                    {
                        for (int i = 0; i < subWindows.size(); i++)
                        {
                            subWindows[i]->setIsActive(true);
                        }
                    }
                    break;
            }
        }
    }
}

void GameWindow::activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar)
{
    for (int i = 0; i < graphics.size(); i++)
    {
        displayGraphic(i, screen);
    }
}

void GameWindow::deactivateWindow()
{
    for (int i = 0; i < graphics.size(); i++)
    {
        SDL_FreeSurface(graphics[i]);
    }
}