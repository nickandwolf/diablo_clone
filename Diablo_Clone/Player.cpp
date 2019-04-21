//
//  Player.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/20/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Player.hpp"

//MAIN SHIT
Player::Player() {
    spriteSheet = LoadTexture("Assets/sheet1.png");
    spriteFrame = (Rectangle){0,0,48,48};
    position = (Vector2){60,60};
    collisionRect = (Rectangle) {15, 31, 18, 9};
    layer = 2;
}
Player::Player(float x, float y) {
    spriteSheet = LoadTexture("Assets/sheet1.png");
    spriteFrame = (Rectangle){0,0,48,48};
    position = (Vector2){x,y};
    collisionRect = (Rectangle) {15, 31, 18, 9};
    layer = 2;
}
void Player::Update(void) {
    
}

//GETS / SETS
void Player::SetPosition(Vector2 newPos) {
    position = newPos;
    
}
void Player::SetPosition(float x, float y) {
    position.x = x;
    position.y = y;
}
Vector2 Player::GetPosition() {
    return position;
}

void Player::SetSprite(Texture2D newTex) {
    UnloadTexture(spriteSheet);
    spriteSheet = newTex;
}
Texture2D Player::GetSprite() {
    return spriteSheet;
}

void Player::SetSpriteFrame(Rectangle newRect) {
    spriteFrame = newRect;
}
void Player::SetSpriteFrame(int x, int y, int width, int height) {
    spriteFrame.x = x;
    spriteFrame.y = y;
    spriteFrame.width = width;
    spriteFrame.height = height;
}
Rectangle Player::GetSpriteFrame(void) {
    return spriteFrame;
}

void Player::SetCollision(Rectangle newColl) {
    collisionRect = newColl;
}
void Player::SetCollision(int x, int y, int width, int height) {
    collisionRect.x = x;
    collisionRect.y = y;
    collisionRect.width = width;
    collisionRect.height = height;
}
Rectangle Player::GetCollision(void) {
    return collisionRect;
}
Rectangle Player::GetCollision(int x, int y) { //for checking /IF/ something will collide
    return (Rectangle) {collisionRect.x + x, collisionRect.y + y, collisionRect.width, collisionRect.height};
}
