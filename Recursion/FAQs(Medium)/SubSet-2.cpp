#include<bits/stdc++.h>

class Solution {
private:
    void func(int ind, vector<int> &lst, vector<vector<int>>& ans, vector<int> &nums){
        if(ind == nums.size()){
            ans.push_back(lst);
            return;
        }
        lst.push_back(nums[ind]);
        func(ind+1, lst, ans, nums);
        lst.pop_back();
        for(int i = ind + 1; i < nums.size(); i++) {
            if(nums[i] != nums[ind]) {
                func(i, lst, ans, nums); 
                return; 
            }
        }
        func(nums.size(), lst, ans, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> lst;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        func(0, lst, ans, nums);
        return ans;
    }
};

"Time Complexity:O(n*2^n) due to generating all possible subsets and sorting.
Space Complexity:O(n) due to the depth of the recursion stack."