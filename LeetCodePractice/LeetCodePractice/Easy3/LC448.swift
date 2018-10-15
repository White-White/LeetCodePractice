/*
 Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements of [1, n] inclusive that do not appear in this array.
 
 Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 
 Example:
 
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [5,6]
 */

import Foundation

class Solution_448 {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        
        var numsCopy = nums
        var ret: [Int] = []
        
        for num in nums {
            let index = num - 1
            if (numsCopy[index] > 0) {
                numsCopy[index] = -numsCopy[index]
            }
        }
        
        for (index, value) in numsCopy.enumerated() {
            if value > 0 {
                ret.append(index + 1)
            }
        }
        
        return ret
    }
}
