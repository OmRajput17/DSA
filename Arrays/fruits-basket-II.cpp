#include <bits/stdc++.h>

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = fruits.size(); 
        vector<bool> used(n, false);
        for(int i = 0; i<fruits.size(); i++){
            bool flg = false;
            for(int j = 0; j<fruits.size(); j++){
                if(!used[j] && fruits[i] <= baskets[j]){
                    flg = true;
                    used[j] = true;
                    break;
                }
            }
            if(flg == 0){
                count++;
            }
        }
        return count;
    }
};