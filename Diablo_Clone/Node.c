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

void RemoveNode( Node * node ) {
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
        }
        
        current = current->next;
    }
}

void HandleInput(Node * node) { //TODO: add freakin' collision detection
    
    if (IsKeyDown(KEY_RIGHT)) {
        node->position.x += 1.0f;
    }
    
    else if (IsKeyDown(KEY_LEFT)) {
        node->position.x -= 1.0f;
    }
    
    if (IsKeyDown(KEY_UP)) {
        node->position.y -= 1.0f;
    }
    
    else if (IsKeyDown(KEY_DOWN)) {
        node->position.y += 1.0f;
    }
}
