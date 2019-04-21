//
//  main.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "raylib.h"
#include "Window.hpp"
#include "Player.hpp"

Camera2D camera;
//we could have a second NodeHead for map shit...

const int TILESIZE = 48; //So collisions work, I guess


int main(int argc, const char * argv[]) {
    InitScreen();
    
    Player p1;
    
    p1.GetCollision();
    
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

