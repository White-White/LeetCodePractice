/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 
 Note: For the purpose of this problem, we define empty string as valid palindrome.
 
 Example 1:
 
 Input: "A man, a plan, a canal: Panama"
 Output: true
 Example 2:
 
 Input: "race a car"
 Output: false
 */

#include "LC125.h"

bool isAlpha(char c) {
    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}

bool isNumeric(char c) {
    return c <= '9' && c >= '0';
}

bool isAlphanumeric(char c) {
    return isAlpha(c) || isNumeric(c);
}

bool isPalindromeChar(char c, char s) {
    if (isNumeric(c)) {
        if (c == s) {
            return true;
        } else {
            return false;
        }
    }
    
    if (isAlpha(c)) {
        if ( c == s || abs(c - s) == 32 ) {
            return true;
        } else {
            return false;
        }
    }
    
    if (!isAlphanumeric(s)) {
        return true;
    }
    
    return false;
}

bool isPalindromeC(char* s) {
    unsigned long length = strlen(s);
    
    if (length <= 0) { return true; }
    
    char* start = s;
    char* end = s+length-1;
    
    while (start < end) {
        if (!isAlphanumeric(*start) && start < end) {
            start++;
            continue;
        }
        
        if (!isAlphanumeric(*end) && start < end) {
            end--;
            continue;
        }
        
        printf("%c - %c \n", *start, *end);
        
        if (!(isPalindromeChar(*start, *end))) {
            return false;
        } else {
            start++;
            end--;
        }
    }
    return true;
}
