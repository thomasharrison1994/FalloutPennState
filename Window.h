//
//  Window.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/14/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_Window_h
#define MenuEfficient_Window_h

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"
#include "SDL_mixer/SDL_mixer.h"
#include "Screen.h"
#include "TextBox.h"

using namespace std;

class Window
{
private:
    //Where to place the window
    int windowXCoordinate;
    int windowYCoordinate;
    
    //Dimensions of the window
    int windowWidth;
    int windowHeight;
    
    //Curently active window screens
    Screen* activeScreen;
    
    //List of screens for this window
    vector<Screen*> screens;
    
    //To navigate the vector of screens
    int navScreens;
    
    //Currently active text box
    TextBox* activeTextBox;
    
    //List of text boxes for this window
    vector<TextBox*> textBoxes;
    
    //To navigate the vector of text boxes
    int navTextBoxes;
    
public:
    /*
     Parameter list:
     x coordinate
     y coordinate
     width
     height
     the window's screen
     the text box
     */    
    
    //Default constructor
    Window();
    
    //Init for 1 screen and 1 text box
    Window(int x, int y, int w, int h, Screen* myScreen, TextBox* myTextBox);
    
    //Init for multiple text boxes
    Window(int x, int y, int w, int h, vector<TextBox*> myTextBoxes);
    
    //Init for multiple screens
    Window(int x, int y, int w, int h, vector<Screen*> myScreens);
    
    //Init for multiple screens and text boxes
    Window(int x, int y, int w, int h, vector<Screen*> myScreens, vector<TextBox*> myTextBoxes);
    
    //Display the window and it's properties
    void applyWindow(SDL_Surface* windowDestination);
    
    //Display list either vertically or horizontally
    void applyTextList(SDL_Surface* windowDestination, bool isVertical, int listSpacing, int x, int y);
};

#endif
