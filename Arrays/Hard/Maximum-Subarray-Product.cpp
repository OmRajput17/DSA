class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        int pre = 1, suf = 1;

        for(int i = 0; i<n; i++){
            pre = (pre == 0 ? 1 : pre) * nums[i];
            suf = (suf == 0 ? 1 : suf) * nums[n - i - 1];

            maxi = max(maxi ,max(pre, suf));
        }

        return maxi;    
    }
};