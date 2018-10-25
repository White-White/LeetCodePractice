/*
 In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
 
 You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
 
 The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
 
 If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
 
 Example 1:
 Input:
 nums =
 [[1,2],
 [3,4]]
 r = 1, c = 4
 Output:
 [[1,2,3,4]]
 Explanation:
 The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
 Example 2:
 Input:
 nums =
 [[1,2],
 [3,4]]
 r = 2, c = 4
 Output:
 [[1,2],
 [3,4]]
 Explanation:
 There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
 Note:
 The height and width of the given matrix is in range [1, 100].
 The given r and c are all positive.

 */

#include "LC566.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
    
    if (numsRowSize * numsColSize != r * c) {
        
        *returnSize = numsRowSize;
        int** retNums = malloc(sizeof(int*)*numsRowSize);
        int* retColSizes = malloc(sizeof(int)*numsRowSize);
        for (int i = 0; i < numsRowSize; i++) {
            retNums[i] = malloc(sizeof(int)*numsColSize);
            memcpy(retNums[i], nums[i], sizeof(int)*numsColSize);
            retColSizes[i] = numsColSize;
        }
        *columnSizes = retColSizes;
        
        return nums;
    }
    
    *returnSize = r;
    int** retNums = malloc(sizeof(int*)*r);
    int* retColSizes = malloc(sizeof(int)*r);
    for (int i = 0; i < r; i++) {
        retNums[i] = malloc(sizeof(int)*c);
        retColSizes[i] = c;
    }
    *columnSizes = retColSizes;
    
    for (int i = 0; i < numsRowSize * numsColSize; i++) {
        
        int rOriginal = i / numsColSize;
        int cOriginal = i % numsColSize;
        
        int rNew = i / c;
        int cNew = i % c;
        
        retNums[rNew][cNew] = nums[rOriginal][cOriginal];
    }
    
    return retNums;
}
