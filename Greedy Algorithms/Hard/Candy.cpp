#include<bits/stdc++.h>
using namespace std;

// Optimal Solution

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1, i = 1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                i++;
                down++;
            }

            if(down > peak){
                sum += (down - peak);
            }
        }

        return sum;
    }
};

"Time Complexity:O(n) because the while loop iterates through the ratings vector once.
Space Complexity:O(1) because the algorithm uses a fixed amount of extra space, regardless of the input size."


// Better Solution
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);

        left[0] = 1;

        for(int i = 1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }
            else{
                left[i] = 1;
            }
        }

        int curr = 1, right = 1;
        int sum = max(left[n-1], 1);

        for(int i = n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                curr = right+1;
            }
            else{
                curr = 1;
            }
            right = curr;
            sum += max(left[i], curr);
        }
        return sum;
    }
};

"Time Complexity:O(n) due to the single for loop iterating through the ratings array and another single for loop iterating from backwards.
Space Complexity:O(n) due to the usage of the left vector of size n."

// Brute Force

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;
        right[n-1] = 1;

        for(int i = 1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }
            else{
                left[i] = 1;
            }
        }

        for(int i = n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1]+1;
            }
            else{
                right[i] = 1;
            }
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};

"Time Complexity:O(n) due to three linear loops that iterate through the input array 'ratings' of size n.
Space Complexity:O(n) because two additional arrays, 'left' and 'right', of size n are used."