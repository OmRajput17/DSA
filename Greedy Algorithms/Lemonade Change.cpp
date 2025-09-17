#include<bits/stdc++.h>
using namespace std;

class Solution{    
  public:    
    bool lemonadeChange(vector<int>& bills){
        int five = 0, ten = 0;
        for(int i = 0; i<bills.size(); i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(five && ten){
                    five--; ten--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

"Time Complexity:O(n), where n is the number of bills.
Space Complexity:O(1), as only a constant amount of extra space is used."