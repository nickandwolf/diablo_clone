//
//  Object.hpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/20/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//  REQUIRES RAYLIB
/*
 So this is everything that isn't part of the map.
 It's gonna take a bit to conver this properly
 
 UID is set at the runtime of the game EACH TIME. It is then set to the Main()'s PLAYER1 we can track the current player.
 No clue how the fuck multiplayer will work out.
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
public:
    //Basic Methods
    Player(void); //initializes the player
    Player(float x, float y);
    void Update(void);
    
    //we put actual player shit down here...
    
    //getter/setters
};


#endif /* Player_hpp */
