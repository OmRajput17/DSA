// Optimal

// TC = O(N)
// SC = O(1)

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.end()-k);

        reverse(nums.end()-k, nums.end());
    }
};


// Brute Force

// TC = O(3N)
// SC = O(N)

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp;
        k = k % n;
        
        // storing to temp
        for(int i = 0; i<k; i++){
            temp.push_back(nums[i]);
        }

        // Shifting elements

        for(int i = k; i<n; i++){
            nums[i-k] = nums[i];
        }

        // Put back remaining elements

        for(int i = n-k; i<n; i++){
            nums[i] = temp[i-(n-k)];
        }
    }
};