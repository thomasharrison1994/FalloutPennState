//
//  PostWarFood.cpp
//  FalloutPennState
//
//  Created by Tom Harrison on 3/29/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"PostWarFood.h"

PostWarFood::PostWarFood()
{
    //srand(time(NULL));
    randFood = rand() % 6;
    
    switch (randFood)
    {
        case 0:
            itemName = "Squirrel stew";
            break;
        case 1:
            itemName = "Brahmin steak";
            break;
        case 2:
            itemName = "Crispy squirrel bits";
            break;
        case 3:
            itemName = "Iguana bits";
            break;
        case 4:
            itemName = "Iguana-on-a-stick";
            break;
        case 5:
            itemName = "Squirrel-on-a-stick";
            break;
        default:
            break;
    }
    aidName = itemName;
    itemDescription = aidName;
    aidEffect = 5;
    aidActionPointCost = 5;    
}