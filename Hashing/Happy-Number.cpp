#include<bits.stdc++.h>

class Solution {
private:
    int getNextNumber(int n) {
        int output = 0;  
        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n = n / 10;
        }   
        return output;
    }
public:
    bool isHappy(int n) {
       unordered_set<int> visit;
        while(visit.find(n) == visit.end()){
            visit.insert(n);
            n = getNextNumber(n);
            if (n == 1) {
                return true;
            }
        }
        return false; 
    }
};

// - Time complexity: approximately O(log n * k), with k being small and bounded.
// - Space complexity: O(log n).