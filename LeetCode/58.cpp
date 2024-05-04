//
// Created by zuo-c on 2024/3/22.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static int lengthOfLastWord(string s) {
        int end = (int)s.size();
        int start = end;
        while (start > 0) {
            while (start > 0 && s[start - 1] != ' ') {
                start--;
            }
            if (start != 0) {
                if (start < end) {
                    return (int)s.substr(start, end - start).size();
                }
                end = start - 1;
                start = end;
            }

        }
        if (end > 0) {
            return (int)s.substr(0, end).size();
        }
    }
};

int main(){
    cout << Solution::lengthOfLastWord("a ") << endl;
}