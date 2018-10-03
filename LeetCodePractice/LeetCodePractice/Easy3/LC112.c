//
//  LC112.c
//  LeetCodePractice
//
//  Created by White on 2018/10/3.
//  Copyright © 2018年 White. All rights reserved.
//

#include "LC112.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//bool hasPath_sub(struct TreeNode* root,)

bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) { return false; }
    if (root->val == sum && !root->left && !root->right) {
        return true;
    } else {
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
}
