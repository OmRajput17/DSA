class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long maxi = LLONG_MIN;
        long sum = 0;

        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};

// Time Complexity:The time complexity is O(n) because the code iterates through the input array `nums` once.
// Space Complexity:The space complexity is O(1) because the code uses a constant amount of extra space, regardless of the input size.