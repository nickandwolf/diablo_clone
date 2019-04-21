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
    
}

void RenderUpdate(void);

int GetFrameCount() {
    return frameCount;
}

void UpdateFrameCount() {
    frameCount++;
    if (frameCount > GetFPS())
        frameCount = 0;
}

void SortParentObjectsVector() {
    std::sort (RenderObjects.begin(), RenderObjects.end(), SortParentObjectsMethod);
}

bool SortParentObjectsMethod(ParentObject v1, ParentObject v2) {
    Vector2 p1 = v1.GetPosition();
    Vector2 p2 = v2.GetPosition();
    
    return (p1.y < p2.y);
}
