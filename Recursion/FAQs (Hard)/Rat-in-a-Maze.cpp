#include<bits/stdc++.h>

class Solution{
private:
    void func(int i, int j, vector<string>& ans, string dir, vector<vector<int> > &grid, int n){
        if(i==n-1 && j==n-1){
            ans.push_back(dir);
            return;
        }

        if(grid[i][j] == 0){
            return;
        }

        // Marking visited
        grid[i][j] = 0;

        // Checking all possible Directions
        // down
        if(i < n-1)
            func(i+1, j, ans, dir+'D', grid, n);
        // right
        if(j < n-1)
            func(i, j+1, ans, dir+'R', grid, n);
        // left
        if(j > 0)
            func(i, j-1, ans, dir+'L', grid, n);
        if(i>0)
            func(i-1, j, ans, dir+'U', grid, n);

        // Unmarking the cell
        grid[i][j] = 1;
    }
public:
    vector<string> findPath(vector<vector<int> > &grid) {
        int n = grid.size();

        vector<string> ans;
        string dir = "";
        if(grid[0][0] == 0 || grid[n-1][n-1]==0){
            return ans; // No answer possible
        }

        func(0, 0, ans, dir, grid, n);
        
        // For maintaining Lexographical order
        sort(ans.begin(), ans.end());

        return ans;
    }
};


"Time Complexity:O(4^(n*n)) due to the recursive calls exploring all possible paths in a n*n grid, and O(n*logn) due to sorting
Space Complexity:O(n*n) for the visited grid, O(n) for the maximum depth of the recursion stack, and O(x), x is the number of possible paths, to store the answer paths
"