//
//  InputHandler.hpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//  REQUIRES RAYLIB

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include "raylib.h"
#include "Player.hpp"

static int MoveUp = KEY_UP;
static int MoveDown = KEY_DOWN;
static int MoveLeft = KEY_LEFT;
static int MoveRight = KEY_RIGHT;

void SetNewKey(int oldKey);

ParentObject HandlePlayerInput(ParentObject* p1);
//void HandleNPCInput()

#endif /* InputHandler_hpp */
