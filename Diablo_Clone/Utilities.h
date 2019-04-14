//
//  Utilities.h
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/14/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef Utilities_h
#define Utilities_h

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

//int md_comparator(const void *v1, const void *v2);
int QNodeYSort( const void *_x, const void *_y );
/* integer array printing function */
void print_int_array(const int *array, size_t len);

void sort_integers_example(void);

void SortNodeByY(void);

#endif /* Utilities_h */
