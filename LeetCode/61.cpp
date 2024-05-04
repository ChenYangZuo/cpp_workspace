//
// Created by zuo-c on 2024/3/27.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* vectorToLinkedList(const std::vector<int>& nums) {
    ListNode *dummy = new ListNode(); // 创建虚拟头节点
    ListNode *current = dummy;

    for (int num : nums) {
        current->next = new ListNode(num); // 创建新节点并链接到当前节点后面
        current = current->next; // 移动当前节点指针到下一个节点
    }

    return dummy->next; // 返回链表的头节点
}

void printLinkedList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* cur = head;
        int length = 1;
        while (cur->next) {
            cur = cur->next;
            length++;
        }

        int move = k % length;
        ListNode *pSlow = head;
        ListNode *pFast = head;
        for (int i = 0; i < move; i++) {
            pFast = pFast->next;
        }
        while (pFast->next) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        dummyNode->next = pSlow->next;
        pSlow->next = nullptr;
        pFast->next = head;

        return dummyNode->next;

    }
};

int main() {
    vector<int> list = {1,2,3,4,5};
    ListNode* head = vectorToLinkedList(list);
    int k = 2;
    ListNode* result = Solution::rotateRight(head, k);
    printLinkedList(result);
}