//
//  Quiz20.h
//  LeetCodePractice
//
//  Created by White on 2018/9/15.
//  Copyright © 2018年 White. All rights reserved.
//

#ifndef Quiz20_h
#define Quiz20_h

#include <stdio.h>

typedef struct {
    int* val;
    int* minValueIndex;
    int currentSize;
    int maxSize;
} MinStack;

MinStack* minStackCreate(int maxSize);

void minStackPush(MinStack* obj, int x);

void minStackPop(MinStack* obj);

int minStackTop(MinStack* obj);

int minStackGetMin(MinStack* obj);

void minStackFree(MinStack* obj);

#endif /* Quiz20_h */
