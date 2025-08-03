#include <bits/stdc++.h>

// Optimal
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1, high = n-2;

        while(low<=high){
            int mid = (low + high)/2;
            if(nums[mid] != nums[mid + 1] &&
            nums[mid] != nums[mid - 1]){
                return nums[mid];
            }

            if(nums[mid] == nums[mid-1] && (mid % 2 == 1) ||
            nums[mid] == nums[mid+1] && (mid % 2 == 0)){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

// Time Complexity:The time complexity is O(log n) due to the binary search algorithm.
// Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space.



// Better
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int xr = 0;
        for(int i = 0; i<nums.size(); i++){
            xr ^= nums[i];
        }
        return xr;
    }
};

// Time Complexity:O(n) due to the single for loop iterating through the input vector nums.
// Space Complexity:O(1) as only a single integer variable 'xr' is used, regardless of the input size.
