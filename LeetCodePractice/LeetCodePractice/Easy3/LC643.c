/*
 
 Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
 
 Example 1:
 Input: [1,12,-5,-6,50,3], k = 4
 Output: 12.75
 Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 Note:
 1 <= k <= n <= 30,000.
 Elements of the given array will be in the range [-10,000, 10,000].

 */

#include "LC643.h"

double findMaxAverage(int* nums, int numsSize, int k) {
    
    bool maxAveInitialized = false;
    double maxAve = 0;
    
    for (int i = 0; i < numsSize - k + 1; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += nums[j];
        }
        double ave = ((double)sum)/k;
        
        if (maxAveInitialized) {
            maxAve = max(maxAve, ave);
        } else {
            maxAve = ave;
            maxAveInitialized = true;
        }
    }
    
    return maxAve;
}
