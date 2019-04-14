//
//  Utilities.c
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/14/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Utilities.h"

int QNodeYSort(const void *a, const void *b) //ONLY WORKS WITH Y RIGHT NOW
{
    struct Node *ia = (struct Node *)a;
    struct Node *ib = (struct Node *)b;
    return (int)(ia->position.y - ib->position.y);
    /* float comparison: returns negative if b > a
     and positive if a > b. We multiplied result by 100.0
     to preserve decimal fraction */
/*
    const Node *p1 = *(const Node **)v1;
    const Node *p2 = *(const Node **)v2;

    if (p1->position.y < p2->position.y)
        return -1;
    else if (p1->position.y > p2->position.y)
        return +1;
    else
        return 0;*/
}
