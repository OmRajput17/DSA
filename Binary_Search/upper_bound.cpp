#include<bits/stdc++.h>

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

// Time Complexity:The time complexity is O(log n) due to the binary search algorithm.
// Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space.