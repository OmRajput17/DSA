// Optimal

class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                mid++; low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Time Complexity:O(n), where n is the size of the input vector, due to the single while loop.
// Space Complexity:O(1), as the algorithm uses a constant amount of extra space for variables, regardless of the input size

// Better Approach
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int c0=0, c1=0, c2 = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == 0) c0++;
            else if(nums[i] == 1) c1++;
            else c2++;
        }

        for(int i = 0; i<c0; i++) nums[i] = 0;
        for(int i = c0; i<c1+c0; i++) nums[i] = 1;
        for(int i = c0+c1; i<nums.size(); i++) nums[i] = 2;
    }
};
// Time Complexity:O(n), as the code iterates through the input vector 'nums' twice, once to count the occurrences of 0, 1, and 2, and again to overwrite the vector with the sorted values.
// Space Complexity:O(1), as the code uses a constant amount of extra space for the variables c0, c1, and c2, regardless of the input size.


// Brute force
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// Time Complexity:The time complexity is O(n log n) due to the sorting algorithm.
// Space Complexity:The space complexity is O(1) as it sorts in place.