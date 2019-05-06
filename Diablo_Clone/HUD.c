//
//  HUD.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/27/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "HUD.h"

void InitHUD() {
    interface = LoadTexture("Assets/interface.png");
    frameCount = 0;
    cursor = smallAimCursor;
    MainPlayer->curHP = 6;
    MainPlayer->maxHP = 10;
    
}

void RenderHUD() {
    
    int i = 0;
    DrawTextureRec(interface, hpBarLeft, (Vector2){5,5}, WHITE);
    
    if (MainPlayer->curHP > 0) {
        
        while (i < MainPlayer->curHP*3) {
            DrawTextureRec(interface, hpBarFull, (Vector2){11+i,5}, WHITE);
            i++;
        }
        
        DrawTextureRec(interface, hpBarCur, (Vector2){11+i,5}, WHITE);
        
        i++;
    }
    
    else {
        DrawTextureRec(interface, hpBarEmptyLeft, (Vector2){10,5}, WHITE);
    }
    
    while (i < MainPlayer->maxHP*3) {
        DrawTextureRec(interface, hpBarEmpty, (Vector2){11+i,5}, WHITE);
        i++;
    }
    
    DrawTextureRec(interface, hpBarRight, (Vector2){11+i,5}, WHITE);
    
    DrawTextureRec(interface, cursor, (Vector2){GetMouseX()-cursor.width/2, GetMouseY()-cursor.height/2}, WHITE);
}

void UpdateHUD() {
    
    UpdateCursor();
    UpdateHealth();
    
    frameCount++;
    if (frameCount == 60) frameCount = 0;
}
void UpdateCursor(void) {
    if (IsMouseButtonDown(FireWeapon1Key)) {
        cursor = clickAimCursor;
    }
    //else if ();//like hovering over items and shit.
    else cursor = smallAimCursor;
}

void UpdateHealth() {
    
}
