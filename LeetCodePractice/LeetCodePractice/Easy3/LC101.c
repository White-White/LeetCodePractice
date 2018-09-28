/*
 
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 
 1
 / \
 2   2
 / \ / \
 3  4 4  3
 But the following [1,2,2,null,3,null,3] is not:
 1
 / \
 2   2
 \   \
 3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.
 

 
 */

#include "LC101.h"

bool isReversed(struct TreeNode* left, struct TreeNode* right) {
    if (left == right) { return true; }
    if (left == NULL || right == NULL) { return false; }
    return left->val == right->val && (isReversed(left->left, right->right)) && (isReversed(left->right, right->left));
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) { return true; }
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    if (left == right) { return true; }
    if (left == NULL || right == NULL) { return false; }
    
    return (isReversed(left, right));
}
