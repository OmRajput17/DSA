#include <bits/stdc++.h>

class Solution {
private:
    void func(int ind, vector<int>& list, vector<vector<int>>& ans,
              vector<int>& candidates, int sum) {
        if (sum == 0) {
            ans.push_back(list);
            return;
        }
        if (sum < 0 || ind == candidates.size()) {
            return;
        }
        list.push_back(candidates[ind]);
        func(ind, list, ans, candidates, sum - candidates[ind]);
        list.pop_back();
        func(ind + 1, list, ans, candidates, sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        func(0, list, ans, candidates, target);
        return ans;
    }
};

"Time Complexity:O(2^n) in the worst case, where n is the number of candidates, due to the recursive calls exploring all possible combinations.
Space Complexity:O(k*x), where k is the average length of combinations, and x is the number of combinations. Additionally, O(n) auxiliary space for the recursion stack."