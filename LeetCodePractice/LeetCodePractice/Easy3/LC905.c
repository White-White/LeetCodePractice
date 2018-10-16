/*
 
 Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
 
 You may return any answer array that satisfies this condition.
 
 
 
 Example 1:
 
 Input: [3,1,2,4]
 Output: [2,4,3,1]
 The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 
 
 Note:
 
 1 <= A.length <= 5000
 0 <= A[i] <= 5000

 
 */

#include "LC905.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int* ret = malloc(sizeof(int)*ASize);
    memcpy(ret, A, sizeof(int)*ASize);
    
    int* start = ret;
    int* end = start+ASize-1;
    
    while (start < end) {
        while (*start % 2 == 0) {
            start++;
        }
        
        while (*end % 2 != 0) {
            end--;
        }
        
        if (start < end) {
            //swap
            int temp = *start;
            *start = *end;
            *end = temp;
        }
    }
    return ret;
}
