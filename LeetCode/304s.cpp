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
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string vec2str(vector<string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            }
            else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++]));
            }
            else {
                // 获取到右括号
                ++ptr;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t, o = vec2str(sub);
                // 构造字符串
                while (repTime--) t += o;
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return vec2str(stk);
    }
};

int main() {
    Solution s = Solution();
    vector<string> inputs = {"3[a]2[bc]", "3[a2[c]]", "2[abc]3[cd]ef"};
    for (const auto &input: inputs) {
        cout << s.decodeString(input) << endl;
    }
}