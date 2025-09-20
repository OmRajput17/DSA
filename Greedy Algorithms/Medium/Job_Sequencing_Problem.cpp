#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[2] > b[2]; // sort by profit (descending)
    }

    vector<int> JobScheduling(vector<vector<int>>& jobs) {
        // sort jobs by profit
        sort(jobs.begin(), jobs.end(), comp);

        int n = jobs.size();
        int maxDeadline = -1;
        for (auto it : jobs) {
            maxDeadline = max(maxDeadline, it[1]);
        }

        vector<int> has(maxDeadline + 1, -1); // slots available
        int cnt = 0, totalProfit = 0;

        for (int i = 0; i < n; i++) {
            // find a free slot for this job (before its deadline)
            for (int j = jobs[i][1]; j > 0; j--) {
                if (has[j] == -1) {
                    cnt++;
                    has[j] = jobs[i][0];  // store job id (optional)
                    totalProfit += jobs[i][2];
                    break;
                }
            }
        }

        return {cnt, totalProfit};
    }
};

"Time Complexity:O(n log n) + O(n*m), where n is the number of jobs and m is the maximum deadline.
Space Complexity:O(m), where m is the maximum deadline, due to the 'has' vector."

