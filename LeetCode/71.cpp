//
// Created by zuo-c on 2024/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    static string simplifyPath(string path) {
        string re;
        vector<string> simp_path;
        string current;
        for(char c : path){
            if(c != '/'){
                current += c;
            }
            else{
                if(current == "."){
                }
                else if(current == ".."){
                    if(!simp_path.empty()){
                        simp_path.pop_back();
                    }
                }
                else{
                    if(!current.empty()){
                        simp_path.push_back(current);
                    }
                }
                current = "";
                continue;
            }
        }
        if(!current.empty()){
            if(current == "."){
            }
            else if(current == ".."){
                if(!simp_path.empty()){
                    simp_path.pop_back();
                }
            }
            else{
                if(!current.empty()){
                    simp_path.push_back(current);
                }
            }
            current = "";
        }
        for (const auto& p : simp_path) {
            re += "/";
            re += p;
        }
        if(re.empty()){
            re = "/";
        }
        return re;
    }
};

int main() {
    string str = "/a//b////c/d//././/..";
    string result = Solution::simplifyPath(str);
    cout << result << endl;
}