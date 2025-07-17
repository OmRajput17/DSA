#include<bits/stdc++.h>


// Optimal Solution for Negative and Positives
class solution{
public:
    int longestSubarray(vector<int> nums, int k){
        map<int, int> mpp;
        int sum = 0, Maxlen=0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            if(sum==k){
                Maxlen = max(Maxlen, i+1);
            }

            int rem = sum - k;
            if(mpp.find(rem) != mpp.end()){
                int len = i - mpp[rem];
                Maxlen = max(Maxlen, len);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return Maxlen;
    }
};

"""
Time Complexity:O(n) due to the single for loop iterating through the input vector.
Space Complexity:O(n) in the worst case, due to the map potentially storing all prefix sums.
"""