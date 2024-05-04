//
// Created by zuo-c on 2024/4/16.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> map;

    Node* cloneGraph(Node* node) {
        if(node== nullptr){
            return nullptr;
        }

        if(map.find(node) != map.end()){
            return map[node];  // 返回克隆结果
        }

        Node* clone_node = new Node(node->val);
        map[node] = clone_node;

        for(auto &n : node->neighbors){
            clone_node->neighbors.push_back(cloneGraph(n));
        }
        return clone_node;
    }
};

int main(){

}