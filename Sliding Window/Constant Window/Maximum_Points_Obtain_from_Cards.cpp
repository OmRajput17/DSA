#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum = 0, n = nums.size(), rsum = 0, maxSum = 0;
        for(int i = 0; i<k; i++){
            lsum += nums[i];
        }

        maxSum = lsum;

        int rightIndex = n-1;

        for(int i = k-1; i>=0; i--){
            lsum = lsum - nums[i];
            rsum = rsum + nums[rightIndex];
            rightIndex--; 

            maxSum = max(maxSum, lsum+rsum);
        }

        return maxSum;
    }
};

"Time Complexity:O(k), due to the two loops that iterate up to k times.
Space Complexity:O(1), because the algorithm uses a fixed amount of extra space."