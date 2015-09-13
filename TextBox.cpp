//
//  TextBox.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "TextBox.h"

TextBox::TextBox()
{
    textBoxXCoordinate = 300;
    textBoxYCoordinate = 375;
    
    textBoxText = "Enter your name:";
    
    textBoxFont = TTF_OpenFont("Courier New.ttf", 32);
    
    textBoxColor.r = 130;
    textBoxColor.g = 250;
    textBoxColor.b = 88;
    
    //Enable Unicode
    SDL_EnableUNICODE(SDL_ENABLE);    
    
    textBoxSurface = TTF_RenderText_Solid(textBoxFont, textBoxText.c_str(), textBoxColor);
}

TextBox::TextBox(string text)
{
    
    //textBoxXCoordinate = 100;
    //textBoxYCoordinate = 100;
    
    textBoxText = text;
    
    textBoxFont = TTF_OpenFont("Courier New.ttf", 32);
    
    textBoxColor.r = 130;
    textBoxColor.g = 250;
    textBoxColor.b = 88;
    
    //Enable Unicode
    SDL_EnableUNICODE(SDL_ENABLE);
    
    textBoxSurface = TTF_RenderText_Solid(textBoxFont, textBoxText.c_str(), textBoxColor);    
}

TextBox::TextBox(string text, int fontSize)
{
    textBoxText = text;
    
    textBoxFont = TTF_OpenFont("Courier New.ttf", fontSize);
    
    textBoxColor.r = 130;
    textBoxColor.g = 250;
    textBoxColor.b = 88;
    
    //Enable Unicode
    SDL_EnableUNICODE(SDL_ENABLE);    
    
    textBoxSurface = TTF_RenderText_Solid(textBoxFont, textBoxText.c_str(), textBoxColor);    
}

TextBox::TextBox(int x, int y, string text, int fontSize, int red, int blue, int green)
{
    textBoxXCoordinate = x;
    textBoxYCoordinate = y;
    
    textBoxText = text;
    
    textBoxFont = TTF_OpenFont("Courier New.ttf", fontSize);
    
    textBoxColor.r = red;
    textBoxColor.g = blue;
    textBoxColor.b = green;
    
    //Enable Unicode
    SDL_EnableUNICODE(SDL_ENABLE);    
    
    textBoxSurface = TTF_RenderText_Solid(textBoxFont, textBoxText.c_str(), textBoxColor);
}

TextBox::~TextBox()
{
    //Free text surface
    //SDL_FreeSurface(textBoxSurface);
    
    //Disable Unicode
    SDL_EnableUNICODE(SDL_DISABLE);
}

void TextBox::setCoordinates(int x, int y)
{
    textBoxXCoordinate = x;
    textBoxYCoordinate = y;
}

void TextBox::applyTextBox(SDL_Surface *textBoxDestination)
{
    SDL_Rect coordinates;
    
    coordinates.x = textBoxXCoordinate;
    coordinates.y = textBoxYCoordinate;
    
    SDL_BlitSurface(textBoxSurface, NULL, textBoxDestination, &coordinates);
}

void TextBox::applyTextBox(SDL_Surface* textBoxDestination, int xSpot, int ySpot)
{
    setCoordinates(xSpot, ySpot);
    
    SDL_Rect coordinates;
    
    coordinates.x = textBoxXCoordinate;
    coordinates.y = textBoxYCoordinate;
    
    SDL_BlitSurface(textBoxSurface, NULL, textBoxDestination, &coordinates);    
    
}

void TextBox::applyTextBox(SDL_Surface* textBoxDestination, int xScale, int yScale, int listPosition)
{
    SDL_Rect coordinates;
    
    coordinates.x = textBoxXCoordinate + (xScale*listPosition);
    coordinates.y = textBoxYCoordinate + (yScale*listPosition);
    
    SDL_BlitSurface(textBoxSurface, NULL, textBoxDestination, &coordinates);
}

void TextBox::applyTextBox(SDL_Surface* textBoxDestination, int xSpot, int ySpot, int xScale, int yScale, int listPosition)
{
    setCoordinates(xSpot, ySpot);
    
    SDL_Rect coordinates;
    
    coordinates.x = textBoxXCoordinate + (xScale*listPosition);
    coordinates.y = textBoxYCoordinate + (yScale*listPosition);
    
    SDL_BlitSurface(textBoxSurface, NULL, textBoxDestination, &coordinates);    
}

void TextBox::setText(string inputText)
{
    textBoxText = inputText;
}