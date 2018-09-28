/*
 Implement int sqrt(int x).
 
 Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 
 Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 
 Example 1:
 
 Input: 4
 Output: 2
 Example 2:
 
 Input: 8
 Output: 2
 Explanation: The square root of 8 is 2.82842..., and since
 the decimal part is truncated, 2 is returned.

*/

#include "LC69.h"

int mySqrt(int x) {
    if (x == 0) { return 0; }
    
    if (x >= 4) {
        
        int xHalf = x/2;
        
        for (int i = xHalf+1; i*i < x; i++) {
            printf("%d\n", i);
        }
        exit(1);
    } else {
        return 1;
    }
    //当x大于等于4的时候，根号x 小于等于 x/2
}

#warning not finished
