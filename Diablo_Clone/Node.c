//
//  Node.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Node.h"

void print_list() { //THIS IS DEBUG SHIT
    Node * current = NodeHead;
    
    while (current != NULL) {
        printf("%d\n", current->ID);
        current = current->next;
    }
}

void InitHeadNode(void) {
    NodeHead = NULL;
    NodeHead = malloc(sizeof(Node));
    NodeHead->next = NULL; //what data should head contain?
    
    //TODO: fix this if collision bullshit works
    NodeHead->COLLISION_X = 0;
    NodeHead->COLLISION_Y = 0;
    NodeHead->COLLISION_WIDTH = 0;
    NodeHead->COLLISION_HEIGHT = 0;
    NodeHead->ID = -1;
    NodeHead->UID = -1;
    NodeHead->position.x = -1;
    NodeHead->position.y = -1;
    NodeHead->layer = -1;
}

void AddNode(Node* node) {
    Node * current = NodeHead;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(Node));
    current->next = node;
    //current->next->next = NULL;
}

void RemoveNode( Node * node ) { //TODO: Never actually tested this, pretty sure it's borked
    Node * temp = node->next;
    
    node->next = temp->next;
    free(temp);
}

void ClearMap() {
    Node* temp = NodeHead->next;
    while (temp != NULL) {
        if (temp->UID == 0) {
            RemoveNode(temp); //GOTTA TEST THIS!
        }
    }
}

Node* GetNode(int UID) {
    Node * node = NodeHead->next;
    while (node != NULL && node->UID != UID) {
        node = node->next;
    }
    
    return node;
}

Node* GetNodeXY(int x, int y) { //TODO: Probably broken
    Node * temp = NodeHead->next;
    while (temp != NULL && temp->position.x != x && temp->position.y != y) {
        temp = temp->next;
    }
    
    return temp;
}

void CreatePlayer() {
    MainPlayer = malloc(sizeof(Node));
    MainPlayer->next = NULL;
    
    MainPlayer->frameRect = (Rectangle){0,0,48,48};
    MainPlayer->ID = 0;
    MainPlayer->position = (Vector2){60,60};
    MainPlayer->UID = master_UID;                       //TODO: MAKE THIS MORE DYNAMIC! MAKE COLLISION BOXES DYNAMIC!!!
    MainPlayer->COLLISION_X = 15;
    MainPlayer->COLLISION_Y = 31;
    MainPlayer->COLLISION_WIDTH = 18;
    MainPlayer->COLLISION_HEIGHT = 9;
    MainPlayer->layer = 2;
    master_UID++;
    
    AddNode(MainPlayer);
}

void CreateNode(int ID) {
    Node * temp = NULL;
    temp = malloc(sizeof(Node));
    temp->next = NULL;//probably not needed
    
    switch(ID) {
        case PLAYER:
            //ERROR, BRO!
            break;
            
        case 1:
            temp->frameRect = (Rectangle){0,0,48,48};
            temp->ID = ID;
            temp->position = (Vector2){160,160};
            temp->UID = master_UID;
            temp->COLLISION_X = 15;
            temp->COLLISION_Y = 31;
            temp->COLLISION_WIDTH = 18;
            temp->COLLISION_HEIGHT = 9;
            temp->layer = 2;
            break;
    }
    
    if (temp != NULL) {
        master_UID++;
        AddNode(temp);
    }
}

