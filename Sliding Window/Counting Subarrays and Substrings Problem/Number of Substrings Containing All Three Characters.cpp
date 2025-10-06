#include<bits/stdc++.h>
using namespace std;

// OPtimal Solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0, n = s.size();
        int lastSeen[3] = {-1,-1,-1};
        for(int i = 0; i<n; i++){
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0]!=-1 && lastSeen[1]!=-1, lastSeen[2]!=-1){
                cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return cnt;
    }
};
"Time Complexity:O(N), where N is the size of the string. The outer loop runs for N time.
Space Complexity: O(1) . As no significant amount of extra space is used."


// Brute Force
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0, n = s.size();
        for(int i = 0; i<n;i++){
            int hash[3] = {0};
            for(int j = i; j<n; j++){
                hash[s[j] - 'a'] = 1;

                if(hash[0]+hash[1]+hash[2] == 3){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

"Time Complexity:O(N2), where N is the size of the string. The outer loop runs for N time and for each character the inner loop also runs for N times.

Space Complexity: O(1) . As no significant amount of extra space is used."