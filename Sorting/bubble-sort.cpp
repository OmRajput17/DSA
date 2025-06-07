class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size(), temp;
        int did_swap = 0;
        for(int i = n-1;i >= 1; i--){
            for(int j = 0; j <= i-1; j++){
                if(nums[j] > nums[j+1]){
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;

                    did_swap = 1;
                }
            }
        }

        if (did_swap == 0){
            break;
        }
        return nums;
    }
};

// TC = O(n^2)
// SC = O(1) 