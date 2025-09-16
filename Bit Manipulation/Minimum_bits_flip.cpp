#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        int ans = start ^ goal;
        int cnt = 0;
        for(int i=0; i<32; i++){
            // Check if the ith bit is set or not if yes then increase count
            if(ans & (1<<i)){
                cnt+=1;
            }
        }
        return cnt;
    }
};

// Time Complexity:O(1), the loop iterates a fixed 32 times.
// Space Complexity:O(1), uses a constant amount of extra space.