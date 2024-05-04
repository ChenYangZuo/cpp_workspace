//
// Created by zuo-c on 2024/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxArea(vector<int>& height) {
        int pLeft = 0;
        int pRight = height.size() - 1;
        int max_capacity = 0;
        int current_capacity = 0;
        while(pLeft != pRight){
            current_capacity = (pRight-pLeft) * min(height[pLeft], height[pRight]);
            if(current_capacity > max_capacity){
                max_capacity = current_capacity;
            }
            if(height[pLeft] < height[pRight]){
                pLeft++;
            }
            else{
                pRight--;
            }
        }
        return max_capacity;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = Solution::maxArea(height);
    cout << result << endl;
}