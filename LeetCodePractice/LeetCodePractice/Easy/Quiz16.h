//
//  Quiz16.h
//  LeetCodePractice
//
//  Created by White on 2018/9/10.
//  Copyright © 2018年 White. All rights reserved.
//

#ifndef Quiz16_h
#define Quiz16_h

#include <stdio.h>

typedef struct {
    int*    original;
    int     size;
} Solution;

Solution* solutionCreate(int* nums, int size);

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize);

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize);

void solutionFree(Solution* obj);

#endif /* Quiz16_h */
