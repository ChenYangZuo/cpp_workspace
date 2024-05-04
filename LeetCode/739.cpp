//
// Created by zuo-c on 24-5-3.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> stk; // stk中保存下标
        vector<int> result(temperatures.size(), 0);
        stk.push(0);

        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[stk.top()]) {
                stk.push(i);
            }
            else{
                while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                    result[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return result;
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s = Solution();
    vector<int> output = s.dailyTemperatures(input);
    for (int i: output) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}