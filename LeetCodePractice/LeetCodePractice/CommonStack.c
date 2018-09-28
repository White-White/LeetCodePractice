//
//  CommonStack.c
//  LeetCodePractice
//
//  Created by White on 2018/9/28.
//  Copyright © 2018年 White. All rights reserved.
//

#include "CommonStack.h"


/* 判断栈是否为空 */
bool isEmpty(CommonStack s) {
    return s->next == NULL;
}
/* create stack */
CommonStack createStack(void) {
    CommonStack stack;
    stack = malloc(sizeof(struct CommonStackNode));
    stack->next = NULL;
    stack->data = NULL;
    return stack;
}
/* release stack */
void releaseStack(CommonStack s) {
    struct CommonStackNode* current = s;
    while (current) {
        struct CommonStackNode* next = current->next;
        free(current);
        current = next;
    }
}
/* 入栈 */
void push(void *data, CommonStack s) {
    struct CommonStackNode* node = malloc(sizeof(struct CommonStackNode));
    node->data = data;
    node->next = s->next;
    s->next = node;
}
/* 取栈顶元素 */
void* top(CommonStack s) {
    if (isEmpty(s)) {
        return NULL;
    } else {
        return s->next->data;
    }
}
/* 出栈 */
void pop(CommonStack s) {
    if (!isEmpty(s)) {
        struct CommonStackNode* ele = s->next;
        s->next = ele->next;
        free(ele);
    }
}
