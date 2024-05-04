//
// Created by zuo-c on 24-5-4.
//
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}