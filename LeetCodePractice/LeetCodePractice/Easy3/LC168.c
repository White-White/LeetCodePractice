/*
 
 Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 
 For example:
 
 1 -> A
 2 -> B
 3 -> C
 ...
 26 -> Z
 27 -> AA
 28 -> AB
 ...
 Example 1:
 
 Input: 1
 Output: "A"
 Example 2:
 
 Input: 28
 Output: "AB"
 Example 3:
 
 Input: 701
 Output: "ZY"
 
 */

#include "LC168.h"

void _reverseString(char * s, int length) {
    if (length < 2) { return; }
    for (int start = 0, end = length - 1; start < end ; start++, end-- ) {
        char tem =  *(s+start);
        *(s+start) = *(s+end);
        *(s+end) = tem;
    }
}

char* convertToTitle(int n) {
    if (n <= 0) { return NULL; }
    
    char *buf = malloc(sizeof(char)*10);
    int bufSize = 10;
    int bufUsed = 0;
    
    while (n != 0) {
        int lastInt = n % 26;
        char lastChar;
        
        if (lastInt == 0) {
            lastChar = 'Z';
            n = n / 26 - 1;
        } else {
            lastChar = ('A' - 1) + lastInt;
            n /= 26;
        }
        
        printf("%c", lastChar);
        
        if (bufUsed >= bufSize) {
            buf = realloc(buf, bufSize);
            bufSize *= 2;
        }
        
        buf[bufUsed] = lastChar;
        bufUsed++;
    }
    
    _reverseString(buf, bufUsed);
    
    char* ret = malloc((bufUsed + 1)*sizeof(char));
    memcpy(ret, buf, bufUsed*sizeof(char));
    ret[bufUsed] = '\0';
    
    return ret;
}

















