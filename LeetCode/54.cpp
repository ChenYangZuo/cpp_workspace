//
// Created by zuo-c on 2024/4/8.
//
#include <iostream>
#include <vector>

using namespace std;

enum mode {
    RIGHT=0,
    DOWN,
    LEFT,
    UP
};

class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        int cnt = matrix[0].size() * matrix.size();
        int i = -1; // 横向
        int j = 0; // 纵向
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        int mode = RIGHT;
        while (cnt > 0) {
            if(mode == RIGHT){
                i++;
                result.push_back(matrix[j][i]);
                if(i==right){
                    mode = DOWN;
                    top++;
                }
            }
            else if(mode == DOWN){
                j++;
                result.push_back(matrix[j][i]);
                if(j==bottom){
                    mode = LEFT;
                    right--;
                }
            }
            else if(mode == LEFT){
                i--;
                result.push_back(matrix[j][i]);
                if(i==left){
                    mode = UP;
                    bottom--;
                }
            }
            else if(mode == UP){
                j--;
                result.push_back(matrix[j][i]);
                if(j==top){
                    mode = RIGHT;
                    left++;
                }
            }
            cnt--;
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2,  3,  4},
                                  {5, 6,  7,  8},
                                  {9, 10, 11, 12}};

    vector<int> result = Solution::spiralOrder(matrix);
    for (auto i: result) {
        cout << i << ",";
    }
    cout << endl;

}