/*
 
 Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
 
 Example 1:
 Input: [3, 2, 1]
 
 Output: 1
 
 Explanation: The third maximum is 1.
 Example 2:
 Input: [1, 2]
 
 Output: 2
 
 Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 Example 3:
 Input: [2, 2, 3, 1]
 
 Output: 1
 
 Explanation: Note that the third maximum here means the third maximum distinct number.
 Both numbers with value 2 are both considered as second maximum.
 
 */

#include "LC414.h"

void _insertAndReplace(int target, int* array, int arraySize) {
    
}

int thirdMax(int* nums, int numsSize) {
    int buf[3];
    int bufSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
//        if (bufUsed < 3) {
//            buf[bufUsed] = nums[i];
//            bufUsed++;
//        } else {
//
//            for (int j = 0)
//
//        }
        for (int j = 0; j < bufSize; j++) {
            
        }
    }
    
}
