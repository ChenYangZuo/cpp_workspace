//
// Created by zuo-c on 2024/4/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &board, int row, int col) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != 'O') {
            return;
        }

        board[row][col] = '1';

        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }

    void solve(vector<vector<char>> &board) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            dfs(board, i, 0);
            dfs(board, i, col - 1);
        }
        for (int i = 1; i < col - 1; i++) {
            dfs(board, 0, i);
            dfs(board, row - 1, i);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> input = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    Solution s = Solution();
    s.solve(input);
    for (const auto &re: input) {
        for (const auto &r: re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}