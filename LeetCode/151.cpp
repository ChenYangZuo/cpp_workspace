//
// Created by zuo-c on 24-5-3.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(const string& s) {
        stringstream ss(s);
        string token;
        string result;
        stack<string> stk;
        while (getline(ss >> std::ws, token, ' ')) {
            stk.push(token);
        }
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
            if(!stk.empty()){
                result += " ";
            }
        }
        return result;
    }
};

int main(){
    Solution s = Solution();
    cout << s.reverseWords("a good   example") << endl;
}