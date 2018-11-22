//
//  OCRun.m
//  LeetCodePractice
//
//  Created by White on 2018/9/2.
//  Copyright © 2018年 White. All rights reserved.
//

#import "OCRun.h"
//oc c 测试环境

#include "LC168.h"
#include "LC541.h"

@implementation OCRun

+ (struct ListNode*)nodeWithVal: (NSNumber*)val {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = [val intValue];
    return node;
}

+ (struct ListNode*)createNodesWithArray:(NSArray*)array {
    struct ListNode* head = NULL;
    struct ListNode* current = NULL;
    for (NSNumber *num in array) {
        if (!head) {
            head = [self nodeWithVal:num];
            current = head;
        } else {
            current->next = [self nodeWithVal:num];
            current = current->next;
        }
    }
    return head;
}

+ (struct TreeNode*)createTreeWith:(int **)array length:(int)length {
    if (!array) { return NULL; }
    //将所有节点按顺序怼到数组
    struct TreeNode* buffer[length];
    for (int i = 0; i < length; i++) {
        int* valPtr = array[i];
        if (valPtr) {
            struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
            newNode->val = *(valPtr);
            newNode->left = NULL;
            newNode->right = NULL;
            buffer[i] = newNode;
        } else {
            buffer[i] = NULL;
        }
    }
    
    for (int i = 0; i <= length/2; i++) {
        int indexLeft = 2*i+1;
        int indexRight = 2*i+2;
        struct TreeNode* currentNode = buffer[i];
        if (currentNode) {
            if (indexLeft < length) {
                currentNode->left = buffer[indexLeft];
            }
            if (indexRight < length) {
                currentNode->right = buffer[indexRight];
            }
        }
    }
    
    [self printNode:buffer[0]];
    
    return buffer[0];
}

+ (void)printNode:(struct TreeNode*)node {
    if (!node) { return; }
    printf("%d\n", node->val);
    [self printNode:node->left];
    [self printNode:node->right];
}



+ (void)run {
    char buffer[] = "abcdefg";
    
    reverseStr(buffer, 2);
}

@end
