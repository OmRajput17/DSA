#include<bits/stdc++.h>

class Solution {
private:
    int findFloor(vector<int> nums, int x){
        int low = 0, high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<=x){
                ans = nums[mid];
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }

    int findCeil(vector<int> nums, int x){
        int low = 0, high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=x){
                ans = nums[mid];
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor, ceil;
        floor = findFloor(nums, x);
        ceil = findCeil(nums, x);
        return {floor, ceil};
    }
};

// Time Complexity:The time complexity is O(log n) because both `findFloor` and `findCeil` use binary search, each taking O(log n) time.
// Space Complexity:The space complexity is O(1) because the algorithm uses a constant amount of extra space.
