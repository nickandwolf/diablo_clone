//
//  Node.h
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raylib.h"
#include "Input.h"

enum NODE_ID {
    PLAYER //placeholder for classes
};

enum TILE_ID { //This dumb shit is the ID from the editor
    FLOOR = 42, //This is probably dumb and can be merged with the NODE_ID enum later
    WALL = 262,
    TAPESTRY_WALL = 285,
    TOP_WALL = 282,
    BOTTOM_WALL = 2, //custom made, yo just for the collision box
    DOOR
};

enum MAP_ID {
    TEST_LEVEL = 0
};

typedef struct Node {
    int ID; //type of thingy
    int UID; //actually unique thingy
    Vector2 position;
    //Texture2D spriteSheet; // All sprites use the same 4 character sheets
    Rectangle frameRect;     // Also there's a lot of white space between sprites
    struct Node* next;       // so we'll have to clean that up in time
    Rectangle collisionRect;
    int layer;               //0 = floor; 1 = stuff on floor; 2 = higher than that, like players; 3 = highest so FAR
} Node;

//MAP SHIT
static const int MAPHEIGHT = 100; //wtf does this even do?
extern const int TILESIZE;
static int map_width = 0;
static int map_height = 0;

extern Camera2D camera;
extern Node* NodeHead;
static int master_UID = 1; //MAP TILES ARE 0 RIGHT NOW
                           //IF WE HAVE DESTRUCTABLE SHIT, WE'LL ADD IT BACK

//MAKE ACTIONS IN HERE TOO, LIKE MOVE COLLISION SHIT AND MOVE PLAYER SHIT

void print_list(void);

void InitHeadNode(void);

void AddNode(Node* node);

void RemoveNode( Node * node );

void ClearMap(void);

Node* GetNode(int UID);//fix this to not take node

Node* GetNodeXY(int x, int y);

void CreateNode(int ID);

void CreateMapNode(int ID, int x, int y);

void UpdateNode(void);

void HandleInput(Node * node);

bool CheckNodeCollision(Rectangle pos, int UID);

bool CheckNodeSpriteCollision(Rectangle pos, int UID); //TODO: implement

void MakeMap(int mapID);

void MergeSort(Node** headRef);

Node* SortedMerge(Node* a, Node* b);

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);

#endif /* Node_h */
