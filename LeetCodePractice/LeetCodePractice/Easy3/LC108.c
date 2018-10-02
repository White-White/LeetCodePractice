/*
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
 Example:
 
 Given the sorted array: [-10,-3,0,5,9],
 
 One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 
 0
 / \
 -3   9
 /   /
 -10  5
 */

#include "LC108.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) { return NULL; }
    
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    if (numsSize == 1) {
        node->val = nums[0];
        return node;
    }
    
    int half = numsSize/2;
    
    node->val = nums[half];
    node->left = sortedArrayToBST(nums, half);
    node->right = sortedArrayToBST(nums+half+1, numsSize-half-1);
    
    return node;
}












