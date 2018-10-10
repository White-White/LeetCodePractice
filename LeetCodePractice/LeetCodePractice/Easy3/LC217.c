/*
 
 Given an array of integers, find if the array contains any duplicates.
 
 Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 
 Example 1:
 
 Input: [1,2,3,1]
 Output: true
 Example 2:
 
 Input: [1,2,3,4]
 Output: false
 Example 3:
 
 Input: [1,1,1,3,3,4,3,2,4,2]
 Output: true
 
 */

#include "LC217.h"

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) { return false; }
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
            } else {
                return true;
            }
        }
    }
    
    return false;
}
