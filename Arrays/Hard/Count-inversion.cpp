// Optimal Approach
class Solution {
public:
    int cnt = 0;
    void merge(vector<int>& arr, int low,int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while((left<=mid) && (right<=high)){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }

    void mergeSortHelper(vector<int>& arr, int low, int high){
        if(low == high) return;

        int mid = (low+high)/2;
        mergeSortHelper(arr, low, mid);
        mergeSortHelper(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

   long long int numberOfInversions(vector<int> nums) {
        int n = nums.size();
        mergeSortHelper(nums, 0, n-1);
        return cnt;
    }
};

// Time Complexity:The time complexity is O(n log n) due to the merge sort algorithm.
// Space Complexity:The space complexity is O(n) because of the temporary array used in the merge function.



// Brute Force
class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
        int cnt = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(i < j && (nums[i]>nums[j])) cnt++;
            }
        }
        return cnt;
    }
};

// Time Complexity:The time complexity is O(n^2) because of the nested loops, where n is the size of the input vector `nums`.
// Space Complexity:The space complexity is O(1) because the algorithm uses a constant amount of extra space, irrespective of the input size.