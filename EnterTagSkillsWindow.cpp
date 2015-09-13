//
//  EnterTagSkillsWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 7/9/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "EnterTagSkillsWindow.h"

EnterTagSkillsWindow::EnterTagSkillsWindow()
{
    //isActive = true;
    isDone = false;
    
    selfIdentity = ENTER_TAG_SKILLS;
    nextIdentity = selfIdentity;
    
    for (int i = 0; i < 13; i++)
    {
        tagSwitches[i] = false;
    }
    
    tagsRemaining = 3;
    
    scrollTop = 0;
    scrollBottom = 7;
    
    activeRectDimensions.x = 240; //240
    activeRectDimensions.y = 670; //670
    activeRectDimensions.w = 275; //275
    activeRectDimensions.h = 45; //45
    
    activeRectCoordinates.x = 268; //268
    activeRectCoordinates.y = 566; //566
    
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
    
    completed = TextBox("Continue");
    
    completed.setCoordinates(950, 170); // 1000, 165
    
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 115; //10
    rectangleDimensions.w = 400; //465
    rectangleDimensions.h = 45;
    
    rectangleCoordinates.x = 530;
    rectangleCoordinates.y = 165;
    
    circleCoordinates.x = 1000;
    circleCoordinates.y = 400; //150
    
    squareCoordinates.x = 885; //890
    
    completedDimensions.x = 470;
    completedDimensions.y = 270;
    completedDimensions.w = 200;
    completedDimensions.h = 60;
    
    completedCoordinates.x = 935;
    completedCoordinates.y = 155;
    
    //DAM box modifications
    //statRectDataTypeDimensions[2].x = 475;
    //statRectDataTypeDimensions[2].w = 73;
}

EnterTagSkillsWindow::~EnterTagSkillsWindow()
{
    
}

void EnterTagSkillsWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        
        int onStat = ((((rectangleCoordinates.y - 15) / 50) - 3) + scrollTop);
        
        //if (isActive == true)
        //{
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                
                if (rectangleCoordinates.y != 165)
                {
                    rectangleCoordinates.y -= 50;
                }
                
                else if (scrollTop != 0)
                {
                    --scrollTop;
                    --scrollBottom;
                    
                    if (tagCoordinates.size() != 0)
                    {
                        for (int i = 0; i < tagCoordinates.size(); i++)
                        {
                            tagCoordinates[i].y += 50;
                        }
                    }                    
                }                    
                
                break;
                
            case SDLK_DOWN:
                
                if (rectangleCoordinates.y != 465)
                {
                    rectangleCoordinates.y += 50;
                }
                
                else if (scrollBottom != 13)
                {
                    ++scrollTop;
                    ++scrollBottom;
                    
                    if (tagCoordinates.size() != 0)
                    {
                        for (int i = 0; i < tagCoordinates.size(); i++)
                        {
                            tagCoordinates[i].y -= 50;
                        }
                    }
                }                    
                
                break;
                
            case SDLK_RIGHT:
                
                if (tagsRemaining == 0)
                {
                    isDone = true;
                }
                
                break;
                
            case SDLK_LEFT:
                
                isDone = false;
                
                break;
                
            case SDLK_RETURN:
                
                if (isDone == true)
                {
                    theScholar.setBarter(skillValues[0]);
                    theScholar.setEnergyWeapons(skillValues[1]);
                    theScholar.setExplosives(skillValues[2]);
                    theScholar.setGuns(skillValues[3]);
                    theScholar.setLockpick(skillValues[4]);
                    theScholar.setMedicine(skillValues[5]);
                    theScholar.setMeleeWeapons(skillValues[6]);
                    theScholar.setRepair(skillValues[7]);
                    theScholar.setScience(skillValues[8]);
                    theScholar.setSneak(skillValues[9]);
                    theScholar.setSpeech(skillValues[10]);
                    theScholar.setSurvival(skillValues[11]);
                    theScholar.setUnarmed(skillValues[12]);
                    
                    //BEGIN TEST CODE
                    nextIdentity = GO_BACK;
                    //END TEST CODE
                    
                    /*
                     Test remove
                    isActive = false;
                     */
                }
                
                else
                {
                    if (tagSwitches[onStat] == false)
                    {
                        if (tagsRemaining > 0)
                        {
                            tagSwitches[onStat] = true;
                            --tagsRemaining;
                            
                            squareCoordinates.y = rectangleCoordinates.y + 5;
                            tagCoordinates.push_back(squareCoordinates);
                        }
                    }
                    
                    else
                    {
                        tagSwitches[onStat] = false;
                        ++tagsRemaining;
                        
                        vector<SDL_Rect>::iterator deleter = tagCoordinates.begin();
                        
                        for (int i = 0; i < tagCoordinates.size(); i++)
                        {
                            if ((tagCoordinates[i].y - rectangleCoordinates.y) == 5)
                            {
                                tagCoordinates.erase(deleter);
                            }
                            
                            ++deleter;
                        }
                    }
                }
                
                break;
                
            default:
                ;
                
                break;
        }
        //}        
    }    
}

void EnterTagSkillsWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    //BEGIN TEST CODE
    nextIdentity = selfIdentity;
    //END TEST CODE    
    
    
    TextBox prompt("Tag 3 Skills:");
    TextBox pointsRemaining(toString(tagsRemaining), 72);
    
    prompt.setCoordinates(540, 120);
    pointsRemaining.setCoordinates(1035, 415);
    
    prompt.applyTextBox(screen);
    pointsRemaining.applyTextBox(screen);
    
    skillValues[0] = theScholar.tag(theScholar.getBarter(), tagSwitches[0]);
    skillValues[1] = theScholar.tag(theScholar.getEnergyWeapons(), tagSwitches[1]);
    skillValues[2] = theScholar.tag(theScholar.getExplosives(), tagSwitches[2]);
    skillValues[3] = theScholar.tag(theScholar.getGuns(), tagSwitches[3]);
    skillValues[4] = theScholar.tag(theScholar.getLockpick(), tagSwitches[4]);
    skillValues[5] = theScholar.tag(theScholar.getMedicine(), tagSwitches[5]);
    skillValues[6] = theScholar.tag(theScholar.getMeleeWeapons(), tagSwitches[6]);
    skillValues[7] = theScholar.tag(theScholar.getRepair(), tagSwitches[7]);
    skillValues[8] = theScholar.tag(theScholar.getScience(), tagSwitches[8]);
    skillValues[9] = theScholar.tag(theScholar.getSneak(), tagSwitches[9]);
    skillValues[10] = theScholar.tag(theScholar.getSpeech(), tagSwitches[10]);
    skillValues[11] = theScholar.tag(theScholar.getSurvival(), tagSwitches[11]);
    skillValues[12] = theScholar.tag(theScholar.getUnarmed(), tagSwitches[12]);
    
    /*
     Do this when the person is completely done
     
    theScholar.setBarter(skillValues[0]);
    theScholar.setEnergyWeapons(skillValues[1]);
    theScholar.setExplosives(skillValues[2]);
    theScholar.setGuns(skillValues[3]);
    theScholar.setLockpick(skillValues[4]);
    theScholar.setMedicine(skillValues[5]);
    theScholar.setMeleeWeapons(skillValues[6]);
    theScholar.setRepair(skillValues[7]);
    theScholar.setScience(skillValues[8]);
    theScholar.setSneak(skillValues[9]);
    theScholar.setSpeech(skillValues[10]);
    theScholar.setSurvival(skillValues[11]);
    theScholar.setUnarmed(skillValues[12]);
     */
    
    //SDL_BlitSurface(imageWell, &activeRectDimensions, screen, &activeRectCoordinates);
    
    for (int i = scrollTop; i < scrollBottom; i++)
    {
        Skills[i].applyTextBox(screen, 540, 170, 0, 50, (i - scrollTop));
        skillValueGraphics[i] = TextBox(toString(skillValues[i]));
        skillValueGraphics[i].applyTextBox(screen, 840, 170, 0, 50, (i - scrollTop));
    }
    
    if (tagCoordinates.size() != 0)
    {
        for (int i = 0; i < tagCoordinates.size(); i++)
        {
            if (tagCoordinates[i].y >= 170 && tagCoordinates[i].y <= 470)
            {
                SDL_BlitSurface(rectangles, &squareDimensions, screen, &tagCoordinates[i]);
            }
        }
    }
    
    /*
    for (int i = 0; i < 7; i++)
    {
        SPECIALS[i].applyTextBox(screen, 540, 170, 0, 50, i);
        SPECIALValueGraphics[i] = TextBox(toString(SPECIALValues[i]));
        SPECIALValueGraphics[i].applyTextBox(screen, 840, 170, 0, 50, i);
    }
     */
    
    SDL_BlitSurface(rectangles, &circleDimensions, screen, &circleCoordinates);    
    //SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
    
    completed.applyTextBox(screen);
    //SDL_BlitSurface(rectangles, &completedDimensions, screen, &completedCoordinates);
    
    if (isDone == true)
    {
        SDL_BlitSurface(rectangles, &completedDimensions, screen, &completedCoordinates);
    }
    else
    {
        SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
    }
    
    /*
     for (int i = 0; i < 3; i++)
     {
     //SDL_BlitSurface(imageWell, &statRectDimensions, screen, &statRectCoordinates[i]);
     //SDL_BlitSurface(imageWell, &statRectDataTypeDimensions[i], screen, &statRectDataTypeCoordinates[i]);
     }
     */
    //SDL_BlitSurface(imageWell, &descriptionLineDimensions, screen, &descriptionLineCoordinates);
    
    
    
}

void EnterTagSkillsWindow::deactivateWindow()
{
    
}