/*
 Write a program to find the node at which the intersection of two singly linked lists begins.
 
 
 For example, the following two linked lists:
 
 A:          a1 → a2
 ↘
 c1 → c2 → c3
 ↗
 B:     b1 → b2 → b3
 begin to intersect at node c1.
 
 
 Notes:
 
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
 Credits:
 Special thanks to @stellari for adding this problem and creating all test cases.
 */

#include "LC160.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if (!headA || !headB) { return NULL; }
    
    struct ListNode* listA = headA;
    struct ListNode* listB = headB;
    
    while (listA != listB) {
        listA = (listA == NULL) ? headB : listA->next;
        listB = (listB == NULL) ? headA : listB->next;
    }
    
    return listA;
}

//使用双指针法
//这个解法 https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
/*
 精彩的地方在于，当listA和listB没有交集时，循环两次后，listA == listB == NULL，依然work
 */
