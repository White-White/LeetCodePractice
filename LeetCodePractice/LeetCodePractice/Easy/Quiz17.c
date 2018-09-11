/*
 计数质数
 统计所有小于非负整数 n 的质数的数量。
 
 示例:
 
 输入: 10
 输出: 4
 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 */

#include "Quiz17.h"

int countPrimes(int n) {
    
    if (n < 3) { return 0; }
    
    int count = 1; //2
    
    for (int i = 3; i < n; i+=2) { //所有偶数必不是质数 所以只判断奇数
        
        //先认为i是一个质数
        int isPrime = 1;
        
        //下面检查i是不是一个合数
        
        /* 若i是合数，则必有小于sqrt(i)的因数。
         奇数的因数不可能是偶数，所以只判断奇数。 */
        
        for (int j = 3; j*j <= i; j+=2) {
            if (i % j == 0) {
                //找到最小因数
                isPrime = 0;
                break;
            }
        }
        
        if (isPrime) {
            count++;
        }
    }
    
    return count;
}
