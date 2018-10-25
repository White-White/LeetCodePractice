/*
 Given an integer array, find three numbers whose product is maximum and output the maximum product.
 
 Example 1:
 Input: [1,2,3]
 Output: 6
 Example 2:
 Input: [1,2,3,4]
 Output: 24
 Note:
 The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
 Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

 */

#include "LC628.h"

int maximumProduct(int* nums, int numsSize) {
    
    if (numsSize <= 0) { exit(1); }
    
    int bufMaxThree[3];
    int bufMaxSize = 0;
    
    int bufMinTwo[2];
    int bufMinSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int indexToInsertToMax = 0;
        int target = nums[i];
        
        for (int j = 0; j < bufMaxSize; j++) {
            if (target >= bufMaxThree[j]) {
                //移动
                for (int k = min(bufMaxSize, 2); k > j; k--) {
                    bufMaxThree[k] = bufMaxThree[k-1];
                }
                break;
            } else {
                indexToInsertToMax++;
                continue;
            }
        }
        
        if (indexToInsertToMax < 3 ) {
            //增加
            bufMaxThree[indexToInsertToMax] = target;
            bufMaxSize = min(bufMaxSize+1, 3);
        }
        
        int indexToInsertToMin = 0;
        for (int j = 0; j < bufMinSize; j++) {
            if (target <= bufMinTwo[j]) {
                //移动
                for (int k = min(bufMinSize, 1); k > j; k--) {
                    bufMinTwo[k] = bufMinTwo[k-1];
                }
                break;
            } else {
                indexToInsertToMin++;
                continue;
            }
        }
        
        if (indexToInsertToMin < 2) {
            //增加
            bufMinTwo[indexToInsertToMin] = target;
            bufMinSize = min(bufMinSize+1, 2);
        }
    }
    
    
    int sumMax = 1;
    for (int i = 0; i < 3; i++) {
        sumMax *= bufMaxThree[i];
    }
    
    int sumMin = bufMinTwo[0] * bufMinTwo[1] * bufMaxThree[0];
    
    return max(sumMin, sumMax);
}
