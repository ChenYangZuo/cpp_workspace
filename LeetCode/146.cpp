//
// Created by zzzcy on 2024/4/20.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;

    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}

    Node(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};



class LRUCache {
private:
    int capacity = 0;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> map;

    void removeNode() {
        this->tail->prev->prev->next = this->tail;
        Node* temp = this->tail->prev->prev;
        map.erase(this->tail->prev->key);
//        delete this->tail->prev;
        this->tail->prev = temp;
    }

    void addNode(Node *node) {
        node->prev = this->head;
        node->next = this->head->next;
        this->head->next->prev = node;
        this->head->next = node;
    }

    void refreshNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = this->head->next;
        node->prev = this->head;
        this->head->next->prev = node;
        this->head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node();
        this->tail = new Node();
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
    }

    int get(int key) {
        //如果关键字key存在于缓存中，则返回关键字的值，否则返回-1
        if (this->map.count(key)) {
            Node *cur_node = map[key];
            refreshNode(cur_node);
            return cur_node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        //如果关键字 key 已经存在，则变更其数据值 value
        //如果不存在，则向缓存中插入该组 key-value
        //如果插入操作导致关键字数量超过 capacity，则应该逐出最久未使用的关键字
        if (this->map.count(key)) {
            Node *cur_node = map[key];
            cur_node->value = value;
            refreshNode(cur_node);
        } else {
            Node *new_node = new Node(key, value);
            addNode(new_node);
            map.insert(make_pair(key, new_node));
            if (map.size() > this->capacity) {
                removeNode();
            }
        }
    }

    //函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache obj = LRUCache(1);

    obj.put(2,1);
    cout << obj.get(2);

    return 0;
}