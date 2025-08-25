#include<bits/stdc++.h>

class Solution {
private:
    bool placingIsPossible(vector<string>& board, int row, int col, int n){
        // Checking Vertical Side
        int r = row, c = col;
        while(r>=0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
        }
        r = row; c = col;
        // Check Right diagonal
        while(r>=0 && c<n){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c++;
        }
        r = row; c = col;
        // Check Left diagonal
        while(r>=0 &&  c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c--;
        }

        return true;
    }
    void func(int row, vector<string>& board, vector<vector<string>>& ans, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            if(placingIsPossible(board, row, col, n)){
                board[row][col] = 'Q';
                func(row+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string str;
        for(int i = 0; i<n; i++){
            str = str+'.';
        }
        for(int i = 0; i<n; i++){
            board.push_back(str);
        }

        func(0, board, ans, n);

        return ans;
    }
};

"Time Complexity:O(n! * n^2) due to the recursive exploration of possible queen placements and the n^2 time complexity of the placingIsPossible function.
Space Complexity:O(n^2) due to the board and recursion depth."