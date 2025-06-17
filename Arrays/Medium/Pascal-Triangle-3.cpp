class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(ans);

        for(int i=1; i<row; i++){
            ans = ans*(row-i);
            ans = ans/i;
            ansRow.push_back(ans);
        }

        return ansRow;
    }
    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>> pascalTriangle;

        for(int row = 1; row <= n; row++){
            pascalTriangle.push_back(generateRow(row));
        }

        return pascalTriangle;
    }
};

// Time Complexity:The time complexity is O(n^2) because the outer loop runs 'n' times, and the inner loop 'generateRow' runs up to 'n' times in the worst case.
// Space Complexity:The space complexity is O(n^2) because the pascalTriangle vector stores 'n' rows, and each row can have up to 'n' elements.