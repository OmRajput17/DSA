class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> quads;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k = j+1, l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        quads.insert(temp);
                        k++; l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                }

            }
        }
        return vector<vector<int>>(quads.begin(), quads.end());
    }
};


// Time Complexity:O(n^3) due to the nested loops and two-pointer approach after sorting.
// Space Complexity:O(n) in the worst case, primarily due to the space used by the set `quads` and sorting, where n is the number of elements in nums.