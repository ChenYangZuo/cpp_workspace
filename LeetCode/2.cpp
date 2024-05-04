//
// Created by zuo-c on 2024/3/26.
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

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* head = dummyNode;
        int add = 0;
        while (l1 || l2) {
            int value_l1 = l1 ? l1->val : 0;
            int value_l2 = l2 ? l2->val : 0;
            int result = 0;
            if (value_l1 + value_l2 + add >= 10) {
                result = value_l1 + value_l2 + add - 10;
                add = 1;
            } else {
                result = value_l1 + value_l2 + add;
                add = 0;
            }
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            head->next = new ListNode(result);
            head = head->next;
        }
        if (add > 0){
            head->next = new ListNode(add);
            head = head->next;
        }
        return dummyNode->next;
    }
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

int main(){
    ListNode* l1 = vectorToLinkedList({9,9,9,9,9,9,9});
    ListNode* l2 = vectorToLinkedList({9,9,9,9});

    ListNode* result = Solution::addTwoNumbers(l1, l2);
    printLinkedList(result);
}
