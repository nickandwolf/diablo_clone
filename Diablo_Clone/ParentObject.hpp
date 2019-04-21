//
//  ParentObject.hpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef ParentObject_hpp
#define ParentObject_hpp

#include "raylib.h"

/*
 This is a wrapper class
 */
class ParentObject
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
    
    virtual void SetLayer(int newL);
    virtual int GetLayer(void);
};

#endif /* ParentObject_hpp */
