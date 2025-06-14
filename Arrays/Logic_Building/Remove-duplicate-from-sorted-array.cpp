class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i<nums.size(); i++){
            if(nums[index]!= nums[i]){
                nums[index+1] = nums[i];
                index++;
            }
        }
        return index+1;
    }
};

// Time Complexity:O(n) because the code iterates through the input vector once.
// Space Complexity:O(1) because the code uses a constant amount of extra space.