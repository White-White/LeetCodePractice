/*
 Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
 
 Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
 
 You may return any answer array that satisfies this condition.
 
 
 
 Example 1:
 
 Input: [4,2,5,7]
 Output: [4,5,2,7]
 Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 
 
 Note:
 
 2 <= A.length <= 20000
 A.length % 2 == 0
 0 <= A[i] <= 1000
 */

#include "LC922.h"

int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    
    int evenDetector = 0;
    int oddDetector = 1;
    
    while (evenDetector < ASize && oddDetector < ASize) {
        
        while (evenDetector < ASize && A[evenDetector] % 2 == 0) {
            evenDetector += 2;
        }
        
        while (oddDetector < ASize && A[oddDetector] % 2 != 0) {
            oddDetector += 2;
        }
        
        if (evenDetector < ASize && oddDetector < ASize) {
            int temp = A[evenDetector];
            A[evenDetector] = A[oddDetector];
            A[oddDetector] = temp;
        }
    }
    
    *returnSize = ASize;
    
    return A;
}

//如果交换的成本很低 则下面的算法可能更快
int* sortArrayByParityIIAnother(int* A, int ASize, int* returnSize) {
    
    int e = 0;
    int o = 1;
    
    while (e < ASize && o < ASize) {
        if (A[e] % 2 != 0) {
            int temp = A[e];
            A[e] = A[o];
            A[o] = temp;
            o+=2;
        } else {
            e+=2;
        }
    }
    
    *returnSize = ASize;
    
    return A;
}
