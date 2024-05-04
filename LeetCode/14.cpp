//
// Created by zuo-c on 2024/3/25.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        char symbol;
        for (int j = 0; j < strs[0].size(); j++) {
            symbol = strs[0].at(j);
            for (int i = 0; i < strs.size(); i++) {
                if(strs[i].size() <= j || strs[i].at(j) != symbol){
                    return result;
                }
            }
            result += symbol;
        }
        return result;
    }
};

int main(){
    vector<string> strs = {"ab","a"};
    string result = Solution::longestCommonPrefix(strs);
    cout << result << endl;
}