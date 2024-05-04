//
// Created by zuo-c on 2024/4/8.
//
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, bool>> rows(9);
        vector<unordered_map<int, bool>> column(9);
        vector<unordered_map<int, bool>> grid(9);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                int temp = 0;
                if (board[i][j] != '.') {
                    temp = board[i][j] - '0';
                }
                else {
                    continue;
                }

                if(rows[i].count(temp)){
                    return false;
                }
                else{
                    rows[i].insert(make_pair(temp, true));
                }

                if(column[j].count(temp)){
                    return false;
                }
                else{
                    column[j].insert(make_pair(temp, true));
                }

                int grid_index = j/3 + 3*(i/3);
                if(grid[grid_index].count(temp)){
                    return false;
                }
                else{
                    grid[grid_index].insert(make_pair(temp, true));
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> sudoku = {{'.','8','7','6','5','4','3','2','1'},
                                   {'2','.','.','.','.','.','.','.','.'},
                                   {'3','.','.','.','.','.','.','.','.'},
                                   {'4','.','.','.','.','.','.','.','.'},
                                   {'5','.','.','.','.','.','.','.','.'},
                                   {'6','.','.','.','.','.','.','.','.'},
                                   {'7','.','.','.','.','.','.','.','.'},
                                   {'8','.','.','.','.','.','.','.','.'},
                                   {'9','.','.','.','.','.','.','.','.'}};
    cout << Solution::isValidSudoku(sudoku) << endl;
    return 0;
}