/*
 Maximum Subarray
 
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 
 Example:
 
 Input: [-2,1,-3,4,-1,2,1,-5,4],
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 Follow up:
 
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 

 */

#include "LC53.h"

/*
 这道题完全没想出来 最后学到了Kadane算法 专门用来算最大子数组的
 */

int maxSubArray(int* nums, int numsSize) {
    
    int currentSum = nums[0];
    int endUpSum = currentSum;
    
    for (int i = 1; i < numsSize; i++) {
        currentSum = max(nums[i], nums[i] + currentSum);
        endUpSum = max(currentSum, endUpSum);
    }
    
    return endUpSum;
}

