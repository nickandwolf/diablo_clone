//
//  Map.h
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/11/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

/*
 Let me break this down, yo.
 You make the map in Tiled, export the "data":  [x,y,z] thingy. Then you change it to an array in C and we hard-code it.
 I do this because I dunno how to parse anything. Someone will need to make a parser.
 
 We'll fix this dumb shit later. Let's just get the functionality there before worrying about creation.
 
 The exported data is always incremented by 1 from his editor version. So I compensate for that.
 USE THE EDITOR ID, NOT THE FREAKIN' DATA ONE!
 */

#ifndef Map_h
#define Map_h

#include <stdlib.h>
#include <string.h>
#include "raylib.h"

//TODO: HEY FIGURE OUT X AND Y SHIT, YO!

//make this a real thing
static const int MAPHEIGHT = 100;
extern const int TILESIZE;

enum TILE_ID { //This dumb shit is the ID from the editor
    FLOOR = 42,
    WALL = 262,
    TAPESTRY_WALL = 285,
    TOP_WALL = 282,
    BOTTOM_WALL = 2, //custom made, yo just for the collision box
    DOOR
};

enum MAP_ID {
    TEST_LEVEL = 0
};

//hmmm struct tiem?!

typedef struct MapTile {
    int ID; //type of thingy
    Vector2 position;
    //Texture2D spriteSheet;
    Rectangle frameRect;
    Rectangle collisionRect;
    struct MapTile* next;
} MapTile;

extern MapTile* MapHead;
static int map_width = 0;
static int map_height = 0;

//make a floor and ceiling map for...like...depth of something

void InitMapHead(void);
void ClearMap(void);
void AddMapTile(MapTile* tile);
void RemoveMapTile(MapTile * node); //MARK: If I can remove it, don't I need to mark that?
MapTile* GetMapTile(MapTile* tile, Vector2 pos);
bool CheckMapCollision(Rectangle pos);
void CreateMapTile(int ID, int x, int y);
void UpdateMapTile(void);

//make some preset rooms and then an algorithm to set them
void MakeMap(int mapID); //mapID would be the level...like in game level.
                         //Also things the player has to go behind should not be here. That's part of the Node.
                         //I'll fix it sometime later. For now the goal is "prototype"
                         //So how about making a render priority system? Like... organize everything by Y and doodle it like that?

#endif /* Map_h */
