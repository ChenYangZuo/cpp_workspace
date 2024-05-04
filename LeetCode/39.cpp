//
// Created by zuo-c on 2024/4/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);

            backtracking(candidates, target, sum, i);

            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

        backtracking(candidates, target, 0, 0);
        return this->result;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {2, 3, 5};
    vector<vector<int>> result = s.combinationSum(input, 8);
    for (const auto &re: result) {
        for (auto r: re) {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}