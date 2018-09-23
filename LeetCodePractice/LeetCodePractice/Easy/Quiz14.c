/*有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/

#include "Quiz14.h"

bool isPush(char c) {
    switch (c) {
        case '(':
        case '[':
        case '{':
            return true;
        default:
            return false;
    }
}

bool canPop(char c, char lastC) {
    return ((c == ']' && lastC == '[') || (c == ')' && lastC == '(') || (c == '}' && lastC == '{'));
}

bool isValid(char* s) {
    unsigned long length = strlen(s);
    if (!length) { return true; }
    char stack[length];
    char *stackPtr = stack;
    
    for (unsigned long i = 0; i < length; i++) {
        
        char currentChar = *(s+i);
        
        if (isPush(currentChar)) {
            *stackPtr = currentChar; //入栈
            stackPtr++;
            continue;
        } else if (stackPtr != stack && canPop(currentChar, *(stackPtr-1))) {
            stackPtr--;
            continue;
        } else {
            return false;
        }
    }
    
    return stackPtr == stack;
}






















