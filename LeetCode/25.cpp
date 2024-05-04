//
// Created by zuo-c on 24-5-2.
//
#include <deque>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        auto *dummyNode = new ListNode(0);
        ListNode *temp = dummyNode;
        deque<ListNode *> stk;
        while (true) {
            for (int i = 0; i < k; i++) {
                if (head != nullptr) {
                    stk.push_back(head);
                    head = head->next;
                }
                else {
                    while (!stk.empty()) {
                        temp->next = stk.front();
                        temp = temp->next;
                        stk.pop_front();
                    }
                    return dummyNode->next;
                }
            }
            while (!stk.empty()) {
                temp->next = stk.back();
                temp = temp->next;
                temp->next = nullptr;
                stk.pop_back();
            }
        }
    }
};

int main() {
    vector<int> input = {1, 2, 3, 4, 5};
    ListNode *head = ListNodeHelper::createLinkedList(input);

    Solution s = Solution();
    ListNode *result = s.reverseKGroup(head, 2);
    ListNodeHelper::printLinkedList(result);
    return 0;
}