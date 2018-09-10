/*
 Shuffle an Array
 打乱一个没有重复元素的数组。
 
 示例:
 
 // 以数字集合 1, 2 和 3 初始化数组。
 int[] nums = {1,2,3};
 Solution solution = new Solution(nums);
 
 // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
 solution.shuffle();
 
 // 重设数组到它的初始状态[1,2,3]。
 solution.reset();
 
 // 随机返回数组[1,2,3]打乱后的结果。
 solution.shuffle();
 */

#include "Quiz16.h"
#include <stdlib.h>
#include <string.h>

Solution* solutionCreate(int* nums, int size) {
    Solution* sol = (Solution *)malloc(sizeof(Solution));
    sol->original = malloc(sizeof(int)*size);
    memcpy(sol->original, nums, sizeof(int)*size);
    sol->size = size;
    return sol;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
    int* result = malloc(sizeof(int)*obj->size);
    memcpy(result, obj->original, sizeof(int)*obj->size);
    *returnSize = obj->size;
    return result;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
    
    int size = obj->size;
    *returnSize = size;
    int* resultArray = (int *)malloc(sizeof(int)*size);
    
    //数组长度为0 直接返回
    if (size == 0) {
        return resultArray;
    }
    
    /* 方法1
     之间的老思路。创建一个index数组，每次循环随机消费其中一个index；
     取到这个随机的index后，去原数组中取值并复制到临时数组中
     被消费的index，将会被末尾的index替换，然后index数组长度-1.
     
    //创建index数组
    int indexArr[obj->size];
    for (int j = 0; j < obj->size; j++) {
        indexArr[j] = j;
    }
    
    int maxIndex = obj->size - 1;
    while (maxIndex >= 0) {
        //随机数
        int randomInt = rand()%(maxIndex + 1);
        //随机index
        int randomIndex = indexArr[randomInt];
        //随机值
        int randomValue = obj->original[randomIndex];
        resultArray[(obj->size - 1) - maxIndex] = randomValue;
        
        //将最后一位index移动过来
        indexArr[randomInt] = indexArr[maxIndex];
        maxIndex--;
    }
     */
    
    //方法2
    memcpy(resultArray, obj->original, size*sizeof(int));
    for (int i = 0; i < size; i++) {
        //随机index
        int j = rand()%(size);
        //交换
        int temp = resultArray[j];
        resultArray[j] = resultArray[i];
        resultArray[i] = temp;
    }
    return resultArray;
}

void solutionFree(Solution* obj) {
    free(obj->original);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */
