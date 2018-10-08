/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.
 Example:
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> Returns -3.
 minStack.pop();
 minStack.top();      --> Returns 0.
 minStack.getMin();   --> Returns -2.

 */

#include "LC155.h"

typedef struct {
    int* values;
    int* minValues;
    int size;
    int ptrIndex;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->size = maxSize;
    stack->ptrIndex = 0;
    stack->values = malloc(sizeof(int)*maxSize);
    stack->minValues = malloc(sizeof(int)*maxSize);
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->ptrIndex == 0) {
        obj->values[obj->ptrIndex] = x;
        obj->minValues[obj->ptrIndex] = x;
        (obj->ptrIndex)++;
    } else if (obj->ptrIndex >= obj->size) {
        return;
    } else {
        obj->values[obj->ptrIndex] = x;
        obj->minValues[obj->ptrIndex] = min(obj->minValues[obj->ptrIndex-1], x);
        (obj->ptrIndex)++;
        printf("%d", obj->minValues[obj->ptrIndex]);
    }
}

void minStackPop(MinStack* obj) {
    if (obj->ptrIndex > 0) {
        (obj->ptrIndex)--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->values[obj->ptrIndex-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->minValues[obj->ptrIndex-1];
}

void minStackFree(MinStack* obj) {
    free(obj->values);
    free(obj->minValues);
    free(obj);
}
