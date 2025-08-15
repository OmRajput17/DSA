#include<bits/stdc++.h>

// OPtimal Solution

class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int row = 0, col = mat[0].size() - 1;
        while(row < mat.size() && col >= 0){
            if(mat[row][col] == target) return true;
            else if(mat[row][col] > target) col --;
            else row++;
        }
        return false;
    }
};

"Time Complexity:The time complexity is O(m + n), where m is the number of rows and n is the number of columns in the matrix.
Space Complexity:The space complexity is O(1) as it uses constant extra space."


// Better Solution
class Solution{
private:
    bool binarySearch(vector<int> nums, int k){
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == k) return true;
            else if(nums[mid] > k) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
public:
 bool searchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i<n; i++){
            if(binarySearch(mat[i], target)) return true;
        }
        return false;
    }
};

"Time Complexity:The time complexity is O(n * log(m)), where n is the number of rows and m is the number of columns in the matrix.
Space Complexity:The space complexity is O(1) as the binary search uses constant extra space."