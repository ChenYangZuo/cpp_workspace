//
// Created by zuo-c on 24-5-2.
//
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createLinkedList(const std::vector<int> &nums) {
    if (nums.empty()) {
        return nullptr;
    }

    ListNode *head = new ListNode(nums[0]);
    ListNode *current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

void releaseLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

class Solution {
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head;
        ListNode *prev = nullptr;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) {
            return true;
        }

        shared_ptr<ListNode> dummyNode = make_shared<ListNode>(0);
        dummyNode->next = head;
        ListNode *pFast = dummyNode.get();
        ListNode *pSlow = dummyNode.get();
        while (pFast->next != nullptr && pFast->next->next != nullptr) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        ListNode *new_head = reverseList(pSlow->next);
        while (new_head != nullptr) {
            if (new_head->val != head->val) {
                return false;
            }
            new_head = new_head->next;
            head = head->next;
        }
        return true;
    }
};

int main() {
    vector<int> input = {1, 2, 2, 1};
    ListNode *root = createLinkedList(input);

    Solution s = Solution();
    bool result = s.isPalindrome(root);
    cout << result << endl;

    releaseLinkedList(root);
    return 0;
}