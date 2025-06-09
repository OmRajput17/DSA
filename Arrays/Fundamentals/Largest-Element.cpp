class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i<nums.size(); i++){
            if(nums[i]>maxi){
                maxi = nums[i];
            }
        }
        return maxi;
    }
};