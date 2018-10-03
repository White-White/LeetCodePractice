//
//  LC119.c
//  LeetCodePractice
//
//  Created by White on 2018/10/3.
//  Copyright © 2018年 White. All rights reserved.
//

/*
 In Pascal's triangle, each number is the sum of the two numbers directly above it.
 
 Example:
 
 Input: 3
 Output: [1,3,3,1]
 Follow up:
 
 Could you optimize your algorithm to use only O(k) extra space?
 */

//Pascal's Triangle II

#include "LC119.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 杨辉三角第n行，相当于二项式系数在幂等于n-1时的展开式
 */

int factorial(int n) {
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        temp*=i;
    }
    return temp;
}

int* getRow(int rowIndex, int* returnSize) {
    int* ret = malloc(sizeof(int)*(rowIndex+1));
    *returnSize = rowIndex+1;
    
    for (int i = 0; i <= rowIndex; i++) {
        ret[i] = factorial(rowIndex) / (factorial(i) * factorial(rowIndex - i));
    }
    return ret;
}

//以上是根据二项式系数的公式给出的解法
//在rowIndex大于等于 13 的时候 会溢出

//以下是安全的解法
int* getRowSafe(int rowIndex, int* returnSize) {
    int line = rowIndex+1;
    int* ret = malloc(sizeof(int)*line);
    memset(ret, 0, sizeof(int)*line);
    *returnSize = line;
    ret[0] = 1;
    for (int i = 1; i < line; i++) {
        for (int j = i; j >= 1; j--) {
            ret[j] = ret[j] + ret[j-1];
        }
    }
    return ret;
}
