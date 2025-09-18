#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int maxInd = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxInd) {
                return false;
            }
            maxInd = max(maxInd, i + nums[i]);
        }
        return true;
    }
};

"Time Complexity:The time complexity is O(n) because the code iterates through the input vector 'nums' once.
Space Complexity:The space complexity is O(1) because the code uses a constant amount of extra space, regardless of the input size."