#include <bits/stdc++.h>

class Solution {
private:
    int func(int ind, vector<int>& nums, int k, int n) {
        if (k == 0) {
            return 1;
        }
        if (k < 0 || ind == n) {
            return 0;
        }
        int path1 = func(ind + 1, nums, k - nums[ind], n);
        int path2 = func(ind + 1, nums, k, n);
        return path1 + path2;
    }

public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        int n = nums.size();
        return func(0, nums, k, n);
    }
};

"Time Complexity:O(2^n) due to the recursive calls exploring all possible subsequences.
Space Complexity:O(n) due to the maximum depth of the recursion stack."