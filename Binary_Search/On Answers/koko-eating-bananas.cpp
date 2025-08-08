#include <bits/stdc++.h>

class Solution {
private:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i<piles.size(); i++){
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }

    long long totalH(vector<int>& piles, int bananas){
        long long hours=0;
        for(int i = 0; i<piles.size(); i++){
            hours += ceil((double)piles[i]/(double)bananas);
        }
        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while(low<=high){
            int mid = (low+high)/2;

            long long req_time = totalH(piles, mid);
            if(req_time <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

// Time Complexity:O(nlogm) where n is the size of nums and m is the maximum element in nums.
// Space Complexity:O(1)