//
// Created by 17634 on 2022/9/13.
//

#ifndef ALGORITHM_2_ADDTWONUMBERS_H
#define ALGORITHM_2_ADDTWONUMBERS_H

// 2. 两数相加
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.



struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
    ListNode* header = nullptr;
    ListNode* pNode = nullptr;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum_ = n1 + n2 + carry;
        if (!header) {
            header = pNode = new ListNode(sum_ % 10);
        } else {
            pNode->next = new ListNode(sum_ % 10);
            pNode = pNode->next;
        }
        carry = sum_ / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry > 0) pNode->next = new ListNode(carry);
    return header;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) { //题目给定为非空
    ListNode* pNode = new ListNode(l1->val + l2->val);
    l1 = l1->next;
    l2 = l2->next;
    ListNode* first = pNode;
    while (l1 && l2) {
        if (pNode && pNode->val > 9) {
            pNode->next= new ListNode(l1->val + l2->val + 1);
            pNode->val = pNode->val - 10;
        } else {
            pNode->next = new ListNode(l1->val + l2->val);
        }
        pNode = pNode->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        if (pNode && pNode->val > 9) {
            pNode->next= new ListNode(l1->val + 1);
            pNode->val = pNode->val - 10;
        } else {
            pNode->next = new ListNode(l1->val);
        }
        pNode = pNode->next;
        l1 = l1->next;
    }
    while (l2) {
        if (pNode && pNode->val > 9) {
            pNode->next= new ListNode(l2->val + 1);
            pNode->val = pNode->val - 10;
        } else {
            pNode->next = new ListNode(l2->val);
        }
        pNode = pNode->next;
        l2 = l2->next;
    }
    if (pNode->val > 9) {
        pNode->next = new ListNode(1);
        pNode->val -= 10;
    }
    return first;
}


#endif //ALGORITHM_2_ADDTWONUMBERS_H
