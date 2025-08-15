#include<bits/stdc++.h>
// Optimal Solution
class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n * m - 1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = (mid / m );
            int col = (mid % m );
            if(mat[row][col] == target) return true;
            else if(mat[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
"Time Complexity:O(log(m*n)) due to the binary search on the flattened matrix where 'm' is the number of columns and 'n' is the number of rows.
Space Complexity:O(1) because the algorithm uses a constant amount of extra space."

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
            if(mat[i][0] <= target && mat[i][m-1] >= target){
                if(binarySearch(mat[i], target)) return true;
            }
        }
        return false;
    }
};

"Time Complexity: O(N + logM), where N is given row number, M is given column number. The rows are traversed in O(N) time complexity. Binary search is applied only once for a particular row, resulting in a time complexity of O(N + logM) instead of O(N*logM).

Space Complexity: As no additional space is used, so the Space Complexity is O(1)."