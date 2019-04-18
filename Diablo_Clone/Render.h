//
//  Render.h
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef Render_h
#define Render_h

#include "raylib.h"
#include "Node.h"

static const int SCREEN_WIDTH = 1280; //could remove static and use extern if needed
static const int SCREEN_HEIGHT = 720; //
static const int TARGET_FPS = 60;
static const int FRAME_SPEED = 8;

extern const int TILESIZE;

static int currentFrame = 0;
static int frameCounter = 0;

extern Node * NodeHead;
extern Camera2D camera;
extern Node * MainPlayer;
extern const int MAPHEIGHT;

static Texture2D mainSheet1;   // We are going with a unique approach.
static Texture2D mainSheet2;   // Instead of moving the square to change frames
static Texture2D mainSheet3;   // we are going to change the texture being used.
static Texture2D mainSheet4;   // I have no clue if this will work good or not.
static Texture2D terrainSheet;

static Texture2D masterSheet; //clean up

void InitRender(void);

void RenderDraw(void);
void RenderUpdate(void);
#endif /* Render_h */
