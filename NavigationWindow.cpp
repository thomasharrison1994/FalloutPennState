//
//  NavigationWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 7/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "NavigationWindow.h"
#include "SuperMutant.h"

// 0 = WEST
// 1 = EAST
// 2 = NORTH
// 3 = SOUTH

NavigationWindow::NavigationWindow()
{
    //isActive = true;
    
    selfIdentity = NAVIGATION;
    nextIdentity = selfIdentity;
    
    scrollTop = 0;
    scrollBottom = 7;
    
    scrollSupplement = 0;
    
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 465;
    rectangleDimensions.h = 45;
    
    rectangleCoordinates.x = 530;
    rectangleCoordinates.y = 165;
    
    choiceType[1] = TextBox("NorthWest");
    choiceType[2] = TextBox("North");
    choiceType[3] = TextBox("NorthEast");
    choiceType[4] = TextBox("East");
    choiceType[5] = TextBox("SouthEast");
    choiceType[6] = TextBox("South");    
    choiceType[7] = TextBox("SouthWest");
    choiceType[8] = TextBox("West");
}

NavigationWindow::~NavigationWindow()
{
    
}

void NavigationWindow::getCoordinates(Location worldMap[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (worldMap[i][j].isIsActive() == true)
            {
                currentX = i;
                currentY = j;
                
                choiceType[0] = TextBox("Explore " + worldMap[i][j].getName());
                
                if (currentX == 0)
                {
                    bounded[WEST] = true;
                }
                else
                {
                    bounded[WEST] = false;
                }
                
                if (currentX == 4)
                {
                    bounded[EAST] = true;
                }
                else
                {
                    bounded[EAST] = false;
                }                
                
                if (currentY == 0)
                {
                    bounded[NORTH] = true;
                }
                else
                {
                    bounded[NORTH] = false;
                }
                
                if (currentY == 4)
                {
                    bounded[SOUTH] = true;
                }
                else
                {
                    bounded[SOUTH] = false;
                }               
            }
        }
    }
    
    setList();
}

void NavigationWindow::setList()
{
    numChoices = 8;
    
    if (choiceList.size() != 0)
    {
        choiceList.clear();
    }
    
    if (directionList.size() != 0)
    {
        directionList.clear();
    }
    
    choiceList.push_back(choiceType[0]);
    directionList.push_back(dEXPLORE);
    
    //Checks north
    if (bounded[NORTH] == false)
    {
        choiceList.push_back(choiceType[2]);
        directionList.push_back(dNORTH);
        
        //Checks northeast
        if (bounded[EAST] == false)
        {
            choiceList.push_back(choiceType[3]);
            directionList.push_back(dNORTHEAST);
        }
        else
        {
            --numChoices;
        }
    }
    else
    {
        --numChoices;
    }
    
    //Checks east
    if (bounded[EAST] == false)
    {
        choiceList.push_back(choiceType[4]);
        directionList.push_back(dEAST);
        
        //Checks southeast
        if (bounded[SOUTH] == false)
        {
            choiceList.push_back(choiceType[5]);
            directionList.push_back(dSOUTHEAST);
        }
        else
        {
            --numChoices;
        }
    }
    else
    {
        --numChoices;
    }
    
    //Checks south
    if (bounded[SOUTH] == false)
    {
        choiceList.push_back(choiceType[6]);
        directionList.push_back(dSOUTH);
        
        //Checks southwest
        if (bounded[WEST] == false)
        {
            choiceList.push_back(choiceType[7]);
            directionList.push_back(dSOUTHWEST);
        }
        else
        {
            --numChoices;
        }
    }
    else
    {
        --numChoices;
    }
    
    //Checks west
    if (bounded[WEST] == false)
    {
        choiceList.push_back(choiceType[8]);
        directionList.push_back(dWEST);
        
        //Checks northwest
        if (bounded[NORTH] == false)
        {
            choiceList.push_back(choiceType[1]);
            directionList.push_back(dNORTHWEST);
        }
        else
        {
            --numChoices;
        }
    }
    else
    {
        --numChoices;
    }
    
    //cout<<numChoices<<endl;
}

