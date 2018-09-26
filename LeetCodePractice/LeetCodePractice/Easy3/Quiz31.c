/*
 Look and say
 Count and day
 The count-and-say sequence is the sequence of integers with the first five terms as following:
 
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 
 Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
 
 Note: Each term of the sequence of integers will be represented as a string.
 
 
 
 Example 1:
 
 Input: 1
 Output: "1"
 Example 2:
 
 Input: 4
 Output: "1211"
 */

#include "Quiz31.h"

char* expandAndSave(char* dest, int currentLength, char* content, int contentLength) {
    if (!content) { return dest; }
    if (dest) {
        dest = realloc(dest, (currentLength + contentLength)*sizeof(char));
        memcpy(dest+currentLength, content, contentLength*sizeof(char));
        return dest;
    } else {
        char* ret = malloc(contentLength*sizeof(char));
        memcpy(ret, content, contentLength*sizeof(char));
        return ret;
    }
}

char* countString(char* str) {
    unsigned long length = strlen(str);
    if (length == 0) { return NULL; }
    
    //计数
    char* current = str;
    int count = 0;
    
    //buffer
    int currentRetLength = 0;
    char* ret = NULL;
    
    //循环
    for (unsigned long i = 0; i <= length; i++) {
        if (str[i] == *current) {
            count++;
        } else {
            //储存到buffer
            char buffer[10];
            int contentLength = sprintf(buffer, "%d%c", count, *current);
            //储存到ret
            ret = expandAndSave(ret, currentRetLength, buffer, contentLength);
            currentRetLength += contentLength;
            
            if (i == length) { //最后一位 添加结束符
                //储存到ret
                char end = '\0';
                ret = expandAndSave(ret, currentRetLength, &end, 1);
                currentRetLength += contentLength;
            } else {
                current = str+i;
                count = 1;
            }
        }
    }
    
    free(str);
    
    return ret;
}

char* countAndSay(int n) {
    if (n == 1) {
        char* buffer = malloc(2);
        buffer[0] = '1';
        buffer[1] = '\0';
        return buffer;
    } else {
        return countString(countAndSay(n - 1));
    }
}


