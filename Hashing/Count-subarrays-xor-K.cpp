#include<bits/stdc++.h>
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int xr = 0;
        map<int, int> mpp;
        mpp[xr]++; // 0, 1
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            xr = xr ^ nums[i];
            // K
            int x = xr ^ k;
            cnt += mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};

"""
Time Complexity:The time complexity is O(n) because the code iterates through the input vector nums once.
Space Complexity:The space complexity is O(n) due to the potential storage of up to n elements in the map mpp in the worst-case scenario.
"""