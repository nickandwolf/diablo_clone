//
//  HUD.h
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/27/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef HUD_h
#define HUD_h
#include "raylib.h"
#include "Input.h"
#include "Node.h"

static Texture2D interface;

extern Node * MainPlayer;

static int frameCount;

static const Rectangle hpBarLeft = (Rectangle) {336, 84, 6, 24};
static const Rectangle hpBarFull = (Rectangle) {342, 84, 2, 24};
static const Rectangle hpBarEmpty = (Rectangle) {378, 84, 2, 24};
static const Rectangle hpBarRight = (Rectangle) {394, 84, 6, 24};
static const Rectangle hpBarEmptyLeft = (Rectangle) {394, 84, 2, 24};

static const Rectangle hpBarCur = (Rectangle) {402, 84, 2, 24};
static const Rectangle hpBarCur2 = (Rectangle) {410, 84, 2, 24};
static const Rectangle hpBarCur3 = (Rectangle) {366, 84, 2, 24};

static const Rectangle bigAimCursor = (Rectangle){1558,616,34,34};
static const Rectangle clickAimCursor = (Rectangle){1612,620,26,26};
static const Rectangle smallAimCursor = (Rectangle){1664,624,18,18};
static Rectangle cursor;


/*
 First space
 Full HP
 dynamic pixel allocation of HP
 if hp != max, do bubble animation
 empty bar
 cap off at max
 */

void InitHUD(void);

void RenderHUD(void);
//HUD UPDATERS
void UpdateCursor(void);
//STAT UPDATERS
void UpdateHUD(void);
void UpdateHealth(void);

#endif /* HUD_h */
