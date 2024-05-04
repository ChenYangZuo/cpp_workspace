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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    }
};

int main() {
    
}