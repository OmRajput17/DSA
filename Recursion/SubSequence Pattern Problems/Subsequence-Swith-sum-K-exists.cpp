#include <bits/stdc++.h>

class Solution{
private:
    bool func(int ind, vector<int>& nums, int sum, int n){
        if(sum == 0){
            return true;
        }
        if(sum < 0 || ind == n){
            return false;
        }
        bool path1 = func(ind+1, nums, sum - nums[ind], n);
        bool path2 = func(ind+1, nums, sum, n);
        return path1 || path2;
    }
public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        int n = nums.size();
        return func(0, nums, k, n);
    }
};

"Time Complexity:O(2^n) due to the exponential nature of the recursive calls exploring all possible subsequences.
Space Complexity:O(n) due to the maximum depth of the recursive call stack, where n is the size of the input vector."