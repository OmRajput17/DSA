#include<bits/stdc++.h>

class Solution {
private:
    bool checkPalindrome(string s, int low, int high){
        while(low<=high){
            if(s[low] != s[high]){
                return false;
            }
            low++; high--;
        }
        return true;
    }
    void func(int ind, string s, vector<vector<string>>& ans, vector<string>& list){
        if(ind == s.size()){
            ans.push_back(list);
            return;
        }

        for(int j = ind; j < s.size(); j++){
            if(checkPalindrome(s, ind, j)){
                string str = s.substr(ind, (j - ind + 1));
                list.push_back(str);
                func(j+1, s, ans, list);
                list.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> list;
        func(0, s, ans, list);

        return ans;
    }
};

"Time Complexity:O(n * 2^n) due to the recursive calls and palindrome checks.
Space Complexity:O(n) due to the depth of the recursion stack and the list."