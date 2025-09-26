#include<bits/stdc++.h>
using namespace std;

// Optimal Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, len = 0, n = s.size(), l = 0, r = 0;

        vector<int> hash(256, -1);

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            len = r - l + 1;

            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
"Time Complexity:O(n), where n is the length of the string s, due to the single while loop.
Space Complexity:O(1), because the hash table has a fixed size of 256, regardless of the input string size."



// Brute Force
class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        int maxLen = 0, len = 0, n = s.size();

        for(int i = 0; i<n; i++){
        
            vector<int>hash(256, 0);
            
            for(int j = i; j<n; j++){
                if(hash[s[j]] == 1){
                    break;
                }

                len = j - i + 1;

                maxLen = max(maxLen, len);
                hash[s[j]] = 1;
            }
        }

        return maxLen;
    }
};

"Time Complexity:O(n^2) due to the nested loops, where 'n' is the length of the string. The outer loop iterates 'n' times, and the inner loop can iterate up to 'n' times in the worst case. The initialization of the hash vector inside the outer loop does not change the overall time complexity.
Space Complexity:O(1) because the hash vector always has a fixed size of 256, regardless of the input string size. Other variables use a constant amount of space."