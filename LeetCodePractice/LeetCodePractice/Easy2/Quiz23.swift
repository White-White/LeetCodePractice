//
//  Quiz23.swift
//  LeetCodePractice
//
//  Created by White on 2018/9/18.
//  Copyright © 2018年 White. All rights reserved.
//

import Foundation

//用hash table的方式实现two sum
class SolutionQuiz23 {
    func twoSumHash(_ nums: [Int], _ target: Int) -> [Int] {
        
        var dict: [Int: Int] = [:]
        
        for (index, value) in nums.enumerated() {
            dict[value] = index
        }
        
        for (index, value) in nums.enumerated() {
            let complement = target - value
            if let targetIndex = dict[complement], targetIndex != index {
                return [index, targetIndex]
            }
        }
        
        fatalError()
    }
    
    func twoSumHashBetter(_ nums: [Int], _ target: Int) -> [Int] {
        
        var dict: [Int: Int] = [:]
        
        for (index, value) in nums.enumerated() {
            let complement = target - value
            if let targetIndex = dict[complement] {
                return [index, targetIndex]
            }
            //
            dict[value] = index
        }
        
        fatalError()
    }
}
