//
//  MiddleNode.h
//  AlgorithmForC
//
//  Created by gjh on 2021/1/28.
//

#ifndef MiddleNode_h
#define MiddleNode_h

#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* middleNode(struct ListNode* head);
#endif /* MiddleNode_h */
