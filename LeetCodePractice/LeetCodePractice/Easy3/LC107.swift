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

import Foundation

private extension TreeNode {
    
    static func nextLevelNodes(with rootNodes: [TreeNode]) -> [TreeNode] {
        var ret: [TreeNode] = []
        for node in rootNodes {
            ret.append(contentsOf: node.nextLevelNodes)
        }
        return ret
    }
    
    private var nextLevelNodes: [TreeNode] {
        var ret: [TreeNode] = []
        if let left = self.left { ret.append(left) }
        if let right = self.right { ret.append(right) }
        return ret
    }
}

class Solution {
    func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
        guard let root = root else { return [] }
        var ret: [[Int]] = []
        let dumbHead = TreeNode(0)
        dumbHead.left = root
        var nextLevel = TreeNode.nextLevelNodes(with: [dumbHead])
        while !nextLevel.isEmpty {
            ret.append(nextLevel.map {$0.val})
            nextLevel = TreeNode.nextLevelNodes(with: nextLevel)
        }
        return ret.reversed()
    }
}
