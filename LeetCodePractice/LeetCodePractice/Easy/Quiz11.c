/*
 颠倒二进制位
 颠倒给定的 32 位无符号整数的二进制位。
 
 示例:
 
 输入: 43261596
 输出: 964176192
 解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
 返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
 进阶:
 如果多次调用这个函数，你将如何优化你的算法？
 */

#include "Quiz11.h"

uint32_t reverseBits(uint32_t n) {
    int32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        uint32_t original = n >> i;
        if (original & 1) {
            result += 1;
        }
    }
    return  result;
}

//LeetCode上的解压 通过分割成 2份 4份 8份 16份 左右交换完成reverse
uint32_t reverseBitsLeetCode(uint32_t n) {
    n = (n << 16) | (n >> 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

