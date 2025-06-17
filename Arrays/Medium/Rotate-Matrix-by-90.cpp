class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Time Complexity:O(n^2) due to nested loops for transpose and O(n^2) for reversing rows, resulting in O(n^2) overall.
// Space Complexity:O(1) as the rotation is performed in-place, using only a constant amount of extra space.