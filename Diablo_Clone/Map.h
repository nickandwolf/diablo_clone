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

//TODO: HEY FIGURE OUT X AND Y SHIT, YO!

//make this a real thing
static const int MAPHEIGHT = 100;

enum MAP_ID {
    FLOOR,
    WALL,
    TOP_WALL,
    DOOR
};

//make a struct that holds map data shit? That way render doesn't have to do shit...?
extern int* MasterMap;

//make a floor and ceiling map for...like...depth of something

int GetTile(int x, int y);
void InitMap(int total);
void ClearMap(void);

//make some preset rooms and then an algorithm to set them
void MakeSquare(void);

#endif /* Map_h */
