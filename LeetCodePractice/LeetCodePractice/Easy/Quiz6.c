//
//  Quiz6.c
//  LeetCodePractice
//
//  Created by White on 2018/9/8.
//  Copyright © 2018年 White. All rights reserved.
//

#include <stdio.h>

/*
 反转链表
 反转一个单链表。
 
 示例:
 
 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL
 进阶:
 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

//迭代解法
struct ListNode* reverseListLoop(struct ListNode* head) {
    
    if (!head) { return NULL; }
    
    struct ListNode* currentNode = head;
    struct ListNode* nextNode = head->next;
    
    currentNode->next = NULL;
    
    while (nextNode) {
        struct ListNode* nextNodeNew = nextNode->next;
        nextNode->next = currentNode;
        
        currentNode = nextNode;
        nextNode = nextNodeNew;
    }
    
    return currentNode;
}

//递归解法

struct ListNode* _reverseList_recersive(struct ListNode* current, struct ListNode* next) {
    if (!next) return current;
    struct ListNode* nextNew = next->next;
    next->next = current;
    return _reverseList_recersive(next, nextNew);
}

struct ListNode* reverseList(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode* next = head->next;
    head->next = NULL;
    return _reverseList_recersive(head, next);
}
















