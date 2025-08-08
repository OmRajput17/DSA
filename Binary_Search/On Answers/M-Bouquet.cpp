#include <bits/stdc++.h>

class Solution {
private:
bool possible(vector<int> nums, int k, int m, int mid){
    int bouq = 0, cnt = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] <= mid){
            cnt++;
        }
        else{
            bouq += (cnt/k);
            cnt = 0;
        }
    }
    bouq += (cnt/k);
    return (bouq >= m) ? true : false;
}
public:
int roseGarden(int n,vector<int> nums, int k, int m) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int val = m * k;

        if(val > n) return -1;

        while(low<=high){
            int mid = (low+high)/2;
            if(possible(nums, k, m, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }    
        }
        return low;
    }
};

// Time Complexity:O(n log(max - min)), where n is the size of the input array nums, and max and min are the maximum and minimum elements in nums.
// Space Complexity:O(1), constant extra space is used.