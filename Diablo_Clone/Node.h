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

enum NODE_ID {
    PLAYER //placeholder for classes
};

typedef struct Node {
    int ID; //type of thingy
    int UID; //actually unique thingy
    Vector2 position;
    //Texture2D spriteSheet; // All sprites use the same 4 character sheets
    Rectangle frameRect;     // Also there's a lot of white space between sprites
    struct Node* next;       // so we'll have to clean that up in time
    Rectangle collisionRect;
} Node;

extern Node* NodeHead;
static int master_UID = 0;

//MAKE ACTIONS IN HERE TOO, LIKE MOVE COLLISION SHIT AND MOVE PLAYER SHIT

void print_list(void);

void InitHeadNode(void);

void AddNode(Node* node);

void RemoveNode( Node * node );

Node* GetNode(Node* node, int UID);

void CreateNode(int ID);

void UpdateNode(void);

void HandleInput(Node * node);

bool CheckNodeCollision(Rectangle pos, int UID);

#endif /* Node_h */
