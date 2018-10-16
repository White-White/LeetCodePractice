/*
 
 Given an integer n, return the number of trailing zeroes in n!.
 
 Example 1:
 
 Input: 3
 Output: 0
 Explanation: 3! = 6, no trailing zero.
 Example 2:
 
 Input: 5
 Output: 1
 Explanation: 5! = 120, one trailing zero.
 Note: Your solution should be in logarithmic time complexity.
 
 
 */

#include "LC172.h"

//只需要数5个个数就可以 参考：
//https://blog.csdn.net/taoyanqi8932/article/details/52129450
//https://www.jianshu.com/p/211618afc695

int trailingZeroes(int n) {
    return n == 0 ? 0 : (n /5 + trailingZeroes(n / 5));
}
