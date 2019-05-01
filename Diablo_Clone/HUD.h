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

static const Rectangle hpBarLeft = (Rectangle) {168, 42, 3, 12};
static const Rectangle hpBarFull = (Rectangle) {171, 42, 1, 12};
static const Rectangle hpBarEmpty = (Rectangle) {189, 42, 1, 12};
static const Rectangle hpBarRight = (Rectangle) {197, 42, 3, 12};
static const Rectangle hpBarEmptyLeft = (Rectangle) {197, 42, 1, 12};

static const Rectangle hpBarCur = (Rectangle) {201, 42, 1, 12};
static const Rectangle hpBarCur2 = (Rectangle) {205, 42, 1, 12};
static const Rectangle hpBarCur3 = (Rectangle) {183, 42, 1, 12};

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
