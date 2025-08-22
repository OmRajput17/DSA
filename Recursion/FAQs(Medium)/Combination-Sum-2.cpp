#include <bits/std++.h>

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
        func(ind+1, list, ans, candidates, sum - candidates[ind]);
        list.pop_back();
        for(int i = ind + 1; i < candidates.size(); i++) {
            if(candidates[i] != candidates[ind]) {
                func(i, list, ans, candidates, sum); 
                break; 
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        func(0, list, ans, candidates, target);
        return ans;
    }
};

