//
//  Object.hpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/20/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//
/*
 So this is everything that isn't part of the map.
 It's gonna take a bit to conver this properly
 */

#ifndef Player_hpp
#define Player_hpp

/*TODO:
 FRAME ANIMATION!
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raylib.h"
#include "Input.h"

class Player
{
    
private:
    //Drawing Variables
    int layer; //0 = floor; 1 = stuff on floor; 2 = higher than that, like players; 3 = highest so FAR
    Texture2D spriteSheet;
    Rectangle spriteFrame;
    Vector2 position;
    
    //Collision bullshit
    Rectangle collisionRect;
    

public:
    //Basic Methods
    Player(void); //initializes the player
    void Update(void);
    
    //we put actual player shit down here...
    
    //getter/setters
    void SetPosition(Vector2 newPos);
    void SetPosition(float x, float y);
    Vector2 GetPosition(void);
    
    void SetSprite(Texture2D newTex);
    Texture2D GetSprite(void);
    
    void SetSpriteFrame(Rectangle newRect);
    void SetSpriteFrame(int x, int y, int width, int height);
    Rectangle GetSpriteFrame(void); //Maybe have another method that returns an array of shit?
    
    void SetCollision(Rectangle newColl);
    void SetCollision(int x, int y, int width, int height);
    Rectangle GetCollision(void);
    Rectangle GetCollision(int x, int y); //for checking /IF/ something will collide
};


#endif /* Player_hpp */
