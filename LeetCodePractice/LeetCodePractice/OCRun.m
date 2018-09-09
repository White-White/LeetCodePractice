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

void merge11(int* nums1, int m, int* nums2, int n) {
    int end=m+n-1;
    m--;n--;
    while(m>=0&&n>=0)
    {
        if(nums2[n]>nums1[m])
        {
            nums1[end--]=nums2[n--];
            
        }
        else
        {
            nums1[end--]=nums1[m--];
            
        }
    }
    while(n>=0)
    {
        nums1[end--]=nums2[n--];
    }
    
}

+ (void)run {
    int num1[9];
    for (int i = 0; i < 5; i++) {
        num1[i] = i;
    }
    int num2[4];
    for (int j = 5; j < 9; j++) {
        num2[j-5] = j;
    }
    
    merge11(num1, 5, num2, 4);
    
}

@end
