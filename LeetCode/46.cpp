//
// Created by zuo-c on 2024/4/13.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    int size = 0;

public:
    void backtracking(vector<int> nums) {
        if (path.size() == this->size) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            path.push_back(nums[i]);
            vector<int> new_nums = nums;
            new_nums.erase(new_nums.begin() + i);
            backtracking(new_nums);
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        this->size = nums.size();
        backtracking(nums);
        return result;
    }
};


int main() {
    Solution s = Solution();
    vector<int> input = {1, 2, 3};
    vector<vector<int>> result = s.permute(input);
    for (const auto &re: result) {
        for (auto r: re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}