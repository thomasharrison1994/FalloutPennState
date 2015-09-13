//
//  ItemsSubWindow.cpp
//  MenuEfficient
//
//  Created by Tom Harrison on 6/25/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ItemsSubWindow.h"

ItemsSubWindow::ItemsSubWindow()
{
    activeItemInQueue = 0;
    
    imageWell = IMG_Load("ItemsButtonGeneral.png");
    rectangles = IMG_Load("Rectangles.png");
    
    statRectDimensions.x = 85;
    statRectDimensions.y = 880;
    statRectDimensions.w = 200;
    statRectDimensions.h = 45;
    
    //VAL box
    statRectCoordinates[0].x = 950;
    statRectCoordinates[0].y = 450;    
    
    statRectDataTypeDimensions[0].x = 355;
    statRectDataTypeDimensions[0].y = 890;
    statRectDataTypeDimensions[0].w = 58;
    statRectDataTypeDimensions[0].h = 21;
    
    statRectDataTypeCoordinates[0].x = 953;
    statRectDataTypeCoordinates[0].y = 465;    
    
    
    //WG box
    statRectCoordinates[1].x = 750;
    statRectCoordinates[1].y = 450;
    
    statRectDataTypeDimensions[1].x = 295;
    statRectDataTypeDimensions[1].y = 890;
    statRectDataTypeDimensions[1].w = 42;
    statRectDataTypeDimensions[1].h = 21;
    
    statRectDataTypeCoordinates[1].x = 753;
    statRectDataTypeCoordinates[1].y = 465;
    
    //DR box
    statRectCoordinates[2].x = 550;
    statRectCoordinates[2].y = 450;
       
    statRectDataTypeDimensions[2].x = 415;
    statRectDataTypeDimensions[2].y = 890;
    statRectDataTypeDimensions[2].w = 58;
    statRectDataTypeDimensions[2].h = 21;
    
    statRectDataTypeCoordinates[2].x = 535;
    statRectDataTypeCoordinates[2].y = 465;
    
    //Line for description
    descriptionLineDimensions.x = 80;
    descriptionLineDimensions.y = 960;    
    descriptionLineDimensions.w = 600;
    descriptionLineDimensions.h = 10;
    
    descriptionLineCoordinates.x = 545;
    descriptionLineCoordinates.y = 130;
    
    rectangleDimensions.x = 470;
    rectangleDimensions.y = 10;
    rectangleDimensions.w = 465;
    rectangleDimensions.h = 45;    
    
    rectangleCoordinates.x = 80;
    rectangleCoordinates.y = 146;    
    
}