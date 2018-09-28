//
//  CommonStack.h
//  LeetCodePractice
//
//  Created by White on 2018/9/28.
//  Copyright © 2018年 White. All rights reserved.
//

#ifndef CommonStack_h
#define CommonStack_h

#include <stdio.h>

#ifndef _STACK_H
#define _STACK_H

struct CommonStackNode {
    void* data;
    struct CommonStackNode* next;
};

typedef struct CommonStackNode* CommonStack;

/* 判断栈是否为空 */
bool isEmpty(CommonStack s);
/* create stack */
CommonStack createStack(void);
/* release stack */
void releaseStack(CommonStack s);
/* 入栈 */
void push(void *data, CommonStack s);
/* 取栈顶元素 */
void* top(CommonStack s);
/* 出栈 */
void pop(CommonStack s);

#endif




#endif /* CommonStack_h */
