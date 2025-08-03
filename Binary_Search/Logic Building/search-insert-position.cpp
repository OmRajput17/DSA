#include<bits/stdc++.h>

class Solution {
public:
    int searchInsert(vector<int> &nums, int target)  {
        int low = 0, high = nums.size()-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};

// Time Complexity:The time complexity is O(log n) due to the binary search algorithm.
// Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space.