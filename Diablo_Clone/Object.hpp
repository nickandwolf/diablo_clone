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

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raylib.h"
#include "Input.h"

class Object
{
    
    private:
        int ID; //type of thingy
        int UID; //actually unique thingy
        Vector2 position;
        //Texture2D spriteSheet; // All sprites use the same 4 character sheets
        Rectangle frameRect;     // Also there's a lot of white space between sprites
                                 // so we'll have to clean that up in time
        float COLLISION_X; //can't assign constants during runtime, so we'll just pretend
        float COLLISION_Y; //I mean, technically we can but we really shouldn't
        float COLLISION_WIDTH;
        float COLLISION_HEIGHT;
        int layer;               //0 = floor; 1 = stuff on floor; 2 = higher than that, like players; 3 = highest so FAR

    public:
        Object GetObjectXY(int x, int y);
    
        void CreateObject(int ID, int x, int y);
    
        void UpdateObject(void);
    
        void HandleInput(void);
    
        bool CheckObjectCollision(Object node, int x, int y);
    
        bool CheckObjectSpriteCollision(Rectangle pos, int UID); //TODO: implement
    
        Rectangle GetObjectCollisionRect(Object node);
    
        Rectangle GetObjectCollisionRectXYWH(float collision_x, float collision_y, float collision_width, float collision_height);
    
        bool GetNullRect(Object rect);
};


#endif /* Object_hpp */
