//
// Created by zuo-c on 2024/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& numbers, int target) {
        int pSmall = 0;
        int pBig = numbers.size() - 1;

        int small = numbers[pSmall];
        int big = numbers[pBig];
        while(small+big != target){
            if(small+big > target){
                pBig--;
            }
            else{
                pSmall++;
            }
            small = numbers[pSmall];
            big = numbers[pBig];
        }
        vector<int> result = {pSmall+1, pBig+1};
        return result;
    }
};

int main(){
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> result = Solution::twoSum(numbers, target);

    for(auto item : result){
        cout << item << endl;
    }
}