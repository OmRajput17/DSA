#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;

        // Left Segment
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        // Overlapping Interval
        while(i<intervals.size() && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Pushing Interval to the res
        res.push_back(newInterval);

        // Right Segment
        while(i < intervals.size()){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

// TC -> O(N)
// SC -> O(N)