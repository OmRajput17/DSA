class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        int el1, el2;
        int cnt1=0, cnt2 = 0;

        for(int i = 0; i<n; i++){
            if(cnt1 == 0 && el2!=nums[i]){
                cnt1 = 1; el1 = nums[i];
            }
            else if(el1!=nums[i] && cnt2==0){
                cnt2 = 1; el2 = nums[i];
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--; cnt2--;
            }
        }

        cnt1=0, cnt2=0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(el1 == nums[i]) cnt1++;
            if(el2 == nums[i]) cnt2++;
        }
        if(cnt1 >= (n/3)+1) ans.push_back(el1);
        if(cnt2 >= (n/3)+1 && el1 != el2) ans.push_back(el2);

        return ans;
    }
};

// Time Complexity:O(n) due to two iterations over the input vector of size n.
// Space Complexity:O(1) as it uses a fixed amount of extra space, regardless of the input size.