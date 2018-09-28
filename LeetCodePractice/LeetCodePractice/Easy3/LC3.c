/*
 Given a string, find the length of the longest substring without repeating characters.
 
 Example 1:
 
 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 Example 2:
 
 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 Example 3:
 
 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

 */

#include "LC3.h"

int lengthOfLongestSubstring(char* s) {
    
    unsigned long length = strlen(s);
    
    int baseIndex = 0;
    int maxCurrent = 0;
    int maxTotal = 0;
    
    for (unsigned long i = 0; i < length; i++) {
        
        bool notRepeating = true;
        for (int j = baseIndex; j < i; j++) {
            if (s[j] == s[i]) {
                baseIndex = j+1;
                maxCurrent = (int)(i - j);
                notRepeating = false;
                break;
            }
        }
        
        if (notRepeating) {
            maxCurrent += 1;
            maxTotal = max(maxTotal, maxCurrent);
        }
    }
    
    return maxTotal;
}
