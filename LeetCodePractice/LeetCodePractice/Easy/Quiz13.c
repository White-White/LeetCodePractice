/*
 帕斯卡三角形
 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 
 在杨辉三角中，每个数是它左上方和右上方的数的和。
 
 示例:
 
 输入: 5
 输出:
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 */

#include "Quiz13.h"

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int** columnSizes) {
    
    int** columns = (int**)malloc(numRows*sizeof(int*));
    int* sizes = (int*)malloc(numRows*sizeof(int));
    
    for (int i = 0; i < numRows; i++) {
        int numOfEles = i+1;
        
        //一行的元素个数
        sizes[i] = numOfEles;
        
        //
        int* line = (int*)malloc(numOfEles*sizeof(int));
        //填充
        for (int j = 0; j < numOfEles; j++) {
            //杨辉三角形中，某个元素x，若其在当前行索引为y，其值等于，上一行索引y-1，与索引y处的值的和
            int indexLeftLastLine = j - 1;
            int indexRightLastLine = j;
            
            if (indexLeftLastLine >= 0 && indexRightLastLine < numOfEles - 1) {
                line[j] = columns[i-1][j-1] + columns[i-1][j];
            } else {
                line[j] = 1;
            }
        }
        columns[i] = line;
    }
    *columnSizes = sizes;
    return columns;
}













