//
//  Radio.cpp
//  Menu
//
//  Created by Tom Harrison on 6/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "Radio.h"

Radio::Radio()
{
    status = 1;
    
    musicQueue = 0;
    
    songCounter = 3;
    songTracker = 0;
    
    seed = time(0);
    
    srand(seed);
    
    /*
     Song Pattern
     
        Instrumental
        UpBeat
        Slow
        Classic
     
     */
    radioPlaylist.push_back(Mix_LoadMUS("Night in Tunisia.wav")); //Instrumental
    radioPlaylist.push_back(Mix_LoadMUS("Get Happy.wav")); //UpBeat
    radioPlaylist.push_back(Mix_LoadMUS("Java Jive.wav")); //Slow
    radioPlaylist.push_back(Mix_LoadMUS("Anything Goes.wav")); //Classic
    radioPlaylist.push_back(Mix_LoadMUS("Minor's Holiday.wav")); //Instrumental
    radioPlaylist.push_back(Mix_LoadMUS("Fly Me To The Moon.wav")); //UpBeat
    radioPlaylist.push_back(Mix_LoadMUS("We'll Meet Again.wav")); //Slow
    radioPlaylist.push_back(Mix_LoadMUS("Something's Gotta Give.wav")); //Classic
    radioPlaylist.push_back(Mix_LoadMUS("Sing, Sing, Sing.wav")); //Instrumental
    radioPlaylist.push_back(Mix_LoadMUS("Boogie Woogie Bugle Boy.wav")); //UpBeat
    radioPlaylist.push_back(Mix_LoadMUS("What A Wonderful World.wav")); //Slow
    radioPlaylist.push_back(Mix_LoadMUS("Lets Go Sunning.wav")); //Classic
    radioPlaylist.push_back(Mix_LoadMUS("In the Mood.wav")); //Instrumental
    radioPlaylist.push_back(Mix_LoadMUS("Daddy Won't You Please Come Home.wav")); //UpBeat
    radioPlaylist.push_back(Mix_LoadMUS("I'll Be Seeing You.wav")); //Slow
    radioPlaylist.push_back(Mix_LoadMUS("Ain't That A Kick In the Head.wav")); //Classic
    radioPlaylist.push_back(Mix_LoadMUS("Moanin'.wav")); //Instrumental
    radioPlaylist.push_back(Mix_LoadMUS("Mr Sandman.wav")); //UpBeat
    radioPlaylist.push_back(Mix_LoadMUS("Too Young.wav")); //Slow
    radioPlaylist.push_back(Mix_LoadMUS("Civilization.wav")); //Classic
    radioPlaylist.push_back(Mix_LoadMUS("Jubilee Stomp.wav")); //Instrumental
    radioPlaylist.push_back(Mix_LoadMUS("Big Noise Blew In From Winnetka.wav")); //UpBeat
    radioPlaylist.push_back(Mix_LoadMUS("Misty.wav")); //Slow
    radioPlaylist.push_back(Mix_LoadMUS("Jingle Jangle Jingle.wav")); //Classic
    
    introBlurbs.push_back(Mix_LoadMUS("IntroA.wav"));
    
    //musicQueue = radioPlaylist.begin();
}
/*
void Radio::offOn()
{
    
}
*/

void Radio::playSongs()
{
    if (Mix_PlayingMusic() == false)
    {
        if (songCounter % 3 == 0)
        {
            talkBreak();
        }
        
        else
        {
            Mix_PlayMusic(radioPlaylist[musicQueue], 0);
            ++musicQueue;
        }
        /*
        Mix_PlayMusic(radioPlaylist[musicQueue], 0);
        ++musicQueue;*/
        /*
        if (isOn == false)
        {
            Mix_VolumeMusic(0);
        }
        else
        {
            Mix_VolumeMusic(MIX_MAX_VOLUME);
        }
         */
        
        if (musicQueue == radioPlaylist.size())
        {
            musicQueue = 0;
        }
        
        ++songCounter;
        ++songTracker;
        
        if (songTracker == 25)
        {
            songTracker = 0;
        }
    }
}

void Radio::talkBreak()
{
    Mix_PlayMusic(introBlurbs[rand() % introBlurbs.size()], 0);
    /*Mix_PlayMusic(newsIntros[rand() % newsIntros.size()], 0);
    Mix_PlayMusic(newsReports[rand() % newsReports.size()], 0);
    Mix_PlayMusic(newsBumps[rand() % newsBumps.size()], 0);
    Mix_PlayMusic(newsReports[rand() % newsReports.size()], 0);
    Mix_PlayMusic(musicBumps[songTracker], 0);*/
}

void Radio::turnOffOn(bool volumeSwitch)
{
    isOn = volumeSwitch;
    
        if (isOn == false)
        {
            Mix_VolumeMusic(0);
        }
        else
        {
            Mix_VolumeMusic(MIX_MAX_VOLUME);
        }        
}