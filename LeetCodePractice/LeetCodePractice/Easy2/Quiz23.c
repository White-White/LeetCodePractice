/*
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 Example:
 
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 
 */

#include "Quiz23.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* ret = malloc(sizeof(int)*2);
    for (int i = 0; i < numsSize; i++) {
        int num1 = nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            int num2 = nums[j];
            if (num1 + num2 == target) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}
