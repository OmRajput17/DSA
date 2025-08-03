#include<bits/stdc++.h>
class Solution{
public:
    int search(vector<int> &nums, int target){
        int low = 0, high = nums.size();

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};

"""
Time Complexity:The time complexity is O(log n) because it's a binary search.
Space Complexity:The space complexity is O(1) because it uses a constant amount of extra space.
"""