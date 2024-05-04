//
// Created by zuo-c on 2024/3/28.
//
#include <iostream>

using namespace std;


class Solution {
public:
    static int mySqrt(int x) {
        int left = 0;
        int right = x;
        long long result;
        while(left <= right){
            result = left + (right-left)/2;
            if(result*result > x){
                right = result-1;
            }
            else if(result*result < x){
                left = result+1;
            }
            else{
                return result;
            }
        }
        return result;
    }
};

int main(){
    cout << Solution::mySqrt(1) << endl;
}