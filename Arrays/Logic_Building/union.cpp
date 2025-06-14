class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int n = nums1.size(), m = nums2.size();
        vector<int> union_arr;
        while(i<n && j<m){
            if(nums1[i] <= nums2[j]){
                int value = nums1[i];
                if (union_arr.empty() || union_arr.back() != value)
                    union_arr.push_back(value);
                i++;
            }
            else{
                int value = nums2[j];
                if (union_arr.empty() || union_arr.back() != value)
                    union_arr.push_back(value);
                j++;
            }
        }

        // Pushing remaining elements
        while(i < n){
            int value = nums1[i];
                if (union_arr.empty() || union_arr.back() != value)
                    union_arr.push_back(value);
            i++;
        }
        while(j<m){
            int value = nums2[j];
                if (union_arr.empty() || union_arr.back() != value)
                    union_arr.push_back(value);

            j++;
        }

        return union_arr;
    }
};

// Time Complexity:O(n+m), where n and m are the sizes of the input arrays nums1 and nums2, respectively. This is because the while loops iterate through both arrays at most once.
// Space Complexity:O(n+m) in the worst case, where n and m are the sizes of the input arrays nums1 and nums2, respectively. This occurs when all elements in both arrays are unique and must be stored in the union_arr vector.