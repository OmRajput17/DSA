#include<bits/stdc++.h>

class Solution {
private:
    void func(int ind,string digits, string str, string combos[], vector<string>& ans){
        if(ind == digits.size()){
            ans.push_back(str);
            return;
        }
        int digit = digits[ind] - '0';
        for(int i = 0; i < combos[digit].size(); i++){
            func(ind+1, digits, str+combos[digit][i], combos, ans);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string str = "";
        func(0, digits, str, combos, ans);
        return ans;
    }
};

"Time Complexity:O(4^n), where n is the length of the input string 'digits'.
Space Complexity:O(n) due to the recursion depth and the space used by the 'ans' vector, which can store up to 4^n strings, each of length n, but the dominant factor for auxiliary space is the recursion depth."