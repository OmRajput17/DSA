// Optimal Soluton 1

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;

        for(int i=0; i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[k]);
                k++;
            }
        }
        
    }
};

// Optimal Soluton 2
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                j=i;
                break;
            }
        }

        if(j == -1) return;

        for(int i = j+1; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

// Time Complexity:O(n), where n is the size of the input vector nums, due to the two linear scans.
// Space Complexity:O(1), as the algorithm uses a constant amount of extra space.


// Brute Force
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }

        int nz = temp.size();

        for(int i = 0; i<nz; i++){
            nums[i] = temp[i];
        }
        for(int i = nz; i<n; i++){
            nums[i] = 0;
        }
        
    }
};

// Time Complexity:O(n) due to iterating through the input array 'nums' multiple times, where n is the size of 'nums'.
// Space Complexity:O(n) because a temporary vector 'temp' is created which in the worst case (no zeros in nums) can store all the elements of the input vector 'nums'.