//
//  Map.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/11/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Map.h"

void InitMap(int total) {
    MasterMap = calloc(total, sizeof(int));
}

void ClearMap() {
    free(MasterMap);
}

//MAKE THIS SHIT VARIABLE STUFF, YO
int GetTile(int x, int y) {
    return MasterMap[y * 20 + x];
}

void MakeSquare() {
    InitMap(400);//gotta fix this, just for debugginggnigng now
    
    //ALSO! AAAALLLSOOOO!!! This method doesn't save any memory
    int temp[] = {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    
    memcpy(MasterMap, temp, sizeof(temp));
    
    /*for (int i = 0; i < 11; i++)
        *(MasterMap + i) = 1;
    
    for (int i = 0; i < 8; i++)
        *(MasterMap + i + 11) = 0;
    
    *(MasterMap + 19) = 1;
    
    for (int i = 0; i < 8; i++)
        *(MasterMap + i + 27) = 0;
    
    *(MasterMap + 35) = 1;*/
}
