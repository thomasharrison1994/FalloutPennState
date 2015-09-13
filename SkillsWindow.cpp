//
//  SkillsWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 7/6/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SkillsWindow.h"

SkillsWindow::SkillsWindow()
{
    isActive = false;
    
    activeRectDimensions.x = 540; //540
    activeRectDimensions.y = 670; //670
    activeRectDimensions.w = 135; //135
    activeRectDimensions.h = 45; //45
    
    activeRectCoordinates.x = 581; //581
    activeRectCoordinates.y = 567; //567
    
    Skills.push_back(TextBox("Barter"));
    Skills.push_back(TextBox("Energy Weapons"));    
    Skills.push_back(TextBox("Explosives"));
    Skills.push_back(TextBox("Guns"));
    Skills.push_back(TextBox("LockPick"));
    Skills.push_back(TextBox("Medicine"));    
    Skills.push_back(TextBox("Melee Weapons"));
    Skills.push_back(TextBox("Repair"));
    Skills.push_back(TextBox("Science"));
    Skills.push_back(TextBox("Sneak"));
    Skills.push_back(TextBox("Speech"));    
    Skills.push_back(TextBox("Survival"));
    Skills.push_back(TextBox("Unarmed"));
    
    scrollTop = 0;
    scrollBottom = 7;
    
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

SkillsWindow::~SkillsWindow()
{
    
}

void SkillsWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
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
                    
                    else if (scrollTop != 0)
                    {
                        --scrollTop;
                        --scrollBottom;
                    }                    
                    
                    break;
                    
                case SDLK_DOWN:
                    
                    if (rectangleCoordinates.y != 446)
                    {
                        rectangleCoordinates.y += 50;
                    }
                    
                    else if (scrollBottom != 13)
                    {
                        ++scrollTop;
                        ++scrollBottom;
                    }                    
                    
                    break;
                    
                default:
                    ;
                    
                    break;
            }
        }        
    }    
}

void SkillsWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    theScholarSkills[0] = (TextBox(toString(theScholar.getBarter())));
    theScholarSkills[1] = (TextBox(toString(theScholar.getEnergyWeapons())));    
    theScholarSkills[2] = (TextBox(toString(theScholar.getExplosives())));    
    theScholarSkills[3] = (TextBox(toString(theScholar.getGuns())));
    theScholarSkills[4] = (TextBox(toString(theScholar.getLockpick())));    
    theScholarSkills[5] = (TextBox(toString(theScholar.getMedicine())));
    theScholarSkills[6] = (TextBox(toString(theScholar.getMeleeWeapons())));    
    theScholarSkills[7] = (TextBox(toString(theScholar.getRepair())));    
    theScholarSkills[8] = (TextBox(toString(theScholar.getScience())));    
    theScholarSkills[9] = (TextBox(toString(theScholar.getSneak())));
    theScholarSkills[10] = (TextBox(toString(theScholar.getSpeech())));    
    theScholarSkills[11] = (TextBox(toString(theScholar.getSurvival())));
    theScholarSkills[12] = (TextBox(toString(theScholar.getUnarmed())));    
    
    SDL_BlitSurface(imageWell, &activeRectDimensions, screen, &activeRectCoordinates);
    
    for (int i = scrollTop; i < scrollBottom; i++)
    {
        Skills[i].applyTextBox(screen, 100, 150, 0, 50, (i - scrollTop));
        theScholarSkills[i].applyTextBox(screen, 400, 150, 0, 50, (i - scrollTop));
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

void SkillsWindow::deactivateWindow()
{
    
}