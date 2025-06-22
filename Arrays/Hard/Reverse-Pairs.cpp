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

    void countPairs(vector<int>& nums, int low, int mid, int high){
        int right = mid+1;
        for(int i = low; i<=mid; i++){
            while(right <= high && (long long)nums[i] > (long long)2*nums[right]) {
                right++;
            }
            cnt += (right - (mid+1));
        }
    }

    void mergeSortHelper(vector<int>& arr, int low, int high){
        if(low == high) return;

        int mid = (low+high)/2;
        mergeSortHelper(arr, low, mid);
        mergeSortHelper(arr, mid+1, high);
        countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSortHelper(nums, 0, n-1);
        return cnt;
    }
};

// Time Complexity:The time complexity is O(n log n) due to the merge sort algorithm.
// Space Complexity:The space complexity is O(n) because of the temporary array used in the merge function.