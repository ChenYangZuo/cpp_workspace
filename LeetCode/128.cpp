//
// Created by zuo-c on 24-5-3.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto num : nums){

        }
    }
};

int main(){
    Solution s = Solution();
//    vector<int> input = {100,4,200,1,3,2};
    vector<int> input = {0,3,7,2,5,8,4,6,0,1};
    int result = s.longestConsecutive(input);
    cout << result << endl;
    return 0;
}