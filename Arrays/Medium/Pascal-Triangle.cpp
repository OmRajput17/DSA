class Solution {
public:
    int nCr(int r, int c){
        int res = 1;
        for (int i = 0; i < c; i++){
            res = res*(r-i);
            res = res/(i+1);
        }
        return res;
    }

    int pascalTriangleI(int r, int c) {
        return nCr(r-1, c-1);
    }
};

// Time Complexity:The time complexity is O(c) due to the loop in the nCr function which iterates 'c' times.
// Space Complexity:The space complexity is O(1) because only a constant amount of extra space is used.