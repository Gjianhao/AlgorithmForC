//
//  MiddleNode.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/28.
//

#include "MiddleNode.h"

/// 876. 链表的中间结点
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast; // 一次两步
    struct ListNode* slow; // 一次一步
    fast = slow = head;
    
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
