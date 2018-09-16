/*
 旋转数组
 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 
 示例 1:
 
 输入: [1,2,3,4,5,6,7] 和 k = 3
 输出: [5,6,7,1,2,3,4]
 解释:
 向右旋转 1 步: [7,1,2,3,4,5,6]
 向右旋转 2 步: [6,7,1,2,3,4,5]
 向右旋转 3 步: [5,6,7,1,2,3,4]
 示例 2:
 
 输入: [-1,-100,3,99] 和 k = 2
 输出: [3,99,-1,-100]
 解释:
 向右旋转 1 步: [99,-1,-100,3]
 向右旋转 2 步: [3,99,-1,-100]
 说明:
 
 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 要求使用空间复杂度为 O(1) 的原地算法。
 */

//1 2 3 4 5 6 7 8
//5 6 7 8 1 2 3 4
//
//1 2 3 4 5 6 7 8 //5
//4 5 6 7 8 1 2 3

#include "Quiz22.h"
#include <string.h>

void rotate(int* nums, int numsSize, int k) {
    int tempNums[numsSize];
    int indexToMove = k%numsSize;
    if (indexToMove == 0) { return; }
    int chunks = numsSize/indexToMove;
    if (numsSize%indexToMove != 0) { chunks+=1; }
    
    for (int i = 0; i < chunks; i++) {
        for (int j = 0, source = i*indexToMove; j < indexToMove && source < numsSize; j++, source++) {
            int dest = (source+indexToMove)%numsSize;
            tempNums[dest] = nums[source];
        }
    }
    
    memcpy(nums, tempNums, sizeof(int)*numsSize);
}
