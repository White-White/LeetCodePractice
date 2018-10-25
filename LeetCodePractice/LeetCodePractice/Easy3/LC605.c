/*
 
 Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
 
 Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
 
 Example 1:
 Input: flowerbed = [1,0,0,0,1], n = 1
 Output: True
 Example 2:
 Input: flowerbed = [1,0,0,0,1], n = 2
 Output: False
 Note:
 The input array won't violate no-adjacent-flowers rule.
 The input array size is in the range of [1, 20000].
 n is a non-negative integer which won't exceed the input array size.

 */

#include "LC605.h"

int _n(int startIndex, int endIndex, int maxEndIndex) {
    
    int x = -1;
    
    if (startIndex == 0) {
        x++;
    }
    
    if (endIndex == maxEndIndex) {
        x++;
    }
    
    int distance = endIndex - startIndex + 1;
    
    return (distance <= 0) ? 0 : (distance + x) / 2;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    int curStartIndex = 0;
    
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 1) {
            count += _n(curStartIndex, i - 1, flowerbedSize - 1);
            curStartIndex = i + 1;
            i++;
        } else { // == 0
            if (i == flowerbedSize - 1) {
                count += _n(curStartIndex, i, flowerbedSize - 1);
                break;
            }
            continue;
        }
    }
    
    return count >= n;
}
