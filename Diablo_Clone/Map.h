//
//  Map.h
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/11/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef Map_h
#define Map_h

#include <stdlib.h>
#include <string.h>
#include "raylib.h"

//TODO: HEY FIGURE OUT X AND Y SHIT, YO!

//make this a real thing
static const int MAPHEIGHT = 100;

enum MAP_ID {
    FLOOR,
    WALL,
    TOP_WALL,
    DOOR
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

//make a floor and ceiling map for...like...depth of something

void InitMapHead(void);
void ClearMap(void);
void AddMapTile(MapTile* tile);
void RemoveMapTile(MapTile * node); //MARK: If I can remove it, don't I need to mark that?
MapTile* GetMapTile(MapTile* tile, Vector2 pos);
void CreateMapTile(int ID, int x, int y);
void UpdateMapTile(void);

//make some preset rooms and then an algorithm to set them
void MakeSquare(void);

#endif /* Map_h */
