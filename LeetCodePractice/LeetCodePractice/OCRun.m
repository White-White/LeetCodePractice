//
//  OCRun.m
//  LeetCodePractice
//
//  Created by White on 2018/9/2.
//  Copyright © 2018年 White. All rights reserved.
//

#import "OCRun.h"
//oc c 测试环境

#include "Quiz31.h"

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

+ (void)run {
    NSLog(@"%s", countAndSay(10));
}

@end
