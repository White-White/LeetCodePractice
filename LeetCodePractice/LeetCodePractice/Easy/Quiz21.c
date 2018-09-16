/*
 罗马数字转整数
 罗马数字包含以下七种字符：I， V， X， L，C，D 和 M。
 
 字符          数值
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 
 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 
 I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 
 示例 1:
 
 输入: "III"
 输出: 3
 示例 2:
 
 输入: "IV"
 输出: 4
 示例 3:
 
 输入: "IX"
 输出: 9
 示例 4:
 
 输入: "LVIII"
 输出: 58
 解释: C = 100, L = 50, XXX = 30, III = 3.
 示例 5:
 
 输入: "MCMXCIV"
 输出: 1994
 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 */

#include "Quiz21.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    R_NUM_I = 1,
    R_NUM_V = 5,
    R_NUM_X = 10,
    R_NUM_L = 50,
    R_NUM_C = 100,
    R_NUM_D = 500,
    R_NUM_M = 1000,
} RomanNumber;

RomanNumber romanNumberFrom(char c) {
    switch (c) {
        case 73:
            return R_NUM_I;
        case 86:
            return R_NUM_V;
        case 88:
            return R_NUM_X;
        case 76:
            return R_NUM_L;
        case 67:
            return R_NUM_C;
        case 68:
            return R_NUM_D;
        case 77:
            return R_NUM_M;
        default:
            exit(1);
    }
}

#pragma - Concrate

struct Concrate {
    RomanNumber *rmNums;
    int lengthMax;
    int length;
    int sum; //当前的和
    struct Concrate* next;
};

struct Concrate* newConcrate() {
    struct Concrate* concrate = malloc(sizeof(struct Concrate));
    int lengthMax = 20;
    concrate->rmNums = malloc(sizeof(RomanNumber)*lengthMax);
    concrate->lengthMax = lengthMax;
    concrate->length = 0;
    concrate->sum = 0;
    concrate->next = NULL;
    return concrate;
}

bool canPushToConcrate(struct Concrate* concrate, RomanNumber newRMNumber) {
    if (concrate->length == 0) { return true; }
    if (concrate->length == concrate->lengthMax) { printf("error maxLength\n"); exit(1); }
    RomanNumber lastRMNumberInConcrate = concrate->rmNums[concrate->length - 1];
    
    if (lastRMNumberInConcrate > newRMNumber) {
        //防止出现IVI的情况 或 IXI
        
        int indexLastButOne = concrate->length - 2;
        int indexLastButTwo = concrate->length - 3;
        
        if ( indexLastButOne >= 0 && indexLastButTwo >= 0 ) {
            switch (newRMNumber) {
                case R_NUM_I: {
                    return ((concrate->rmNums[indexLastButOne] != R_NUM_V && concrate->rmNums[indexLastButOne] != R_NUM_X )
                            || concrate->rmNums[indexLastButTwo] != newRMNumber);
                }
                case R_NUM_X: {
                    return ((concrate->rmNums[indexLastButOne] != R_NUM_L && concrate->rmNums[indexLastButOne] != R_NUM_C)
                            || concrate->rmNums[indexLastButTwo] != newRMNumber);
                }
                case R_NUM_C: {
                    return ((concrate->rmNums[indexLastButOne] != R_NUM_D && concrate->rmNums[indexLastButOne] != R_NUM_M)
                            || concrate->rmNums[indexLastButTwo] != newRMNumber);
                }
                default:
                    return true;
            }
        }
        
        return true;
    } else if (lastRMNumberInConcrate == newRMNumber) {
        if (newRMNumber != R_NUM_I && newRMNumber != R_NUM_X && newRMNumber != R_NUM_C && newRMNumber != R_NUM_M) {
            return false;
        }
        
        bool canPush = true;
        
        //多个I X C D的情况 检查倒数第二位和倒数第三位
        int indexLastButOne = concrate->length - 2;
        int indexLastButTwo = concrate->length - 3;
        
        if ( indexLastButOne >= 0 && indexLastButTwo >= 0
            && concrate->rmNums[indexLastButOne] == newRMNumber
            && concrate->rmNums[indexLastButTwo] == newRMNumber ) {
            canPush = false;
        }
        
        return canPush;
    } else { //lastRMNumberInConcrate < newRMNumber
        
        //倒数第二位必须不等于 lastRMNumberInConcrate 本身 否则会出现IIV的情况
        int indexLastButOne = concrate->length - 2;
        
        if (indexLastButOne >= 0) {
            
        } else {
            
        }
        
        int lastButOne = concrate->rmNums[indexLastButOne];
        
        
        
        switch (lastRMNumberInConcrate) {
            case R_NUM_I: {
                return !( (newRMNumber == R_NUM_V || newRMNumber == R_NUM_X)
                         && indexLastButOne >= 0
                         && lastRMNumberInConcrate == lastButOne);
            }
            case R_NUM_X: {
                return !( (newRMNumber == R_NUM_L || newRMNumber == R_NUM_C)
                         && indexLastButOne >= 0
                         && lastRMNumberInConcrate == lastButOne);
            }
            case R_NUM_C: {
                return !( (newRMNumber == R_NUM_D || newRMNumber == R_NUM_M)
                         && indexLastButOne >= 0
                         && lastRMNumberInConcrate == lastButOne);
            }
            default:
                return false;
        }
    }
}

void pushToConcrate(struct Concrate* concrate, RomanNumber newRMNumber) {
    int indexLast = concrate->length - 1;
    
    switch (newRMNumber) {
        case R_NUM_X:
        case R_NUM_V: { //之前所有的I判负
            if (indexLast >= 0 && concrate->rmNums[indexLast] == R_NUM_I) {
                concrate->sum -= R_NUM_I*2;
            }
            break;
        }
        case R_NUM_C:
        case R_NUM_L: { //之前所有的X判负
            if (indexLast >= 0 && concrate->rmNums[indexLast] == R_NUM_X) {
                concrate->sum -= R_NUM_X*2;
            }
            break;
        }
        case R_NUM_M:
        case R_NUM_D: { //之前所有的C判负
            if (indexLast >= 0 && concrate->rmNums[indexLast] == R_NUM_C) {
                concrate->sum -= R_NUM_C*2;
            }
            break;
        }
        default:
            break;
    }
    
    concrate->rmNums[concrate->length] = newRMNumber;
    concrate->length += 1;
    concrate->sum = concrate->sum + newRMNumber;
}

int sumOf(struct Concrate* concrate) {
    return concrate->sum + (concrate->next ? sumOf(concrate->next) : 0);
}

void freeConcrate(struct Concrate* concrate) {
    struct Concrate* next = concrate->next;
    free(concrate->rmNums);
    free(concrate);
    if (next) {
        freeConcrate(next);
    }
}

int romanToInt(char* s) {
    
    unsigned long length = strlen(s);
    
    struct Concrate* concrateHead = newConcrate();
    struct Concrate* concrateCurrent = concrateHead;
    
    for (int i = 0; i < length; i++) {
        char oneRMChar = s[i];
        RomanNumber newRMNumber = romanNumberFrom(oneRMChar);
        if (canPushToConcrate(concrateCurrent, newRMNumber)) {
            pushToConcrate(concrateCurrent, newRMNumber);
        } else {
            concrateCurrent->next = newConcrate();
            concrateCurrent = concrateCurrent->next;
            pushToConcrate(concrateCurrent, newRMNumber);
        }
    }
    
    int sum = sumOf(concrateHead);
    freeConcrate(concrateHead);
    
    return sum;

}
