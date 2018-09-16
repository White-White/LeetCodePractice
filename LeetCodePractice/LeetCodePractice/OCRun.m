//
//  OCRun.m
//  LeetCodePractice
//
//  Created by White on 2018/9/2.
//  Copyright © 2018年 White. All rights reserved.
//

#import "OCRun.h"
//oc c 测试环境

#include "Quiz22.h"

@implementation OCRun

+ (void)run {
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    rotate(arr, 8, 5);
    for (int i = 0; i < 8; i++) {
        printf("%d", arr[i]);
    }
}

@end
