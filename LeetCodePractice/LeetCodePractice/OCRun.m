//
//  OCRun.m
//  LeetCodePractice
//
//  Created by White on 2018/9/2.
//  Copyright © 2018年 White. All rights reserved.
//

#import "OCRun.h"
#import "Quiz9.h"

@implementation OCRun

+ (void)run {

    int size;
    char **result = fizzBuzz(5, &size);
    
    for (int j = 0; j < size; j++) {
        NSLog(@"%s", result[j]);
    }
}

@end
