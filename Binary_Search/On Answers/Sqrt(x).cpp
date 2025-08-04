#include<bits/stdc++.h>

class Solution {
public:
    long long floorSqrt(long long x) {
        long long low = 1, high = x;
        int ans = 0;
        while(low<=high){
            long long mid = (low+high)/2;

            if(mid*mid <= x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        while(low<=high){
            long long mid = (low+high)/2;
            if(x>=mid*mid){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return high;
    }
};