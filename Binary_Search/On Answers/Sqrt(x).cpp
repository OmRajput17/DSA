#include<bits/stdc++.h>

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