#include<bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, n = nums.size(), l = 0, r = 0, zeros = 0;
        while(r < n){
            if(nums[r] == 0){
                zeros++;
            }
            if(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            if(zeros <= k){
                int len = r-l+1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};

"Time Complexity:O(n), where n is the size of the input vector nums.
Space Complexity:O(1), as the algorithm uses a constant amount of extra space."


// Better Solution
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, n = nums.size(), l = 0, r = 0, zeros = 0;
        while(r < n){
            if(nums[r] == 0){
                zeros++;
            }
            while(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            if(zeros <= k){
                int len = r-l+1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};

"Time Complexity:O(n), where n is the size of the input vector nums, due to the single pass sliding window approach.
Space Complexity:O(1), as the algorithm uses a constant amount of extra space regardless of the input size."


// Brute Force
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here
        int maxLen = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            int zeroes = 0;
            for(int j = i; j<n; j++){
                if(nums[j] == 0){
                    zeroes++;
                }
                if(zeroes <= k){
                    int len = j - i + 1;
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};

"Time Complexity:The time complexity is O(n^2) because of the nested loops.
Space Complexity:The space complexity is O(1) as the algorithm uses a constant amount of extra space."