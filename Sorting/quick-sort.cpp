class Solution {
public:
    void qS(vector<int>& arr, int low, int high){
        int partition;
        if(low < high){
            partition = Helper(arr, low, high);
            qS(arr, low, partition-1);
            qS(arr, partition+1, high);
        }
    }

    int Helper(vector<int>& arr, int low, int high){
        int pivot;
        pivot = arr[low];
        int i = low, j = high;

        while(i < j){
            while(arr[i] <= pivot && i <= high){
                i++;
            }
            while(arr[j] > pivot && j >= low){
                j--;
            }

            if (i < j){
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);

        return j;
    }
    vector<int> quickSort(vector<int>& arr) {
        qS(arr, 0, arr.size()-1);

        return arr;
    }
};


// TC = O(N^2)
// SC = O(1)