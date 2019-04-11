//
//  main.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "raylib.h"
#include "Map.h"
#include "Node.h"
#include "Render.h"

//TEMP SHIT BEFORE MOVING IT TO ANOTHER FILE
//MAP
//header
/*
 map Map (2D array or wut?
 cycle through map
 do other shit
*/
// \END MAP
//END TEMP

Node * NodeHead;
int* MasterMap;

int main(int argc, const char * argv[]) {
    InitRender();
    InitHeadNode();
    MakeSquare();
    
    //MAKE A VARIABLE FOR FULL SIZE OF MAP! GONNA HAVE TO RE-MAKE ALL THIS GARBAGE
    for (int i = 0; i < 360; i++) {
        if (i % 20 == 0)
            printf("\n");
        printf("%i", *(MasterMap+i));
        
    }
    
    CreateNode(PLAYER);//this shit needs to be fixed too
    
    while (!WindowShouldClose()) {
        RenderDraw();
        
        UpdateNode();
        RenderUpdate();
    }
    
    return 0;
}
