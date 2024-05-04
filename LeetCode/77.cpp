//
// Created by zuo-c on 2024/4/12.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int index) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = index; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    // 返回范围[1, n]中所有可能的k个数的组合。
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return this->result;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> result = s.combine(4, 2);
    for (const auto &re: result) {
        for (auto r: re) {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}