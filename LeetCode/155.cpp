//
// Created by zuo-c on 2024/3/26.
//
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> data;
    stack<int> min_data;

    MinStack() {
        data.push(INT_MAX);
    }

    void push(int val) {
        data.push(val);
        min_data.push(min(val, min_data.top()));
    }

    void pop() {
        data.pop();
        min_data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min_data.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
//    MinStack* obj = new MinStack();
//    obj->push(val);
//    obj->pop();
//    int param_3 = obj->top();
//    int param_4 = obj->getMin();
}