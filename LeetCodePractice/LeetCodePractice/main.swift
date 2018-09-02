//
//  main.swift
//  LeetCodePractice
//
//  Created by White on 2018/8/25.
//  Copyright © 2018年 White. All rights reserved.
//

import Foundation

//Day3.reverse(1534236469)
OCRun.run()

func createUnsafeMutablePointer<T>(with array: [T]) -> UnsafeMutablePointer<T> {
    let pointer = UnsafeMutablePointer<T>.allocate(capacity: array.count)
    for (index, value) in array.enumerated() {
        pointer.advanced(by: index).pointee = value
    }
    return pointer
}


//quiz4
var pointer = createUnsafeMutablePointer(with: [-1,-1,-2] as [Int32])
print(Quiz4.singleNumber(pointer, numsSize: 3))
