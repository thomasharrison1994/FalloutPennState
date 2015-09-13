//
//  Screen.h
//  MenuEfficient
//
//  Created by Tom Harrison on 6/15/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MenuEfficient_Screen_h
#define MenuEfficient_Screen_h

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"
#include "SDL_mixer/SDL_mixer.h"

using namespace std;

class Screen
{
private:
    //Where to place the window screen
    int screenXCoordinate;
    int screenYCoordinate;
    
    //Dimensions of the window screen
    int screenWidth;
    int screenHeight;
    
    //Origin coordinates of the clip
    int screenClipXCoordinate;
    int screenClipYCoordinate;
    
    //Dimensions of the clip
    int screenClipWidth;
    int screenClipHeight;
    
    //Image file for the window screen
    SDL_Surface* screenImage;
    
    //Clip dimensions of the image to be used
    SDL_Rect screenImageClip;
    
    //Dimensions of the actual screen
    SDL_Rect screenDimensions;
    
public:
    //Default constructor
    Screen();
    
    //Init constructor
    /*
     Parameter list:
     x coordinate
     y coordinate
     width
     height
     the image to be used
     */        
    Screen(int x, int y, int w, int h, SDL_Surface* surface, SDL_Rect myClip);
    
    //Function to display the window's screen
    void applyScreen(SDL_Surface* screenDestination);
};

#endif
