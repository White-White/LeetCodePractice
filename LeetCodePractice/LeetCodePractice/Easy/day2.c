//
//  day2.c
//  LeetCodePractice
//
//  Created by White on 2018/8/26.
//  Copyright © 2018年 White. All rights reserved.
//

#include <stdio.h>

char *reverseString(char * s) {
    
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
