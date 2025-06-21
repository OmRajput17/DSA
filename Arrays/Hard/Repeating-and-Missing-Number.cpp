// OPtimal 1

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        long long n = nums.size();
        // S - Sn
        long long Sn = (n * (n + 1)) / 2;
        long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;

        long long S=0;
        long long S2 = 0;
        for(int i = 0; i<n ; i++){
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        long long val1 = S - Sn; // x-y
        long long val2 = S2 - S2n;

        val2 = val2 / val1; //x+y

        long long x = (val1 + val2) / 2;
        long long y = (x - val1);

        return {(int)x, (int)y};

    }
};


// Better Solution
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        vector<int> hasharr(n+2, 0);
        int missing, repeating;

        for(int i = 0; i<n;i++){
            hasharr[nums[i]] += 1;
        }

        for(int i = 1; i<= n; i++){
            if(hasharr[i] == 2){
                repeating = i;
            }
            else if(hasharr[i] == 0){
                missing = i;
            }
        }

        return {repeating, missing};
    }
};

// Time Complexity:O(n) due to two loops iterating through the input of size n.
// Space Complexity:O(n) due to the use of hasharr of size n+2.