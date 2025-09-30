#include<bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution {
   public:
    int totalFruits(vector<int>& fruits) {
        int maxLen = 0;
        int n = fruits.size();
        int l = 0, r = 0;
        unordered_map<int, int> mpp;
        while (r < n){
            mpp[fruits[r]]++;

            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            if(mpp.size() <= 2){
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};

"Time Complexity:O(N), where N is the size of the array. As the while loop runs for N time only. Ignore the contribution of map data structure in the time complexity as size of the map is extremely small.

Space Complexity: O(N) , as the map may store up to N unique fruit types in the worst case."

// Better Solution
class Solution {
   public:
    int totalFruits(vector<int>& fruits) {
        int maxLen = 0;
        int n = fruits.size();
        int l = 0, r = 0;
        unordered_map<int, int> mpp;
        while (r < n){
            mpp[fruits[r]]++;

            if(mpp.size()>2){
                while (mpp.size()>2)
                {
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0){
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }
            }

            if(mpp.size() <= 2){
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};

"Time Complexity:The time complexity is O(n), where n is the number of fruits, due to the sliding window approach where each fruit is visited at most twice.
Space Complexity:The space complexity is O(1), as the unordered map 'mpp' stores at most 3 distinct fruit types, making it constant."


// Brute Force
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int maxLen = 0;
        for(int i = 0; i<fruits.size(); i++){
          set<int> st;
          for(int j = i; j<fruits.size(); j++){
            st.insert(fruits[j]);
            if(st.size()<=2){
              maxLen = max(maxLen, (j - i + 1));
            }
            else{
              break;
            }
          }
        }

        return maxLen;
    }
};

"Time Complexity:The time complexity is O(n^2 * log(n)) because of the nested loops and the set insertion.
Space Complexity:The space complexity is O(n) due to the set potentially storing up to n distinct fruit types."