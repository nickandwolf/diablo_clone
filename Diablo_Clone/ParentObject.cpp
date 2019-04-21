//
//  ParentObject.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "ParentObject.hpp"

void UpdateP(void);

//getter/setters
void ParentObject::SetPositionP(Vector2 newPos) {
    ParentObject::SetPosition(newPos);
}
void ParentObject::SetPositionP(float x, float y) {
    ParentObject::SetPosition(x, y);
}
Vector2 ParentObject::GetPositionP() {
    return ParentObject::GetPosition();
}

void ParentObject::SetSpriteP(Texture2D newTex) {
    ParentObject::SetSprite(newTex);
}
Texture2D ParentObject::GetSpriteP() {
    return ParentObject::GetSprite();
}

void ParentObject::SetSpriteFrameP(Rectangle newRect) {
    ParentObject::SetSpriteFrame(newRect);
}
void ParentObject::SetSpriteFrameP(int x, int y, int width, int height) {
    ParentObject::SetSpriteFrame(x,y,width,height);
}
Rectangle ParentObject::GetSpriteFrameP() { //Maybe have another method that returns an array of shit?
    return ParentObject::GetSpriteFrame();
}
void ParentObject::SetCollisionP(Rectangle newColl) {
    ParentObject::SetCollision(newColl);
}
void ParentObject::SetCollisionP(int x, int y, int width, int height) {
    ParentObject::SetCollision(x,y,width,height);
}
Rectangle ParentObject::GetCollisionP() {
    return ParentObject::GetCollision();
}
Rectangle ParentObject::GetCollisionP(int x, int y) { //for checking /IF/ something will collide
    return ParentObject::GetCollision(x,y);
}
