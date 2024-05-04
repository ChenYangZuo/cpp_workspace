//
// Created by zzzcy on 2024/4/20.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<size; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[size-1];
    }
};

int main(){
    Solution s = Solution();
    vector<int> input = {2,7,9,3,1};
    int result = s.rob(input);
    cout << result;
}