//
//  TextBox.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_TextBox_h
#define MenuEfficient_TextBox_h

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"
#include "SDL_mixer/SDL_mixer.h"

using namespace std;

class TextBox
{
private:
    //Where to place the text box
    int textBoxXCoordinate;
    int textBoxYCoordinate;
    
    //storage string
    string textBoxText;
    
    //The text box surface
    SDL_Surface *textBoxSurface;
    
    //The text box font
    TTF_Font *textBoxFont;
    
    //The text box color
    SDL_Color textBoxColor;
    
public:
    
    /*
     Parameter list:
     x coordinate
     y coordinate
     text to be displayed
     the size of the font
     red value for font color
     blue value for font color
     green value for font color
     */    
    
    //Default constructor
    TextBox();
    
    //Init constructor
    TextBox(string text);
    
    //Init constructor
    TextBox(string text, int fontSize);
    
    //Init position constructor
    TextBox(int x, int y, string text, int fontSize, int red, int blue, int green);
    
    //Destructor
    ~TextBox();
    
    //Function to set coordinates of the text box
    void setCoordinates(int x, int y);
    
    //Function to display the window's text box
    void applyTextBox(SDL_Surface* textBoxDestination);
    
    //Overloaded function
    void applyTextBox(SDL_Surface* textBoxDestination, int xSpot, int ySpot);
    
    //Optimized previous function for displaying lists
    void applyTextBox(SDL_Surface* textBoxDestination, int xScale, int yScale, int listPosition);
    
    //For scaling lists within unknown or no initial coordinates
    void applyTextBox(SDL_Surface* textBoxDestination, int xSpot, int ySpot, int xScale, int yScale, int listPosition);
    
    //Function to set text of TextBox
    void setText(string inputText);
};

#endif
