#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;
        while(l < n && r < m){
            if(g[l] <= s[r]){
                l++;
            }
            r++;
        }
        return l;
    }
};

"Time Complexity:O(n log n + m log m + min(n, m)), where n is the size of Student vector and m is the size of Cookie vector. Sorting takes O(n log n) and O(m log m) respectively, and the while loop takes O(min(n, m)).
Space Complexity:O(1), as the algorithm sorts in place and uses a constant amount of extra space."