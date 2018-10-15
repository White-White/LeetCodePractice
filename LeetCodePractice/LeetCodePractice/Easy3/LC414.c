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

int thirdMax(int* nums, int numsSize) {
    if (numsSize <= 0) { exit(1); }
    
    int xth = 3; //xth largest number
    
    int bufMaxSize = xth;
    int buf[bufMaxSize];
    int bufSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int indexToInsert = 0;
        int target = nums[i];
        
        for (int j = 0; j < bufSize; j++) {
            if (target > buf[j]) {
                //移动
                for (int k = min(bufMaxSize - 1, bufSize); k > j; k--) {
                    buf[k] = buf[k-1];
                }
                break;
            } else if (target == buf[j]) {
                indexToInsert = bufMaxSize; //这里使indexToInsert等于bufMaxSize，则表示插入不合法，底下不会插入
                break;
            } else {
                indexToInsert++;
                continue;
            }
        }
        
        if (indexToInsert > bufMaxSize - 1) {
            continue;
        } else {
            //增加
            buf[indexToInsert] = target;
            bufSize = min(bufSize+1, bufMaxSize);
        }
    }
    
    if (bufSize == bufMaxSize) {
        return buf[bufMaxSize - 1];
    } else {
        return buf[0];
    }
}
