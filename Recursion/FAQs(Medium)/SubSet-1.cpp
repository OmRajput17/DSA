#include<bits/stdc++.h>

// Subsets I
// Given an array nums of n integers. Return array of sum of all subsets of the array nums.
// Output can be returned in any order.

class Solution {
private:
    void func(int ind, vector<int> &lst, vector<int> &ans,vector<int> &nums, int n) {
        if (ind == n) {
          int sum = 0;
          for(auto it:lst){
            sum += it;
          }
          ans.push_back(sum);
          return;
        }
        lst.push_back(nums[ind]);
        func(ind + 1, lst, ans, nums, n);
        lst.pop_back();
        func(ind + 1, lst, ans, nums, n);
    }

public:
    vector<int> subsetSums(vector<int> &nums) {
      vector<int> ans;
      vector<int> lst;
      int n = nums.size();
      func(0, lst, ans, nums, n);
      return ans;
    }
};

"Time Complexity:O(2^n) due to the recursive calls exploring all possible subsets, and O(n) to calculate the sum of each subset.
Space Complexity:O(n) due to the depth of the recursion stack and the space used by the 'lst' vector."