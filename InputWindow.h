//
//  InputWindow.h
//  Menu
//
//  Created by Tom Harrison on 6/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Menu_InputWindow_h
#define Menu_InputWindow_h


#pragma once

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"
#include "SDL_mixer/SDL_mixer.h"

using namespace std;

class InputWindow
{
private:
    //storage string
    string inputString;
    
    //The text surface
    SDL_Surface *text;
    
    //Text font
    TTF_Font *textFont;
    
    //Text color
    SDL_Color textColor;
    
    //Horizontal menu ID number
    int horizontalID;
    
    bool nameEntered;
    
public:
    //Initializes variables
    InputWindow();
    
    //Constructor for passing in strings
    InputWindow(string myString, int ID);
    
    //Does clean up
    ~InputWindow();
    
    //Determines whether the name was entered or not
    bool isNameEntered();
    
    //Handles input
    //was void
    string handle_input(SDL_Event event);
    
    //Shows the message on screen
    void show_centered(SDL_Surface* pasteTo);
    
    //Shows message on screen at designated coordinates
    void show_centered(SDL_Surface* pasteTo, int x, int y);
    
    //Shows the message on screen
    void show_centered(SDL_Surface* pasteTo, int yBuffer);    
    
    //Returns horizontal ID
    int getID();
};

#endif
