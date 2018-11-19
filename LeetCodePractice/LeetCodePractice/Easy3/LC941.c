/*
 Given an array A of integers, return true if and only if it is a valid mountain array.
 
 Recall that A is a mountain array if and only if:
 
 A.length >= 3
 There exists some i with 0 < i < A.length - 1 such that:
 A[0] < A[1] < ... A[i-1] < A[i]
 A[i] > A[i+1] > ... > A[B.length - 1]
 
 
 Example 1:
 
 Input: [2,1]
 Output: false
 Example 2:
 
 Input: [3,5,5]
 Output: false
 Example 3:
 
 Input: [0,3,2,1]
 Output: true
 
 
 Note:
 
 0 <= A.length <= 10000
 0 <= A[i] <= 10000

 */

#include "LC941.h"

bool validMountainArray(int* A, int ASize) {
    
    if (ASize <= 2) { return false; }
    
    int* peak = NULL;
    int last = *(A);
    
    for (int i = 1; i < ASize; i++) {
        int current = *(A+i);
        
        if (peak) {
            if (current >= last) {
                return false;
            }
        } else {
            if (current > last) {
                //do nothing
            } else if (current < last) {
                peak = A+i-1;
            } else {
                return false;
            }
        }
        
        last = current;
    }
    
    return peak != NULL && peak != A;
}

//以上的版本相对复杂了
//使用walk up，walk down的逻辑去抽象处理会更好
bool validMountainArrayBetter(int* A, int ASize) {
    
    if (ASize <= 2) { return false; }
    
    int i = 0;
    
    //严肃的walk up
    while (i + 1 < ASize && A[i] < A[i+1]) {
        i++;
    }
    
    //peak不能是队首或者队尾
    if (i == 0 || i == ASize - 1) {
        return false;
    }
    
    while (i + 1 < ASize && A[i] > A[i+1]) {
        i++;
    }
    
    return i == ASize - 1;
}
