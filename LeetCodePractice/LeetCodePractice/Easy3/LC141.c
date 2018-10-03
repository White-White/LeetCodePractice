/*
 Given a linked list, determine if it has a cycle in it.
 
 Follow up:
 Can you solve it without using extra space?
 */

#include "LC141.h"

bool hasCycle(struct ListNode *head) {
    struct ListNode* currentHead = head;
    while (currentHead) {
        struct ListNode* currentHeadInside = head;
        while (currentHeadInside != currentHead) {
            if (currentHeadInside == currentHead->next) {
                return true;
            }
            currentHeadInside = currentHeadInside->next;
        }
        currentHead = currentHead->next;
    }
    return false;
}

//注： 以上双循环法在leetCode超时

//以下使用双指针法
bool hasCycleBetter(struct ListNode *head) {
    if (!head || !(head->next)) {
        return false;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
