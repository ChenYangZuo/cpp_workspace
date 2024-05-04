//
// Created by zuo-c on 24-5-4.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int pSlow = 0; //写指针
        int pFast = 0; //读指针
        while (pFast < nums.size()) {
            if (nums[pFast] == 0) {
                pFast++;
            }
            else {
                nums[pSlow] = nums[pFast];
                pFast++;
                pSlow++;
            }
        }
        while (pSlow < nums.size()) {
            nums[pSlow++] = 0;
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}