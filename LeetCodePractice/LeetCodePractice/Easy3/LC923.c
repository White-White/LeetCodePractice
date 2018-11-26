/*
 Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.
 
 As the answer can be very large, return it modulo 10^9 + 7.
 
 
 
 Example 1:
 
 Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
 Output: 20
 Explanation:
 Enumerating by the values (A[i], A[j], A[k]):
 (1, 2, 5) occurs 8 times;
 (1, 3, 4) occurs 8 times;
 (2, 2, 4) occurs 2 times;
 (2, 3, 3) occurs 2 times.
 Example 2:
 
 Input: A = [1,1,2,2,2,2], target = 5
 Output: 12
 Explanation:
 A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
 We choose one 1 from [1,1] in 2 ways,
 and two 2s from [2,2,2,2] in 6 ways.
 
 
 Note:
 
 3 <= A.length <= 3000
 0 <= A[i] <= 100
 0 <= target <= 300

 */

#include "LC923.h"

//超时
int threeSumMulti(int* A, int ASize, int target) {
    int total = 0;
    for (int i = 0; i < ASize; i++) {
        int sumI = A[i];
        for (int j = i + 1; j < ASize; j++) {
            int sumJ = sumI + A[j];
            for (int k = j + 1; k < ASize; k++) {
                int sumK = sumJ + A[k];
                if (sumK == target) { total++; }
            }
        }
    }
    return total;
}

//answer from LC
int threeSumMultiLC(int* A, int ASize, int target) {
    long total = 0;
    int MAX_ARRAY_LENGTH = 100;
    
    long buffer[MAX_ARRAY_LENGTH + 1];
    memset(buffer, 0, sizeof(long)*(MAX_ARRAY_LENGTH + 1));
    
    for (int i = 0; i < ASize; i++) {
        buffer[A[i]]++;
    }
    
    for (int i = 0; i <= MAX_ARRAY_LENGTH; i++) {
        for (int j = i; j <= MAX_ARRAY_LENGTH; j++) {
            int k = target - i - j;
            if (k < 0 || k > 100) { continue; }
            //
            if (i == j && j == k) { // C(A[i], 3)
                long t = (buffer[i] * (buffer[i] - 1) * (buffer[i] - 2)) / 6;
                total += t;
            } else if (i == j && j < k) {
                long t = (buffer[i] * (buffer[i] - 1)) / 2 * buffer[k];
                total += t;
            } else if (i < j && j == k) {
                long t = (buffer[j] * (buffer[j] - 1)) / 2 * buffer[i];
                total += t;
            } else if (i < j && j < k) {
                long t = buffer[i] * buffer[j] * buffer[k];
                total += t;
            }
        }
    }
    
    long result = total%(1000000007);
    
    return (int)result;
}
