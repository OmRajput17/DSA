#include<bits/stdc++.h>

// Optimal
class Solution {
public:
    int bookHold(vector<int> &nums, int pages){
        int students = 1, pagesStudent = 0;

        for(int i = 0; i<nums.size(); i++){
            if(pagesStudent+nums[i] <= pages){
                pagesStudent += nums[i];
            }
            else{
                students++;
                pagesStudent = nums[i];
            }
        }
        return students;
    }
    
    int findPages(vector<int> &nums, int m)  {
        if(nums.size() < m) return -1;
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(),0);

        while(low<=high){
            int mid = (low+high)/2;

            if(bookHold(nums, mid) > m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};

"Time Complexity:The time complexity is O(n log(sum(nums) - max(nums))), where n is the size of nums.
Space Complexity:The space complexity is O(1)."


// Brute Force
class Solution {
public:
    int bookHold(vector<int> &nums, int pages){
        int students = 1, pagesStudent = 0;

        for(int i = 0; i<nums.size(); i++){
            if(pagesStudent+nums[i] <= pages){
                pagesStudent += nums[i];
            }
            else{
                students++;
                pagesStudent = nums[i];
            }
        }

        return students;
    }
    
    int findPages(vector<int> &nums, int m)  {
        if(nums.size() < m) return -1;
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(),0);

        for(int i = low; i<=high; i++){
            if(bookHold(nums, i) <= m){
                return i;
            }
        } 
        return low;
    }
};

"Time Complexity:O(n*sum(nums)), where n is the size of nums and sum(nums) is the sum of elements in nums.
Space Complexity:O(1), as the algorithm uses a constant amount of extra space."