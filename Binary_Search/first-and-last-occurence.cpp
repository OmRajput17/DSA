#include<bits/stdc++.h>

class Solution{
private:
    int firstOccurence(vector<int> &nums, int target){
        int low = 0, high = nums.size()-1;
        int first = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid]>target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return first;
    }
    int lastOccurrence(vector<int> &nums, int target){
        int low = 0, high = nums.size()-1;
        int last = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid]>target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int first, last;
        first = firstOccurence(nums, target);
        last = lastOccurrence(nums, target);
        return {first, last};
    }
};

// Time Complexity:The time complexity is O(log n) because both firstOccurence and lastOccurrence use binary search.
// Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space.