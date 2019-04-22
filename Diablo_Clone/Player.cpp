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
    ParentObject::SetSprite(LoadTexture("Assets/sheet1.png"));
    ParentObject::SetSpriteFrame((Rectangle){0,0,48,48});
    ParentObject::SetPosition((Vector2){60,60});
    ParentObject::SetCollision((Rectangle) {15, 31, 18, 9});
    ParentObject::SetLayer(2);
    ParentObject::SetUID();
}
Player::Player(float x, float y) {
    ParentObject::SetSprite(LoadTexture("Assets/sheet1.png"));
    ParentObject::SetSpriteFrame((Rectangle){0,0,48,48});
    ParentObject::SetPosition((Vector2){x,y});
    ParentObject::SetCollision((Rectangle) {15, 31, 18, 9});
    ParentObject::SetLayer(2);
    ParentObject::SetUID();
}
void Player::Update(void) {
    
}
