#include <bits/stdc++.h>

class Solution {
private:
    void func(int k, int n, vector<int>& list, vector<vector<int>>& ans){
        if(n==0 && list.size() == k){
            ans.push_back(list);
            return;
        }
        if(n < 0 || list.size() > k){
            return;
        }
        int element = list.empty() ? 1 : list.back() + 1;

        for(int i = element; i <= 9; i++){
            if(i <= n){
                list.push_back(i);
                func(k, n-i, list, ans);
                list.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int>> ans;
        vector<int> list;
        func(k, n, list, ans);
        return ans;
    }
};

"Time Complexity:O(9 choose k), where k is the number of elements and the 9 comes from the loop's upper bound (digits 1-9).
Space Complexity:O(k), where k is the number of elements in a combination; this reflects the depth of the recursion stack and the space used by the 'list' vector."