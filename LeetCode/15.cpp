//
// Created by zuo-c on 2024/4/16.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 返回三数之和为0的索引列表
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int startIndex = 0; startIndex < nums.size() - 1; startIndex++) {
            int left = startIndex + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if(nums[left] + nums[right] + nums[startIndex] == 0){
                    result.push_back({nums[startIndex], nums[left], nums[right]});
                    while(left < right && nums[left]==nums[left+1]){
                        left++;
                    }
                    left++;

                    while(left < right && nums[right]==nums[right-1]){
                        right--;
                    }
                    right--;
                }
                else if(nums[left] + nums[right] + nums[startIndex] > 0){
                    right--;
                }
                else{
                    left++;
                }
            }

        }
        return result;
    }
};

int main() {
    vector<int> input = {-1,0,1,2,-1,-4};

    Solution s = Solution();
    vector<vector<int>> result = s.threeSum(input);
    for (const auto re: result) {
        for (const auto r: re) {
            cout << r << " ";
        }
        cout << endl;
    }
}