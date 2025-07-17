#include<bits/stdc++.h>
// Optimal Solution for Positives
class solution{
public:
    int longestSubarray(vector<int> nums, int k){
        int left = 0, right = 0;
        int sum = nums[0];
        int maxLen = 0;
        int n = nums.size();
        while (right<n){
            while(left<= right &&  sum>k){
                sum -= nums[left];
                left++;
            }
            if(sum == k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
            if (right<n){
                sum += nums[right];
            }
        }
        return maxLen;
    }
};

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