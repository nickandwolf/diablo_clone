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
    //WE GONNA TRY NOW!
    size_t nodehead_len = sizeof(NodeHead)/sizeof(Node);
    qsort(NodeHead, nodehead_len, sizeof(Node), QNodeYSort); //so QSort isn't working...
    //nope, fuck this shit, we gonna go with sprite layers instead.
    
    Node* current = NodeHead->next;
    while (current != NULL) {
        if (current->UID == 0 && current->ID == FLOOR) {
            DrawTextureRec(terrainSheet, current->frameRect, current->position, WHITE);
        }
        current = current->next;
    }
    
    current = NodeHead->next;
    while (current != NULL) {
        if (current->UID == 0) {
            if (current->ID != FLOOR)
                DrawTextureRec(terrainSheet, current->frameRect, current->position, WHITE);
        }
        else {
            DrawTextureRec(masterSheet, current->frameRect, current->position, WHITE);
        }
        DrawRectangleLines(current->collisionRect.x, current->collisionRect.y, current->collisionRect.width, current->collisionRect.height, RED);
        
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
