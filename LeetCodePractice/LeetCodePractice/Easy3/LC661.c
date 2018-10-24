/*
 Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
 
 Example 1:
 Input:
 [[1,1,1],
 [1,0,1],
 [1,1,1]]
 Output:
 [[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
 Explanation:
 For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 Note:
 The value in the given matrix is in the range of [0, 255].
 The length and width of the given matrix are in the range of [1, 150].

 */

#include "LC661.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize) {
    
    *returnSize = MRowSize;
    int** ret = malloc(sizeof(int*)*MRowSize);
    int* retColumnSizes = malloc(sizeof(int)*MRowSize);
    
    for (int rowIndex = 0; rowIndex < MRowSize; rowIndex++) {
        retColumnSizes[rowIndex] = MColSize;
        ret[rowIndex] = malloc(sizeof(int)*MColSize);
        
        for (int colIndex = 0; colIndex < MColSize; colIndex++) {
            
            int count = 0;
            int sum = 0;
            
            for (int rowIndex_start = max(0, rowIndex-1), rowIndex_end = min(MRowSize - 1, rowIndex + 1); rowIndex_start <= rowIndex_end; rowIndex_start++) {
                for (int colIndex_start = max(0, colIndex - 1), colIndex_end = min(MColSize - 1, colIndex + 1); colIndex_start <= colIndex_end; colIndex_start++) {
                    sum += M[rowIndex_start][colIndex_start];
                    count += 1;
                }
            }
            
            ret[rowIndex][colIndex] = sum / count;
            
        }
    }
    
    *columnSizes = retColumnSizes;
    return ret;
}
