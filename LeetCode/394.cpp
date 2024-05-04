//
// Created by zuo-c on 24-5-2.
//
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            // 是字母
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            }
            else {
                int cnt = 0;
                //是数字
                while (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + s[i] - '0';
                    i++;
                }
                int pos = i + 1;
                int lcnt = 1;
                while (lcnt) {
                    i++;
                    if (s[i] == '[') lcnt++;
                    else if (s[i] == ']') lcnt--;
                }
                string tmp = decodeString(s.substr(pos, i - pos));
                while (cnt--) {
                    ans.append(tmp);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s = Solution();
    string result = s.decodeString("3[a2[c]]");
    cout << result << endl;
}