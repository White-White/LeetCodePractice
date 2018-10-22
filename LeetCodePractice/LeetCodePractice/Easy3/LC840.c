/*
 A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
 
 Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
 
 
 
 Example 1:
 
 Input: [[4,3,8,4],
 [9,5,1,9],
 [2,7,6,2]]
 Output: 1
 Explanation:
 The following subgrid is a 3 x 3 magic square:
 438
 951
 276
 
 while this one is not:
 384
 519
 762
 
 In total, there is only one magic square inside the given grid.
 Note:
 
 1 <= grid.length <= 10
 1 <= grid[0].length <= 10
 0 <= grid[i][j] <= 15

 */

#include "LC840.h"

bool isMagicSquare(int** grid) {
    int rowSize = 3;
    int sum = -1;
    
    int x = 0b000000000;
    
    for (int i = 0; i < rowSize; i++) {
        int rowSum = 0;
        int columnSum = 0;
        int diagonal1Sum = 0;
        int diagonal2Sum = 0;
        
        for (int j = 0; j < rowSize; j++) {
            
            //check sum
            int valueInRow = grid[i][j];
            
            {
                //check num existance
                if ((valueInRow) > 9 || (valueInRow) < 1) { return false; } //只允许 1-9
                
                int tempFlag = 1;
                tempFlag <<= (valueInRow - 1);
                
                if ((tempFlag & x) == tempFlag) { return false; } //已将此数标记为了已存在
                x |= tempFlag;
            }
            
            rowSum += valueInRow;
            
            //check sum
            int columnInRow = grid[j][i];
            columnSum += columnInRow;
            
            
            //check sum
            int diagonal1 = grid[j][j];
            diagonal1Sum += diagonal1;
            
            //check sum
            int diagonal2 = grid[rowSize-j-1][j];
            diagonal2Sum += diagonal2;
        }
        
        //row sum
        if (sum == -1) {
            sum = rowSum;
        } else if (rowSum != sum) {
            return false;
        }
        
        //columnSum
        if (columnSum != sum) {
            return false;
        }
        
        //check sum
        if (diagonal1Sum != sum) {
            return false;
        }
        
        //check sum
        if (diagonal2Sum != sum) {
            return false;
        }
    }
    
    //对角线
    return true;
}

int numMagicSquaresInside(int** grid, int gridRowSize, int *gridColSizes) {
    
    int columnSize = gridColSizes[0];
    int count = 0;
    for (int i = 0; i < gridRowSize - 2; i++) {
        for (int j = 0; j < columnSize - 2; j++) {
            int* tempGrid[3];
            for (int k = 0; k < 3; k++) {
                *(tempGrid+k) = *(grid+i+k)+j;
            }
            if (isMagicSquare(tempGrid)) {
                count++;
            }
        }
    }
    return count;
}

















