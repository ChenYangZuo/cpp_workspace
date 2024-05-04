//
// Created by zuo-c on 24-5-3.
//

#ifndef WORKSPACE_LISTNODE_H
#define WORKSPACE_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //WORKSPACE_LISTNODE_H
