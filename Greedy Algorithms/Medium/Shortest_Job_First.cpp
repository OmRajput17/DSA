#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());

        long long wTime = 0, totalTime = 0;
        for(int i = 0; i<bt.size(); i++){
            wTime += totalTime;
            totalTime += bt[i];
        }

        return wTime/bt.size();
    }
};

"Time Complexity: O(N logN + N) where N is the length of the jobs array.The code first sorts the job durations, which takes O(N logN) time. After sorting, it iterates through the job durations to calculate the total waiting time, which takes O(N) time.
Space Complexity: O(1) no extra space used."