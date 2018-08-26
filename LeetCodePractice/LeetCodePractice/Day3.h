//
//  Day3.h
//  LeetCodePractice
//
//  Created by White on 2018/8/26.
//  Copyright © 2018年 White. All rights reserved.
//

/*
 
 给定一个 32 位有符号整数，将整数中的数字进行反转。
 
 示例 1:
 
 输入: 123
 输出: 321
 示例 2:
 
 输入: -123
 输出: -321
 示例 3:
 
 输入: 120
 输出: 21
 注意:
 
 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
 
 */

#import <Foundation/Foundation.h>

@interface Day3 : NSObject

+ (int)reverse: (int)x;

@end

@implementation Day3

+ (int)reverse: (int)x {
    
    int32_t theX = x;
    int32_t rev = 0;
    
    while (theX != 0) {
        int pop = theX % 10;
        theX /= 10;
        
        //保护接下来的加法不溢出
        if (rev > INT32_MAX/10 || (rev == INT32_MAX/10 && pop > INT32_MAX%10)) { return 0; }
        if (rev < INT32_MIN/10 || (rev == INT32_MIN/10 && pop < INT32_MIN%10)) { return 0; }
        
        int32_t temp = rev * 10 + pop;
        rev = temp;
    }
    
    return rev;
}

@end

/*
 
 后记：
 这套题没想出来来办法，打印字符串强转int的方法又十分不优雅。
 
 答案中 INT32_MAX%10 和 INT32_MIN%10 分别写死成 7 和 -8,
 这里改成计算的方便可读性。
 
 因为是两个常数，编译器应该会优化掉。
 
 */
