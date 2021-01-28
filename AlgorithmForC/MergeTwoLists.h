//
//  MergeTwoLists.h
//  AlgorithmForC
//
//  Created by gjh on 2021/1/28.
//

#ifndef MergeTwoLists_h
#define MergeTwoLists_h

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

#endif /* MergeTwoLists_h */
