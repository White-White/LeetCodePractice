/*
 只出现一次的数字
 
 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 
 说明：
 
 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 
 示例 1:
 
 输入: [2,2,1]
 输出: 1
 示例 2:
 
 输入: [4,1,2,1,2]
 输出: 4
 */

#import <Foundation/Foundation.h>

@interface Quiz4 : NSObject

//第一个版本
+ (int)singleNumber:(int *)nums numsSize: (int)numsSize;

//第二个版本
+ (int)singleNumberv2:(int *)nums numsSize: (int)numsSize;

@end

@implementation Quiz4

//第一个版本
+ (int)singleNumber:(int *)nums numsSize:(int)numsSize {

    for (int j = 1; j < numsSize; j++) {
        
        for (int k = j; k >= 1; k--) {
            
            
            int *ptrRight = nums+k;
            int *ptrLeft = nums+k-1;
            
            if (*ptrLeft > *ptrRight) {
                //exchange
                int temp = *ptrLeft;
                *ptrLeft = *ptrRight;
                *ptrRight = temp;
            } else {
                continue;
            }
            
        }
        
        
    }
    
    //已排完序
    for (int l = 0; l < numsSize; ) {
        if (*(nums+l) != *(nums+l+1)) {
            return *(nums+l);
        }
        l+=2;
    }
    
    
    return 0;
}

+ (int)singleNumberv2:(int *)nums numsSize:(int)numsSize {
    //还未实现
    return 0;
}


@end
