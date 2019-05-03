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
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "raylib.h"
#include "Input.h"

#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )
#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )

enum TYPE_ID {
    MAP_TILE = 0,
    PC,
    NPC,
    OBJECT
};

enum NODE_ID {
    PLAYER //placeholder for classes
};

enum TILE_ID { //This dumb shit is the ID from the editor
    FLOOR = 42, //This is probably dumb and can be merged with the NODE_ID enum later
    TOP_WALL = 262,
    BOTTOM_WALL = 282,
    FULL_WALL = 3, //This is a whole wall
    TAPESTRY_WALL = 285,
    FILLER_WALL = 2, //custom made, yo just for the collision box
    DOOR
};

enum MAP_ID {
    TEST_LEVEL = 0
};

typedef struct Node {
    //Engine
    int TYPE; //type of thingy
    int ID; //sub-type of thingy
    int UID; //actually unique thingy
    Vector2 position;
    //Texture2D spriteSheet; // All sprites use the same 4 character sheets
    Rectangle frameRect;     // Also there's a lot of white space between sprites
    struct Node* next;       // so we'll have to clean that up in time
    Rectangle collisionRect;
    int layer;               //0 = floor; 1 = stuff on floor; 2 = higher than that, like players; 3 = highest so FAR
    float MOVEMENT_SPEED;
    float movementSpeed;
    
    bool visible; //useless right now
    bool seen; //only for map nodes
    
    //Stats
    int level;
    int EXP;
    int curHP;
    int maxHP; //probably not needed depending on how quick it executes
    
    int curMP;
    int maxMP;
    
    int STR;
    int STR_H; //to hit
    int STR_D; //damage
    
    int DEX;
    int DEX_H; //to hit w/ ranged
    int DEX_AC; //AC bonus
    
    int CON;
    int CON_HP; //Hit point bonus //TODO:Implement sub-stats
    int CON_CC; //Carrying Capacity
    
    int INT;
    int INT_P; //magic power
    int INT_MP;//magic points
    
    int WIS;
    int WIS_V; //visibility radius //TODO: figure this shit out
    int WIS_N; //notice
    int visibilityRadius; //MARK: PLACEHOLDER!!!
    
    int CHA;
    int CHA_L; //loot chance
    int CHA_M; //merchant
    
    
} Node;

//MAP SHIT
static const int MAPHEIGHT = 100; //wtf does this even do?
extern const int TILESIZE;
static int map_width = 0;
static int map_height = 0;

extern Camera2D camera;
extern Node* NodeHead;
extern Node* MainPlayer;
static int master_UID = 1; //MAP TILES ARE 0 RIGHT NOW
                           //IF WE HAVE DESTRUCTABLE SHIT, WE'LL ADD IT BACK

//MAKE ACTIONS IN HERE TOO, LIKE MOVE COLLISION SHIT AND MOVE PLAYER SHIT

//ENGINE SHIT
void InitHeadNode(void);
void CreateNode(int ID);
void UpdateNode(void);
void AddNode(Node* node);
void RemoveNode( Node * node );
Node* GetNode(int UID);//fix this to not take node
Node* GetNodeXY(int x, int y);
bool CheckNodeCollision(Node * node, int x, int y);
bool CheckNodeSpriteCollision(Rectangle pos, int UID); //TODO: implement
bool CheckCircleCollision(Vector2 pos, float radius, Rectangle rec); //TODO: add blocking line of sight
bool GetNullRect(Node * rect);
void MergeSort(Node** headRef);
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);

//DEBUG
void print_list(void);

//MAP SHIT
void MakeMap(int mapID);
void CreateMapNode(int ID, int x, int y);
void ClearMap(void);
void MarkSeen(Node * node);

//PLAYER SHIT
void CreatePlayer(void);
void HandleInput(void);
void MakeVisible(Node * node);
void MakeInvisible(Node * node);
void LevelUp(void);
void CalculateHP(Node * node); //when do we call this shit? May need to make a "check if something changed stats wise" check function check check
void CalculateCarryCapacity(Node * node);//when would we call this?
void CalculateVisibilityRadius(Node * node);

#endif /* Node_h */


//bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
