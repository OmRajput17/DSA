#include <bits/stdc++.h>
using namespace std;
// Optimal Approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt = 0, el;

        for(int i = 0; i<n; i++){
            if(cnt == 0){
                el = nums[i];
                cnt = 1;
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        int cnt1=1;
        for(int i= 0; i<n; i++){
            if(nums[i] == el){
                cnt1++;
            }
        }
        if(cnt1 > (n/2)) return el;

        return -1;
    }
};

// Time Complexity:O(n) due to two for loops that iterate through the input vector of size n.
// Space Complexity:O(1) as it uses a constant amount of extra space for variables regardless of the input size.

// Better Approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int num:nums){
            mpp[num]++;
        }

        // Iterate in map

        for(auto & pair:mpp){
            if(pair.second>(n/2)){
                return pair.first;
            }
        }

        return -1;
    }
};

// Time Complexity:O(n) + O(n) which simplifies to O(n), where n is the size of the input array.
// Space Complexity:O(n) in the worst case, where n is the size of the input array.

// Brute Force
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=i; j<n; j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt>(n/2)){
                return nums[i];
            }
        }
        return 0;
    }
};

// Time Complexity:The time complexity is O(n^2) because of the nested loops, where the outer loop runs 'n' times and the inner loop, in the worst case, also runs 'n' times for each iteration of the outer loop.
// Space Complexity:The space complexity is O(1) because the algorithm uses a constant amount of extra space, regardless of the input size. Only a few integer variables are used.