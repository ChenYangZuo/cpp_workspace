//
// Created by zuo-c on 24-5-3.
//

#ifndef WORKSPACE_LISTNODEHELPER_H
#define WORKSPACE_LISTNODEHELPER_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ListNode.h"

using namespace std;

class ListNodeHelper{
public:
    static ListNode *createLinkedList(const std::vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }

        auto *head = new ListNode(nums[0]);
        ListNode *current = head;
        for (size_t i = 1; i < nums.size(); ++i) {
            current->next = new ListNode(nums[i]);
            current = current->next;
        }
        return head;
    }

    static void printLinkedList(ListNode* head){
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    static void releaseLinkedList(ListNode* head) {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    static ListNode *reverseList(ListNode *head) {
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

    static bool hasCycle(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        ListNode* pSlow = head;
        ListNode* pFast = head->next;
        while(pSlow != pFast){
            if(pFast == nullptr || pFast->next == nullptr){
                return false;
            }
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        return true;
    }

    static ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* pSlow = head;
        ListNode* pFast = head;
        while (pFast != nullptr) {
            pSlow = pSlow->next;
            if(pFast->next == nullptr){
                break;
            }
            pFast = pFast->next->next;
            // 此时pSlow与pFast在环中相遇
            if (pSlow == pFast) {
                pFast = head;
                while (pSlow != pFast) {
                    pSlow = pSlow->next;
                    pFast = pFast->next;
                }
                return pSlow;
            }
        }
        return nullptr;
    }

};

#endif //WORKSPACE_LISTNODEHELPER_H
