/*
 3的幂
 给定一个整数，写一个函数来判断它是否是 3 的幂次方。
 
 示例 1:
 
 输入: 27
 输出: true
 示例 2:
 
 输入: 0
 输出: false
 示例 3:
 
 输入: 9
 输出: true
 示例 4:
 
 输入: 45
 输出: false
 进阶：
 你能不使用循环或者递归来完成本题吗？
 */

#include "Quiz18.h"
#include <math.h>

bool isPowerOfThree(int n) {
    if (n == 0) { return false; }
    int i = n;
    while (i && i%3 == 0) {
        //能被3整除
        i /= 3;
    }
    return i == 1;
}

//使用换底对数公示
bool isPowerOfThreeBetter(int n) {
    return (n > 0 && ( (int)(log10(n) / log10(3)) - log10(n) / log10(3) == 0 ) );
}
