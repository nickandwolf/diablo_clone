//
//  main.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/7/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "raylib.h"
#include "Node.h"
#include "Render.h"

Node * NodeHead;

int main(int argc, const char * argv[]) {
    InitRender();
    InitHeadNode();
    
    Node * shit = NULL;
    
    CreateNode(0);//this shit needs to be fixed too
    
    while (!WindowShouldClose()) {
        RenderDraw();
        RenderUpdate();
    }
//GIANT DEBUG FOR POINTERS
//    Node * shit = NULL;
//    shit = malloc(sizeof(Node));
//    shit->ID = 100;
//    shit->UID = 200;
//
//    AddNode(shit);
//
//    Node * shitt = NULL;
//    shitt = malloc(sizeof(Node));
//    shitt->ID = 10;
//    shitt->UID = 20;
//
//    AddNode(shitt);
//
//    Node * shittt = NULL;
//    shittt = malloc(sizeof(Node));
//    shittt->ID = 1;
//    shittt->UID = 2;
//
//    AddNode(shittt);
//
//    print_list();
    
    return 0;
}
