//
// Created by zuo-c on 2024/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    static int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;
        for(const auto& item : tokens){
            if (item == "+"){
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int result = a+b;
                num_stack.push(result);
            }
            else if(item == "-"){
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int result = b-a;
                num_stack.push(result);
            }
            else if(item == "*"){
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int result = a*b;
                num_stack.push(result);
            }
            else if(item == "/"){
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int result = b/a;
                num_stack.push(result);
            }
            else{
                num_stack.push(stoi(item));
            }
        }
        return num_stack.top();
    }
};

int main(){
    vector<string> token = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = Solution::evalRPN(token);
    cout << result << endl;
}