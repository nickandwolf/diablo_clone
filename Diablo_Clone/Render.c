//
//  Render.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Render.h"

void InitRender() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Diablo_Clone");
    SetTargetFPS(TARGET_FPS);
    
    mainSheet1 = LoadTexture("Assets/sheet1.png");
    mainSheet2 = LoadTexture("Assets/sheet2.png");
    mainSheet3 = LoadTexture("Assets/sheet3.png");
    mainSheet4 = LoadTexture("Assets/sheet4.png");
    terrainSheet = LoadTexture("Assets/terrain.png");
}

void RenderDraw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    //create a Y build order?!?
    MapTile* tile = MapHead->next;
    while (tile != NULL) {
        
        DrawTextureRec(terrainSheet, tile->frameRect, (Vector2) {tile->position.x, tile->position.y}, WHITE);
        DrawRectangleLines(tile->collisionRect.x, tile->collisionRect.y, tile->collisionRect.width, tile->collisionRect.height, RED);
        tile = tile->next;
    }
    
    //MARK: CPU Intensive stupid solution
    for (int y = 0; y < MAPHEIGHT*TILESIZE; y++) {
        Node* current = NodeHead->next;
        while (current != NULL) {
            if (y == current->position.y) {
                DrawTextureRec(masterSheet, current->frameRect, current->position, WHITE);
                DrawRectangleLines(current->collisionRect.x, current->collisionRect.y, current->collisionRect.width, current->collisionRect.height, RED);
            }
            current = current->next;
        }
    }
    
    EndDrawing();
}



void RenderUpdate(void) {
    //make masterSheet change here.
    frameCounter++;
    if (frameCounter >= (60/FRAME_SPEED)) {
        frameCounter = 0;
        currentFrame++;
        
        if (currentFrame > 3) currentFrame = 0;
        
        switch (currentFrame) {
            case 0:
                masterSheet = mainSheet1;
                break;
                
            case 1:
                masterSheet = mainSheet2;
                break;
                
            case 2:
                masterSheet = mainSheet3;
                break;
                
            case 3:
                masterSheet = mainSheet4;
                break;
        }
    }
}
