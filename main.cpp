//
//  main.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 2/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//  Final project for CMPSC 122

#include <iostream>
#include <string>
#include <vector>
#include "ObjectLibrary.h"
#include "FunctionLibrary.h"
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"
#include "SDL_mixer/SDL_mixer.h"
#include "GenericWindow.h"
#include "MasterButtonWindow.h"
#include "GameWindow.h"
#include "StatsWindow.h"
#include "DataWindow.h"
#include "ItemsWindow.h"
#include "Location.h"
#include "Human.h"
#include "Container.h"

//Screen attributes
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;
const int SCREEN_BPP = 32;

//Zone* activeZone;

 //Consider creating a series of constants to define
 //the various sub-windows of the GameButton class
 
 //GameButton sub-windows
/*
const int ENTER_NAME = 0;
const int ENTER_SPECIAL = 1;
const int ENTER_TAG_SKILLS = 2;
const int GO_BACK = 3;
const int NAVIGATE = 4;
*/
/*
//#include "Weapon.h"
//#include "Creature.h"
#include "SuperMutant.h"
#include "Minigun.h"
 //Randomize weapons for entities just like you did with food!!!
 //Scale to player character by using switch statements for level of enemy, get level/10
 
 //Adjust values for guns!
*/

//TEST
//Global variables for extraction from other classes
/*
vector<IntelligentEntity*> enemyBattleTeam;

Container* activeContainer;
IntelligentEntity* activeVendor;
*/
using namespace std;

bool init(SDL_Surface *&screen)
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if(screen == NULL)
    {
        return false;
    }
    
    //Initialize SDL_mixer
    //(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)
    
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        return false;
    }
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }    
    
    //Set the window caption
    SDL_WM_SetCaption("Fallout: Penn State", NULL);
    
    //If everything initialized fine
    return true;
}

/*
 Will include sub-functions:
    setName
    setSPECIAL
    setTagSkills
 
    accepts the intelligent entity that will be the player character as argument
 */

//BEGIN TEST FUNCTION
bool graphicHandler(vector<MasterButtonWindow*>& gui, SDL_Surface*& screen, SDL_Event& event, IntelligentEntity& theScholar)
{
    
}
//END TEST FUNCTION

void initWorld(Location worldMap[][5], IntelligentEntity theScholar)
{
    worldMap[0][0].setName("Keller Buildling");
    worldMap[0][1].setName("Recreation Hall");
    worldMap[0][2].setName("IST Building");
    worldMap[0][3].setName("ZBT House");    
    worldMap[0][4].setName("Vault 115");
    
    worldMap[1][0].setName("Forum");
    worldMap[1][1].setName("Paterno Library");
    worldMap[1][2].setName("Fiji House");
    worldMap[1][3].setName("Willard Building");    
    worldMap[1][4].setName("Electrical Engineering Building");    
    
    worldMap[2][0].setName("North Halls");
    worldMap[2][1].setName("AEPI House");
    worldMap[2][2].setName("Osmond Lab");
    worldMap[2][3].setName("The HUB");    
    worldMap[2][4].setName("Schreyer Honors College");
    
    worldMap[3][0].setName("Business Building");
    worldMap[3][1].setName("Eisenhower Auditorium");
    worldMap[3][2].setName("Life Sciences Building");
    worldMap[3][3].setName("Pollock Halls");    
    worldMap[3][4].setName("South Halls");
    
    worldMap[4][0].setName("East Halls");
    worldMap[4][1].setName("Bryce Jordan Center");
    worldMap[4][2].setName("Nittany Apartments");
    worldMap[4][3].setName("Vault 122");    
    worldMap[4][4].setName("Eastview Terrace");
    
    worldMap[theScholar.getXCoordinate()][theScholar.getYCoordinate()].setIsActive(true);
}

Location getActiveLocationFromWorld(Location worldMap[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (worldMap[i][j].isIsActive() == true)
            {
                return worldMap[i][j];
            }
        }
    }
}

void refreshLocation(Location worldMap[][5], IntelligentEntity theScholar)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i == theScholar.getXCoordinate()) && (j == theScholar.getYCoordinate()))
            {
                worldMap[i][j].setIsActive(true);
            }
            else
            {
                worldMap[i][j].setIsActive(false);
            }
        }
    }
}

