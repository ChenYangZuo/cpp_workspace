//
// Created by zzzcy on 2024/3/23.
//
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]] = i;
        }
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            int f = target - nums[i];
            auto it = map.find(f);
            if(it != map.end()){
                return {i, it->second};
            }
        }
        return result;
    }
};

int main(){
    vector<int> vec = {3,2,4};
    vector<int> result = Solution::twoSum(vec, 6);
    for(int re : result){
        cout << re << endl;
    }

}