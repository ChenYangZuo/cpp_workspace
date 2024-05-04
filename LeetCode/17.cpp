//
// Created by zuo-c on 2024/4/12.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, string> phoneMap{
            {0, ""},
            {1, ""},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
    };
    string path;
    vector<string> result;
public:
    void backtracking(const string &digits, int index) {
        // 1.终止条件
        if (index == digits.size()) {
            this->result.push_back(this->path);
            return;
        }
        // 2.遍历
        int digit = digits[index] - '0';
        string letters = this->phoneMap[digit];
        for (char letter : letters){
            this->path.push_back(letter);
            backtracking(digits, index+1);
            this->path.pop_back();
        }

    }

    vector<string> letterCombinations(const string &digits) {
        if(digits.empty()){
            return result;
        }

        backtracking(digits, 0);
        return result;
    }
};

int main() {
    Solution s = Solution();
    vector<string> result = s.letterCombinations("23");
    for (const auto& i: result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}