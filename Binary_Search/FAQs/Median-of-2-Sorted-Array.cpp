#include<bits/stdc++.h>
// Optimal

class Solution {
public:
    double median(vector<int> &a, vector<int> &b) {
        int n1 = a.size(), n2 = b.size();

        if(n1 > n2) return median(b, a);
        int left = (n1+n2+1)/2;
        int low = 0, high = n1;
        while(low <= high){
            int mid1 = (low+high)/2;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2) return max(l1, l2);
                else{
                    return (double)((max(l1, l2) + min(r1, r2)))/2.0;
                }
            }
            else if(l2 > r1){
                low = mid1 + 1;
            }
            else{
                high = mid1 - 1;
            }
        }
        return 0.0;
    }
};

"Time Complexity:The time complexity is O(log(min(n1, n2))) because of the binary search on the smaller array.
Space Complexity:The space complexity is O(1) because only a constant amount of extra space is used."

// Better Approach

class Solution {
public:
    double median(vector<int> &a, vector<int> &b) {
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0;
        int n = (n1 + n2);
        int ind2 = n/2;
        int ind1 = ind2-1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;

        while(i < n1 && j < n2){
            if(a[i] < b[j]){
                if(cnt == ind1) ind1el = a[i];
                if(cnt == ind2) ind2el = a[i];
                cnt++; i++;
            }
            else{
                if(cnt == ind1) ind1el = b[j];
                if(cnt == ind2) ind2el = b[j];
                cnt++; j++;
            }
        }
        while(i<n1){
            if(cnt == ind1) ind1el = a[i];
            if(cnt == ind2) ind2el = a[i];
            cnt++; i++;
        }
        while(j<n2){
            if(cnt == ind1) ind1el = b[j];
            if(cnt == ind2) ind2el = b[j];
            cnt++; j++;
        }
        if(n % 2){
            return (double) ind2el;
        }

        return (double) ((double)(ind1el+ind2el)) / 2.0;
    }
};

"Time Complexity:O(m+n) due to iterating through both input arrays a and b, where m and n are the sizes of the arrays, respectively.
Space Complexity:O(1) because the algorithm uses a constant amount of extra space, regardless of the input size."


// Brute Force
class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> merged;
        int i = 0, j=0;
        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]){
                merged.push_back(arr1[i++]);
            }
            else{
                merged.push_back(arr2[j++]);
            }
        }
        while(i<n1){
            merged.push_back(arr1[i++]);
        }
        while(j<n2){
            merged.push_back(arr2[j++]);
        }
        int n = n1 + n2;
        if(n % 2==1) return (double)merged[n / 2];
        double median = ((double)merged[n / 2] + (double)merged[(n / 2) - 1])/2.0;
        return median;
    }
};

"Time Complexity:O(n1 + n2) due to merging two arrays of size n1 and n2.
Space Complexity:O(n1 + n2) to store the merged array."