// OPtimal Approch

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num = nums[i];
            int needed = target - num;
            if(mpp.find(needed) != mpp.end()){
                return {mpp[needed], i};
            }
            mpp[num] = i;
        }
        return {-1,-1};

    }
};

// Time Complexity:O(n) due to the single for loop iterating through the input array
// Space Complexity:O(n) in the worst case, as the unordered map 'mpp' might store all elements of the input array 'nums'



// Brute Force

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};

// Time Complexity:The time complexity is O(n^2) due to the nested loops.
// Space Complexity:The space complexity is O(1) as it uses a fixed amount of extra space.