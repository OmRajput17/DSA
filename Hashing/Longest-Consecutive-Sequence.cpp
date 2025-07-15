// Optimal Solution
class solution{
private:
    int longestConsecutive(vector<int>& arr){
        int longest = 1;
        unordered_set<int> st;
        for(int i = 0; i<arr.size(); i++){
            st.insert(arr[i]);
        }
        for (auto it:st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x + 1;
                    cnt += 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

"""
Time Complexity:O(n) due to the insertion into the set and the iteration through the set, with the inner while loop effectively processing each element once in the worst case.
Space Complexity:O(n) because the unordered set can store up to n elements, where n is the number of elements in the input array.

"""


// Better Solution
class solution{
private:
    int longestConsecutive(vector<int>& arr){
        sort(arr.begin(), arr.end());
        int last_smaller = INT_MIN, longest = 1, cnt = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] - 1 == last_smaller){
                cnt += 1;
                last_smaller = arr[i];
            }
            else if(arr[i] != last_smaller){
                cnt = 1; last_smaller = arr[i];
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};
"""
Time Complexity:O(n log n) due to the sorting algorithm, where n is the size of the input array.
Space Complexity:O(1) as it uses a constant amount of extra space.

"""

// Brute Force
#include<bits/stdc++.h>
class Solution {
private:
    bool linearSearch(vector<int>& arr, int num){
        for(int i=0; i< arr.size(); i++){
            if(arr[i] == num) return true;
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& arr) {
        int longest = 1;
        for(int i = 0; i<arr.size(); i++){
            int x = arr[i];
            int cnt = 1;
            while (linearSearch(arr, x+1))
            {
                x = x + 1;
                cnt += 1;
            }    
            
            longest = max(longest, cnt);
        }
        return longest;
    }
};

"""
Time Complexity:O(n^2) due to nested loops: the outer loop iterates 'n' times, and the inner `linearSearch` also iterates up to 'n' times in the worst case for each iteration of the outer loop.
Space Complexity:O(1) as the algorithm uses a constant amount of extra space, regardless of the input size. The `linearSearch` function uses O(1) extra space, and the variables `longest`, `x`, `cnt`, and `i` also use O(1) space.
"""