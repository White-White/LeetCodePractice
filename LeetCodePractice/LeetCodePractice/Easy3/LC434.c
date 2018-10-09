/*
 
 Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
 
 Please note that the string does not contain any non-printable characters.
 
 Example:
 
 Input: "Hello, my name is John"
 Output: 5

 
 */

#include "LC434.h"

int countSegments(char* s) {
    
    int count = 0;
    unsigned long len = strlen(s);
    
    bool isStateWord = false;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c != ' ') {
            isStateWord = true;
        } else if (isStateWord) {
            isStateWord = false;
            count++;
        }
    }
    
    if (isStateWord) { count++; }
    return count;
}

int countSegmentsBetter(char* s) {
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != ' ' && ( i == 0 || s[i-1] == ' ' )) {
            count++;
        }
    }
    return count;
}
