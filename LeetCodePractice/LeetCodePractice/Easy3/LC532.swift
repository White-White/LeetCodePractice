//
//  LC532.swift
//  LeetCodePractice
//
//  Created by White on 2018/10/15.
//  Copyright © 2018年 White. All rights reserved.
//

import Foundation

class Solution_532 {
    func findPairs(_ nums: [Int], _ k: Int) -> Int {
        var dict: [Int: [Int]] = [:]
        
        for (index, num) in nums.enumerated() {
            for indexInside in (index+1)..<nums.count {
                let numAnother = nums[indexInside]
                
                if abs(num - numAnother) == k {
                    let smaller = min(num, numAnother)
                    let bigger = max(num, numAnother)
                    if let results = dict[smaller] {
                        if !results.contains(bigger) {
                            dict[smaller] = results + [bigger]
                        }
                    } else {
                        dict[smaller] = [bigger]
                    }
                }
            }
        }
        return dict.count
    }
}
//超时

//注： 一个恶心的问题必然有一个恶心的答案

class Solution_532_Better {
    func findPairs(_ nums: [Int], _ k: Int) -> Int {
        //生成一个类Python中collections.Counter的计数器
        var dict: [Int: Int] = [:]
        var totalCount = 0
        for num in nums {
            if let count = dict[num] {
                dict[num] = count+1
            } else {
                dict[num] = 1
            }
        }
        
        for num in dict.keys.sorted(by: <) {
            let existed = dict[num + k] ?? 0
            
            if (k > 0 && existed != 0) || (k == 0 && existed > 1) {
                totalCount += 1
            }
        }
        
        return totalCount
    }
}
//根据leetCode一个Python答案，改写的swift解法 O(n)
//https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/100135/Easy-Understood-Python-Solution
