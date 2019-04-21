//
//  main.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include <iostream>
#include <vector>
#include "raylib.h"
#include "Window.hpp"
#include "Player.hpp"
#include "ParentObject.hpp"
#include "Render.hpp"

Camera2D camera;
//we could have a second NodeHead for map shit...

const int TILESIZE = 48; //So collisions work, I guess

std::vector<ParentObject> RenderObjects;

int main(int argc, const char * argv[]) {
    InitScreen();
    
    Player p1;
    Player p2(100,100);
    Player p3(10,10);
    RenderObjects.push_back(p1);//this is where things are gonna get complicated
    RenderObjects.push_back(p2);
    RenderObjects.push_back(p3);
    
    
    while (!WindowShouldClose()) {
        //Clean this out later
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(SCREEN_WIDTH/2 -5, SCREEN_HEIGHT/2 - 5, 10, 10, RED);
        DrawTextureRec(p1.GetSprite(), p1.GetSpriteFrame(), p1.GetPosition(), WHITE); //gonna have to fix this :\ no worries yet
        EndDrawing();
    }
    
    return 0;
}

