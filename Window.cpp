//
//  Window.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/14/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "Window.h"

Window::Window()
{
    windowXCoordinate = 0;
    windowYCoordinate = 0;
    
    windowWidth = 110;
    windowHeight = 75;
    
    screens.push_back(new Screen);
    textBoxes.push_back(new TextBox);
    
    navScreens = 0;
    navTextBoxes = 0;
    
    activeScreen = screens[navScreens];
    activeTextBox = textBoxes[navTextBoxes];
}

Window::Window(int x, int y, int w, int h, Screen* myScreen, TextBox* myTextBox)
{
    windowXCoordinate = x;
    windowYCoordinate = y;
    
    windowWidth = w;
    windowHeight = h;
    
    screens.push_back(myScreen);
    textBoxes.push_back(myTextBox);
    
    navScreens = 0;
    navTextBoxes = 0;
    
    activeScreen = screens[navScreens];
    activeTextBox = textBoxes[navTextBoxes];
}

Window::Window(int x, int y, int w, int h, vector<TextBox*> myTextBoxes)
{
    windowXCoordinate = x;
    windowYCoordinate = y;
    
    windowWidth = w;
    windowHeight = h;
    
    textBoxes = myTextBoxes;
    
    navScreens = 0;
    navTextBoxes = 0;
    
    activeTextBox = textBoxes[navTextBoxes];    
}

Window::Window(int x, int y, int w, int h, vector<Screen*> myScreens)
{
    windowXCoordinate = x;
    windowYCoordinate = y;
    
    windowWidth = w;
    windowHeight = h;
    
    screens = myScreens;
    
    navScreens = 0;
    navTextBoxes = 0;
    
    activeScreen = screens[navScreens];
}

Window::Window(int x, int y, int w, int h, vector<Screen*> myScreens, vector<TextBox*> myTextBoxes)
{
    windowXCoordinate = x;
    windowYCoordinate = y;
    
    windowWidth = w;
    windowHeight = h;
    
    screens = myScreens;
    textBoxes = myTextBoxes;
    
    navScreens = 0;
    navTextBoxes = 0;
    
    activeScreen = screens[navScreens];
    activeTextBox = textBoxes[navTextBoxes];    
}

void Window::applyWindow(SDL_Surface *windowDestination)
{
    if (screens.empty() == false)
    {
        for (int i = 0; i < screens.size(); i++)
        {
            screens[i]->applyScreen(windowDestination);
        }
    }
    
    if (textBoxes.empty() == false)
    {
        for (int i = 0; i < textBoxes.size(); i++)
        {
            textBoxes[i]->applyTextBox(windowDestination);
        }
    }
}

void Window::applyTextList(SDL_Surface *windowDestination, bool isVertical, int listSpacing, int x, int y)
{
    int xScale;
    int yScale;
    
    if (isVertical == true)
    {
        xScale = 0;
        yScale = listSpacing;
    }
    else
    {
        xScale = listSpacing;
        yScale = 0;
    }
    
    for (int i = 0; i < textBoxes.size(); i++)
    {
        textBoxes[i]->setCoordinates((x + xScale*i), (y + yScale*i));
        textBoxes[i]->applyTextBox(windowDestination);
    }
}