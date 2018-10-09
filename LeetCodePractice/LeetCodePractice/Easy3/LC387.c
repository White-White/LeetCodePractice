/*
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 
 Examples:
 
 s = "leetcode"
 return 0.
 
 s = "loveleetcode",
 return 2.
 Note: You may assume the string contain only lowercase letters.
 */

#include "LC387.h"

int firstUniqChar(char* s) {
    
    int repo[26];
    memset(repo, 0, sizeof(int)*26);
    
    char charsInSeq[26];
    int cahrsInSeqIndexInS[26];
    int charsInSeqIndex = 0;
    
    unsigned long sLength = strlen(s);
    
    for (int i = 0; i < sLength; i++) {
        int index = s[i] - 'a';
        if (repo[index] == 0) { //首次计数
            charsInSeq[charsInSeqIndex] = s[i]; //首次出现的char
            cahrsInSeqIndexInS[charsInSeqIndex] = i; //首次出现该char所在的stringIndex
            charsInSeqIndex++;
        }
        repo[index]++;
    }
    
    for (int i = 0; i < charsInSeqIndex; i++) {
        char targetChar = charsInSeq[i];
        if (repo[targetChar - 'a'] == 1) { //只出现一次
            return cahrsInSeqIndexInS[i];
        }
    }
    
    return -1;
}

int firstUniqCharBetter(char* s) {
    
    int repo[26];
    memset(repo, 0, sizeof(int)*26);
    unsigned long sLength = strlen(s);
    
    for (int i = 0; i < sLength; i++) {
        int index = s[i] - 'a';
        repo[index]++;
    }
    
    for (int i = 0; i < sLength; i++) {
        if (repo[s[i] - 'a'] == 1) { //只出现一次
            return i;
        }
    }
    
    return -1;
}
