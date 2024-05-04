//
// Created by zuo-c on 24-5-4.
//
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string decodeString(const string &s) {
        string token;
        stack<string> stk;
        int i = 0;
        string result = "";
        while (i < s.size()) {
            char c = s[i];
            if (isdigit(c)) {
                token += c;
                i++;
                while (isdigit(s[i])) {
                    token += s[i++];
                }
                stk.push(token);
                token = "";
            }
            else if (isalpha(c) || c == '[') {
                token += c;
                i++;
                stk.push(token);
                token = "";
            }
            else {
                i++;
                string sub;
                while (stk.top() != "[") {
                    sub = stk.top() + sub;
                    stk.pop();
                }
                stk.pop();// 左括号出栈
                int time = stoi(stk.top());
                stk.pop();
                for (int j = 0; j < time; ++j) {
                    token += sub;
                }
                stk.push(token);
                token = "";
            }
        }
        while(!stk.empty()){
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};

int main() {
    Solution s = Solution();
    vector<string> inputs = {"3[a]2[bc]", "3[a2[c]]", "2[abc]3[cd]ef"};
    for (const auto &input: inputs) {
        cout << s.decodeString(input) << endl;
    }
}