#include <bits/stdc++.h>

class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int target)  {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }

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
        return false;
    }
};

"Time Complexity:The worst-case time complexity is O(n) because, in cases with many duplicate elements, the low and high pointers may only move by one position in each iteration, effectively degenerating to a linear search. The best and average case time complexity is O(log n), similar to binary search, when the array does not contain many duplicates.
Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space, regardless of the input size.
"
