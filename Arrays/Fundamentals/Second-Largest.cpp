class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
       int maxi = INT_MIN;
       int sec_max = INT_MIN;
       for(int i = 0; i<nums.size(); i++){
            if(nums[i]>maxi){
                sec_max = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > sec_max && nums[i] != maxi){
                sec_max = nums[i];
            }
        }
        return sec_max == INT_MIN ? -1 : sec_max;
    }
};