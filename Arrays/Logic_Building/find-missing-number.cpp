class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nums_sum = 0, range_sum=0;
        int n = nums.size();

        nums_sum = accumulate(nums.begin(), nums.end(),0);
        range_sum = (n*(n+1))/2;
        int res = range_sum - nums_sum;

        return res;
    }
};

// Time Complexity:O(n) due to the accumulate function iterating through the nums vector, where n is the size of the input vector.
// Space Complexity:O(1) as the algorithm uses a constant amount of extra space, regardless of the input size.