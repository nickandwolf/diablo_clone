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
    
    //GOTTA MOVE EVERYTHING!
    node->UID = node->next->UID;
    
    node->next = temp->next;
    free(temp);
}

Node* GetNode(Node* node, int UID) {
    while (node != NULL && node->UID != UID) {
        node = node->next;
    }
    
    return node;
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
    
    //THIS SHIT IS FUCKING STUPID
    //Won't let me move away from the collision!
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
