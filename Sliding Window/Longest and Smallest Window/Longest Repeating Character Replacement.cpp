#include<bits/stdc++.h>
using namespace std;

// OPtimal Solution

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxf = 0, n = s.size();
        vector<int> hash(26, 0);

        while(r < n){
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);

            int changes = (r - l + 1) - maxf;
            if(changes > k){
                hash[s[l]-'A']--;
                l++;
                changes = (r - l + 1) - maxf;
            }

            if(changes <= k){
                maxLen = max(maxLen, (r-l+1));
            }
            r++;
        }

        return maxLen;
    }
};

"Time Complexity:O(n) because the while loop iterates through the string once, and operations inside take O(1) time.
Space Complexity:O(1) because the hash table has a fixed size of 26, independent of the input string size."


// Better Solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxf = 0, n = s.size();
        vector<int> hash (26, 0);
        while(r < n){
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);

            int changes = (r-l+1)-maxf;
            while(changes  > k){
                hash[s[l] - 'A']--;
                maxf = 0;
                for(int i = 0; i<26; ++i){
                    maxf = max(maxf, hash[i]);
                }
                l++;
                changes = (r-l+1)-maxf;
            }

            if(changes <= k){
                maxLen = max(maxLen, (r-l+1));
            }
            r++;
        }
        return maxLen;
    }
};

"Time Complexity:O(n) in the average case, but could potentially degrade to O(n^2) in the worst-case scenarios where the inner while loop iterates excessively. The outer loop iterates `n` times, and the inner loop's iterations depend on the input string `s` and the value of `k`.
Space Complexity:O(1) because the `hash` vector has a fixed size of 26, regardless of the input string size."

// Brute Force Solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, n = s.size();
        for(int i = 0; i<n;i++){
            vector<int> hash(26, 0);
            int maxf = 0;
            for(int j = i; j<n; j++){
                hash[s[j] - 'A']++;
                maxf = max(maxf, hash[s[j] - 'A']);
                int changes = (j - i + 1) - maxf;

                if(changes <= k){
                    maxLen = max(maxLen, (j-i+1));
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }
};

"Time Complexity:The time complexity is O(n^2) due to the nested loops, where the outer loop iterates 'n' times, and the inner loop iterates up to 'n' times for each iteration of the outer loop.
Space Complexity:The space complexity is O(1) because the 'hash' vector has a fixed size of 26, regardless of the input string size."