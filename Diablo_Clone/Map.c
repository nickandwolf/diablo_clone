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
            CreateMapTile(data[j], x*TILESIZE, y*TILESIZE);
            x++;
            if (x > map_width) {
                x = 0;
                y++;
            }
        }
    }
    free(data); //do we gotta do this?, if we wanna save 1.2MB of memory, yes...
}

bool CheckMapCollision(Rectangle pos) {
    MapTile* temp1 = MapHead;
    
    while (temp1 != NULL) {
        if (temp1->collisionRect.x == -1 && temp1->collisionRect.y == -1 && temp1->collisionRect.width == -1 && temp1->collisionRect.height == -1) {
            
        }
        //SO WE ONLY ALLOW PERFECT SQUARE BOXES SO FAR BECAUSE OF HOW THE ENGINE RENDERS X and Y- FUCK I JUST REMEMBERED HOW TO DO THIS RIGHT
        else if (pos.x < temp1->collisionRect.x + temp1->collisionRect.width &&
            pos.x + pos.width > temp1->collisionRect.x &&
            pos.y < temp1->collisionRect.y + temp1->collisionRect.height &&
            pos.y + pos.height > temp1->collisionRect.y)
            return false;
        temp1 = temp1->next;
    }
    return true;
}
