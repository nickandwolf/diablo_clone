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
    Node* current = NodeHead;
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    Rectangle sprite;
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            int spriteNum = GetTile(x, y);
            switch (spriteNum) {
                case 0:
                    sprite.x = 48;
                    sprite.y = 600;
                    sprite.height = 48;
                    sprite.width = 48;
                    break;
                    
                case 1:
                    sprite.x = 48;
                    sprite.y = 672;
                    sprite.height = 48;
                    sprite.width = 48;
                    break;
                    
                case 2:
                    sprite.x = 480;
                    sprite.y = 624;
                    sprite.height = 48;
                    sprite.width = 59;
                    break;
            }
            
            DrawTextureRec(terrainSheet, sprite, (Vector2){x * TILESIZE, y * TILESIZE}, WHITE);
        }
    }
    
    while (current != NULL) {
        DrawTextureRec(masterSheet, current->frameRect, current->position, WHITE);
        current = current->next;
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
