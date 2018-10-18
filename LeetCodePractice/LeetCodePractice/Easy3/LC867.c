/*
 
 Given a matrix A, return the transpose of A.
 
 The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
 
 
 
 Example 1:
 
 Input: [[1,2,3],[4,5,6],[7,8,9]]
 Output: [[1,4,7],[2,5,8],[3,6,9]]
 Example 2:
 
 Input: [[1,2,3],[4,5,6]]
 Output: [[1,4],[2,5],[3,6]]
 
 
 Note:
 
 1 <= A.length <= 1000
 1 <= A[0].length <= 1000

 
 */

#include "LC867.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    
    *returnSize = AColSizes[0];
    int** ret = malloc(sizeof(int*)*(*returnSize));
    int* retColumnSizes = malloc(sizeof(int)*(*returnSize));
    *columnSizes = retColumnSizes;
    
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = malloc(sizeof(int)*ARowSize);
        retColumnSizes[i] = ARowSize;
    }
    
    for (int i = 0; i < ARowSize; i++) {
        int AColSize = AColSizes[i];
        for (int j = 0; j < AColSize; j++) {
            ret[j][i] = A[i][j];
        }
    }
    
    return ret;
}
