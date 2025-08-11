#include <bits/stdc++.h>

// Optimal Solution
class Solution {
public:
    bool canWePlace(vector<int> &nums,int dist, int k){
        int count = 1, last = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if((nums[i]-last) >= dist){
                count++;
                last = nums[i];
            }
        }
        if(count >= k) return true;
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 1, high = nums[nums.size()-1] - nums[0];
        while(low<=high){
            int mid = (low+high)/2;

            if(canWePlace(nums, mid, k)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};

// Time Complexity:O(n log n) due to sorting, plus O(n log(range)) where range is the difference between the largest and smallest element, due to binary search and the canWePlace function's O(n) complexity.
// Space Complexity:O(1) excluding the input array, as only a few variables are used.

// Brute Force
class Solution {
public:
    bool canWePlace(vector<int> &nums,int dist, int k){
        int count = 1, last = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if((nums[i]-last) >= dist){
                count++;
                last = nums[i];
            }
        }
        if(count >= k) return true;
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN, mini = nums[0];

        for(int i = 0; i<nums.size(); i++){
            maxi = max(nums[i], maxi);
        }

        for(int i = 1; i<=(maxi-mini); i++){
            if(canWePlace(nums, i, k)){
                continue;
            }
            else{
                return (i-1);
            }
        }
        return (maxi-mini);
    }
};

// Time Complexity:O(n log n) + O( (max_element - min_element) * n ) where n is the size of nums.
// Space Complexity:O(1) excluding the space used by the sorting algorithm which might be O(log n) in some implementations.