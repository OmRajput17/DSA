#include<bits/stdc++.h>

// Using Recursion
class Solution {
   private:
    double power(double x, long n) {
        if (n == 0) {
            return 1.0;
        }

        if (n == 1) {
            return x;
        }

        if (n % 2 == 0) {
            return power(x * x, n / 2);
        }

        return x * power(x, n - 1);
    }

   public:
    double myPow(double x, int n) {
        long num = n;

        if (num < 0) {
            return (1.0 / power(x, -1*num));
        }

        return power(x, num);
    }
};

"Time Complexity:O(log n) due to the recursive calls which halves the exponent in each call.
Space Complexity:O(log n) due to the recursive call stack."


// Using Maths

class Solution {
   public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long num = n;

        if (num < 0) {
            x = 1 / x;
            num = -num;
        }
        while (num > 0) {
            if (num % 2) {
                ans *= x;
                num = num - 1;
            } else {
                x *= x;
                num = num / 2;
            }
        }
        return ans;
    }
};

"Time Complexity:The time complexity is O(log n) because in each iteration, the value of 'num' is halved.
Space Complexity:The space complexity is O(1) as only a constant amount of extra space is used."