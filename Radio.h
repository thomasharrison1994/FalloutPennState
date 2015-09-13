//
//  Radio.h
//  Menu
//
//  Created by Tom Harrison on 6/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Menu_Radio_h
#define Menu_Radio_h

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_ttf/SDL_ttf.h"
#include "SDL_mixer/SDL_mixer.h"

using namespace std;

class Radio
{
private:
    //Whether radio is on or not
    int status;
    
    //DJ playlist
    //list<Mix_Music*> radioPlaylist;
    
    //DJ talking blurbs
    vector<Mix_Music*> introBlurbs;
    vector<Mix_Music*> newsIntros;
    vector<Mix_Music*> newsReports;
    vector<Mix_Music*> newsBumps;
    vector<Mix_Music*> musicBumps;
    
    //list<Mix_Music*>::iterator musicQueue;
    vector<Mix_Music*> radioPlaylist;
    
    //Vector counter
    int musicQueue;
    
    //Song counter (running count)
    int songCounter;
    
    //Song tracker (resets)
    int songTracker;
    
    //Determines volume
    bool isOn;
    
    //Random seed
    unsigned seed;
    
public:
    //Default constructor
    Radio();
    
    //Turn radio on/off
    //void offOn();
    
    //Play the radio songs
    void playSongs();
    
    //Talk interruption
    void talkBreak();
    
    void turnOffOn(bool volumeSwitch);
    
};

#endif
