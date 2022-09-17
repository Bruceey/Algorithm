//
// Created by 17634 on 2022/9/14.
//

#ifndef ALGORITHM_21_MERGETWOLISTS_H
#define ALGORITHM_21_MERGETWOLISTS_H

#include <algorithm>
#include "../ListNode.h"
using namespace std;



class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode header;
        ListNode* pNode = &header;
        while (list1 && list2) {
            if (list1->val > list2->val) swap(list1, list2);
            pNode->next = list1;
            pNode = pNode->next;
            list1 = list1->next;
        }
        pNode->next = list1 ? list1 : list2;
        return header.next;
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode* header = new ListNode;
        ListNode* pNode = header;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                pNode->next = list1;
                pNode->next->next = list2;
            } else {
                pNode->next = list2;
                pNode->next->next = list1;
            }
            pNode = pNode->next->next;
            list1 = list1->next;
            list2 = list2->next;
        } //此时list1和list2两者至少有一个为空
        while (list1) {
            pNode->next = list1;
            pNode = pNode->next;
            list1 = list1->next;
        }
        while (list2) {
            pNode->next = list2;
            pNode = pNode->next;
            list2 = list2->next;
        }
        pNode = header->next;
        delete header;
        return pNode;
    }
};

#endif //ALGORITHM_21_MERGETWOLISTS_H
