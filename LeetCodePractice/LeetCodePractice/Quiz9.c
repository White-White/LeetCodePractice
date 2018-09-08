/*
 Fizz Buzz
 写一个程序，输出从 1 到 n 数字的字符串表示。
 
 1. 如果 n 是3的倍数，输出“Fizz”；
 
 2. 如果 n 是5的倍数，输出“Buzz”；
 
 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 
 示例：
 
 n = 15,
 
 返回:
 [
 "1",
 "2",
 "Fizz",
 "4",
 "Buzz",
 "Fizz",
 "7",
 "8",
 "Fizz",
 "Buzz",
 "11",
 "Fizz",
 "13",
 "14",
 "FizzBuzz"
 ]
 */

#include "Quiz9.h"



/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *reverseStringTemp(char * s) {
    
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


char* convertNumToChar(int num, int* length) {
    
    
    char* result = (char*)malloc(20 * sizeof(char));
    
    int startIndex = 0;
    int left = num;
    
    while (left) {
        char lastDightChar = (left%10) + '0';
        result[startIndex] = lastDightChar;
        left /= 10;
        startIndex += 1;
    }
    
    result[startIndex+1] = '\0';
    
    *length = startIndex+2;
    return reverseStringTemp(result);
}

char** fizzBuzz(int n, int* returnSize) {
    
    char** finalArray = (char**)malloc(n*sizeof(char*));
    
    for (int j = 0; j < n; j++) {
        int is3 = !((j+1)%3);
        int is5 = !((j+1)%5);
        
        if (is3 && is5) {
            char *array = (char*)malloc(9*sizeof(char));
            strcpy(array, "FizzBuzz");
            finalArray[j] = array;
        } else if (is3) {
            char *array = (char*)malloc(5*sizeof(char));
            strcpy(array, "Fizz");
            finalArray[j] = array;
        } else if (is5) {
            char *array = (char*)malloc(5*sizeof(char));
            strcpy(array, "Buzz");
            finalArray[j] = array;
        } else {
//            int length = 0;
//            finalArray[j] = convertNumToChar(j+1, &length);
            sprintf(finalArray[j] = malloc(10 * sizeof(char)), "%d", j+1);
            //注：这里注释掉的函数，在leetCode的playground和mac本机显示正常，但是过不了leetCode的case
        }
    }
    
    *returnSize = n;
    
    return finalArray;
}


char** fizzBuzzSolution2(int n, int* returnSize) {
    
    char** finalArray = (char**)malloc(n*sizeof(char*));
    
    for (int j = 0; j < n; j++) {
        int is3 = !((j+1)%3);
        int is5 = !((j+1)%5);
        
        if (is3 && is5) {
            sprintf(finalArray[j] = malloc(10 * sizeof(char)), "Fizz");
        } else if (is3) {
            sprintf(finalArray[j] = malloc(10 * sizeof(char)), "Fizz");
        } else if (is5) {
            sprintf(finalArray[j] = malloc(10 * sizeof(char)), "Buzz");
        } else {
            sprintf(finalArray[j] = malloc(10 * sizeof(char)), "%d", j+1);
        }
    }
    
    *returnSize = n;
    
    return finalArray;
}










