/*
 
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 
 Example:
 
 Input: [0,1,0,3,12]
 Output: [1,3,12,0,0]
 Note:
 
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
 
 */

#include "LC283.h"

void moveZeroes(int* nums, int numsSize) {
    int lowIndex = 0;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            if (lowIndex != i) {
                nums[lowIndex] = nums[i];
            }
            lowIndex++;
        } else {
            count++;
        }
    }
    
    for (int i = 0; i < count; i++) {
        *(nums+numsSize-1-i) = 0;
    }
}
