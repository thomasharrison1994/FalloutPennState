//
//  PreWarFood.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/29/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"PreWarFood.h"

PreWarFood::PreWarFood()
{
    //srand(time(NULL));
    randFood = rand() % 11;
    
    switch (randFood)
    {
        case 0:
            itemName = "BlamCo Mac & Cheese";
            break;
        case 1:
            itemName = "Cram";
            break;
        case 2:
            itemName = "Dandy Boy Apples";
            break;
        case 3:
            itemName = "Fancy Lad Snack Cakes";
            break;
        case 4:
            itemName = "InstaMash";
            break;
        case 5:
            itemName = "Junk food";
            break;
        case 6:
            itemName = "Pork n' Beans";
            break;
        case 7:
            itemName = "Potato Crisps";
            break;
        case 8:
            itemName = "Salisbury Steak";
            break;
        case 9:
            itemName = "Sugar Bombs";
            break;
        case 10:
            itemName = "YumYum Deviled Eggs";
            break;
        default:
            break;
    }
    aidName = itemName;
    itemDescription = aidName;
    aidEffect = 5;
    aidActionPointCost = 5;    
}