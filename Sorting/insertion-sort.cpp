class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
        int temp;
        for(int i = 0; i<n; i++){
            int j = i;
            while(j>0 && (nums[j-1]>nums[j])){
                swap(nums[j-1], nums[j]);
                j--;
            }
        }
        return nums;
    }
};

// TC = O(N^2)
// SC = OO(1)