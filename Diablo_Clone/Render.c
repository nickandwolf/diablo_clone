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
    
    //TODO: Have character variable for this shit
    //TODO: Gotta get sprites working... "more" correctly
    camera.target = (Vector2) {MainPlayer->position.x + MainPlayer->frameRect.width/2, MainPlayer->position.y + MainPlayer->frameRect.height/2};
    camera.offset = (Vector2) {SCREEN_WIDTH/2 - MainPlayer->frameRect.width/2 - MainPlayer->position.x, SCREEN_HEIGHT/2 - MainPlayer->frameRect.height/2 - MainPlayer->position.y}; //half-screen, half-sprite, current x/y
    
    camera.rotation = 0.0f;
    camera.zoom = 1.0f; //TODO: FIGURE OUT ZOOM MATH!
}

void RenderDraw() {
    BeginMode2D(camera);
    
    for (int layer = 0; layer <= 3; layer++) {
        Node* current = NodeHead->next;
        while (current != NULL) {
            DrawCircleLines(MainPlayer->frameRect.width/2 + MainPlayer->position.x, MainPlayer->frameRect.height/2 + MainPlayer->position.y, MainPlayer->visibilityRadius, RED);
            
            //do lighting
            if (CheckCircleCollision((Vector2){MainPlayer->position.x + MainPlayer->frameRect.width/2, MainPlayer->position.y + MainPlayer->frameRect.height/2}, MainPlayer->visibilityRadius, (Rectangle){current->position.x, current->position.y, current->frameRect.width, current->frameRect.height})) {
                MakeVisible(current);
                if (current->TYPE == 0) MarkSeen(current);
            }
            else {
                MakeInvisible(current);
            }
            
            if (current->visible) {
                if (current->layer == layer) {
                    if (current->UID == 0) { //we're gonna have to rewrite this eventually...
                        DrawTextureRec(terrainSheet, current->frameRect, current->position, WHITE);
                    }
                    else {
                        DrawTextureRec(masterSheet, current->frameRect, current->position, WHITE);
                    }
                }
            }
            else if (current->layer == layer && current->UID == 0 && current->seen) DrawTextureRec(terrainSheet, current->frameRect, current->position, GRAY);
            
            //collision debug
            //DrawRectangleLinesEx(GetNodeCollisionRect(current), 1, RED);
            
            current = current->next;
        }
    }
    
    EndMode2D();
    //STUPID DEBUG SHIT
//    int dude = GetFPS();
//    printf("FPS: %i", dude);
//
    DrawRectangle(SCREEN_WIDTH/2 -5, SCREEN_HEIGHT/2 - 5, 10, 10, RED);
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
