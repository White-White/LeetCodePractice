/*
 Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
 
 To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 
 To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 
 Example 1:
 
 Input: [[1,1,0],[1,0,1],[0,0,0]]
 Output: [[1,0,0],[0,1,0],[1,1,1]]
 Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 Example 2:
 
 Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 Notes:
 
 1 <= A.length = A[0].length <= 20
 0 <= A[i][j] <= 1

 */

#include "LC832.h"
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    
    int** retA = malloc(sizeof(int*)*ARowSize);
    int* retColSizes = malloc(sizeof(int)*ARowSize);
    
    for (int i = 0; i < ARowSize; i++) {
        int colSize = AColSizes[i];
        retColSizes[i] = colSize;
        
        retA[i] = malloc(sizeof(int)*colSize);
        memcpy(retA[i], A[i], sizeof(int)*colSize);
        int* theRow = *(retA+i);
        
        for (int j = 0, k = colSize - 1; j <= k; j++, k--) {
            int temp = theRow[j];
            theRow[j] = theRow[k] ? 0 : 1;
            theRow[k] = temp ? 0 : 1;
        }
    }
    
    *columnSizes = retColSizes;
    *returnSize = ARowSize;
    
    return retA;
}
