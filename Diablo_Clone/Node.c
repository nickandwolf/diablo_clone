//
//  Node.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Node.h"

//DEBUG
void print_list() { //THIS IS DEBUG SHIT
    Node * current = NodeHead;
    
    while (current != NULL) {
        printf("%d\n", current->ID);
        current = current->next;
    }
}

//ENGINE
void InitHeadNode(void) {
    NodeHead = NULL;
    NodeHead = malloc(sizeof(Node));
    NodeHead->next = NULL; //what data should head contain?
    
    //TODO: fix this if collision bullshit works
    NodeHead->collisionRect = (Rectangle){0,0,0,0};
    NodeHead->ID = -1;
    NodeHead->UID = -1;
    NodeHead->position.x = -1;
    NodeHead->position.y = -1;
    NodeHead->layer = -1;
    NodeHead->movementSpeed = -1;
    NodeHead->MOVEMENT_SPEED = -1;
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
            temp->collisionRect = (Rectangle){15,31,18,9};
            temp->layer = 2;
            temp->visible = false;
            break;
    }
    
    if (temp != NULL) {
        master_UID++;
        AddNode(temp);
    }
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
bool CheckNodeCollision(Node * node, int x, int y) {
    Node* temp1 = NodeHead;
    
    while (temp1 != NULL) {
        if (node->UID != temp1->UID) {
            if (!GetNullRect(temp1))
                if ((node->position.x + node->collisionRect.x + x < temp1->collisionRect.x + temp1->position.x + temp1->collisionRect.width) &&
                    (node->position.x + node->collisionRect.x + x + node->collisionRect.width > temp1->collisionRect.x + temp1->position.x) &&
                    (node->position.y + node->collisionRect.y + y < temp1->collisionRect.y + temp1->position.y + temp1->collisionRect.height) &&
                    (node->position.y + node->collisionRect.y + y + node->collisionRect.height > temp1->collisionRect.y + temp1->position.y))
                    return false;
        }
        
        temp1 = temp1->next;
    }
    return true;
}
//check sprite collision
bool CheckCircleCollision(Vector2 pos, float radius, Rectangle rec) {
    float deltaX = pos.x - MAX(rec.x, MIN(pos.x, rec.x + rec.width));
    float deltaY = pos.y - MAX(rec.y, MIN(pos.y, rec.y + rec.height));
    return (deltaX * deltaX + deltaY * deltaY) < (radius * radius);
}
bool GetNullRect(Node * rect) {
    if (rect->collisionRect.x == 0 && rect->collisionRect.y == 0 && rect->collisionRect.width == 0 & rect->collisionRect.height == 0)
        return true;
    return false;
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

//MAP
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
void CreateMapNode(int ID, int x, int y) {
    Node * temp = NULL;
    temp = malloc(sizeof(Node));
    temp->next = NULL;//probably not needed
    
    switch(ID) {
        case FLOOR:
            temp->frameRect = (Rectangle){48,48,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x,y};
            temp->collisionRect = (Rectangle){0,0,0,0};
            temp->layer = 0;
            temp->visible = false;
            break;
            
        case BOTTOM_WALL:
            //temp->frameRect = (Rectangle){48,624,48,48};
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){0,24,TILESIZE,24};
            temp->layer = 3;
            temp->visible = false;
            break;
            
        case TAPESTRY_WALL:
            temp->frameRect = (Rectangle){192,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){0,0,TILESIZE,TILESIZE};
            temp->layer = 1;
            temp->visible = false;
            break;
            
        case TOP_WALL:
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){0,24,TILESIZE,24};
            temp->layer = 1;
            temp->visible = false;
            break;
            
        case FULL_WALL:
            temp->frameRect = (Rectangle){48,624,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){0,0,TILESIZE,TILESIZE};
            temp->layer = 3;
            temp->visible = false;
            break;
            
        case FILLER_WALL:
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){0,0,TILESIZE,TILESIZE};
            temp->layer = 3;
            temp->visible = false;
            break;
            
        default:
            temp->frameRect = (Rectangle){0,0,48,48};
            temp->ID = ID;
            temp->position = (Vector2){-1, -1};
            temp->collisionRect = (Rectangle){0,0,0,0};
            temp->layer = -1;
            temp->visible = false;
            break;
    }
    
    temp->UID = 0;
    AddNode(temp);
}
void ClearMap() {
    Node* temp = NodeHead->next;
    while (temp != NULL) {
        if (temp->UID == 0) {
            RemoveNode(temp); //GOTTA TEST THIS!
        }
    }
}

