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
    NodeHead->frameRect.x = 0;
    NodeHead->frameRect.y = 0;
    NodeHead->frameRect.width = 0;
    NodeHead->frameRect.height = 0;
    NodeHead->ID = -1;
    NodeHead->UID = -1;
    NodeHead->position.x = -1;
    NodeHead->position.y = -1;
}

void AddNode(Node* node) {
    Node * current = NodeHead;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(Node));
    current->next = node;
    current->next->next = NULL;
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

void CreateNode(int ID) {
    Node * temp = NULL;
    temp = malloc(sizeof(Node));
    temp->next = NULL;//probably not needed
    
    switch(ID) {
        case PLAYER:
            temp->frameRect = (Rectangle){0,0,48,48};
            temp->ID = ID;
            temp->position = (Vector2){60,60};
            temp->UID = master_UID;
            temp->collisionRect = (Rectangle){temp->position.x + 15, temp->position.y+31, 18, 9};
            break;
            
        case 1:
            temp->frameRect = (Rectangle){0,0,48,48};
            temp->ID = ID;
            temp->position = (Vector2){160,160};
            temp->UID = master_UID;
            temp->collisionRect = (Rectangle){temp->position.x + 15, temp->position.y+31, 18, 9};
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
            temp->collisionRect = (Rectangle){-1,-1,-1,-1};
            break;
            
        case WALL:
            temp->frameRect = (Rectangle){48,624,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){temp->position.x, temp->position.y, 48, 48};
            break;
            
        case TAPESTRY_WALL:
            temp->frameRect = (Rectangle){192,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){temp->position.x, temp->position.y, 48, 48};
            break;
            
        case TOP_WALL:
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){temp->position.x, temp->position.y+24, 48, 24};
            break;
            
        case BOTTOM_WALL:
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){temp->position.x, temp->position.y, 48, 48};
            break;
            
        default:
            temp->frameRect = (Rectangle){0,0,48,48};
            temp->ID = ID;
            temp->position = (Vector2){-1, -1};
            temp->collisionRect = (Rectangle){0, 0, 0, 0};
            break;
    }
    
    if (temp != NULL) {
        temp->UID = 0;
        AddNode(temp);
    }
}

void UpdateNode() {
    Node* current = NodeHead;
    
    while (current != NULL) {
        switch(current->ID) {
            case PLAYER:
                HandleInput(current);
                break;
                
            case 1:
                
                break;
        }
        
        current = current->next;
    }
}

void HandleInput(Node * node) { //TODO: add freakin' collision detection
    if (IsKeyDown(KEY_RIGHT)) {
        if (CheckNodeCollision((Rectangle) {node->collisionRect.x + 1, node->collisionRect.y, node->collisionRect.width, node->collisionRect.height}, node->UID)) {
            node->position.x += 1.0f;
            node->collisionRect = (Rectangle){node->position.x + 15, node->position.y+31, 18, 9};
        }
    }
    
    else if (IsKeyDown(KEY_LEFT)) {
        if (CheckNodeCollision((Rectangle) {node->collisionRect.x - 1, node->collisionRect.y, node->collisionRect.width, node->collisionRect.height}, node->UID)) {
            node->position.x -= 1.0f;
            node->collisionRect = (Rectangle){node->position.x + 15, node->position.y+31, 18, 9};
        }
    }
    
    if (IsKeyDown(KEY_UP)) {
        if (CheckNodeCollision((Rectangle) {node->collisionRect.x, node->collisionRect.y - 1, node->collisionRect.width, node->collisionRect.height}, node->UID)) {
            node->position.y -= 1.0f;
            node->collisionRect = (Rectangle){node->position.x + 15, node->position.y+31, 18, 9};
        }
    }
    
    else if (IsKeyDown(KEY_DOWN)) {
        if (CheckNodeCollision((Rectangle) {node->collisionRect.x, node->collisionRect.y + 1, node->collisionRect.width, node->collisionRect.height}, node->UID)) {
            node->position.y += 1.0f;
            node->collisionRect = (Rectangle){node->position.x + 15, node->position.y+31, 18, 9};
        }
    }
}

bool CheckNodeCollision(Rectangle pos, int UID) {
    Node* temp1 = NodeHead;
    
    while (temp1 != NULL) {
        if (UID != temp1->UID) {
            if (pos.x < temp1->collisionRect.x + temp1->collisionRect.width &&
                pos.x + pos.width > temp1->collisionRect.x &&
                pos.y < temp1->collisionRect.y + temp1->collisionRect.height &&
                pos.y + pos.height > temp1->collisionRect.y)
                return false;
        }
        
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
            
            int temp[] = {262,282,282,282,282,282,285,282,282,282,282,282,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
                262,42,42,42,42,42,42,42,42,42,42,42,262,0,0,0,
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
