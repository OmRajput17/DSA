#include <bits/stdc++.h>

class Solution {
private:
    int maxElem(vector<vector<int>>& mat, int n, int m, int col){
        int max_val = -1;
        int index = -1;
        for(int i = 0; i<n; i++){
            if(mat[i][col] > max_val){
                max_val = mat[i][col];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1;

        while(low<=high){
            int mid = (low+high)/2;
            int row = maxElem(mat, n, m, mid);
            int left = (mid - 1) >= 0 ? mat[row][mid - 1] : -1;
            int right = (mid + 1) < m ? mat[row][mid + 1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if(mat[row][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

"Time Complexity:O(nlog(m)) where n is the number of rows and m is the number of columns due to the binary search on columns and linear search to find the maximum element in a column.
Space Complexity:O(1) as it uses a constant amount of extra space."