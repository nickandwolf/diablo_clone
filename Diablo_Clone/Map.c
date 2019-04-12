//
//  Map.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/11/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Map.h"

void InitMapHead() {
    MapHead = NULL;
    MapHead = malloc(sizeof(MapTile));
    MapHead->next = NULL;
    MapHead->frameRect.x = 0;
    MapHead->frameRect.y = 0;
    MapHead->frameRect.width = 0;
    MapHead->frameRect.height = 0;
    MapHead->ID = -1;
    MapHead->position.x = -1;
    MapHead->position.y = -1;
}

void ClearMap() {
    free(MapHead);
}

void AddMapTile(MapTile* tile) {
    MapTile * current = MapHead;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = malloc(sizeof(MapTile));
    current->next = tile;
    current->next->next = NULL;
}

void RemoveMapTile(MapTile * tile) { //TODO: See Node as borked
    MapTile * temp = tile->next;
    
    tile->next = temp->next;
    free(temp);
}

MapTile* GetMapTile(MapTile* tile, Vector2 pos) { //TODO: Probably broken
    while (tile != NULL && tile->position.x != pos.x && tile->position.y != pos.y) {
        tile = tile->next;
    }
    
    return tile;
}

void CreateMapTile(int ID, int x, int y) {
    MapTile * temp = NULL;
    temp = malloc(sizeof(MapTile));
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
            
        case TOP_WALL:
            temp->frameRect = (Rectangle){48,672,48,48};
            temp->ID = ID;
            temp->position = (Vector2){x, y};
            temp->collisionRect = (Rectangle){temp->position.x, temp->position.y, 48, 48};
            break;
            
        default:
            temp->frameRect = (Rectangle){0,0,48,48};
            temp->ID = ID;
            temp->position = (Vector2){-1, -1};
            temp->collisionRect = (Rectangle){temp->position.x, temp->position.y, 48, 48};
            break;
    }
    
    AddMapTile(temp);
}

void UpdateMapTile() { //for animations, I guess...
    MapTile* current = MapHead;
    
    while (current != NULL) {
        switch(current->ID) {
            case FLOOR:
                
                break;
                
            case 1:
                
                break;
        }
        
        current = current->next;
    }
}

void MakeSquare() {
    //int id = 0;
    //for (int x )
    //CreateMapTile(id, x, y)
}
