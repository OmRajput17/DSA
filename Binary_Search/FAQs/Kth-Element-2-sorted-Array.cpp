#include <bits/stdc++.h>

// Optimal
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();

        if(n1 > n2) return kthElement(b, a, k);
        int left = k;
        int low = max(0, k-n2), high = min(k, n1);
        while(low <= high){
            int mid1 = (low+high)/2;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

            if(l1<=r2 && l2<=r1){
                return max(l1, l2);
            }
            else if(l2 > r1){
                low = mid1 + 1;
            }
            else{
                high = mid1 - 1;
            }
        }
        return 0;
    }
};

"Time Complexity:The time complexity is O(log(min(n1, n2))), where n1 and n2 are sizes of the input arrays due to binary search.
Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space."


// Better Solutin
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        int cnt = 0;
        int ans;
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(a[i] < b[j]){
                if(cnt == (k-1)) ans = a[i];
                cnt++; i++;
            }
            else{
                if(cnt == (k-1)) ans = b[j];
                cnt++; j++;
            }
        }
        while(i < n1){
            if(cnt == (k-1)) ans = a[i];
            cnt++; i++;
        }
        while(j < n2){
            if(cnt == (k-1)) ans = b[j];
            cnt++; j++;
        }

        return ans;
    }
};

"Time Complexity:The time complexity is O(k) because the while loops iterate until 'cnt' reaches k, which is at most the sum of the lengths of the two input arrays.
Space Complexity:The space complexity is O(1) because the algorithm uses a constant amount of extra space, regardless of the input size."