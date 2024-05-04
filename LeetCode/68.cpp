//
// Created by zuo-c on 24-5-3.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* 每行恰好有 maxWidth 个字符，且左右两端对齐
 * 尽可能多地往每行中放置单词。必要时可用空格' '填充
 * 某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格
 */

class Solution {
private:
    string join(vector<string> &words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }

    string blank(int n) {
        return string(n, ' ');
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = static_cast<int>(words.size());
        while (true) {
            int start_index = i;
            int current_width = 0;
            while (i < n && current_width + words[i].size() + i - start_index <= maxWidth) {
                current_width += static_cast<int>(words[i++].size());
            }

            int num_words = i - start_index;
            int num_spaces = maxWidth - current_width;
            // 1.如果是最后一行
            if (i == n) {
                //单词之间一个空格，在后边补全空格
                string s = words[start_index];
                for (int j = start_index + 1; j < i; j++) {
                    s += ' ' + words[j];
                }
                s += string(maxWidth-s.size(), ' ');
                result.push_back(s);
                return result;
            }
            // 2.如果仅有一个单词
            if (num_words == 1) {
                //在后边补全空格
                string s = words[start_index];
                s += string(num_spaces, ' ');
                result.push_back(s);
            }
            // 3.普通行
            else {
                int avgSpaces = num_spaces / (num_words - 1);
                int extraSpaces = num_spaces % (num_words - 1);
                string s1 = join(words, start_index, start_index + extraSpaces + 1, blank(avgSpaces + 1)); // 拼接额外加一个空格的单词
                string s2 = join(words, start_index + extraSpaces + 1, i, blank(avgSpaces)); // 拼接其余单词
                result.emplace_back(s1 + blank(avgSpaces) + s2);
            }
        }
    }
};

int main() {
    vector<string> input = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a",
                            "computer.", "Art", "is", "everything", "else", "we", "do"};
    Solution s = Solution();
    vector<string> output = s.fullJustify(input, 20);
    for (const auto &str: output) {
        cout << str << endl;
    }
    return 0;
}