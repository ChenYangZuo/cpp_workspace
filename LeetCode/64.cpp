//
// Created by zzzcy on 2024/4/20.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),0));


        return dp[grid.size()-1][grid[0].size()-1];
    }
};