//PLAYER
void CreatePlayer() {
    MainPlayer = malloc(sizeof(Node));
    MainPlayer->next = NULL;
    
    MainPlayer->frameRect = (Rectangle){0,0,48,48};
    MainPlayer->ID = 0;
    MainPlayer->position = (Vector2){60,60};
    MainPlayer->UID = master_UID; //TODO: MAKE THIS MORE DYNAMIC! MAKE COLLISION BOXES DYNAMIC!!!
    MainPlayer->collisionRect = (Rectangle){15,31,18,9};
    MainPlayer->layer = 2;
    MainPlayer->movementSpeed = 2.0f;
    MainPlayer->MOVEMENT_SPEED = 2.0f;
    MainPlayer->visible = true;
    master_UID++;
    
    MainPlayer->level = 1;
    MainPlayer->CON = 5;
    MainPlayer->CON_HP = 0;
    MainPlayer->CON_CC = 0;
    
    AddNode(MainPlayer);
}
void HandleInput() {
    CalculateHP(MainPlayer);
    
    if (IsKeyDown(MoveRightKey)) {
        if (CheckNodeCollision(MainPlayer,MainPlayer->movementSpeed,0)) {
            MainPlayer->position.x += MainPlayer->movementSpeed;
            camera.offset.x -= MainPlayer->movementSpeed * camera.zoom; //TODO: FIX THE CAMERA
        }
    }
    
    else if (IsKeyDown(MoveLeftKey)) {
        if (CheckNodeCollision(MainPlayer,-MainPlayer->movementSpeed,0)) {
            MainPlayer->position.x -= MainPlayer->movementSpeed;
            camera.offset.x += MainPlayer->movementSpeed * camera.zoom;
        }
    }
    
    if (IsKeyDown(MoveUpKey)) {
        if (CheckNodeCollision(MainPlayer,0,-MainPlayer->movementSpeed)) {
            MainPlayer->position.y -= MainPlayer->movementSpeed;
            camera.offset.y += MainPlayer->movementSpeed * camera.zoom;
        }
    }
    
    else if (IsKeyDown(MoveDownKey)) {
        if (CheckNodeCollision(MainPlayer,0,MainPlayer->movementSpeed)) {
            MainPlayer->position.y += MainPlayer->movementSpeed;
            camera.offset.y -= MainPlayer->movementSpeed * camera.zoom;
        }
    }
    
    if (IsKeyPressed((MoveRunKey))) {
        MainPlayer->movementSpeed = MainPlayer->MOVEMENT_SPEED*2;
    }
    else if (IsKeyUp(MoveRunKey)) {
        MainPlayer->movementSpeed = MainPlayer->MOVEMENT_SPEED;
    }
    
    if (IsKeyDown(CameraZoomIn)) { //TODO: FIX THIS
        //if (camera.zoom < 6.0f) camera.zoom += 0.05f;
        //else camera.zoom = 6.0f;
    }
    else if (IsKeyDown(CameraZoomOut)) {
        //if (camera.zoom > 0.5f) camera.zoom -= 0.05f;
        //else camera.zoom = 0.5f;
    }
}

void MakeVisible(Node * node) {
    if (node->visible == false) node->visible = true;
}

void MakeInvisible(Node * node) {
    if (node->visible == true) node->visible = false;
}

void CalculateHP(Node * node) {
    int max = node->maxHP;
    node->maxHP = ((node->CON * 3) + (node->CON_HP * 2)) * node->level;
    node->curHP += node->maxHP - max;
    if (node->curHP > node->maxHP) node->curHP = node->maxHP;
    if (node->curHP < 1) node->curHP = 1;
}
