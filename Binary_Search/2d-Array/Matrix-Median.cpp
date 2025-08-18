#include <bits/stdc++.h>

class Solution{
private:
    int upperBound(vector<int> &nums, int x){
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int blackBox(vector<vector<int>>&matrix, int x){ // To check how many number are less than mid 
        int cnt = 0; 
        for(int i = 0; i<matrix.size(); i++){
            cnt += upperBound(matrix[i], x);
        }
        return cnt;
    }
public:
    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = INT_MAX, high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        int req = (n*m)/2;

        while(low<=high){
            int mid = low + (high - low)/2;

            int smallEquals = blackBox(matrix, mid);

            if(smallEquals <= req){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};

