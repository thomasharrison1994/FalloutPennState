//
//  GoBackWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 7/12/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GoBackWindow.h"

GoBackWindow::GoBackWindow()
{
    //isActive = true;
    isDone = false;
    
    selfIdentity = GO_BACK;
    nextIdentity = selfIdentity;
    
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 465;
    rectangleDimensions.h = 45;
    
    rectangleCoordinates.x = 530;
    rectangleCoordinates.y = 165;
    
    choices[0] = TextBox("Edit name");
    choices[1] = TextBox("Edit S.P.E.C.I.A.L.");
    choices[2] = TextBox("Edit tag skills");
    choices[3] = TextBox("Begin your adventure");
}

GoBackWindow::~GoBackWindow()
{
    
}

bool GoBackWindow::getIsDone()
{
    return isDone;
}

int GoBackWindow::getToWhere()
{
    return toWhere;
}

void GoBackWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        
        int onStat = (((rectangleCoordinates.y - 15) / 50) - 3);
        
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                
                if (rectangleCoordinates.y != 165)
                {
                    rectangleCoordinates.y -= 50;
                }                
                
                break;
                
            case SDLK_DOWN:
                
                if (rectangleCoordinates.y != 315)
                {
                    rectangleCoordinates.y += 50;
                }                
                
                break;
                
            case SDLK_RIGHT:
                
                break;
                
            case SDLK_LEFT:
                
                break;
                
            case SDLK_RETURN:
                
                toWhere = onStat;
                
                /*
                 Test remove
                isActive = false;
                */
                //BEGIN TEST CODE
                switch (toWhere)
                {
                    case 0:
                        
                        nextIdentity = ENTER_NAME;
                    
                        break;
                        
                    case 1:
                        
                        nextIdentity = ENTER_SPECIAL;
                        
                        break;
                        
                    case 2:
                        
                        nextIdentity = ENTER_TAG_SKILLS;
                        
                        break;
                        
                    case 3:
                        
                        nextIdentity = NAVIGATION;
                        
                        break;                        
                        
                    default:
                        break;
                }
                //END TEST CODE
                /*
                 potentially put back
                if (toWhere == 3)
                {
                    isDone = true;
                }
                 */
                
                break;
                
            default:
                ;
                
                break;
        }       
    }    
}

void GoBackWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    //BEGIN TEST CODE
    nextIdentity = selfIdentity;
    //END TEST CODE    
    
    for (int i = 0; i < 4; i++)
    {
        choices[i].applyTextBox(screen, 540, 170, 0, 50, i);
    }
    
    SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);    
}

void GoBackWindow::deactivateWindow()
{
    
}