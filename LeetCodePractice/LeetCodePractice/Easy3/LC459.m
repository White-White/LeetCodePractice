/*
 Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 
 
 
 Example 1:
 
 Input: "abab"
 Output: True
 Explanation: It's the substring "ab" twice.
 Example 2:
 
 Input: "aba"
 Output: False
 Example 3:
 
 Input: "abcabcabcabc"
 Output: True
 Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 */

#import "LC459.h"

@implementation LC459

bool repeatedSubstringPattern(char* s) {
    
    int slen = (int)strlen(s);
    int subLen = 1;
    int read = 1;
    
    char *degradePoint = NULL;
    
    while (read < slen) {
        char cur = s[read];
        
        if (degradePoint == NULL && cur == *s && read != subLen) {
            degradePoint = s + read;
        }
        
        char charToCompare = s[read%subLen];
        
        if (charToCompare == cur) {
            read++;
        } else {
            if (degradePoint) {
                read = (int)(degradePoint - s) + 1;
                subLen = read - 1;
                degradePoint = NULL;
            } else {
                subLen = read + 1;
                read++;
            }
        }
    }
    
    bool result = (subLen != slen && slen%subLen == 0);
    
    return result;
}

@end
