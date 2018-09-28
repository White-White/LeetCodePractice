/*
 Given a binary tree, find its minimum depth.
 
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 
 Note: A leaf is a node with no children.
 
 Example:
 
 Given binary tree [3,9,20,null,null,15,7],
 
 3
 / \
 9  20
 /  \
 15   7
 return its minimum depth = 2.
 */

#include "LC111.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



int minDepth(struct TreeNode* root) {
    if (!root) { return 0; }
    return (root->left == NULL || root->right == NULL)
    ? (minDepth(root->left) + minDepth(root->right) + 1)
    : (min(minDepth(root->left), minDepth(root->right)) + 1);
}
