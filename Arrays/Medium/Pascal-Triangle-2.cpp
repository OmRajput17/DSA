class Solution {
public:
    vector<int> pascalTriangleII(int r) {
        vector<int> ans(r);
        ans[0] = 1;
        for(int i = 1; i < r; i++){
            ans[i] = (ans[i-1]*(r-i))/i;
        }
        return ans;
    }
};