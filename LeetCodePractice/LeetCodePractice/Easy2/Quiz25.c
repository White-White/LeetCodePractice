/*
 
 Longest Common Prefix
 
 Write a function to find the longest common prefix string amongst an array of strings.
 
 If there is no common prefix, return an empty string "".
 
 Example 1:
 
 Input: ["flower","flow","flight"]
 Output: "fl"
 Example 2:
 
 Input: ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
 Note:
 
 All given inputs are in lowercase letters a-z.
 
 */

#include "Quiz25.h"

char* longestCommonPrefix(char** strs, int strsSize) {
    char *ret;
    
    if (strsSize <= 0) {
        ret = malloc(1);
        ret[0] = '\0';
        return ret;
    }
    
    unsigned long minStrLength = 0;
    for (int i = 0; i < strsSize; i++) {
        char* str = strs[i];
        unsigned long currLength = strlen(str);
        if (minStrLength == 0 || currLength < minStrLength) {
            minStrLength = currLength;
        }
    }
    
    if (minStrLength <= 0) {
        ret = malloc(1);
        ret[0] = '\0';
        return ret;
    }

    char prefix[minStrLength]; //buffer
    char* currentChar = NULL;
    
    for (int i = 0; i < minStrLength; i++) {
        
        for (int j = 0; j < strsSize; j++) {
            if (currentChar) {
                if (*currentChar != strs[j][i]) { //找到不同的prefix
                    ret = malloc(sizeof(char)*(i+1));
                    memcpy(ret, prefix, sizeof(char)*i);
                    ret[i] = '\0';
                    return ret;
                }
            } else {
                currentChar = strs[j]+i;
            }
        }
        
        prefix[i] = *currentChar;
        currentChar = NULL;
    }
    
    ret = malloc(sizeof(char)*(minStrLength + 1));
    memcpy(ret, prefix, sizeof(char)*minStrLength);
    ret[minStrLength] = '\0';
    
    return ret;
}
