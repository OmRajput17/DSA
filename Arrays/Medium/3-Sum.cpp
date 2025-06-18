// OPtimal Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int j = i+1, k = n-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    triplets.push_back(temp);
                    j++; k--;

                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return triplets;
    }
}

// Time Complexity:O(n log n) for sorting + O(n^2) for the nested loops, which simplifies to O(n^2)
// Space Complexity:O(1) ignoring the space required for the output, otherwise it depends on the number of triplets found which can be O(n) in the worst case.


// Better Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplets;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            set<int> hashset;

            for(int j = i+1; j<n; j++){
                int third = -(nums[i]+nums[j]);

                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {third, nums[i], nums[j]};

                    sort(temp.begin(), temp.end());

                    triplets.insert(temp);
                }

                hashset.insert(nums[j]);
            }
        }

        return vector<vector<int>> (triplets.begin(), triplets.end());
    }
};

// Time Complexity:O(n^2) due to nested loops iterating through the array, with a set lookup inside.
// Space Complexity:O(n) in the worst case, due to the hashset and set potentially storing n elements.


// Brute Force Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplets;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j=i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        triplets.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(triplets.begin(), triplets.end());
    }
};

// Time Complexity:O(n^3 * log(n)), due to three nested loops and sorting within the innermost loop and set insertion.
// Space Complexity:O(n) in the worst case, considering the space used by the set 'triplets' to store the triplets and the temporary vector 'temp'.