/*
 
Implement strStr()
 
 Implement strStr().
 
 Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 Example 1:
 
 Input: haystack = "hello", needle = "ll"
 Output: 2
 Example 2:
 
 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 Clarification:
 
 What should we return when needle is an empty string? This is a great question to ask during an interview.
 
 For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

#include "Quiz29.h"

int strStr(char* haystack, char* needle) {
    
    unsigned long hayLength = strlen(haystack);
    unsigned long needleLength = strlen(needle);
    
    if (needleLength == 0) { return 0; }
    
    int wrong = -1;
    
    int hayIndex = 0;
    
    
    while (hayIndex < hayLength) {
        
        int needleIndex = 0;
        
        while (haystack[hayIndex+needleIndex] == needle[needleIndex] && needleIndex < needleLength && hayIndex+needleIndex < hayLength) {
            needleIndex++;
        }
        
        //needleIndex 成功匹配的字符数量
        if (needleIndex == needleLength) {
            //success
            return hayIndex;
        } else {
            //fail
            hayIndex += 1;
            if (hayLength - hayIndex < needleLength) {
                return wrong;
            }
        }
    }
    
    return wrong;
}






