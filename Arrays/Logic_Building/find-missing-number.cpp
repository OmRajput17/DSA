class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nums_sum = 0, range_sum=0;
        int n = nums.size();

        nums_sum = accumulate(nums.begin(), nums.end(),0);
        range_sum = (n*(n+1))/2;
        int res = range_sum - nums_sum;

        return res;
    }
};

// Time Complexity:O(n) due to the accumulate function iterating through the nums vector, where n is the size of the input vector.
// Space Complexity:O(1) as the algorithm uses a constant amount of extra space, regardless of the input size.

class Solution {
public:
    // Function to find the missing number
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;

        // Calculate XOR of all array elements
        for (int i = 0; i < nums.size(); i++) {
            xor1 = xor1 ^ (i + 1); //XOR up to [1...N]
            xor2 = xor2 ^ nums[i]; // XOR of array elements
        }

        // XOR of xor1 and xor2 gives missing number
        return (xor1 ^ xor2);
    }
};

// Time Complexity:O(n) due to the single for loop iterating through the input array.
// Space Complexity:O(1) as only constant extra space is used for variables.