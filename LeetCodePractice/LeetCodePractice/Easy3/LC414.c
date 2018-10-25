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

int maximumProduct(int* nums, int numsSize) {
    
    if (numsSize <= 0) { exit(1); }
    
    int bufMaxThree[3];
    int bufMaxSize = 0;
    
    int bufMinTwo[2];
    int bufMinSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int indexToInsertToMax = 0;
        int target = nums[i];
        
        for (int j = 0; j < bufMaxSize; j++) {
            if (target >= bufMaxThree[j]) {
                //移动
                for (int k = min(bufMaxSize, 2); k > j; k--) {
                    bufMaxThree[k] = bufMaxThree[k-1];
                }
                break;
            } else {
                indexToInsertToMax++;
                continue;
            }
        }
        
        if (indexToInsertToMax < 3 ) {
            //增加
            bufMaxThree[indexToInsertToMax] = target;
            bufMaxSize = min(bufMaxSize+1, 3);
        }
        
        int indexToInsertToMin = 0;
        for (int j = 0; j < bufMinSize; j++) {
            if (target <= bufMinTwo[j]) {
                //移动
                for (int k = min(bufMinSize, 1); k > j; k--) {
                    bufMinTwo[k] = bufMinTwo[k-1];
                }
                break;
            } else {
                indexToInsertToMin++;
                continue;
            }
        }
        
        if (indexToInsertToMin < 2) {
            //增加
            bufMinTwo[indexToInsertToMin] = target;
            bufMinSize = min(bufMinSize+1, 2);
        }
    }
    

    int sumMax = 1;
    for (int i = 0; i < 3; i++) {
        sumMax *= bufMaxThree[i];
    }
    
    int sumMin = bufMinTwo[0] * bufMinTwo[1] * bufMaxThree[0];

    return max(sumMin, sumMax);
}