void NavigationWindow::setEnemyBattleTeam(vector<IntelligentEntity*>& enemyTeam)
{
    enemyTeam.clear();
    
    enemyTeam.push_back(new SuperMutant);
    enemyTeam.push_back(new SuperMutant);
}

void NavigationWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    if(event.type == SDL_KEYDOWN)
    {
        int onStat = (((rectangleCoordinates.y - 15) / 50) - 3);
        
        int listLength;
        
        if (choiceList.size() < 7)
        {
            listLength = (((choiceList.size() + 2) * 50) + 15);
        }
        else
        {
            listLength = 465;
        }
        
        //cout<<listLength<<endl;        
        
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                
                if (rectangleCoordinates.y != 165)
                {
                    rectangleCoordinates.y -= 50;
                }
                
                else if (scrollTop != 0 && (listLength == 465))
                {
                    --scrollTop;
                    --scrollBottom;
                    //TEST
                    --scrollSupplement;
                    //--onStat;
                }                
                
                break;
                
            case SDLK_DOWN:
                
                if (rectangleCoordinates.y != listLength)
                {
                    rectangleCoordinates.y += 50;
                }
                
                else if (scrollBottom != choiceList.size()/*13*/ && (listLength == 465))
                {
                    ++scrollTop;
                    ++scrollBottom;
                    //TEST
                    ++scrollSupplement;
                    //++onStat;
                }
                
                break;
                
            case SDLK_RIGHT:
                
                break;
                
            case SDLK_LEFT:
                
                break;
                
            case SDLK_RETURN:
                
                onStat+=scrollSupplement;
                
                switch (directionList[onStat])
                {
                    case dEXPLORE:
                        
                        //nextIdentity = COMBAT;
                        //nextIdentity = STORAGE;
                        nextIdentity = BARTER;
                        //nextIdentity = EXPLORE;
                        
                        break;
                        
                    case dNORTH:
                        
                        --currentY;
                        
                        break;
                        
                    case dNORTHEAST:
                        
                        ++currentX;
                        --currentY;
                        
                        break;
                        
                    case dNORTHWEST:
                        
                        --currentX;
                        --currentY;
                        
                        break;
                        
                    case dEAST:
                        
                        ++currentX;
                        
                        break;
                        
                    case dSOUTHEAST:
                        
                        ++currentX;
                        ++currentY;
                        
                        break;
                        
                    case dSOUTH:
                        
                        ++currentY;
                        
                        break;
                        
                    case dSOUTHWEST:
                        
                        --currentX;
                        ++currentY;
                        
                        break;
                        
                    case dWEST:
                        
                        --currentX;
                        
                        break;
                        
                    default:
                        
                        break;
                }
                
                theScholar.setXCoordinate(currentX);
                theScholar.setYCoordinate(currentY);
                
                //TEST
                rectangleCoordinates.y = 165;
                scrollSupplement = 0;
                scrollTop = 0;
                scrollBottom = 7;
                
                break;
                
            default:
                ;
                
                break;
        }
    }
}

void NavigationWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    //BEGIN TEST CODE
    nextIdentity = selfIdentity;
    //END TEST CODE    
    
    if (numChoices > 6)
    {
        for (int i = scrollTop; i < scrollBottom; i++)
        {
            choiceList[i].applyTextBox(screen, 540, 170, 0, 50, (i-scrollTop));
        }
    }
    else
    {
        for (int i = 0; i < choiceList.size(); i++)
        {
            choiceList[i].applyTextBox(screen, 540, 170, 0, 50, i);
        }
    }
    
    /*
    for (int i = 0; i < choiceList.size(); i++)
    {
        choiceList[i].applyTextBox(screen, 540, 170, 0, 50, (i-scrollTop));
    }
    */
    SDL_BlitSurface(rectangles, &rectangleDimensions, screen, &rectangleCoordinates);
}

void NavigationWindow::deactivateWindow()
{
    
}