//
//  Input.h
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/16/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef Input_h
#define Input_h

#include "raylib.h"

//TODO:GOTTA MAKE UP A PLAYER MOVEMENT SPEED

//Make required buttons as variables
//Make actions in here too
//Have a function for each control method (do that w/ buttons too)

//Movement
static int MoveUpKey = KEY_UP;
static int MoveDownKey = KEY_DOWN;
static int MoveLeftKey = KEY_LEFT;
static int MoveRightKey = KEY_RIGHT;
static int MoveRunKey = KEY_LEFT_SHIFT;

static int FireWeapon1Key = MOUSE_LEFT_BUTTON;

//Camera
static int CameraZoomIn = KEY_EQUAL;
static int CameraZoomOut = KEY_MINUS;

//there's gotta be a better way to map keys
void AssignUpKey(int newKey);
void AssignDownKey(int newKey);
void AssignLeftKey(int newKey);
void AssignRightKey(int newKey);
void AssignRunKey(int newKey);

#endif /* Input_h */
