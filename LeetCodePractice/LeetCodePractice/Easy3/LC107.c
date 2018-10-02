/*
 
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
 15   7
 return its bottom-up level order traversal as:
 [
 [15,7],
 [9,20],
 [3]
 ]
 */

#include "LC107.h"
#include "Quiz7.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** reverseArrayOfArray(int** array, int length) {
    
    if (length < 2) { return array; }
    
    int lastIndex = length - 1;
    int k = 0;
    
    for (; k < lastIndex ; k++, lastIndex-- ) {
        
        int* tem = *(array+k);
        *(array+k) = *(array+lastIndex);
        *(array+lastIndex) = tem;
    }
    
    return array;
}

int* reverseArray(int* array, int length) {
    
    if (length < 2) { return array; }
    
    int lastIndex = length - 1;
    int k = 0;
    
    for (; k < lastIndex ; k++, lastIndex-- ) {
        
        int tem = *(array+k);
        *(array+k) = *(array+lastIndex);
        *(array+lastIndex) = tem;
    }
    
    return array;
}

struct TreeNode** nextLevel(struct TreeNode** nodeArray, int nodeArrayLength, int* size) {
    if (nodeArrayLength == 0) {
        *size = 0;
        return NULL;
    }
    
    struct TreeNode* nodeArrayNextLevel[nodeArrayLength*2];
    int nextLevelNodeCount = 0;
    
    for (int i = 0; i < nodeArrayLength; i++) {
        struct TreeNode* oneNode = nodeArray[i];
        
        if (oneNode->left) {
            nodeArrayNextLevel[nextLevelNodeCount] = oneNode->left;
            nextLevelNodeCount++;
        }
        
        if (oneNode->right) {
            nodeArrayNextLevel[nextLevelNodeCount] = oneNode->right;
            nextLevelNodeCount++;
        }
    }
    
    if (nextLevelNodeCount == 0) {
        *size = 0;
        return NULL;
    }
    
    struct TreeNode** ret = malloc(sizeof(struct TreeNode*)*nextLevelNodeCount);
    memcpy(ret, nodeArrayNextLevel, sizeof(struct TreeNode*)*nextLevelNodeCount);
    *size = nextLevelNodeCount;
    return ret;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (!root) { return NULL; }
    
    int retLength = 100;
    int retLengthUsed = 0;
    int** ret = malloc(sizeof(int*)*retLength);
    int* retColumnSizes = malloc(sizeof(int)*retLength);
    
    struct TreeNode dumbHead = {0, root, NULL};
    struct TreeNode* buffer[1];
    buffer[0] = &dumbHead;
    
    int size;
    struct TreeNode** nextLevelNodes = nextLevel(buffer, 1, &size);
    while (nextLevelNodes) {
        int* column = malloc(sizeof(int)*size);
        for (int i = 0; i < size; i++) {
            column[i] = nextLevelNodes[i]->val;
        }
        
        //空间不够 再次申请
        while (retLengthUsed >= retLength) {
            int** newRet = malloc(sizeof(int*)*retLength*2);
            int* newRetColumnSizes = malloc(sizeof(int)*retLength);
            memcpy(newRet, ret, sizeof(int*)*retLengthUsed);
            memcpy(newRetColumnSizes, retColumnSizes, sizeof(int)*retLengthUsed);
            free(ret);free(retColumnSizes);
            ret = newRet;
            retColumnSizes = newRetColumnSizes;
            retLength *= 2;
        }
        
        ret[retLengthUsed] = column;
        retColumnSizes[retLengthUsed] = size;
        retLengthUsed++;
        
        //下一层深度
        nextLevelNodes = nextLevel(nextLevelNodes, size, &size);
    }
    
    *columnSizes = reverseArray(retColumnSizes, retLengthUsed);
    ret = reverseArrayOfArray(ret, retLengthUsed);
    *returnSize = retLengthUsed;
    
    return ret;
}


///LC107 fuck it. no more C








