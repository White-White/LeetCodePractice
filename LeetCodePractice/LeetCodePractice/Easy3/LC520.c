/*
 Given a word, you need to judge whether the usage of capitals in it is right or not.
 
 We define the usage of capitals in a word to be right when one of the following cases holds:
 
 All letters in this word are capitals, like "USA".
 All letters in this word are not capitals, like "leetcode".
 Only the first letter in this word is capital if it has more than one letter, like "Google".
 Otherwise, we define that this word doesn't use capitals in a right way.
 Example 1:
 Input: "USA"
 Output: True
 Example 2:
 Input: "FlaG"
 Output: False
 */

#include "LC520.h"

bool isCapital(char c) {
    return c <= 'Z' && c >= 'A';
}

bool detectCapitalUse(char* word) {
    
    int len = (int)strlen(word);
    
    
    bool mustCapital = true;
    if (isCapital(word[len-1])) {
        //最后一个字母大写
        //其它必须大写 否则不合法
        if (!isCapital(*word)) {
            return false;
        }
    } else {
        //最后一个小写 首字母无所谓 中间必须全部小写
        mustCapital = false;
    }
    
    for (int i = 1; i < len - 1; i++) {
        if (isCapital(word[i]) == mustCapital) {
            continue;
        } else {
            return false;
        }
    }
    
    return true;
}
