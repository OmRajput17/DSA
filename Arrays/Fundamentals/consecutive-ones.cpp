class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, maxi = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
                maxi = max(maxi, count);
            }
            else{
                count = 0;
            }
        }
        return maxi;
    }
};

// TC = O(N)
// SC = O(1)