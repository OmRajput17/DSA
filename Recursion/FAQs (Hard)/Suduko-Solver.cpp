#include <bits/sdtc++.h>

class Solution {
private:
    bool rules(vector<vector<char>>& grid, int row, int col, char digit){
        int startR = (row/3) * 3, startC = (col/3) * 3;
        for(int i = 0; i<9; i++){
            if(grid[row][i] == digit){
                return false;
            }
            if(grid[i][col] == digit){
                return false;
            }
            if(grid[startR + (i/3)][startC + (i%3)] == digit){
                return false;
            }
        }

        return true;
    }
    bool func(vector<vector<char>>& grid){
        int n = 9;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '.'){
                    for(char digit = '1'; digit<='9'; digit++){
                        if(rules(grid, i, j, digit)){
                            grid[i][j] = digit;
                            bool val = func(grid);
                            if(val){
                                return true;
                            }
                            else{
                                grid[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char> >& grid) {
        func(grid);
    }
};

"Time Complexity:O(9^(number of empty cells)), potentially exponential due to backtracking.
Space Complexity:O(1) excluding the input grid, due to the constant amount of extra space used by the recursive calls on the stack which is bounded by the depth of the recursion."