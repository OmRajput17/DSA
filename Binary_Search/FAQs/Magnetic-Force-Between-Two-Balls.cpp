#include<bits/stdc++.h>

// Similar to Aggresive Cows
class Solution {
public:
    bool canWePlace(vector<int> &nums,int dist, int k){
        int count = 1, last = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if((nums[i]-last) >= dist){
                count++;
                last = nums[i];
            }
        }
        if(count >= k) return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position[position.size()-1] - position[0];
        while(low<=high){
            int mid = (low+high)/2;

            if(canWePlace(position, mid, m)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};

"Time Complexity:
- Sorting the positions takes O(n log n), where n is the number of positions.
- The binary search runs over a range of distances, which in the worst case is proportional to the difference between the maximum and minimum position values. Let's denote this range as D.
- For each binary search iteration, the canWePlace function is called, which runs in O(n) time, as it iterates through the positions once.
- The number of binary search iterations is approximately O(log D).

Overall, the total time complexity is O(n log n + n log D). Since D can be large but is bounded by the maximum position difference, the dominant term is typically O(n log D).

Space Complexity:
- The algorithm uses a constant amount of extra space aside from the input array, mainly for variables and temporary storage.
- The sorting operation may require O(n) space depending on the sorting implementation, but typically it's considered O(1) or O(n) auxiliary space.

In summary:
Time complexity: O(n log n + n log D)
Space complexity: O(n) (due to sorting, if not in-place)"