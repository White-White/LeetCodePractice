/*
 Length of Last Word
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 Example:
 
 Input: "Hello World"
 Output: 5
 
 */

#include "LC58.h"
int lengthOfLastWord(char* s) {
    unsigned long length = strlen(s);
    if (length <= 0) { return 0; }
    int count = 0;
    
    for (char* last = s+length-1; last-s >= 0; last--) {
        if (*last != ' ') {
            count++;
        } else {
            if (count == 0) {
                continue;
            } else {
                break;
            }
        }
    }
    
    return count;
}
