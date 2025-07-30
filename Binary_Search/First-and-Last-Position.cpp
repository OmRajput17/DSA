class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int first = -1;
        int low = 0, high = n-1;
        vector<int> result(2);

        while(low<=high){
            int mid = (low + high)/2;

            if(arr[mid]==target){
            first = mid;
            high = mid -1;
            }
            else if(arr[mid]<target){
            low = mid +1;
            }else{
            high = mid-1;
            }
        }
        result[0] = first;
        low = 0, high = n-1;
        int last = -1;
        while(low<=high){
            int mid = (low + high)/2;

            if(arr[mid]==target){
            last = mid;
            low = mid + 1;
            }
            else if(arr[mid]<target){
            low = mid + 1;
            }
            else{
            high = mid - 1;
            }
        }
        result[1] = last;
        
        return result;
    }
}; 