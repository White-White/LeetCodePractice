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



int maxSubArray(int* nums, int numsSize) {
    int* currentSum = NULL;
    
    if (numsSize == 0) { return 0; }
    
    for (int i = 0; i < numsSize; i++) {
        int loopNum = nums[i];
        
        if (currentSum == NULL) {
            currentSum = nums+i;
            continue;
        }
        
        if (*currentSum < 0) {
            
            if (loopNum < 0) {
                *currentSum = max(loopNum, *currentSum);
            } else {
                *currentSum = loopNum;
            }
            
        } else { // currentSum >= 0
            if (loopNum < 0) {
                int sumOfNextSeg = maxSubArray(nums+i, numsSize - i);
                return max(sumOfNextSeg, 0) + *currentSum;
            } else {
                *currentSum = *currentSum + loopNum;
            }
        }
    }
    
    return *currentSum;
}

