//
//  Render.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Render.hpp"

extern const int TILESIZE;

extern Camera2D camera;

void InitRender() {
    frameCount = 0;
}

void RenderDraw() {
    UpdateFrameCount();
    ResortVectorCheck(); //uhhh...makes no sense with Y values D:
                         //maybe we'll have "Inanimate" be a thing
    
    BeginDrawing();
    ClearBackground(BLACK);
    
    for(std::vector<ParentObject>::iterator it = RenderObjects.begin(); it != RenderObjects.end(); ++it) {
        DrawTextureRec(it->GetSprite(), it->GetSpriteFrame(), it->GetPosition(), WHITE);
    }
    
    EndDrawing();
}

void RenderUpdate(void);

int GetFrameCount() {
    return frameCount;
}

void UpdateFrameCount() {
    frameCount++;
    
    if (frameCount > TARGET_FPS)
        frameCount = 1;
}

void SortParentObjectsVector() {
    std::sort (RenderObjects.begin(), RenderObjects.end(), SortParentObjectsMethod);
}

bool SortParentObjectsMethod(ParentObject v1, ParentObject v2) {
    Vector2 p1 = v1.GetPosition();
    Vector2 p2 = v2.GetPosition();
    
    return (p1.y < p2.y);
}

void ResortVectorCheck() {
    if (RenderObjects.size() != RenderObjectsSize) {
        RenderObjectsSize = (int)RenderObjects.size();
        SortParentObjectsVector();
    }
}
