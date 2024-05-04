//
// Created by zuo-c on 2024/3/27.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyNode = new ListNode(-1, head);
        ListNode *pSlow = dummyNode;
        ListNode *pFast = head;

        for (int i = 0; i < n; i++) {
            pFast = pFast->next;
        }
        while (pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        pSlow->next = pSlow->next->next;

        return dummyNode->next;
    }
};