/*
 Merge Two Sorted Lists
 
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 Example:
 
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
 */

#include "Quiz27.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* nodeHead = NULL;
    struct ListNode* nodeCurrent = NULL;
    struct ListNode* l1Current = l1;
    struct ListNode* l2Current = l2;
    
    while (l1Current || l2Current) {
        struct ListNode* nodeNext = NULL;
        
        if (!l1Current) {
            nodeNext = l2Current;
            l2Current = NULL;
        } else if (!l2Current) {
            nodeNext = l1Current;
            l1Current = NULL;
        } else {
            if (l1Current->val > l2Current->val) {
                nodeNext = l2Current;
                l2Current = l2Current->next;
            } else {
                nodeNext = l1Current;
                l1Current = l1Current->next;
            }
            nodeNext->next = NULL;
        }
        
        if (nodeHead) {
            nodeCurrent->next = nodeNext;
            nodeCurrent = nodeNext;
        } else {
            nodeHead = nodeNext;
            nodeCurrent = nodeNext;
        }
    }
    
    return nodeHead;
}
