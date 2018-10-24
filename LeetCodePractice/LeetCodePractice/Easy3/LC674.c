/*
 Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
 
 Example 1:
 Input: [1,3,5,4,7]
 Output: 3
 Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
 Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
 Example 2:
 Input: [2,2,2,2,2]
 Output: 1
 Explanation: The longest continuous increasing subsequence is [2], its length is 1.
 Note: Length of the array will not exceed 10,000.
 

 */

#include "LC674.h"

int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize < 2) { return numsSize; }
    
    int maxLength = 1;
    int curLength = 1;
    int startIndex = 0;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[startIndex]) {
            curLength += 1;
            maxLength = max(maxLength, curLength);
        } else {
            curLength = 1;
        }
        startIndex = i;
    }
    
    return maxLength;
}
