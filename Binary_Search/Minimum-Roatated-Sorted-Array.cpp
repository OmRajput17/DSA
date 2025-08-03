#include <bits/stdc++.h>
class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;

            if(arr[low]<=arr[mid]){ // left half sorted
                ans = min(ans, arr[low]);

                low = mid+1;
            }
            else{
                // Right half sorted
                ans = min(ans, arr[mid]);

                high = mid-1;
            }
        }
        return ans;
    }
};

// Time Complexity:The time complexity is O(log n) because it performs a binary search.
// Space Complexity:The space complexity is O(1) because it uses a constant amount of extra space.