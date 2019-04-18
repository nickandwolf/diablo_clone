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
#include "Node.h"
#include "Render.h"

Camera2D camera;
Node * NodeHead;
Node * MainPlayer;
//we could have a second NodeHead for map shit...

const int TILESIZE = 48; //So collisions work, I guess


int main(int argc, const char * argv[]) {
    InitHeadNode();
    CreatePlayer();
    CreateNode(1);
    MakeMap(TEST_LEVEL);
    MergeSort(&NodeHead); //make a thingy saying if we should change this or not...
    
    InitRender();
    
    while (!WindowShouldClose()) {
        RenderDraw();
        
        UpdateNode();
        RenderUpdate();
        
        
    }
    
    return 0;
}

