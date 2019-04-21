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

#include <vector>
#include "raylib.h"
#include "ParentObject.hpp"

extern std::vector<ParentObject> RenderObjects;

class Player : public ParentObject
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
    Player(float x, float y);
    virtual void Update(void);
    
    //we put actual player shit down here...
    
    //getter/setters
    virtual void SetPosition(Vector2 newPos);
    virtual void SetPosition(float x, float y);
    virtual Vector2 GetPosition(void);
    
    virtual void SetSprite(Texture2D newTex);
    virtual Texture2D GetSprite(void);
    
    virtual void SetSpriteFrame(Rectangle newRect);
    virtual void SetSpriteFrame(int x, int y, int width, int height);
    virtual Rectangle GetSpriteFrame(void); //Maybe have another method that returns an array of shit?
    
    virtual void SetCollision(Rectangle newColl);
    virtual void SetCollision(int x, int y, int width, int height);
    virtual Rectangle GetCollision(void);
    virtual Rectangle GetCollision(int x, int y); //for checking /IF/ something will collide
};


#endif /* Player_hpp */
