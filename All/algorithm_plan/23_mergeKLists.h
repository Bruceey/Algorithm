//
// Created by 王锐 on 2022/9/17.
//

#ifndef ALGORITHM_23_MERGEKLISTS_H
#define ALGORITHM_23_MERGEKLISTS_H

#include "../ListNode.h"
#include <vector>
#include <queue>
using namespace std;

/*
 23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 示例1：
 输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

 示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
*/

ListNode* mergeTwo(ListNode* list1, ListNode* list2) { //两个列表合并
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

//方法1：暴力
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    ListNode* header = nullptr;
    for (auto & list : lists) {
        header = mergeTwo(header, list);
    }
    return header;
}


//方法2：分而治之
ListNode* merge(vector<ListNode*>& lists, int lo, int hi) {
    if (hi - lo < 2) return lists[lo];
    int mi = (lo + hi) >> 1;
    ListNode* left = merge(lists, lo, mi);
    ListNode* right = merge(lists, mi, hi);
    return mergeTwo(left, right);
}

ListNode* mergeKLists2(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return merge(lists, 0, lists.size());
}

//方法三：优先级队列
struct Status {
    int val;
    ListNode *ptr;
    bool operator < (const Status &rhs) const { //节点的值越小优先级越高
        return val > rhs.val;
    }
};

ListNode* mergeKLists3(vector<ListNode*>& lists) {
    priority_queue <Status> q;
    for (auto node: lists) {
        if (node) q.push({node->val, node});
    }
    ListNode head, *tail = &head;
    while (!q.empty()) {
        auto f = q.top(); q.pop();
        tail->next = f.ptr;
        tail = tail->next;
        if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
    }
    return head.next;
}

#endif //ALGORITHM_23_MERGEKLISTS_H
