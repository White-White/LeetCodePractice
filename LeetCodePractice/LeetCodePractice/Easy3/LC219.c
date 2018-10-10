/*
 
 Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 
 Example 1:
 
 Input: nums = [1,2,3,1], k = 3
 Output: true
 Example 2:
 
 Input: nums = [1,0,1,1], k = 1
 Output: true
 Example 3:
 
 Input: nums = [1,2,3,1,2,3], k = 2
 Output: false
 
 */

#include "LC219.h"

//超出时间限制
bool containsNearbyDuplicate_bad(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = 1; j <= k; j++) {
            if (i+j < numsSize && nums[i] == nums[i+j]) {
                return true;
            }
        }
    }
    return false;
}


bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize <= 1) { return false; }
    
    //原本的index
    int bufIndex[numsSize];
    for (int i = 0; i < numsSize; i++) {
        bufIndex[i] = i;
    }
    
    //缓存
    int buf[numsSize];
    memcpy(buf, nums, sizeof(int)*numsSize);
    
    for (int i = 1; i < numsSize; i++) {
        for (int j = i; j > 0; j--) {
            if (buf[j] > buf[j-1]) {
                break;
            } else if (buf[j] < buf[j-1]) {
                int temp = buf[j];
                buf[j] = buf[j-1];
                buf[j-1] = temp;
                
                //index的记录也交换
                int tempIndex = bufIndex[j];
                bufIndex[j] = bufIndex[j-1];
                bufIndex[j-1] = tempIndex;
            } else if (abs(bufIndex[j] - bufIndex[j-1]) <= k ) {
                return true;
            }
        }
    }
    
    return false;
}

