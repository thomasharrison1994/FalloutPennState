//
//  RadioWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/1/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "RadioWindow.h"

RadioWindow::RadioWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 920; //745
    activeRectDimensions.y = 710; //710
    activeRectDimensions.w = 119; //110
    activeRectDimensions.h = 45; //45
    
    activeRectCoordinates.x = 934; //759
    activeRectCoordinates.y = 569; //567
    
    onOff.push_back(TextBox("Off"));
    onOff.push_back(TextBox("On"));
    
    /*
    rectangleDimensions.x = 475;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 600;
    rectangleDimensions.h = 60;    
    */
    
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 465;
    rectangleDimensions.h = 45;
    
    rectangleCoordinates.x = 46;
    rectangleCoordinates.y = 146;
    
    squareDimensions.x = 50;
    squareDimensions.y = 75;
    squareDimensions.w = 35;
    squareDimensions.h = 35;    
    
    squareCoordinates.x = 60;
    squareCoordinates.y = rectangleCoordinates.y + 5;
    
    //myRadio.playSongs();
    
    isOn = false;
    
    myRadio.turnOffOn(isOn);
    
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

RadioWindow::~RadioWindow()
{
    
}

void RadioWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        if (isActive == true)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    
                    if (rectangleCoordinates.y != 146)
                    {
                        rectangleCoordinates.y -= 50;
                    }
                    
                    break;
                    
                case SDLK_DOWN:
                    
                    if (rectangleCoordinates.y != 196)
                    {
                        rectangleCoordinates.y += 50;
                    }
                    
                    break;
                    
                case SDLK_RETURN:
                    
                    squareCoordinates.y = rectangleCoordinates.y + 5;
                    
                    if (squareCoordinates.y == 151)
                    {
                        isOn = false;
                    }
                    
                    else
                    {
                        isOn = true;
                    }
                    
                    myRadio.turnOffOn(isOn);
                    
                    break;
                    
                default:
                    ;
                    
                    break;
            }
        }        
    }    
}

void RadioWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    SDL_BlitSurface(imageWell, &activeRectDimensions, screen, &activeRectCoordinates);
    
    for (int i = 0; i < 2; i++)
    {
        onOff[i].applyTextBox(screen, 100, 150, 0, 50, i);
    }
    
    SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
    SDL_BlitSurface(rectangles, &squareDimensions, screen, &squareCoordinates);
    
    
    /*
     for (int i = 0; i < 3; i++)
     {
     //SDL_BlitSurface(imageWell, &statRectDimensions, screen, &statRectCoordinates[i]);
     //SDL_BlitSurface(imageWell, &statRectDataTypeDimensions[i], screen, &statRectDataTypeCoordinates[i]);
     }
     */
    //SDL_BlitSurface(imageWell, &descriptionLineDimensions, screen, &descriptionLineCoordinates);
    
    
    
}

void RadioWindow::deactivateWindow()
{
    
}

void RadioWindow::playStation()
{
    myRadio.playSongs();
}