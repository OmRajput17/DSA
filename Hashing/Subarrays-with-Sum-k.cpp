#include<bits/stdc++.h>

//  Optimal Solution
class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        map<int, int> mpp;
        mpp[0] = 1;
        int preSum = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++){
            preSum += nums[i];

            int remove = preSum - k;
            cnt += mpp[remove];
            mpp[preSum] += 1;
            
        }

        return cnt;
    }
};

//  Better Solution
class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        int count = 0;

        for(int i = 0; i<nums.size(); i++){
            int sum = 0;
            for(int j = i; j<nums.size(); j++){
                sum += nums[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};


// Time Complexity:The time complexity is O(n^2) due to the nested loops.
// Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space.



