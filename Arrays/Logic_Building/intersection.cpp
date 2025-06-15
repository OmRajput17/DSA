// Time Complexity:The time complexity is O(min(n, m)) because in the worst case, we iterate through the shorter of the two arrays once.
// Space Complexity:The space complexity is O(k), where k is the number of common elements in the two arrays, due to the 'ans' vector.

class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;

        while(i < n && j < m){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }

        return ans;
    }
};