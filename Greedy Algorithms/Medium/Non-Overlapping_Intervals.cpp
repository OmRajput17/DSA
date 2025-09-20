#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(vector<int>& val1, vector<int>& val2){
      return val1[1] < val2[1];
    }
    int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
        //your code goes here
        sort(Intervals.begin(), Intervals.end(), comparator);

        int n = Intervals.size();

        int cnt = 1;
        int freeTime = Intervals[0][1];

        for(int i = 1; i < n; i++){
          if(Intervals[i][0] >= freeTime){
            cnt++;
            freeTime = Intervals[i][1];
          }
        }
        return n - cnt;
    }
};


"Time Complexity:O(n log n) due to sorting, plus O(n) for the loop, so O(n log n + n) which simplifies to O(n log n)
Space Complexity:O(1) because the algorithm uses a constant amount of extra space."