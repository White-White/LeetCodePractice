//
//  OCRun.m
//  LeetCodePractice
//
//  Created by White on 2018/9/2.
//  Copyright © 2018年 White. All rights reserved.
//

#import "OCRun.h"
//oc c 测试环境

#include "Quiz16.h"

@implementation OCRun

+ (void)run {
//    Your Solution struct will be instantiated and called as such:
    int* nums = malloc(sizeof(int)*3);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    
    int size = 3;
    int returnSize;
    
    struct Solution* obj = solutionCreate(nums, size);
    int* param_1 = solutionReset(obj, &returnSize);
    int* param_2 = solutionShuffle(obj, &returnSize);
    
    printf("%d\n", param_2[0]);
    printf("%d\n", param_2[1]);
    printf("%d\n", param_2[2]);
    
    solutionFree(obj);
}

@end
