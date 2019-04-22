//
//  main.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//  REQUIRES RAYLIB

#include <iostream>
#include <vector>
#include "raylib.h"
#include "Window.hpp"
#include "Player.hpp"
#include "ParentObject.hpp"
#include "Render.hpp"
#include "InputHandler.hpp"

int master_UID = 0;
int PlayerUID;
Camera2D camera;
const int TARGET_FPS = 60;
//we could have a second NodeHead for map shit...

const int TILESIZE = 48; //So collisions work, I guess

std::vector<ParentObject> RenderObjects;

int main(int argc, const char * argv[]) {
    InitScreen();
    
    RenderObjects.push_back(Player(50,50));//this is where things are gonna get complicated
    RenderObjects.push_back(Player(10,10));
    RenderObjects.push_back(Player(200,200));
    
    PlayerUID = RenderObjects[0].GetUID();
    
    SortParentObjectsVector();
    
    while (!WindowShouldClose()) { //GOTTA DETECT WHICH ELEMENT IS THE PLAYER;
        RenderDraw();
        RenderObjects[0] = HandlePlayerInput(RenderObjects[0]);
    }
    
    return 0;
}

