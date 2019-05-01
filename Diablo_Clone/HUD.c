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
    
    MainPlayer->curHP = 6;
    MainPlayer->maxHP = 10;
    
}

void RenderHUD() {
    
    int i = 0;
    DrawTextureRec(interface, hpBarLeft, (Vector2){5,5}, WHITE);
    
    if (MainPlayer->curHP > 0) {
        
        while (i < MainPlayer->curHP*3) {
            DrawTextureRec(interface, hpBarFull, (Vector2){8+i,5}, WHITE);
            i++;
        }
        
        DrawTextureRec(interface, hpBarCur, (Vector2){8+i,5}, WHITE);
        
        i++;
    }
    
    else {
        DrawTextureRec(interface, hpBarEmptyLeft, (Vector2){7,5}, WHITE);
    }
    
    while (i < MainPlayer->maxHP*3) {
        DrawTextureRec(interface, hpBarEmpty, (Vector2){8+i,5}, WHITE);
        i++;
    }
    
    DrawTextureRec(interface, hpBarRight, (Vector2){8+i,5}, WHITE);
    
}

void UpdateHUD() {
    UpdateHealth();
}
void UpdateHealth() {
    
}
