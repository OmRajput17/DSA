class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int left = 0, right = m-1;
        int top = 0, bottom = n-1;
        vector<int> ans;

        while(left<=right && top<=bottom){ 
            // right
            for(int i = left; i<=right; i++){
                ans.push_back(mat[top][i]);
            }
            top++;

            // bottom
            for(int i = top; i<= bottom; i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            
            if(top<=bottom){ 
                // left
                for(int i = right; i>=left; i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            

            if(left<=right){ 
                // top
                for(int i = bottom; i >= top; i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

// Time Complexity:O(m*n) because it iterates through all elements of the m x n matrix once.
// Space Complexity:O(m*n) due to the 'ans' vector storing all m*n elements of the matrix.