#include<bits/stdc++.h>

class Solution {
private:
    bool func(int ind, int i, int j, vector<vector<char> >& board, string& word){
        if(ind == word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[ind]){
            return false;
        }
        char x = board[i][j];
        board[i][j] = ' ';

        bool ans = func(ind+1, i-1, j, board, word) ||  // up
                   func(ind+1, i+1, j, board, word) ||  // down
                   func(ind+1, i, j-1, board, word) ||  // left
                   func(ind+1, i, j+1, board, word);    // right

        board[i][j] = x;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(word[0]==board[i][j]){
                    if(func(0, i, j, board, word)==true){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

"Time Complexity:O(n * m * 4^k) where n is the number of rows, m is the number of columns in the board, and k is the length of the word.
Space Complexity:O(k) due to the recursive call stack, where k is the length of the word."