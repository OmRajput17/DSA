#include<bits/stdc++.h>

class Solution {
private:
    int Helper(int mid, vector<int> &nums){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += ceil((double)nums[i]/(double)mid);
        }
        return ans;
    }

public:
  int smallestDivisor(vector<int> &nums, int limit) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            int sum = Helper(mid, nums);
            if(sum <= limit){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

// Time Complexity:O(n log m), where n is the size of the input array nums and m is the maximum element in nums.
// Space Complexity:O(1), as the algorithm uses a constant amount of extra space.