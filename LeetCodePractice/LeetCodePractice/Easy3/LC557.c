/*
 Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 
 Example 1:
 Input: "Let's take LeetCode contest"
 Output: "s'teL ekat edoCteeL tsetnoc"
 Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 

 */

#include "LC557.h"

char *_reverseString557(char * s, int maxLen) {
    
    int length = min(maxLen, (int)strlen(s));
    
    if (length < 2) { return s; }
    
    for (int lastIndex = length - 1, k = 0; k < lastIndex ; k++, lastIndex-- ) {
        char tem =  *(s+k);
        *(s+k) = *(s+lastIndex);
        *(s+lastIndex) = tem;
    }
    
    return s;
}

char* reverseWords(char* s) {
    
    int len = (int)strlen(s);
    char *lastSpace = NULL;
    
    for (int i = 0; i < len; i++) {
        
        if (s[i] == ' ') {
            lastSpace = s+i;
            continue;
        } else {
            if (s[i+1] == ' ' || s[i+1] == '\0') {
                char *wordStart = (lastSpace ? lastSpace + 1 : s);
                _reverseString557(wordStart, (int)(s+i-wordStart) + 1);
            }
        }
        
    }
    
    return s;
}
