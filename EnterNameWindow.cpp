//
//  EnterNameWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 7/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "EnterNameWindow.h"

EnterNameWindow::EnterNameWindow()
{
    nameEntered = false;
    
    /*
     test remove
    isActive = true;
    */
    selfIdentity = ENTER_NAME;
    nextIdentity = selfIdentity;
}

EnterNameWindow::~EnterNameWindow()
{
    
}

void EnterNameWindow::manageEvent(SDL_Event event, IntelligentEntity& theScholar)
{
    string pcName;
    
    SDL_EnableUNICODE(SDL_ENABLE);
    //theScholar.setName(playerName.handle_input(event));
    pcName = playerName.handle_input(event);
    
    nameEntered = playerName.isNameEntered();
    
    //cout<<nameEntered<<endl;
    
    if (nameEntered == true)
    {
        theScholar.setName(pcName);
        SDL_EnableUNICODE(SDL_DISABLE);
        /*
         Test remove
         isActive = false;
        */
        //BEGIN TEST CODE
        nextIdentity = ENTER_SPECIAL;
        //END TEST CODE
    }
    /*
    else
    {
        isActive = true;
    }
    */
    /*
    if (event.key.keysym.sym == SDLK_RETURN)
    {
        theScholar.setName(pcName);
        
        SDL_EnableUNICODE(SDL_DISABLE);
        
        isActive = false;
    }
     */
}

void EnterNameWindow::activateWindow(SDL_Surface *screen, IntelligentEntity& theScholar)
{
    //BEGIN TEST CODE
    nextIdentity = selfIdentity;
    //END TEST CODE
    
    prompt.setCoordinates(540, 120);
    prompt.applyTextBox(screen);
    playerName.show_centered(screen, 540, 220);
}

void EnterNameWindow::deactivateWindow()
{
    
}