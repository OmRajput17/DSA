#include <bits/stdc++.h>

// Brute Force 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int maxLen = 0, k = 2; // As we have only 2 baskets
        for(int i = 0; i<fruits.size(); i++){
            mpp.clear();
            for(int j = i; j<fruits.size(); j++){
                mpp[fruits[j]]++;
                if(mpp.size()<=k){
                    maxLen = max(maxLen, j - i + 1);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }
};

// TC -> O(N^2)
// SC -> O(N) In worst Cases
