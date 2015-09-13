//
//  EnterSPECIALWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 7/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "EnterSPECIALWindow.h"

EnterSPECIALWindow::EnterSPECIALWindow()
{
    //isActive = true;
    
    selfIdentity = ENTER_SPECIAL;
    nextIdentity = selfIdentity;
    
    for (int i = 0; i < 7; i++)
    {
        SPECIALValues.push_back(5);
    }
    
    SPECIALPointsRemaining = 5;
    
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
    
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 465;
    rectangleDimensions.h = 45;
    
    rectangleCoordinates.x = 530;
    rectangleCoordinates.y = 165;
    
    circleCoordinates.x = 1000;
    circleCoordinates.y = 400; //150
    
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

EnterSPECIALWindow::~EnterSPECIALWindow()
{
    
}

void EnterSPECIALWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        
        int onStat = (((rectangleCoordinates.y - 15) / 50) - 3);
        
        //if (isActive == true)
        //{
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    
                    if (rectangleCoordinates.y != 165)
                    {
                        rectangleCoordinates.y -= 50;
                    }
                    
                    break;
                    
                case SDLK_DOWN:
                    
                    if (rectangleCoordinates.y != 465)
                    {
                        rectangleCoordinates.y += 50;
                    }
                    
                    break;
                    
                case SDLK_RIGHT:
                    
                    if ((SPECIALValues[onStat] < 10) && SPECIALPointsRemaining > 0)
                    {
                        --SPECIALPointsRemaining;
                        ++SPECIALValues[onStat];
                    }
                    
                    break;
                    
                case SDLK_LEFT:
                    
                    if (SPECIALValues[onStat] > 1)
                    {
                        ++SPECIALPointsRemaining;
                        --SPECIALValues[onStat];
                    }                    
                    
                    break;
                    
                case SDLK_RETURN:
                    
                    if (SPECIALPointsRemaining == 0)
                    {
                        theScholar.setS(SPECIALValues[0]);
                        theScholar.setP(SPECIALValues[1]);                    
                        theScholar.setE(SPECIALValues[2]);
                        theScholar.setC(SPECIALValues[3]);                    
                        theScholar.setI(SPECIALValues[4]);                    
                        theScholar.setA(SPECIALValues[5]);
                        theScholar.setL(SPECIALValues[6]);
                        
                        theScholar.setBarter(theScholar.setSkill(theScholar.getC()));
                        theScholar.setEnergyWeapons(theScholar.setSkill(theScholar.getP()));
                        theScholar.setExplosives(theScholar.setSkill(theScholar.getP()));
                        theScholar.setGuns(theScholar.setSkill(theScholar.getA()));                    
                        theScholar.setLockpick(theScholar.setSkill(theScholar.getP()));
                        theScholar.setMedicine(theScholar.setSkill(theScholar.getI()));
                        theScholar.setMeleeWeapons(theScholar.setSkill(theScholar.getS()));
                        theScholar.setRepair(theScholar.setSkill(theScholar.getI()));                    
                        theScholar.setScience(theScholar.setSkill(theScholar.getI()));
                        theScholar.setSneak(theScholar.setSkill(theScholar.getA()));
                        theScholar.setSpeech(theScholar.setSkill(theScholar.getC()));
                        theScholar.setSurvival(theScholar.setSkill(theScholar.getE()));
                        theScholar.setUnarmed(theScholar.setSkill(theScholar.getE()));
                        
                        theScholar.calculateHealth(theScholar.getE());
                        theScholar.calculateActionPoints(theScholar.getA());
                        theScholar.calculateCarryWeight(theScholar.getS());
                        theScholar.calculateSkillPoints(theScholar.getI());
                        
                        theScholar.actualHealth = theScholar.getHealth();
                        theScholar.actualActionPoints = theScholar.getActionPoints();
                        /*
                         Test remove
                        isActive = false;
                        */
                        //BEGIN TEST CODE
                        nextIdentity = ENTER_TAG_SKILLS;
                        //END TEST CODE
                    }
                    
                    break;
                    
                default:
                    ;
                    
                    break;
            }
        //}        
    }    
}

void EnterSPECIALWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    //BEGIN TEST CODE
    nextIdentity = selfIdentity;
    //END TEST CODE    
    
    TextBox prompt("Enter S.P.E.C.I.A.L. :");
    TextBox pointsRemaining(toString(SPECIALPointsRemaining), 72);
    
    prompt.setCoordinates(540, 120);
    pointsRemaining.setCoordinates(1035, 415);
    
    prompt.applyTextBox(screen);
    pointsRemaining.applyTextBox(screen);
    
    //SDL_BlitSurface(imageWell, &activeRectDimensions, screen, &activeRectCoordinates);
    
    for (int i = 0; i < 7; i++)
    {
        SPECIALS[i].applyTextBox(screen, 540, 170, 0, 50, i);
        SPECIALValueGraphics[i] = TextBox(toString(SPECIALValues[i]));
        SPECIALValueGraphics[i].applyTextBox(screen, 840, 170, 0, 50, i);
    }
    
    SDL_BlitSurface(rectangles, &circleDimensions, screen, &circleCoordinates);    
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

void EnterSPECIALWindow::deactivateWindow()
{
    
}