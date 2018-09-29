/*
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as:
 
 a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
 Example 1:
 
 Given the following tree [3,9,20,null,null,15,7]:
 
 3
 / \
 9  20
 /  \
 15   7
 Return true.
 
 Example 2:
 
 Given the following tree [1,2,2,3,3,null,null,4,4]:
 
 1
 / \
 2   2
 / \
 3   3
 / \
 4   4
 Return false.
 */

#include "LC110.h"

int balancedDepth(bool* isBalanced, struct TreeNode* node) {
    if (!node) {
        *isBalanced = true;
        return 0;
    }
    bool isBalancedLeft = true;
    bool isBalancedRight = true;
    int depthLeft = node->left ? balancedDepth(&isBalancedLeft, node->left) : 0;
    int depthRight = node->right ? balancedDepth(&isBalancedRight, node->right) : 0;
    int depthDistance = depthLeft - depthRight;
    *isBalanced = isBalancedRight && isBalancedLeft && (depthDistance <= 1 && depthDistance >= -1);
    
    return max(depthLeft, depthRight) + 1;
}

bool isBalanced(struct TreeNode* root) {
    bool isBalanced;
    balancedDepth(&isBalanced, root);
    return isBalanced;
}