void CreateMapNode(int ID, int x, int y) {
    Node * temp = NULL;
    temp = malloc(sizeof(Node));
    temp->next = NULL;//probably not needed
    
    switch(ID) {
        case FLOOR:
            temp->frameRect = (Rectangle){48,48,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x,y};
            temp->COLLISION_X = 0;
            temp->COLLISION_Y = 0;
            temp->COLLISION_WIDTH = 0;
            temp->COLLISION_HEIGHT = 0;
            temp->layer = 0;
            break;
            
        case BOTTOM_WALL:
            //temp->frameRect = (Rectangle){48,624,48,48};
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->COLLISION_X = 0;
            temp->COLLISION_Y = 24;
            temp->COLLISION_WIDTH = TILESIZE;
            temp->COLLISION_HEIGHT = 24;
            temp->layer = 3;
            break;
            
        case TAPESTRY_WALL:
            temp->frameRect = (Rectangle){192,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->COLLISION_X = 0;
            temp->COLLISION_Y = 0;
            temp->COLLISION_WIDTH = TILESIZE;
            temp->COLLISION_HEIGHT = TILESIZE;
            temp->layer = 1;
            break;
            
        case TOP_WALL:
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->COLLISION_X = 0;
            temp->COLLISION_Y = 24;
            temp->COLLISION_WIDTH = TILESIZE;
            temp->COLLISION_HEIGHT = 24;
            temp->layer = 1;
            break;
       
        case FULL_WALL:
            temp->frameRect = (Rectangle){48,624,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->COLLISION_X = 0;
            temp->COLLISION_Y = 0;
            temp->COLLISION_WIDTH = TILESIZE;
            temp->COLLISION_HEIGHT = TILESIZE;
            temp->layer = 3;
            break;
            
        case FILLER_WALL:
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->COLLISION_X = 0;
            temp->COLLISION_Y = 0;
            temp->COLLISION_WIDTH = TILESIZE;
            temp->COLLISION_HEIGHT = TILESIZE;
            temp->layer = 3;
            break;
            
        default:
            temp->frameRect = (Rectangle){0,0,48,48};
            temp->ID = ID;
            temp->position = (Vector2){-1, -1};
            temp->COLLISION_X = 0;
            temp->COLLISION_Y = 0;
            temp->COLLISION_WIDTH = 0;
            temp->COLLISION_HEIGHT = 0;
            temp->layer = -1;
            break;
    }
    
    temp->UID = 0;
    AddNode(temp);
}

void UpdateNode() {
    MergeSort(&NodeHead);
    
    Node* current = NodeHead;
    
    while (current != NULL) {
        if (current->UID == 0) {
            
        }
        
        else {
            switch(current->ID) {
                case PLAYER:
                    if (current->UID == MainPlayer->UID)
                        HandleInput();
                    break;
                    
                case 1:
                    
                    break;
            }
        }
        current = current->next;
    }
}

void HandleInput() {
    if (IsKeyDown(MoveRightKey)) {
        if (CheckNodeCollision(MainPlayer,1,0)) {
            MainPlayer->position.x += 1.0f;
            camera.offset.x -= 1.0f * camera.zoom;
        }
    }
    
    else if (IsKeyDown(MoveLeftKey)) {
        if (CheckNodeCollision(MainPlayer,-1,0)) {
            MainPlayer->position.x -= 1.0f;
            camera.offset.x += 1.0f * camera.zoom;
        }
    }
    
    if (IsKeyDown(MoveUpKey)) {
        if (CheckNodeCollision(MainPlayer,0,-1)) {
            MainPlayer->position.y -= 1.0f;
            camera.offset.y += 1.0f * camera.zoom;
        }
    }
    
    else if (IsKeyDown(MoveDownKey)) {
        if (CheckNodeCollision(MainPlayer,0,1)) {
            MainPlayer->position.y += 1.0f;
            camera.offset.y -= 1.0f * camera.zoom;
        }
    }
}

bool CheckNodeCollision(Node * node, int x, int y) {
    Node* temp1 = NodeHead;
    
    while (temp1 != NULL) {
        if (node->UID != temp1->UID && (!GetNullRect(temp1)))
            if ((node->position.x + node->COLLISION_X + x < temp1->COLLISION_X + temp1->position.x + temp1->COLLISION_WIDTH) &&
                (node->position.x + node->COLLISION_X + x + node->COLLISION_WIDTH > temp1->COLLISION_X + temp1->position.x) &&
                (node->position.y + node->COLLISION_Y + y < temp1->COLLISION_Y + temp1->position.y + temp1->COLLISION_HEIGHT) &&
                (node->position.y + node->COLLISION_Y + y + node->COLLISION_HEIGHT > temp1->COLLISION_Y + temp1->position.y))
                return false;
        
        temp1 = temp1->next;
    }
    
    return true;
}

void MakeMap(int mapID) {
    int* data = 0;
    int length = 0;
    switch (mapID) {
        case TEST_LEVEL:
            map_width = 12;
            map_height = 10;
            
            int temp[] = {3,262,262,262,262,262,285,262,262,262,262,262,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                3,42,42,42,42,42,42,42,42,42,42,42,3,0,0,0,
                2,282,282,282,282,282,282,282,282,282,282,282,2,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            
            length = sizeof(temp)/sizeof(int);
            data = calloc(length, sizeof(int));
            memcpy(data, temp, sizeof(temp));
            break;
            
        default:
            
            break;
    }
    
    int x = 0;
    int y = 0;
    
    for (int j = 0; j < length; j++) {
        if (data[j] != 0 ) { //There's a bunch of stupid 0s in the map data. So we skip that.
            CreateMapNode(data[j], x*TILESIZE, y*TILESIZE);
            x++;
            if (x > map_width) {
                x = 0;
                y++;
            }
        }
    }
    
    free(data); //do we gotta do this?, if we wanna save 1.2MB of memory, yes...
}

void MergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* a;
    Node* b;
    
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
    
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
    
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b) {
    Node* result = NULL;
    
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    
    /* Pick either a or b, and recur */
    if (a->position.y <= b->position.y) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    /* 'slow' is before the midpoint in the list, so split it in two
     at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Rectangle GetNodeCollisionRect(Node* node) {
    return (Rectangle) {node->COLLISION_X + node->position.x, node->COLLISION_Y + node->position.y, node->COLLISION_WIDTH, node->COLLISION_HEIGHT};
}

Rectangle GetNodeCollisionRectXYWH(float collision_x, float collision_y, float collision_width, float collision_height) {
    return (Rectangle) {collision_x, collision_y, collision_width, collision_height};
}

bool GetNullRect(Node * rect) {
    if (rect->COLLISION_X == 0 && rect->COLLISION_Y == 0 && rect->COLLISION_WIDTH == 0 & rect->COLLISION_HEIGHT == 0)
        return true;
    return false;
}
