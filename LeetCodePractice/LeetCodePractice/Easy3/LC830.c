/*
 In a string S of lowercase letters, these letters form consecutive groups of the same character.
 
 For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
 
 Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
 
 The final answer should be in lexicographic order.
 
 
 
 Example 1:
 
 Input: "abbxxxxzzy"
 Output: [[3,6]]
 Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
 Example 2:
 
 Input: "abc"
 Output: []
 Explanation: We have "a","b" and "c" but no large group.
 Example 3:
 
 Input: "abcdddeeeeaabbbcd"
 Output: [[3,5],[6,9],[12,14]]
 
 
 Note:  1 <= S.length <= 1000
 

 */

#include "LC830.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {
    int sLen = (int)(strlen(S));
    if (sLen < 3) { return NULL; }

    int* buf[sLen/3];
    int numOfPairs = 0;
    
    char* curChar = S;
    int curCount = 1;
    for (int i = 1; i <= sLen; i++) {
        if (S[i] == *curChar) {
            curCount ++;
        } else {
            if (curCount >= 3) {
                int *newPair = malloc(sizeof(int)*2);
                newPair[0] = (int)(curChar-S); newPair[1] = i-1;
                buf[numOfPairs] = newPair;
                numOfPairs++;
            }
            curChar = S+i;
            curCount = 1;
        }
    }
    
    if (numOfPairs == 0) { return NULL; }
    
    int** ret = malloc(sizeof(int*)*numOfPairs);
    memcpy(ret, buf, sizeof(int*)*numOfPairs);
    
    int* retColSizes = malloc(sizeof(int)*numOfPairs);
    for (int i = 0; i < numOfPairs; i++) {
        retColSizes[i] = 2;
    }
    *columnSizes = retColSizes;
    
    *returnSize = numOfPairs;
    
    return ret;
}
