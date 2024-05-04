//
// Created by zuo-c on 2024/4/8.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    static int romanToInt_1(string s) {
        unordered_map<string, int> map;
        map["I"] = 1;
        map["V"] = 5;
        map["X"] = 10;
        map["L"] = 50;
        map["C"] = 100;
        map["D"] = 500;
        map["M"] = 1000;
        map["IV"] = 4;
        map["IX"] = 9;
        map["XL"] = 40;
        map["XC"] = 90;
        map["CD"] = 400;
        map["CM"] = 900;

        int result = 0;
        for(int i=0; i<s.size(); i++){
            if(map.count(s.substr(i,2))){
                result += map[s.substr(i,2)];
                i++;
            }
            else{
                result += map[s.substr(i,1)];
            }
        }
        return result;
    }

    static int romanToInt(string s) {
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int result = 0;
        for(int i=0; i<s.size(); i++){
            if(i < s.size()-1 && map[s[i]] < map[s[i+1]]){
                result -= map[s[i]];
            }
            else{
                result += map[s[i]];
            }
        }
        return result;
    }
};


int main(){
    int result = Solution::romanToInt("LVIII");
    cout << result << endl;
    return 0;
}