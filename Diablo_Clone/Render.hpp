//
//  Render.hpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef Render_hpp
#define Render_hpp

#include <vector>
#include <algorithm>
#include "raylib.h"
#include "ParentObject.hpp"

static int frameCount;

extern const int TILESIZE;

extern std::vector<ParentObject> RenderObjects;

extern Camera2D camera;

void InitRender(void);

void RenderDraw(void);

void RenderUpdate(void);

int GetFrameCount(void);

void UpdateFrameCount(void);

void SortVector(void);

bool RenderObjectsMethod(ParentObject v1, ParentObject v2);

#endif /* Render_hpp */
