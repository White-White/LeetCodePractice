/*
 最小栈
 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 
 push(x) -- 将元素 x 推入栈中。
 pop() -- 删除栈顶的元素。
 top() -- 获取栈顶元素。
 getMin() -- 检索栈中的最小元素。
 示例:
 
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> 返回 -3.
 minStack.pop();
 minStack.top();      --> 返回 0.
 minStack.getMin();   --> 返回 -2.
 */

#include "Quiz20.h"
#include <stdlib.h>

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->val = malloc(sizeof(int)*maxSize);
    stack->minValueIndex = malloc(sizeof(int)*maxSize);
    stack->currentSize = 0;
    stack->maxSize = maxSize;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->currentSize >= obj->maxSize) {
        return;
    } else {
        
        if (obj->currentSize > 0) {
            int lastMinValueIndex = *(obj->minValueIndex+obj->currentSize-1);
            int lastMinValue = *(obj->val+lastMinValueIndex);
            if (x < lastMinValue) {
                *(obj->minValueIndex+obj->currentSize) = obj->currentSize;
            } else {
                *(obj->minValueIndex+obj->currentSize) = lastMinValueIndex;
            }
        } else {
            *(obj->minValueIndex+obj->currentSize) = obj->currentSize;
        }
        *(obj->val+obj->currentSize) = x;
        obj->currentSize += 1;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->currentSize <= 0) {
        return;
    } else {
        obj->currentSize -= 1;
    }
}

int minStackTop(MinStack* obj) {
    return *(obj->val+obj->currentSize-1);
}

int minStackGetMin(MinStack* obj) {
    if (obj->currentSize > 0) {
        int lastMinValueIndex = *(obj->minValueIndex+obj->currentSize-1);
        int lastMinValue = *(obj->val+lastMinValueIndex);
        return lastMinValue;
    } else {
        return NULL; //fatalError()
    }
}

void minStackFree(MinStack* obj) {
    free(obj->val);
    free(obj->minValueIndex);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
