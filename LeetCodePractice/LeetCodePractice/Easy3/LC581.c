/*
 Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
 
 You need to find the shortest such subarray and output its length.
 
 Example 1:
 Input: [2, 6, 4, 8, 10, 9, 15]
 Output: 5
 Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 Note:
 Then length of the input array is in range [1, 10,000].
 The input array may contain duplicates, so ascending order here means <=.

 */

#include "LC581.h"

int findUnsortedSubarray(int* nums, int numsSize) {
    
    bool isInSubArray = false;
    int subStartIndex = -1;
    int subEndIndex = -1;
    
    int maxValue = nums[0];
    int maxInSubarray = maxValue;
    
    for (int i = 1; i < numsSize; i++) {
        maxValue = max(maxValue, nums[i]);
        
        if (nums[i] < nums[i-1]) { //减少
            isInSubArray = true;
            int candidate_subStartIndex = 0;
            for (int j = i - 2; j >= 0; j--) {
                if (nums[i] >= nums[j]) { //寻找低点
                    candidate_subStartIndex = j + 1;

                    //起点
                    if (subStartIndex == -1) {
                        candidate_subStartIndex = candidate_subStartIndex;
                    } else {
                        candidate_subStartIndex = min(subStartIndex, candidate_subStartIndex);
                    }
                    break;
                }
            }
            
            subStartIndex = candidate_subStartIndex;
            subEndIndex = i;
            maxInSubarray = maxValue;
    
        } else {
            if (isInSubArray) {
                if (nums[i] >= maxInSubarray) {
                    subEndIndex = i - 1;
                    isInSubArray = false;
                } else {
                    subEndIndex = i;
                }
            }
        }
    }
    
    if (subEndIndex == -1) {
        return 0;
    }
    
    return subEndIndex - subStartIndex + 1;
}
