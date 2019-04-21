//
//  ParentObject.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "ParentObject.hpp"

//MAIN SHIT
void ParentObject::Update(void) {
    
}

//GETS / SETS
void ParentObject::SetPosition(Vector2 newPos) {
    position = newPos;
    
}
void ParentObject::SetPosition(float x, float y) {
    position.x = x;
    position.y = y;
}
Vector2 ParentObject::GetPosition() {
    return position;
}

void ParentObject::SetSprite(Texture2D newTex) {
    UnloadTexture(spriteSheet);
    spriteSheet = newTex;
}
Texture2D ParentObject::GetSprite() {
    return spriteSheet;
}

void ParentObject::SetSpriteFrame(Rectangle newRect) {
    spriteFrame = newRect;
}
void ParentObject::SetSpriteFrame(int x, int y, int width, int height) {
    spriteFrame.x = x;
    spriteFrame.y = y;
    spriteFrame.width = width;
    spriteFrame.height = height;
}
Rectangle ParentObject::GetSpriteFrame(void) {
    return spriteFrame;
}

void ParentObject::SetCollision(Rectangle newColl) {
    collisionRect = newColl;
}
void ParentObject::SetCollision(int x, int y, int width, int height) {
    collisionRect.x = x;
    collisionRect.y = y;
    collisionRect.width = width;
    collisionRect.height = height;
}
Rectangle ParentObject::GetCollision(void) {
    return collisionRect;
}
Rectangle ParentObject::GetCollision(int x, int y) { //for checking /IF/ something will collide
    return (Rectangle) {collisionRect.x + x, collisionRect.y + y, collisionRect.width, collisionRect.height};
}

void ParentObject::SetLayer(int newL) {
    layer = newL;
}
int ParentObject::GetLayer() {
    return layer;
}
