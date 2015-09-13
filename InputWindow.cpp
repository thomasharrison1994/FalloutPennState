//
//  InputWindow.cpp
//  Menu
//
//  Created by Tom Harrison on 6/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "InputWindow.h"

InputWindow::InputWindow()
{
    //Initialize the string
    inputString = "The Scholar";
    
    //Initialize the surface
    text = NULL;
    
    //Intialize text font
    textFont = TTF_OpenFont("Courier New.ttf", 32);
    
    //Initialize text color
    textColor.r = 130;
    textColor.g = 250;
    textColor.b = 88;
    
    //Enable Unicode
    SDL_EnableUNICODE(SDL_ENABLE);
    
    //Delete later
    text = TTF_RenderText_Solid(textFont, inputString.c_str(), textColor); 
    
    nameEntered = false;
}

InputWindow::InputWindow(string myString, int ID)
{
    //Initialize the string
    inputString = myString;
    
    horizontalID = ID;
    
    //Intialize text font
    textFont = TTF_OpenFont("Courier New.ttf", 32);
    
    //Initialize text color
    textColor.r = 130;
    textColor.g = 250;
    textColor.b = 88;
    
    //Enable Unicode
    SDL_EnableUNICODE(SDL_ENABLE);
    
    //Initialize the surface
    text = TTF_RenderText_Solid(textFont, inputString.c_str(), textColor);
    
    nameEntered = false;
}

InputWindow::~InputWindow()
{
    //Free text surface
    //SDL_FreeSurface(text);
    
    //Disable Unicode
    SDL_EnableUNICODE(SDL_DISABLE);
}

bool InputWindow::isNameEntered()
{
    return nameEntered;
}

string InputWindow::handle_input(SDL_Event event)
{
    nameEntered = false;
    
    //If a key was pressed
    if (event.type == SDL_KEYDOWN)
    {
        //nameEntered = false;
        
        //Testing cast of keys to char data type in if statement
        //LEAVE ALONE IN inputString += !!!
        
        //Keep a copy of the current version of the string
        string temp = inputString;
        
        //If the string less than maximum size
        if (inputString.length() <= 32)
        {
            //If the key is a space
            if (event.key.keysym.unicode == (Uint16)' ')
            {
                //Append the character
                inputString += (char)event.key.keysym.unicode;
            }
            
            //If the key is a number
            else if((event.key.keysym.unicode >= (Uint16) '0' ) && (event.key.keysym.unicode <= (Uint16)'9'))
            {
                //Append the character
                inputString += (char)event.key.keysym.unicode;
            }
            
            //If the key is an uppercase letter
            else if((event.key.keysym.unicode >= (Uint16) 'A' ) && (event.key.keysym.unicode <= (Uint16)'Z'))
            {
                //Append the character
                inputString += (char)event.key.keysym.unicode;
            }            
            
            //If the key is a lowercase letter
            else if((event.key.keysym.unicode >= (Uint16) 'a' ) && (event.key.keysym.unicode <= (Uint16)'z'))
            {
                //Append the character
                inputString += (char)event.key.keysym.unicode;
            }
        }
        
        //If backspace was pressed and the string isn't blank
        if ((event.key.keysym.sym == SDLK_BACKSPACE) && (inputString.length() != 0)) 
        {
            //nameEntered = false;
            
            //Remove a character from the end
            inputString.erase(inputString.length() - 1);
        }
        /*
        else if(event.key.keysym.sym == SDLK_RETURN)
        {
            //nameEntered = true;
        }        
        */
        //If the string was changed
        if (inputString != temp)
        {
            //nameEntered = false;
            
            //Free the old surface
            SDL_FreeSurface(text);
            
            //Render a new text surface
            text = TTF_RenderText_Solid(textFont, inputString.c_str(), textColor);
        }
        
        
        if (event.key.keysym.sym == SDLK_RETURN)
        {
            nameEntered = true;
        }
        else
        {
            nameEntered = false;
        }
    }
    
    return inputString;
}

void InputWindow::show_centered(SDL_Surface* pasteTo)
{
    //If the surface isn't blank
    if (text != NULL)
    {
        //Show the name
        //Holds offsets
        SDL_Rect offset;
        
        //Get offsets
        offset.x = 100;
        offset.y = 85;
        
        //Blit
        SDL_BlitSurface(text, NULL, pasteTo, &offset);        
        
    }
}

void InputWindow::show_centered(SDL_Surface* pasteTo, int x, int y)
{
    //If the surface isn't blank
    if (text != NULL)
    {
        //Show the name
        //Holds offsets
        SDL_Rect offset;
        
        //Get offsets
        offset.x = x;
        offset.y = y;
        
        //Blit
        SDL_BlitSurface( text, NULL, pasteTo, &offset );        
        
    }    
}

//Good yBuffer value is factor of 50
void InputWindow::show_centered(SDL_Surface* pasteTo, int yBuffer)
{
    //If the surface isn't blank
    if (text != NULL)
    {
        //Show the name
        //Holds offsets
        SDL_Rect offset;
        
        //Get offsets
        offset.x = 100;
        offset.y = 85 + yBuffer;
        
        //Blit
        SDL_BlitSurface( text, NULL, pasteTo, &offset );        
        
    }
}

int InputWindow::getID()
{
    return horizontalID;
}