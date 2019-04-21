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
    
    RenderObjects.resize(3);
    
    Player p1(50,50);
    Player p2(100,100);
    Player p3(10,10);
    
    RenderObjects[0] = p1;//this is where things are gonna get complicated
    RenderObjects[1] = p2;
    RenderObjects[2] = p3;
    
    SortParentObjectsVector();
    
    while (!WindowShouldClose()) {
        //Clean this out later
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(SCREEN_WIDTH/2 -5, SCREEN_HEIGHT/2 - 5, 10, 10, RED);
        DrawTextureRec(RenderObjects[0].GetSprite(), RenderObjects[0].GetSpriteFrame(), RenderObjects[0].GetPosition(), WHITE); //gonna have to fix this :\ no worries yet
        DrawTextureRec(RenderObjects[1].GetSprite(), RenderObjects[1].GetSpriteFrame(), RenderObjects[1].GetPosition(), WHITE); //gonna have to fix this :\ no worries yet
        DrawTextureRec(RenderObjects[2].GetSprite(), RenderObjects[2].GetSpriteFrame(), RenderObjects[2].GetPosition(), WHITE); //gonna have to fix this :\ no worries yet
        EndDrawing();
    }
    
    return 0;
}

