/*
 Given a binary tree, flatten it to a linked list in-place.
 
 For example, given the following tree:
 
 1
 / \
 2   5
 / \   \
 3   4   6
 The flattened tree should look like:
 
 1
 \
 2
 \
 3
 \
 4
 \
 5
 \
 6
 */

#include "LC114.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* _flatten_private(struct TreeNode* node) {
    if (!node) {
        return NULL;
    }
    
    if (!node->left && !node->right) {
        return node;
    }
    
    struct TreeNode* nodeRight = node->right;
    struct TreeNode* leftEnd = NULL;
    
    if (node->left) {
        leftEnd = _flatten_private(node->left);
        node->right = node->left;
        node->left = NULL;
        leftEnd->right = nodeRight;
    }
    
    if (nodeRight) {
        return _flatten_private(nodeRight);
    } else {
        return leftEnd;
    }
}

void flatten(struct TreeNode* root) {
    _flatten_private(root);
}
