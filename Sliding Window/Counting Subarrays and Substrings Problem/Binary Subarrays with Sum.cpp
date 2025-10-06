#include<bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumLessEqualToGoal(nums, goal) - numSubarraysWithSumLessEqualToGoal(nums, goal - 1);
    }
private:
    int numSubarraysWithSumLessEqualToGoal(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0, r = 0; 
        int sum = 0;      
        
        int count = 0;   
        
        while (r < nums.size()) {
            sum += nums[r]; 
            
            while (sum > goal) {
                sum -= nums[l];  
                l++;            
            }
            count += (r - l + 1);
            r++; 
        }
        return count;
    }
};

"Time Complexity:O(2*2N), where N is the size of the string. The outer loop runs for N time and the inner while loop might be running for N time throughout the program. So it becomes O(2N), also the helper function is being called twice so overall time complexity is O(2*2N).
Space Complexity: O(1). There is no extra space being used."

// Brute force
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += nums[j];

                if(sum == goal){
                    count++;
                    // break;
                }
            }
        }
        return count;
    }
};

"Time Complexity:The time complexity is O(n^2) because of the nested loops iterating through the array.
Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space."