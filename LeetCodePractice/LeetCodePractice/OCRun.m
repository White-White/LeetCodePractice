//
//  OCRun.m
//  LeetCodePractice
//
//  Created by White on 2018/9/2.
//  Copyright © 2018年 White. All rights reserved.
//

#import "OCRun.h"
//oc c 测试环境

#include "Quiz20.h"

@implementation OCRun

+ (void)run {
    
//    Your MinStack struct will be instantiated and called as such:
    MinStack* obj = minStackCreate(10);
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    printf("%d", minStackGetMin(obj));
    minStackPop(obj);
    printf("%d", minStackTop(obj));
    printf("%d", minStackGetMin(obj));
    minStackFree(obj);
}

@end
