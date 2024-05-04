//
// Created by zuo-c on 2024/4/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;

    bool isValid(int row, int col, const vector<string> &chessboard, int n) {
        // row: 行 col: 列
        // 1. 不能同行
        // 2. 不能同列
        // 3. 不能同斜线（45度和135度）
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void backtracking(int n, int row, vector<string> &chessboard) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)) {
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n,'.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<string>> result = s.solveNQueens(4);
    for (const auto &re: result) {
        for (const auto &r: re) {
            cout << r << endl;
        }
        cout << endl;
    }
    return 0;
}