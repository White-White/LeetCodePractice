/*
 
 Remove Duplicates from Sorted List

 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 Example 1:
 
 Input: 1->1->2
 Output: 1->2
 Example 2:
 
 Input: 1->1->2->3->3
 Output: 1->2->3
 */

#include "LC83.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) { return NULL; }
    struct ListNode* current = head;
    while (current->next) {
        if (current->val == current->next->val) {
            if (current->next->next) {
                current->next = current->next->next;
            } else {
                current->next = NULL;
                break;
            }
        } else {
            current = current->next;
        }
    }
    return head;
}
