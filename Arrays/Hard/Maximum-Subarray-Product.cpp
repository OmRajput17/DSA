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

// Time Complexity:The time complexity is O(n) because the code iterates through the input vector `nums` once.
// Space Complexity:The space complexity is O(1) because the code uses a constant amount of extra space, regardless of the input size.