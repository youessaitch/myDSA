class Solution {
public:
    int cnt = 0;  // Global counter for reverse pairs

    // Merge function to merge two halves
    void merge(vector<int> &arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temporary arrays
        vector<int> L(n1), R(n2);

        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        // Merge the temporary arrays back into arr[l..r]
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[], if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[], if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    //********MAIN PART - FUNCTION OTHER THAN MERGE SORT**********
    // Function to count reverse pairs in the array
    void countPairs(vector<int> &nums, int l, int mid, int r) {
        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));  // Increment the global count
        }
    }

    // Merge sort function
    void mergeSort(vector<int> &arr, int l, int r) {
        if (l >= r) {
            return;
        }

        int mid = l + (r - l) / 2;

        // Sort both halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        //****MERGE KRNE SE PEHLE CNT KRLO KI REQUIRED PAIR MIL RHE YA NHI***
        // Count reverse pairs
        countPairs(arr, l, mid, r);

        // Merge the two sorted halves
        merge(arr, l, mid, r);
    }

    // Main function to return the number of reverse pairs
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return cnt;
    }
};


