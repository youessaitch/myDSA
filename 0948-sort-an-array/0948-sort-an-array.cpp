class Solution {
public:
    int n;
    void merge(vector<int>&nums, int l, int mid, int r){
        //divide into two
        int n1 = mid-l+1;
        int n2 = r-mid;

        vector<int> a(n1); //two arrays to store the left and right array
        vector<int> b(n2);

        for(int i=0;i<n1;i++) a[i] = nums[l+i];
        for(int i=0;i<n2;i++) b[i] = nums[mid+1+i];

        int i=0,j=0,k=l; //k->traverse main array nums
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                nums[k] = a[i];
                i++;
                k++;
            }else{
                nums[k] = b[j];
                j++;
                k++;
            }
        }

        while(i<n1){
            nums[k] = a[i];
            i++;k++;
        }

        while(j<n2){
            nums[k] = b[j];
            j++;k++;
        }
    }

    //divide and conquer
    void mergeSort(vector<int> &nums,int l,int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,r);

            merge(nums,l,mid,r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};