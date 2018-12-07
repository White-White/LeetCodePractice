//
//  LC606.swift
//  LeetCodePractice
//
//  Created by White on 2018/12/7.
//  Copyright © 2018 White. All rights reserved.
//

import Foundation

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution_606 {
    func _tree2str(_ t: TreeNode?) -> String {
        if let t = t {
            var ret = "(\(t.val)"
            
            if (t.left == nil && t.right != nil) {
                ret += "()\(_tree2str(t.right))"
            } else {
                ret += "\(_tree2str(t.left))\(_tree2str(t.right))"
            }

            ret += ")"
            return ret
        } else {
            return ""
        }
    }
    
    func tree2str(_ t: TreeNode?) -> String {
        if let t = t {
            var ret = "\(t.val)"
            
            
            if (t.left == nil && t.right != nil) {
                ret += "()\(_tree2str(t.right))"
            } else {
                ret += "\(_tree2str(t.left))\(_tree2str(t.right))"
            }
            
            return ret
        } else {
            return ""
        }
    }
}
