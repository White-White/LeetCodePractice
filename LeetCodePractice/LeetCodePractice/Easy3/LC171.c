/*
 
 Given a column title as appear in an Excel sheet, return its corresponding column number.
 
 For example:
 
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 ...
 Example 1:
 
 Input: "A"
 Output: 1
 Example 2:
 
 Input: "AB"
 Output: 28
 Example 3:
 
 Input: "ZY"
 Output: 701
 */

#include "LC171.h"

int titleToNumber(char* s) {
    int sLen = (int)strlen(s);
    int total = 0;
    int power = 1;
    for (int i = sLen - 1; i >= 0; i--) {
        char c = *(s+i);
        int value = (c - 'A') + 1;
        total += value * power;
        power *= 26;
    }
    return total;
}
