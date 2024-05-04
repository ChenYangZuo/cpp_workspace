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
    static bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        int length = s.size();
        for (int i = 0; i < length; i++) {
            char a = s[i];
            char b = t[i];
            if (map.count(a) && map[a] != b) {
                cout << "a: " << a << " b: " << b <<endl;
                return false;
            }
            map[a] = b;
        }
        return true;
    }
};

int main(){
    if(Solution::isIsomorphic("badc", "baba")){
        cout << "True" << endl;
    }
}