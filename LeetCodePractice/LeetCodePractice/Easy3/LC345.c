/*
 Write a function that takes a string as input and reverse only the vowels of a string.
 
 Example 1:
 
 Input: "hello"
 Output: "holle"
 Example 2:
 
 Input: "leetcode"
 Output: "leotcede"
 Note:
 The vowels does not include the letter "y".
 */

#include "LC345.h"

bool isVowel(char c) {
    switch (c) {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return true;
        default:
            return false;
    }
}

char* reverseVowels(char* s) {
    unsigned long length = strlen(s);
    char* end = s+length-1;
    char* start = s;
    
    while (start < end) {
        if (!isVowel(*start)) {
            start++;
            continue;
        }
        
        if (!isVowel(*end)) {
            end--;
            continue;
        }
        
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return s;
}
