//
//  ItemsWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/25/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ItemsWindow.h"

ItemsWindow::ItemsWindow()
{
    isActive = false;
    
    identity = ITEMS;
    
    navSubWindows = 0;
    
    subWindows.push_back(new WeaponsWindow);
    subWindows.push_back(new ApparelWindow);
    subWindows.push_back(new AidWindow);
    subWindows.push_back(new MiscWindow);
    subWindows.push_back(new AmmoWindow);
    
    //Button
    graphics.push_back(IMG_Load("PipBoyButtonSheet.bmp"));    
    
    //SDL_Rect buttonRect;
    
    buttonRect.x = 106;
    buttonRect.y = 0;
    buttonRect.w = 110;
    buttonRect.h = 75;
    
    graphicDimensions.push_back(&buttonRect);
    
    //SDL_Rect buttonCoordinates;
    
    buttonCoordinates.x = 731;
    buttonCoordinates.y = 667;
    buttonCoordinates.w = 100;
    buttonCoordinates.h = 75;
    
    graphicCoordinates.push_back(&buttonCoordinates);
    
    //Screen
    graphics.push_back(IMG_Load("ItemsButtonGeneral.png"));
    
    //SDL_Rect mainScreen;
    
    mainScreen.x = 23;
    mainScreen.y = 80;
    mainScreen.w = 1150;
    mainScreen.h = 551;
    
    graphicDimensions.push_back(&mainScreen);
    
    //SDL_Rect mainScreenCoordinates;
    
    mainScreenCoordinates.x = 24;
    mainScreenCoordinates.y = 52;
    
    graphicCoordinates.push_back(&mainScreenCoordinates);
}

ItemsWindow::~ItemsWindow()
{
    
}

void ItemsWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
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

void ItemsWindow::activateWindow(SDL_Surface* screen, IntelligentEntity& theScholar)
{
    weightRatio = toString(theScholar.actualTotalWeight) + "/" + toString(theScholar.getCarryWeight());
    
    itemsValues[0] = weightRatio;
    
    healthRatio = toString(theScholar.actualHealth) + "/" + toString(theScholar.getHealth());
    
    itemsValues[1] = healthRatio;
    
    itemsValues[2] = toString(theScholar.getDamageResistance());
    
    itemsValues[3] = toString(theScholar.getCaps());    
    
    for (int i = 0; i < graphics.size(); i++)
    {
        displayGraphic(i, screen);
    }
    
    itemsValues[0].applyTextBox(screen, 320, 70); // (320, 74)
    itemsValues[1].applyTextBox(screen, 555, 70); // (465, 74)
    //statValues[2].applyTextBox(screen, 540, 74);
    itemsValues[2].applyTextBox(screen, 780, 70); // (700, 74)
    //statValues[4].applyTextBox(screen, 775, 74);
    itemsValues[3].applyTextBox(screen, 1030, 70); // (930, 74)
    
}

void ItemsWindow::deactivateWindow()
{
    for (int i = 0; i < graphics.size(); i++)
    {
        SDL_FreeSurface(graphics[i]);
    }
}