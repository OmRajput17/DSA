#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {        
        int ones = 0, twos = 0;
        for(int i=0; i<nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};

"Time Complexity:The time complexity is O(n) because the code iterates through the input vector 'nums' once.
Space Complexity:The space complexity is O(1) because the code uses a constant amount of extra space, regardless of the input size."