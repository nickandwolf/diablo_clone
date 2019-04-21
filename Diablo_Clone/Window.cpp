//
//  Window.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Window.hpp"

void InitScreen() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Diablo_Clone");
    SetTargetFPS(TARGET_FPS);
}
