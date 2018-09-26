/*
 Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 
 Example 1:
 
 Input: 121
 Output: true
 Example 2:
 
 Input: -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 Example 3:
 
 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 Follow up:
 
 Coud you solve it without converting the integer to a string?
 */

#include "Quiz24.h"

bool isPalindrome(int x) {
    if (x < 0) { return false; }
    
    int intArray[20];
    int length = 0;
    
    while (x != 0) {
        int pop = x%10;
        intArray[length] = pop;
        x /= 10;
        length++;
    }
    
    for (int i = 0, j = length - 1; i <= j; i++, j--) {
        if (intArray[i] != intArray[j]) {
            return false;
        }
    }
    
    return true;
}

//从leetCode上的解法
bool isPalindromeLeetCode(int x) {
    if (x < 0) { return false; }
    if (x != 0 && x%10 == 0) { return false; }
    //这里要把以0结尾的情况去掉 以0结尾的非零数肯定不是Palindrome
    
    int rev = 0;
    while (x > rev) {
        rev = rev*10 + x%10;
        x /= 10;
    }
    
    //    return (x == rev) || (x == rev/10);   : leetCode原写法
    //这里，相对于原解，考虑了x为10，20或30等情况下，rev为1，2或3，是小于10的整数，此时rev/10 == x == 0，会返回true，实际上应该返回false
    //然后这里的额外判断不必要，是因为最上面的early exit判断条件已经剔除了所以以0为结尾的情况
    return (x == rev) || (rev >= 10 && x == rev/10);
}
