#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, minLen = INT_MAX, sIndex = -1;

        int hash[256] = {0};

        for(char c : t){
            hash[c]++;
        }

        int cnt = 0;

        while(r<s.size()){
            if(hash[s[r]] > 0){
                cnt++;
            }

            hash[s[r]]--;

            while(cnt == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIndex = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};

"Time Complexity:O(2N + M ), where N is the size of the string s and M is the size of the string t.
Space Complexity: O(256) . Hash array to store frequency of all the characters."