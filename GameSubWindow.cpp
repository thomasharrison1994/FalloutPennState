//
//  GameSubWindow.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 7/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GameSubWindow.h"

GameSubWindow::GameSubWindow()
{
    imageWell = IMG_Load("GameButtonGeneral.png");
    rectangles = IMG_Load("Rectangles.png");
    statRects = IMG_Load("ItemsButtonGeneral.png");
    
    rectangleDimensions.x = 475;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 600;
    rectangleDimensions.h = 60;
    
    squareDimensions.x = 50;
    squareDimensions.y = 75;
    squareDimensions.w = 35;
    squareDimensions.h = 35;
    
    circleDimensions.x = 100;
    circleDimensions.y = 75;
    circleDimensions.w = 140;
    circleDimensions.h = 120;
    
    isActive = false;
    
    //Pulled from ItemsSubWindow
    statRectDimensions.x = 85;
    statRectDimensions.y = 880;
    statRectDimensions.w = 190; //200
    statRectDimensions.h = 45;
    
    //VAL box
    statRectCoordinates[0].x = 940; //950
    statRectCoordinates[0].y = 475; //450    
    
    statRectDataTypeDimensions[0].x = 355;
    statRectDataTypeDimensions[0].y = 890;
    statRectDataTypeDimensions[0].w = 58;
    statRectDataTypeDimensions[0].h = 21;
    
    statRectDataTypeCoordinates[0].x = 943; //953
    statRectDataTypeCoordinates[0].y = 490; //465  
    
    
    //WG box
    statRectCoordinates[1].x = 740; //750
    statRectCoordinates[1].y = 475; //450
    
    statRectDataTypeDimensions[1].x = 295;
    statRectDataTypeDimensions[1].y = 890;
    statRectDataTypeDimensions[1].w = 42;
    statRectDataTypeDimensions[1].h = 21;
    
    statRectDataTypeCoordinates[1].x = 743; //753
    statRectDataTypeCoordinates[1].y = 490; //465
    
    //DR box
    statRectCoordinates[2].x = 540; //550
    statRectCoordinates[2].y = 475; //450
    
    statRectDataTypeDimensions[2].x = 425; //415
    statRectDataTypeDimensions[2].y = 890; //890
    statRectDataTypeDimensions[2].w = 58; //58
    statRectDataTypeDimensions[2].h = 21; //21
    
    statRectDataTypeCoordinates[2].x = 535; //535
    statRectDataTypeCoordinates[2].y = 490; //465
    
    //DAM box modifications
    
    statRectCoordinates[3].x = statRectCoordinates[2].x;
    statRectCoordinates[3].y = statRectCoordinates[2].y;
    
    statRectDataTypeDimensions[3].x = statRectDataTypeDimensions[2].x;
    statRectDataTypeDimensions[3].y = statRectDataTypeDimensions[2].y;
    statRectDataTypeDimensions[3].w = statRectDataTypeDimensions[2].w;
    statRectDataTypeDimensions[3].h = statRectDataTypeDimensions[2].h;
    
    statRectDataTypeCoordinates[3].x = statRectDataTypeCoordinates[2].x;
    statRectDataTypeCoordinates[3].y = statRectDataTypeCoordinates[2].y;    
    
    statRectDataTypeDimensions[3].x = 490; //475
    statRectDataTypeDimensions[3].w = 73; //73
    statRectDataTypeCoordinates[3].x = 540;
}

GameSubWindow::~GameSubWindow()
{
    
}

gameWindowIdentity GameSubWindow::getIdentity()
{
    return selfIdentity;
}

gameWindowIdentity GameSubWindow::getNextIdentity()
{
    return nextIdentity;
}

void GameSubWindow::setNextIdentity(gameWindowIdentity theNextIdentity)
{
    nextIdentity = theNextIdentity;
}