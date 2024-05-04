//
// Created by zuo-c on 24-4-22.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); i++) {
            int j;
            int remain = 0;
            for (j = 0; j < gas.size();) {
                int c = (i + j) % gas.size();
                remain += gas[c];
                if (remain < cost[c]) {
                    break;
                } else {
                    remain -= cost[c];
                    j++;
                }
            }
            if (j >= gas.size()) {
                return i;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> input1 = {2,3,4};
    vector<int> input2 = {3,4,3};
    Solution s = Solution();
    cout << s.canCompleteCircuit(input1, input2);
}