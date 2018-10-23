/*
 We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
 
 Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.
 
 Example 1:
 Input:
 bits = [1, 0, 0]
 Output: True
 Explanation:
 The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
 Example 2:
 Input:
 bits = [1, 1, 1, 0]
 Output: False
 Explanation:
 The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
 Note:
 
 1 <= len(bits) <= 1000.
 bits[i] is always 0 or 1.
 */

#include "LC717.h"

//递归
bool isOneBitCharacter(int* bits, int bitsSize) {
    switch (bitsSize) {
        case 0:
            return false;
        case 1:
            return bits[0] == 0;
        case 2:
            return bits[0] == 0 && bits[1] == 0;
        default:
            if (bits[0] == 0) {
                return isOneBitCharacter(bits+1, bitsSize-1);
            } else {
                return isOneBitCharacter(bits+2, bitsSize-2);
            }
    }
}

//
//from leetCode
bool isOneBitCharacterBetter(int* bits, int bitsSize) {
    int i = 0;
    while (i < bitsSize - 1) {
        i += (bits[i] + 1);
    }
    return i == (bitsSize - 1);
}
