#include<bits/stdc++.h>

// For Sorted Rows of matrix

class Solution {
private:
    int first_occ(vector<int>nums, int k){
        int low = 0, high = nums.size()-1;
        int first = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=k){
                first = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return first;
    }
public:   
    int rowWithMax1s(vector < vector < int >> & mat) {
        int n = mat.size(), m = mat[0].size();
        int cnt_max = 0;
        int index = -1;
        for(int i = 0; i<n; i++){
            int cnt_ones = 0;
            cnt_ones = m - first_occ(mat[i], 1);
            if(cnt_max < cnt_ones){
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

"Time Complexity:The outer loop iterates 'n' times, and the inner function 'first_occ' has a time complexity of O(log m). Thus, the overall time complexity is O(n log m).
Space Complexity:The space complexity is O(1) because the algorithm uses a constant amount of extra space."