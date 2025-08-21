#include<bits/stdc++.h>

class Solution {
private:
    void func(int open, int close, int n, string s, vector<string> &ans){
        if(open == close && (open + close) == 2 *n){
            ans.push_back(s);
            return;
        }
        if(open > n) {
            return;
        }
        func(open+1, close, n, s + '(', ans);

        if(open > close){
            func(open, close+1, n, s + ')', ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(0, 0, n, "", ans);

        return ans;
    }
};

"Time Complexity:O(4^n / sqrt(n)) due to the number of possible valid parentheses combinations (Catalan number).
Space Complexity:O(n) due to the maximum depth of the recursion stack."