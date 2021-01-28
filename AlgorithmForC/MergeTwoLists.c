//
//  MergeTwoLists.c
//  AlgorithmForC
//
//  Created by gjh on 2021/1/28.
//

#include "MergeTwoLists.h"

/// 21.合并两个有序链表  目前觉得最简单的方法:递归法
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->val >= l2->val) {
        l2->next = mergeTwoLists(l1, l2->next);
    } else {
        l1->next = mergeTwoLists(l1->next, l2);
        l2 = l1;
    }
    return l2;
}
