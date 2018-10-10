/*
 
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
 You may assume that the array is non-empty and the majority element always exist in the array.
 
 Example 1:
 
 Input: [3,2,3]
 Output: 3
 Example 2:
 
 Input: [2,2,1,1,1,2,2]
 Output: 2

 
 */

#include "LC169.h"

/*
 注：
 https://leetcode.com/problems/majority-element/solution/
 关于major element，这里有很多精彩的解读。
 其中随机算法、多数投票算法最引人注目。以下是多数投票算法的实现
 */

int majorityElement(int* nums, int numsSize) {
    
    //Boyer-Moore Algorithm
    
    int count = 0;
    int candidate = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (candidate == nums[i] ? 1 : -1);
    }
    
    //验算 这个步骤在LC的题中可以省略 因为LC保证major element绝对存在
    int reCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (candidate == nums[i]) {
            reCount++;
        }
    }
    
    if (reCount >= numsSize/2) {
        return candidate;
    } else {
        exit(1); // impossible in lc context
    }
    //验算
    
    return candidate;
}
