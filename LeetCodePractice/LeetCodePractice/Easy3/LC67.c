/*
 
 Add Binary
 
 Given two binary strings, return their sum (also a binary string).
 
 The input strings are both non-empty and contains only characters 1 or 0.
 
 Example 1:
 
 Input: a = "11", b = "1"
 Output: "100"
 Example 2:
 
 Input: a = "1010", b = "1011"
 Output: "10101"
 */

#include "LC67.h"

char *reverseStringPrivate(char * s) {
    
    unsigned long int length = strlen(s);
    
    if (length < 2) { return s; }
    
    unsigned long int lastIndex = length - 1;
    unsigned long int k = 0;
    
    for (; k < lastIndex ; k++, lastIndex-- ) {
        
        char tem =  *(s+k);
        *(s+k) = *(s+lastIndex);
        *(s+lastIndex) = tem;
    }
    
    return s;
}

char* addBinary(char* a, char* b) {
    
    unsigned long lena = strlen(a);
    unsigned long lenb = strlen(b);
    
    int lenMax = (int)max(lena, lenb);
    char buffer[lenMax+2];
    
    int bufferIndex;
    char carry = false;
    
    for (bufferIndex = 0; bufferIndex < lenMax; bufferIndex++) {
        
        int targetIndexA = (int)lena - 1 - bufferIndex;
        int targetIndexB = (int)lenb - 1 - bufferIndex;
        
        char charFromA = (targetIndexA >= lena ? '0' : a[targetIndexA]);
        char charFromB = (targetIndexB >= lenb ? '0' : b[targetIndexB]);
        
        int endUp = (int)charFromA + (int)charFromB + (int)(carry ? '1' : '0');
        
        switch (endUp) {
            case 147: {//三个1
                buffer[bufferIndex] = '1';
                carry = true;
                break;
            }
            case 146: {
                buffer[bufferIndex] = '0';
                carry = true;
                break;
            }
            case 145: {
                buffer[bufferIndex] = '1';
                carry = false;
                break;
            }
            default: {
                buffer[bufferIndex] = '0';
                carry = false;
                break;
            }
        }
    }
    
    int finalLen;
    if (carry) {
        buffer[bufferIndex] = '1';
        finalLen = bufferIndex+2;
    } else {
        finalLen = bufferIndex+1;
    }
    buffer[finalLen-1] = '\0';
    
    char* ret = malloc(sizeof(char)*finalLen);
    memcpy(ret, buffer, finalLen);
    return reverseStringPrivate(ret);
}
