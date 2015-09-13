//
//  SPECIALWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SPECIALWindow.h"

SPECIALWindow::SPECIALWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 240; //240
    activeRectDimensions.y = 670; //670
    activeRectDimensions.w = 275; //275
    activeRectDimensions.h = 45; //45
    
    activeRectCoordinates.x = 268; //268
    activeRectCoordinates.y = 566; //566
    
    SPECIALS.push_back(TextBox("Strength"));
    SPECIALS.push_back(TextBox("Perception"));
    SPECIALS.push_back(TextBox("Endurance"));
    SPECIALS.push_back(TextBox("Charisma"));
    SPECIALS.push_back(TextBox("Intelligence"));
    SPECIALS.push_back(TextBox("Agility"));
    SPECIALS.push_back(TextBox("Luck"));
    
    /*
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 600;
    rectangleDimensions.h = 60;
    */
    
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 465;
    rectangleDimensions.h = 45;    
    
    rectangleCoordinates.x = 80;
    rectangleCoordinates.y = 146;    
    
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

SPECIALWindow::~SPECIALWindow()
{
    
}

void SPECIALWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
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
                    
                    if (rectangleCoordinates.y != 446)
                    {
                        rectangleCoordinates.y += 50;
                    }
                    
                    break;
                    
                default:
                    ;
                    
                    break;
            }
        }        
    }    
}

void SPECIALWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    /*
    vector<TextBox> theScholarSPECIAL;
    
    theScholarSPECIAL.push_back(TextBox(toString(theScholar.getS())));
    theScholarSPECIAL.push_back(TextBox(toString(theScholar.getP())));    
    theScholarSPECIAL.push_back(TextBox(toString(theScholar.getE())));    
    theScholarSPECIAL.push_back(TextBox(toString(theScholar.getC())));
    theScholarSPECIAL.push_back(TextBox(toString(theScholar.getI())));    
    theScholarSPECIAL.push_back(TextBox(toString(theScholar.getA())));
    theScholarSPECIAL.push_back(TextBox(toString(theScholar.getL())));    
    */
    
    theScholarSPECIAL[0] = (TextBox(toString(theScholar.getS())));
    theScholarSPECIAL[1] = (TextBox(toString(theScholar.getP())));    
    theScholarSPECIAL[2] = (TextBox(toString(theScholar.getE())));    
    theScholarSPECIAL[3] = (TextBox(toString(theScholar.getC())));
    theScholarSPECIAL[4] = (TextBox(toString(theScholar.getI())));    
    theScholarSPECIAL[5] = (TextBox(toString(theScholar.getA())));
    theScholarSPECIAL[6] = (TextBox(toString(theScholar.getL())));
    
    SDL_BlitSurface(imageWell, &activeRectDimensions, screen, &activeRectCoordinates);
    
    for (int i = 0; i < 7; i++)
    {
        SPECIALS[i].applyTextBox(screen, 100, 150, 0, 50, i);
        theScholarSPECIAL[i].applyTextBox(screen, 400, 150, 0, 50, i);
    }
    
    SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
    
    /*
     for (int i = 0; i < 3; i++)
     {
     //SDL_BlitSurface(imageWell, &statRectDimensions, screen, &statRectCoordinates[i]);
     //SDL_BlitSurface(imageWell, &statRectDataTypeDimensions[i], screen, &statRectDataTypeCoordinates[i]);
     }
     */
    //SDL_BlitSurface(imageWell, &descriptionLineDimensions, screen, &descriptionLineCoordinates);
    
    
    
}

void SPECIALWindow::deactivateWindow()
{
    
}