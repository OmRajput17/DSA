#include <bits/stdc++.h>

// Binary Search
class Solution {   
private:
    long long power(int mid, int n, int m) {
        long long result = 1, base = mid;
        while(n>0){
            if(n % 2 == 1){
                result *= base;
                if(result>m) return 2;
                n = n-1;
            }
            else{
                n = n/2;
                base = base*base; 
                if(base > m) return 2;
            }
        }

        if (result == m) return 1;
        return 0;
    }
public:
    int NthRoot(int N, int M) {
        int low = 1, high = M;

        while(low<=high){
            int mid = (low+high)/2;
            int midN = power(mid, N, M);
            if(midN == 1) return mid;
            else if(midN == 2) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};

// Linear Search
class Solution {   
private:
    long long helperFunc(int k , int n){
        long ans = 1;
        while(k>0){
            ans *= n;
            k--;
        }

        return ans;
    }
public:
    int NthRoot(int N, int M) {
        for(int i = 1; i<= M; i++){
            if(helperFunc(i, N) == M){
                return i;
            }
            else if(helperFunc(i, N)>M){
                break;
            }
        }
        return -1;
    }
};

// Time Complexity:The time complexity is O(M * logN), where M is the input M and N is the input N.
// Space Complexity:The space complexity is O(1) as it uses constant extra space.