/*
 
 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
 
 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 
 示例：
 
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 */

#include "Quiz19.h"
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode(int value) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int power = 1;
    int left = 0;
    
    struct ListNode *l1temp = l1;
    struct ListNode *l2temp = l2;
    
    struct ListNode *result = NULL;
    struct ListNode *returnNode = NULL;

    while ((l1temp != NULL) || (l2temp != NULL) || left != 0){
        if (!result) {
            result = createNode(0); //新建根节点
            returnNode = result;
        } else {
            result->next = createNode(0); //新建子节点
            result = result->next;
        }
        
        int val1 = l1temp ? l1temp->val : 0;
        int val2 = l2temp ? l2temp->val : 0;
        
        int total = val1+val2+left;
        
        //当前位置的数
        result->val = total%10;
        
        //进位
        left = total/10;
        
        //
        power*=10;
        l1temp = l1temp ? l1temp->next : NULL;
        l2temp = l2temp ? l2temp->next : NULL;
    }
    
    return returnNode;
}
