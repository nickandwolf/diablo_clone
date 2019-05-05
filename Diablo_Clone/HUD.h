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
#include "Node.h"

static Texture2D interface;

extern Node * MainPlayer;

static const Rectangle hpBarLeft = (Rectangle) {336, 84, 6, 24};
static const Rectangle hpBarFull = (Rectangle) {342, 84, 2, 24};
static const Rectangle hpBarEmpty = (Rectangle) {378, 84, 2, 24};
static const Rectangle hpBarRight = (Rectangle) {394, 84, 6, 24};
static const Rectangle hpBarEmptyLeft = (Rectangle) {394, 84, 2, 24};

static const Rectangle hpBarCur = (Rectangle) {402, 84, 2, 24};
static const Rectangle hpBarCur2 = (Rectangle) {410, 84, 2, 24};
static const Rectangle hpBarCur3 = (Rectangle) {366, 84, 2, 24};

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
//UPDATERS
void UpdateHUD(void);
void UpdateHealth(void);

#endif /* HUD_h */