int main (int argc, char* args[])
{
    //Initializations
    SDL_Surface* screen = NULL;
    init(screen);
    
    SDL_Surface* pipBoy = IMG_Load("PipBoy2.png");
    bool quit = false;
    SDL_Event event;
    
    SDL_BlitSurface(pipBoy, NULL, screen, NULL);
    
    vector<MasterButtonWindow*> masterWindows;
    
    vector<IntelligentEntity*> scholarBattleTeam;
    vector<IntelligentEntity*> enemyBattleTeam;
    Container activeContainer;
    IntelligentEntity activeVendor = Brotherhood();
    
    /*
     WORKS!
    Human wastelander(WASTELANDER);
    
    wastelander.outSpecial();
    */
    masterWindows.push_back(new GameWindow);
    masterWindows.push_back(new StatsWindow);
    masterWindows.push_back(new DataWindow);
    masterWindows.push_back(new ItemsWindow);
    
    Location worldMap[5][5];
    
    //MasterButtonWindow* mainWindow;
    //GenericWindow* subWindow;
    
    
    IntelligentEntity theScholar;
    
    //int playerCreation = ENTER_SPECIAL;
    
    initWorld(worldMap, theScholar);
    
    //characterCreation(theScholar, dynamic_cast<GameWindow*>(masterWindows[0]), screen, event);    
    
    scholarBattleTeam.push_back(&theScholar);
    scholarBattleTeam.push_back(new Brotherhood);
    
    enemyBattleTeam.push_back(new SuperMutant);
    enemyBattleTeam.push_back(new SuperMutant);
    
    while (quit == false)
    {
        
        dynamic_cast<RadioWindow*>(masterWindows[2]->getSubWindow(4))->playStation();
        
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            
            for (int i = 0; i < masterWindows.size(); i++)
            {
                masterWindows[i]->manageEvent(event, theScholar);
                
                if (masterWindows[i]->isIsActive() == true)
                {
                    //mainWindow = masterWindows[i];
                    SDL_BlitSurface(pipBoy, NULL, screen, NULL);
                    masterWindows[i]->activateWindow(screen, theScholar);
                    //mainWindow->activateWindow(screen, theScholar); //Test line
                    //subWindow = mainWindow->getActiveSubWindow(); // Test line
                    
                    //if (masterWindows[i]->getSubWindowSize() == 5)
                    //if (mainWindow->getSubWindowSize() == 5)
                    //{
                    
                    if (masterWindows[i]->getIdentity() != GAME/*masterWindows[i]->getSubWindowSize() == 5*/)
                    {
                        masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                        //subWindow->activateWindow(screen, theScholar);
                        masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                    }
                    
                    else
                    {
                        dynamic_cast<GameWindow*>(masterWindows[i])->determineActiveSubWindow();
                        //BEGIN TEST CODE
                        switch (dynamic_cast<GameWindow*>(masterWindows[i])->getNextWindow())
                        {
                            case ENTER_NAME:
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);                                
                                
                                break;
                                
                            case ENTER_SPECIAL:
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                
                                break;
                                
                            case ENTER_TAG_SKILLS:
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                
                                break;
                                
                            case GO_BACK:
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                
                                break;                                
                                
                            case NAVIGATION:
                                
                                dynamic_cast<NavigationWindow*>(masterWindows[i]->getActiveSubWindow())->getCoordinates(worldMap);
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                
                                /*
                                if (dynamic_cast<GameSubWindow*>(masterWindows[i]->getActiveSubWindow())->getNextIdentity() == COMBAT)
                                {
                                    dynamic_cast<NavigationWindow*>(masterWindows[i]->getActiveSubWindow())->setEnemyBattleTeam(enemyBattleTeam);
                                }
                                */
                                refreshLocation(worldMap, theScholar);
                                
                                break;
                                
                            case COMBAT:
                                
                                //dynamic_cast<CombatWindow*>(masterWindows[i]->getActiveSubWindow())->cleanUp(scholarBattleTeam, enemyBattleTeam);                                
                                
                                dynamic_cast<CombatWindow*>(masterWindows[i]->getActiveSubWindow())->setTeams(scholarBattleTeam, enemyBattleTeam);
                                
                                //cout<<enemyBattleTeam.size();
                                
                                //dynamic_cast<CombatWindow*>(masterWindows[i]->getActiveSubWindow())->cleanUp();
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                
                                if (dynamic_cast<CombatWindow*>(masterWindows[i]->getActiveSubWindow())->getIsPlayerTurn() == true)
                                {
                                    masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                }
                                else
                                {
                                    dynamic_cast<CombatWindow*>(masterWindows[i]->getActiveSubWindow())->enemyTakeAction();
                                }
                                
                                //masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                
                                break;
                                
                            case STORAGE:
                                
                                //dynamic_cast<StorageWindow*>(masterWindows[i]->getActiveSubWindow())->setInventories(theScholar.getInventory(), activeContainer);
                                
                                dynamic_cast<StorageWindow*>(masterWindows[i]->getActiveSubWindow())->setInventories(theScholar, activeContainer);
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                
                                dynamic_cast<StorageWindow*>(masterWindows[i]->getActiveSubWindow())->resetInventories(theScholar, activeContainer);                                
                                
                                break;
                                
                            case BARTER:
                                
                                if (dynamic_cast<BarterWindow*>(masterWindows[i]->getActiveSubWindow())->getIsTradeInProgress() == false)
                                {
                                    dynamic_cast<BarterWindow*>(masterWindows[i]->getActiveSubWindow())->setInventories(theScholar, activeVendor);
                                }
                                else
                                {
                                    dynamic_cast<BarterWindow*>(masterWindows[i]->getActiveSubWindow())->scopeSet();                                    
                                }
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                
                                if (dynamic_cast<BarterWindow*>(masterWindows[i]->getActiveSubWindow())->getIsTradeConcluded() == true)
                                {
                                    dynamic_cast<BarterWindow*>(masterWindows[i]->getActiveSubWindow())->confirmTrade(theScholar, activeVendor);
                                }
                                
                                //dynamic_cast<BarterWindow*>(masterWindows[i]->getActiveSubWindow())->resetInventories(theScholar, activeVendor);
                                
                                break;
                                
                            case EXPLORE:
                                
                                //Tweak this line
                                /*
                                 Error that occurs
                                 
                                 FalloutPennState(12363,0x7fff79b6e960) malloc: *** mmap(size=140730450948096) failed (error code=12)
                                 *** error: can't allocate region
                                 *** set a breakpoint in malloc_error_break to debug
                                 FalloutPennState(12363,0x7fff79b6e960) malloc: *** error for object 0x103362a90: pointer being freed was not allocated
                                 *** set a breakpoint in malloc_error_break to debug                                 
                                 
                                 */
                                //dynamic_cast<ExploreWindow*>(masterWindows[i]->getActiveSubWindow())->setCurrentLocation(getActiveLocationFromWorld(worldMap));
                                
                                masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                                masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                                
                                //getActiveLocationFromWorld(worldMap) = dynamic_cast<ExploreWindow*>(masterWindows[i]->getActiveSubWindow())->resetCurrentLocation();
                                
                                break;
                                
                            default:
                                break;
                        }
                        //END TEST CODE
                        /*
                         Test remove
                        masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                        masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                        */
                        /*
                         //NAVIGATION
                        dynamic_cast<NavigationWindow*>(masterWindows[i]->getActiveSubWindow())->getCoordinates(worldMap);
                        
                        masterWindows[i]->getActiveSubWindow()->activateWindow(screen, theScholar);
                        masterWindows[i]->getActiveSubWindow()->manageEvent(event, theScholar);
                        
                        refreshLocation(worldMap, theScholar);
                         */
                    }
                }
            }
            /*
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
            {
                playerCreation = ENTER_TAG_SKILLS;
            }
             */
        }
        
        SDL_Flip(screen);
    }
    
    SDL_Quit();    
    
    /*
    //cout<<theScholar.getName();
    
    playerPlatoon.push_back(new Brotherhood);
    playerPlatoon.push_back(new SuperMutant);
    //playerPlatoon.push_back(new Brotherhood);
    //playerPlatoon.push_back(new Brotherhood);
    enemyPlatoon.push_back(new SuperMutant(1));
    enemyPlatoon.push_back(new SuperMutant(2));
    enemyPlatoon.push_back(new SuperMutant(3));
    
    battle(playerPlatoon, enemyPlatoon);
    
    system("pause");
    //quests will be int functions that return numbers based on outcome.
    //values of quest variables determine rewards for completion and actions and events that occur during final quest.
    //int quest1AnybodyHome = 0;
    //int quest2HereKittyKitty = 0;
    //int quest3OhBrotherhood = 0;
    //int quest4MovingToFiji = 0;
     */
    
    return 0;
}

