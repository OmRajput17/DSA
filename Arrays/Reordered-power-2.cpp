#include <bits/stdc++.h>

class Solution {
// private:
//     string getSorted(int n){
//         string s = to_string(n);
//         sort(s.begin(), s.end());
//         return s;
//     }
public:
    // unordered_set<string> st;
    // void buildset(){
    //     // 2^p -> 2^0 to 2^29
    //     // convert to string
    //  // sort it and store it in set
    //     for(int p = 0; p<=29; p++){
    //         string s = to_string(1<<p);
    //         sort(s.begin(), s.end());
    //         st.insert(s);
    //     } 
    // }
    vector<int> getVectorCount(int n){
        vector<int> vec(10, 0);

        while(n>0){
            vec[n%10] += 1;
            n = n/10;
        }
        return vec;

    }
    bool reorderedPowerOf2(int n) {

        vector<int> input = getVectorCount(n);
        for(int i=0; i<=29; i++){
            if(input == getVectorCount(1<<i)){
                return true;
            }
        }   

        return false;
        

        // if (st.empty()){
        //     buildset();
        // }
        
        // string str = to_string(n);
        // sort(str.begin(), str.end());
        
        // return st.count(str);
    }
};

// TC -> O(Logn)