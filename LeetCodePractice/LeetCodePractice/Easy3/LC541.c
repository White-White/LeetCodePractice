/*
 
 
 Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
 Example:
 Input: s = "abcdefg", k = 2
 Output: "bacdfeg"
 Restrictions:
 The string consists of lower English letters only.
 Length of the given string and k will in the range [1, 10000]

 */

#include "LC541.h"

char *_reverseString541(char * s, int maxLen) {
    
    int length = min(maxLen, (int)strlen(s));
    
    if (length < 2) { return s; }
    
    for (int lastIndex = length - 1, k = 0; k < lastIndex ; k++, lastIndex-- ) {
        char tem =  *(s+k);
        *(s+k) = *(s+lastIndex);
        *(s+lastIndex) = tem;
    }
    
    return s;
}

char* reverseStr(char* s, int k) {
    
    int len = (int)strlen(s);
    
    for (int start = 0, end = start + k; start < len; start += 2*k, end = start + k) {
        if (end > len) {
            _reverseString541(s+start, min(k, len - start));
            break;
        }
        _reverseString541(s+start, k);
    }
    
    return s;
}
