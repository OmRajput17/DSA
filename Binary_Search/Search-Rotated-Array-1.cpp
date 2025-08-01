#include<bits/stdc++.h>
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
// Time Complexity:O(log n) because the search space is halved in each iteration.
// Space Complexity:O(1) as it uses a constant amount of extra space.