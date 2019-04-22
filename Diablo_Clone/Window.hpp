//
//  Window.hpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//  REQUIRES RAYLIB

#ifndef Window_hpp
#define Window_hpp

#include "raylib.h"

static const int SCREEN_WIDTH = 1280;
static const int SCREEN_HEIGHT = 720;
extern const int TARGET_FPS;

void InitScreen(void);
//maybe we'll have a thing resize the window later for resolution garbage. For now, stick with the target...
#endif /* Window_hpp */
