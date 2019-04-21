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
public:
    void UpdateP(void);
    
    //getter/setters
    void SetPositionP(Vector2 newPos);
    void SetPositionP(float x, float y);
    Vector2 GetPositionP(void);
    
    void SetSpriteP(Texture2D newTex);
    Texture2D GetSpriteP(void);
    
    void SetSpriteFrameP(Rectangle newRect);
    void SetSpriteFrameP(int x, int y, int width, int height);
    Rectangle GetSpriteFrameP(void); //Maybe have another method that returns an array of shit?
    
    void SetCollisionP(Rectangle newColl);
    void SetCollisionP(int x, int y, int width, int height);
    Rectangle GetCollisionP(void);
    Rectangle GetCollisionP(int x, int y); //for checking /IF/ something will collide
    
private:
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

#endif /* ParentObject_hpp */
