// Optimal Solution
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        int last_val = nums[n-1];
        temp.push_back(last_val);
        for(int i = n-2; i >= 0; i--){
            if(nums[i] > last_val){
                temp.push_back(nums[i]);
                last_val = nums[i];
            }
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

// Time Complexity:O(n) due to the single for loop and reverse function which iterates at most n times.
// Space Complexity:O(n) in the worst case, as the 'temp' vector might store all elements of the input array.


// Brute Force Solution
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            int flag = 0;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] >= nums[i]){
                    flag++;
                }
                if(flag == 1) break;
            }
            if(flag == 0){
                temp.push_back(nums[i]);
            }
            
        }

        return temp;
    }
};

// Time Complexity:The time complexity is O(n^2) due to the nested for loops.
// Space Complexity:The space complexity is O(n) because, in the worst case, the 'temp' vector could store all elements of the input 'nums' vector.