#include<bits/stdc++.h>
using namespace std;

class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};

// Time Complexity:The time complexity is O(n), due to a single loop iterating through the input vector.
// Space Complexity:The space complexity is O(1), as only a single integer variable is used.