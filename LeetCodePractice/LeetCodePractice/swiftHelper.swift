//
//  swiftHelper.swift
//  LeetCodePractice
//
//  Created by White on 2018/9/9.
//  Copyright © 2018年 White. All rights reserved.
//

import Foundation

func createUnsafeMutablePointer<T>(with array: [T]) -> UnsafeMutablePointer<T> {
    let pointer = UnsafeMutablePointer<T>.allocate(capacity: array.count)
    for (index, value) in array.enumerated() {
        pointer.advanced(by: index).pointee = value
    }
    return pointer
}
