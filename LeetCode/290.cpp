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
    vector<string> splitString(const string& str, char delimiter) {
        vector<string> result;
        size_t start = 0;
        size_t end = 0;

        // 遍历字符串
        while (end < str.size()) {
            // 找到分隔符的位置
            while (end < str.size() && str[end] != delimiter) {
                end++;
            }

            // 如果找到了非连续的分隔符，则将[start, end)之间的子串加入结果
            if (end > start) {
                result.push_back(str.substr(start, end - start));
            }

            // 更新start和end指针，准备下一次查找
            start = end + 1;
            end = start;
        }
        return result;
    }

    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        vector<string> words = splitString(s, ' ');
        int pattern_length = pattern.size();

        if(words.size() != pattern_length){
            return false;
        }

        for (int i = 0; i < pattern_length; i++) {
            char a = pattern[i];
            if ((map1.count(a) && map1[a] != words[i]) || (map2.count(words[i]) && map2[words[i]] != a)) {
                return false;
            }
            map1[a] = words[i];
            map2[words[i]] = a;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    bool result = s.wordPattern("abba", "dog cat cat dog");
    cout << result << endl;
}