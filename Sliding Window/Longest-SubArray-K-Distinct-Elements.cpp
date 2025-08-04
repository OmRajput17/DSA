#include <bits/stdc++.h>
// Optimal
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int maxLen = 0, l = 0, r = 0, n = fruits.size(), k = 2;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            if(mpp.size()<=k){
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
}; 
"
In summary:
- Time Complexity: O(n)
- Space Complexity: O(1)
"

// Better 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int maxLen = 0, l = 0, r = 0, n = fruits.size(), k = 2;


        while(r<n){
            mpp[fruits[r]]++;

            while(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            if(mpp.size()<=k){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
}; 
" In summary:
 - Time complexity: O(n)
 - Space complexity: O(1)
"


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

"TC -> O(N^2)
SC -> O(1)
"
