#include<bits/stdc++.h>
using namespace std;

class Solution {  
public:
    bool isValid(string s) {
        int minOpen = 0, maxOpen = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                minOpen++;
                maxOpen++;
            }
            else if(s[i] == ')'){
                minOpen--;
                maxOpen--;
            }
            else if(s[i]=='*'){
                minOpen--;
                maxOpen++;
            }

            if(minOpen < 0) minOpen = 0;
            if(maxOpen < 0) return false;
        }

        return minOpen == 0;
    }
};

"Time Complexity:O(n), where n is the length of the string s, due to the single for loop.
Space Complexity:O(1), as the algorithm uses a constant amount of extra space."