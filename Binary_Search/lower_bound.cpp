#include<bits/stdc++.h>

class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(nums[i] >= x){
                return i;
            }
        }
        return n;
    }
};

// Time Complexity:The time complexity is O(n) because the loop iterates through the input vector 'nums' in the worst case.
// Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space.


class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int low = 0, high = nums.size() - 1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] >= x){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};

// Time Complexity:The time complexity is O(log n) due to the binary search algorithm.
// Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space.


