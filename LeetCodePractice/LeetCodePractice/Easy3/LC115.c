/*
 Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 
 A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 
 Example 1:
 
 Input: S = "rabbbit", T = "rabbit"
 Output: 3
 Explanation:
 
 As shown below, there are 3 ways you can generate "rabbit" from S.
 (The caret symbol ^ means the chosen letters)
 
 rabbbit
 ^^^^ ^^
 rabbbit
 ^^ ^^^^
 rabbbit
 ^^^ ^^^
 Example 2:
 
 Input: S = "babgbag", T = "bag"
 Output: 5
 Explanation:
 
 As shown below, there are 5 ways you can generate "bag" from S.
 (The caret symbol ^ means the chosen letters)
 
 babgbag
 ^^ ^
 babgbag
 ^^    ^
 babgbag
 ^    ^^
 babgbag
 ^  ^^
 babgbag
 ^^^
 */

#include "LC115.h"

//https://leetcode.com/problems/distinct-subsequences/discuss/37327/Easy-to-understand-DP-in-Java
//这题没解出来 实际应该使用二次矩阵的方式

int numDistinct(char* s, char* t) {
    int lenS = (int)strlen(s);
    int lenT = (int)strlen(t);
    
    //lenT+1 行 lenS+1 列的矩阵
    int buffer[lenT+1][lenS+1];
    memset(buffer, 0, sizeof(int)*(lenT+1)*(lenS+1));
    
    //第0行，相当于t为空字符串，此时s有且只有一个子序列，即空字符串，等于t
    for (int i = 0; i <= lenS; i++) {
        buffer[0][i] = 1;
    }
    
    for (int i = 0; i < lenT; i++) {
        for (int j = 0; j < lenS; j++) {
            if (s[j] == t[i]) {
                buffer[i+1][j+1] = buffer[i][j] + buffer[i+1][j];
            } else {
                buffer[i+1][j+1] = buffer[i+1][j];
            }
        }
    }
    
    return buffer[lenT][lenS];
}
