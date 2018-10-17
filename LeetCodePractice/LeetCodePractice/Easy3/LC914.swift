/*
 In a deck of cards, each card has an integer written on it.
 
 Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
 
 Each group has exactly X cards.
 All the cards in each group have the same integer.
 
 
 Example 1:
 
 Input: [1,2,3,4,4,3,2,1]
 Output: true
 Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
 Example 2:
 
 Input: [1,1,1,2,2,2,3,3]
 Output: false
 Explanation: No possible partition.
 Example 3:
 
 Input: [1]
 Output: false
 Explanation: No possible partition.
 Example 4:
 
 Input: [1,1]
 Output: true
 Explanation: Possible partition [1,1]
 Example 5:
 
 Input: [1,1,2,2,2,2]
 Output: true
 Explanation: Possible partition [1,1],[2,2],[2,2]
 
 Note:
 
 1 <= deck.length <= 10000
 0 <= deck[i] < 10000

 */

import Foundation

class Solution_914 {
    func hasGroupsSizeX(_ deck: [Int]) -> Bool {
        
        if deck.count < 2 {
            return false
        }
        
        var dict: [Int: Int] = [:]
        
        for num in deck {
            if let count = dict[num] {
                dict[num] = count + 1
            } else {
                dict[num] = 1
            }
        }
        
        let counts = dict.keys.compactMap { dict[$0] }
        
        if let smallestCount = counts.sorted(by: <).first, smallestCount >= 2 {
            
            for index in 2...smallestCount {
                var isOK = true
                for oneCount in counts {
                    if oneCount % index != 0 {
                        isOK = false
                        break
                    }
                }
                if (isOK) {
                    return true
                }
            }
            
            return false
        } else {
            return false
        }
        
    }
}

